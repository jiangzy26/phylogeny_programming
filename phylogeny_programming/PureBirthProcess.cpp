#include "PureBirthProcess.h"

#include "Tree.h"
#include "TreeNode.h"
#include <cmath>


PureBirthProcess::PureBirthProcess(const double *b):
birth_rate(b)
{

}

PureBirthProcess::~PureBirthProcess()
{

}

double PureBirthProcess::lnProbability(void) const
{
	double ln_prob = 0.0;
	double l = *birth_rate;

	const std::vector<TreeNode *> &nodes = value->getNodes();

	for(size_t i = 0; i< nodes.size();i++)
	{
		TreeNode * node = nodes[i];

		if(node ->isRoot() == false)
		{
			double bl = node-> getBranchLength();
			ln_prob -= l * bl;

			if(node->isTip() == false)
			{
				ln_prob += std::log(l);
			}

		}

	}

	return ln_prob;

}

Tree * PureBirthProcess::rv(RandomNumberGenerator * rng, double age)
{
	double l = *birth_rate;

	std::vector<TreeNode*> active;
	std::vector<TreeNode*> inactive;

	TreeNode *root = new TreeNode();
	TreeNode *left = new TreeNode();
	left->setParent(root);
	root->setLeftChild(left);
	TreeNode *right = new TreeNode();
	right->setParent(root);
	root->setRightChild(right);

	root->setAge(age);

	active.push_back(left);
	active.push_back(right);
	inactive.push_back(root);

	double current_time=age;
	while(current_time >0.0)
	{
		double rate = l * active.size();
		double u = rng->uniform01();
		double next_time = current_time + (1.0 / rate) * std::log(u);

		if(next_time < 0)
		{
			break;
		}

		size_t index = rng->uniform01() * active.size();
		TreeNode * node = active[index];

		node->setAge(next_time);

		TreeNode * left = new TreeNode();
		left->setParent(node);
		node->setLeftChild(left);
		TreeNode * right = new TreeNode();
		right->setParent(node);

		node->setRightChild(right);

		active.erase(active.begin() + index);
		active.push_back(left);
		active.push_back(right);

		inactive.push_back(node);

		current_time = next_time;

	}

	size_t num_taxa = active.size();

	for(size_t i = 0; i < inactive.size(); i++)
	{
		TreeNode * node = inactive[i];
		node->setIndex(2*num_taxa-2-i);
	}

	for(size_t i = 0; i < num_taxa;i++)
	{
		size_t index = rng->uniform01() * active.size();
		TreeNode * node = active[index];
		active.erase(active.begin() + index);
		node->setIndex(i);
		node->setName("Tip" + std::to_string(i));
	}

	Tree * t= new Tree(root);

	return t;

}

