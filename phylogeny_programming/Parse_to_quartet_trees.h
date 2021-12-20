//
// Created by ╫╙ж╬сю on 2021/11/22.
//

#ifndef PHYLOGENY_LEARN_PARSE_TO_QUARTETE_TREES_H
#define PHYLOGENY_LEARN_PARSE_TO_QUARTETE_TREES_H

#include <string>
#include "TreeNode.h"

class TreeNode;

class Parse_to_quartet_trees
{
	public:
		Parse_to_quartet_trees();
		~Parse_to_quartet_trees();
	
		TreeNode *                          getQuartetTrees(TreeNode * tn);

};



#endif //PHYLOGENY_LEARN_PARSE_TO_QUARTETE_TREES_H
