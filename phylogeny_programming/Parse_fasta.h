//
// Created by 姜志永 on 2021/11/22.
//

#ifndef PHYLOGENY_LEARN_PARSE_FASTA_H
#define PHYLOGENY_LEARN_PARSE_FASTA_H

#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>


class Fasta
{
private:
    size_t num_taxa;
    size_t num_sites;
    std::vector<std::string>            taxon_names;

public:
    Fasta();
    ~Fasta();
    Fasta readFasta(const std::string & fn);
};

#endif //PHYLOGENY_LEARN_PARSE_FASTA_H
