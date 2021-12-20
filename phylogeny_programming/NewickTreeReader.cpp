//
// Created by 姜志永 on 2021/11/23.
//

#include "NewickTreeReader.h"
#include "Tree.h"
#include "TreeNode.h"

/*
std::vector<Tree> NewickTreeReader:readTrees(const std::string & fn)
{
    std::ifstream inFile(fn);
}
*/

std::vector<std::string> NewickTreeReader::parseNewickString(const std::string ns)
{
    //read newick format tree to linestring
    std::ifstream in_stream;
    in_stream.open(ns);
    std::string linestring = "";
    getline(in_stream, linestring);


    //create a vector for the tokens
    std::vector<std::string> tks;
    for(int i =0; i < linestring.size();i++)
    {
        //the current character
        char c = linestring[i];

        if(c == '(' || c == ')' || c == ',' || c == ';' || c == ':')
        {
            tks.push_back(std::string(1, c));
        }
        else
        {
            int j = i;
            std::string temp_string = "";
            while(!(c == '(' || c == ')' || c == ',' || c == ';' || c == ':'))
            {
                temp_string += c;
                j++;
                c=linestring[j];
            }
            i = j -1 ;
            tks.push_back(temp_string);
        }
    }


    for(int i =0;i < tks.size();i++)
    {
        std::cout << tks[i]<<std::endl;
    }
    in_stream.close();

    return tks;
}

//parse the tokens, and create TreeNode object, return TreeNode pointer
TreeNode * NewickTreeReader::createTreeFromNewick(const std::string & newick)
{
    //break the newick tree string to components
    std::vector<std::string> tokens = parseNewickString(newick);

    //check, if the token is :, then we need to read the branch length
    bool reading_branch_length = false;
    //pointer to the ancestor
    TreeNode * ancestor = NULL;
    //pointer to the root for checking that the algorithm worked correctly
    TreeNode * root = NULL;

    //build up the tree from the parsed Newick string
    for(int i =0;i<tokens.size();i++)
    {
        //get the current token
        const std::string & token = tokens[i];

        //check the token
        if(token == "(")
        {
            TreeNode * next_node = new TreeNode();

            if (ancestor == NULL)
            {
                root = next_node;
               
            }

            else
            {
                next_node->setParent(ancestor);

                if (ancestor->getLeftChild() == NULL)
                {
                    ancestor->setLeftChild(next_node);
                }
                else
                {
                    ancestor->setRightChild(next_node);
                }
            }
            ancestor = next_node;
            //std::cout << "The address of ancestor is " << &ancestor << std::endl;
        }
        else if (token == ")" || token == ",")
        {
            ancestor = ancestor->getParent();
        }
        else if(token == ":")
        {
            //begin reading a branch length
            reading_branch_length = true;
        }
        else if(token == ";")
        {
            //finished and make sure that we also terminated at the root
           // exit(1);
        }

        else
        {
            if (reading_branch_length == true)
            {
                double x = std::stod(token);
                ancestor->setBranchLength_jiang(x);

                if (ancestor->getParent() != NULL)
                {

                    ancestor->getParent()->setAge(ancestor->getAge() + x);
                    
                }

                reading_branch_length = false;

            }
            else
            {
                TreeNode * next_node = new TreeNode();
                next_node->setParent(ancestor);
                if (ancestor->getLeftChild() == NULL)
                {
                    ancestor->setLeftChild(next_node);
                }
                else
                {
                   ancestor->setRightChild(next_node);
                }

                next_node->setName(token);
                ancestor = next_node;

            }
        }

    }

    return root;
}


