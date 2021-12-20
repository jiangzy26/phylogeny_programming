//
// Created by 姜志永 on 2021/11/22.
//

#ifndef PHYLOGENY_LEARN_PARSE_PHYLIP_H
#define PHYLOGENY_LEARN_PARSE_PHYLIP_H
#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>


class Phylip
{
private:
        size_t num_taxa;
        size_t num_sites;
    std::vector<std::string>            taxon_names;

public:
    Phylip();
    ~Phylip();
    Phylip readPhylip(const std::string & fn);
};

#endif //PHYLOGENY_LEARN_PARSE_PHYLIP_H
