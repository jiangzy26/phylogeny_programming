//
// Created by 姜志永 on 2021/11/22.
//

#ifndef PHYLOGENY_LEARN_TREENODE_H
#define PHYLOGENY_LEARN_TREENODE_H

#include <string>


class TreeNode
{
public:
	TreeNode(void);
	TreeNode(const TreeNode & tn); 
	~TreeNode(void);

	TreeNode &                                       operator=(const TreeNode & tn);

	double                                                getAge(void) const;
	double                                                getBranchLength(void) const;
	size_t                                                  getIndex(void) const;
	const TreeNode *                               getLeftChild(void) const;
	TreeNode *                                        getLeftChild(void);
	const std::string &                              getName(void) const;
	const TreeNode *                               getParent(void) const;
	TreeNode *                                        getParent(void);
	const TreeNode *                               getRightChild(void) const;
	TreeNode *                                        getRightChild(void);
	bool                                                   isRoot(void) const;
	bool                                                   isTip(void) const;
	void                                                   setAge(double a);
	void                                                   setLeftChild(TreeNode *n);
	void                                                   setIndex(size_t i);
	void                                                   setName(const std::string & n);
	void                                                   setParent(TreeNode * n);
	void                                                   setRightChild(TreeNode *n);
	void                                                   setBranchLength_jiang( double a);
	double                                                   getBranchLength_jiang(void) const;

private:
	TreeNode *                                            parent;
	TreeNode *                                            left;
	TreeNode *                                            right;

	int                                                           index;
	double                                                    age;
	double                                                    branch;
	std::string                                               name;

};



#endif //PHYLOGENY_LEARN_TREENODE_H
