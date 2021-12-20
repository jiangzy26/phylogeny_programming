//
// Created by 姜志永 on 2021/11/22.
//

#ifndef PHYLOGENY_LEARN_TREE_H
#define PHYLOGENY_LEARN_TREE_H

#include <vector>
#include <string>

class TreeNode;

class Tree
{
	public:
		Tree(TreeNode * r);
		Tree(const Tree & t);
		~Tree(void);

		Tree &                                                   operator=(const Tree & t);
		std::string                                              getNewick(void) const ;
		const std::vector<TreeNode *>             getNodes(void) const;
		size_t                                                     getNumberofNodes(void) const;
		const TreeNode *                                  getRootNode(void)  const;

	private:
	std::string                                                  computeNewickRecursively(const TreeNode & n ) const;
	void                                                           fillNodesByPhylogeneticTraversal(TreeNode * node);

	TreeNode *                                               root;
	std::vector<TreeNode *>                          nodes;
};



#endif //PHYLOGENY_LEARN_TREE_H
