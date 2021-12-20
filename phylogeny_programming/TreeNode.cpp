//
// Created by 姜志永 on 2021/11/22.
//

#include "TreeNode.h"
#include <stdio.h>
#include <iostream>

//Constructor of the tree node class, initialize the TreeNode object
TreeNode::TreeNode(void):
parent(NULL),
left(NULL),
right(NULL),
index(0),
age(0.0),
branch(0.0),
name("")
{
}

TreeNode::TreeNode(const TreeNode & tn):
    parent(tn.parent),
	left(NULL),
	right(NULL),
	index(tn.index),
	age(tn.age),
	branch(tn.branch),
	name(tn.name)
	{
		if (tn.left != NULL)
		{
			left = new TreeNode(* tn.left);
			left-> setParent(this);
		}
		if (tn.right != NULL)
		{
			right = new TreeNode(* tn.right);
			right-> setParent(this);
		}
	}

//Destructor
TreeNode::~TreeNode(void)
{
	delete left;
	delete right;
}

TreeNode & TreeNode::operator=(const TreeNode & tn)
{
	if (this != &tn)
	{
		delete left;
		delete right;

		left = NULL;
		right=NULL;

		parent = tn.parent;
		index = tn.index;
		age = tn.age;
		name = tn.name;

		if (tn.left != NULL)
		{
			left = new TreeNode(* tn.left);
			left-> setParent(this);
		}
		if (tn.right != NULL)
		{
			right = new TreeNode(* tn.right);
			right-> setParent(this);
		}
	}

	return *this;
}

double TreeNode::getAge(void) const
{
	return age;
}

double TreeNode::getBranchLength(void) const
{
	if ( parent != NULL )
	{
		return parent->getAge() - age;
	}
	else
	{
		return 0.0;
	}
}

double TreeNode::getBranchLength_jiang(void) const
{
	return branch;
}


size_t TreeNode::getIndex(void) const
{
	return index;
}

const TreeNode * TreeNode::getLeftChild(void) const
{
	return left;
}

TreeNode * TreeNode::getLeftChild(void)
{
	return left;
}

const std::string & TreeNode::getName(void) const
{
	return name;
}


const TreeNode * TreeNode::getParent(void) const
{
	return parent;
}

TreeNode * TreeNode::getParent(void)
{
	return parent;
}


const TreeNode * TreeNode::getRightChild(void) const
{
	return right;
}


TreeNode * TreeNode::getRightChild(void)
{
	return right;
}


bool TreeNode::isRoot(void) const
{
	return parent == NULL;
}

bool TreeNode::isTip(void) const
{
	return left == NULL && right == NULL;
}

void TreeNode::setAge(double a)
{
	age = a;
}

void TreeNode::setLeftChild(TreeNode * n)
{
	delete left;
	left = n;
}

void TreeNode::setIndex(size_t i)
{
	index = i;
}

void TreeNode::setName(const std::string & n)
{
	name = n;
}

void TreeNode::setParent(TreeNode * n)
{
	parent = n;
}

void TreeNode::setRightChild(TreeNode * n)
{
	delete right;
	right = n;
}

void TreeNode::setBranchLength_jiang(double a)
{
	branch = a;
}

