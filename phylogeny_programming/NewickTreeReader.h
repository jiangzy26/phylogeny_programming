//
// Created by 姜志永 on 2021/11/23.
//

#ifndef PHYLOGENY_LEARN_NEWICKTREEREADER_H
#define PHYLOGENY_LEARN_NEWICKTREEREADER_H

#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "TreeNode.h"

class NewickTreeReader
{

public:
    std::vector<std::string> parseNewickString(const std::string ns);
    TreeNode *                    createTreeFromNewick(const std::string & newick); 
    TreeNode *                    createTreeFromNewick2(const std::string & newick); 
};

#endif //PHYLOGENY_LEARN_NEWICKTREEREADER_H
