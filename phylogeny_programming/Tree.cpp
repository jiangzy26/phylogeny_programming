//
// Created by 姜志永 on 2021/11/22.
//

#include "Tree.h"
#include "TreeNode.h"

#include <stdio.h>
#include <iostream>

Tree::Tree(TreeNode *r):
	root(r)
{
	fillNodesByPhylogeneticTraversal(root);
}

Tree::Tree(const Tree &t):
	root(NULL)
{
	if(t.root != NULL)
	{
		root = new TreeNode( *t.root);
		fillNodesByPhylogeneticTraversal(root);
	}
}

Tree::~Tree(void)
{
	delete root;
}

Tree & Tree::operator=(const Tree &t)
{
	if (this != &t)
	{
		delete root;
		root = NULL;
		nodes.clear();

		if (t.root != NULL)
		{
			root = new TreeNode(*t.root);
			fillNodesByPhylogeneticTraversal(root);
		}

	}

	return *this;

}


std::string Tree::computeNewickRecursively(const TreeNode & node) const
{
	//initialize the newick string as an empty string
	std::string newick = "";
	if (node.isTip() == true)
	{
		newick = node.getName();
	}
	else
	{
		//since it is not a tip node, it must be an interior node with two children
		//we therefore compute the newick string for both children
		//this is done with a recursive call to this function with the left and right child as an argument
		std::string left = computeNewickRecursively( *node.getLeftChild() );
		std::string right = computeNewickRecursively( *node.getRightChild() );

		if (left < right)
		{
			newick = "(" + left + ","+right+")";
		}
		else
		{
			newick = "(" + right + ","+left+")";
		}

	}

	newick += ":" + std::to_string(node.getBranchLength_jiang());

	return newick;

}


//Fill the nodes vector in phylogenetic ordering 
void Tree::fillNodesByPhylogeneticTraversal(TreeNode * node)
{
	if(node -> isTip())
	{
		nodes.insert(nodes.begin(), node);
	}
	else
	{
		fillNodesByPhylogeneticTraversal(node->getLeftChild());
		fillNodesByPhylogeneticTraversal(node->getRightChild());

		nodes.push_back(node);

	}
}


std::string Tree::getNewick(void) const
{
	return computeNewickRecursively (*root);
}


const std::vector<TreeNode *> Tree::getNodes(void) const
{
	return nodes;
}

size_t Tree::getNumberofNodes(void) const
{
	return nodes.size();
}


const TreeNode * Tree::getRootNode(void) const
{
	return root;
}














