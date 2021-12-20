#include "Parse_phylip.h"
#include "Parse_fasta.h"
#include "NewickTreeReader.h"
#include "TreeNode.h"
#include "Tree.h"
#include "RandomNumberGenerator.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    Phylip phylogeny_phylip;
    const std::string file_name = "D:/github/test/primates.phy";
    //phylogeny_phylip.readPhylip(file_name);

    Fasta phylogeny_fasta;
    const std::string file_name2 = "D:/github/test/primates.fas";
    //phylogeny_fasta.readFasta(file_name2);

    NewickTreeReader NT;
    //const std::string tree_file = "D:/github/test/primates.trees" ;   //"D:/github/test/RAxML_bestTree.raxml_476"
       const std::string tree_file = "D:/github/test/primates.trees" ;   //"D:/github/test/RAxML_bestTree.raxml_476"

    //NT.parseNewickString(tree_file);
    /*
    TreeNode * test=NULL;

   test =  NT.createTreeFromNewick(tree_file);
   
   std::cout << "test" << std::endl;
   

  std::cout << test->getRightChild()->getBranchLength_jiang()<< std::endl;
  std::cout << test->getLeftChild()->getBranchLength_jiang()<< std::endl;
   std::cout << test->getRightChild()->getRightChild()->getBranchLength_jiang()<< std::endl;

   Tree ts(test);
   std::cout << ts.getNumberofNodes() << std::endl;
   std::cout << ts.getNewick() << std::endl;
   
   */
   RandomNumberGenerator time;
   std::cout << time.uniform01() <<std::endl;
    return 0;
}


