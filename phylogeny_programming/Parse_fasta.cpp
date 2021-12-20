//
// Created by 姜志永 on 2021/11/22.
//

#include "Parse_fasta.h"


Fasta::Fasta()
{

}

Fasta::~Fasta()
{

}

Fasta Fasta::readFasta(const std::string &fn) {
    std::ifstream in_stream;
    in_stream.open(fn);
    std::string linestring = "";

    bool taxon_names_read = false;
    // we also need the current taxon number
    size_t taxon_num = -1;

    // for the actual data, and for convenience, we create a data matrix that has num_taxa rows but no columns yet
    std::vector<std::vector<char> > matrix = std::vector<std::vector<char> >(0, std::vector<char>());

    //loop the file to get the taxon name and sequence
    bool more_line_exist = getline(in_stream, linestring).good();

    while (true) {
        while (more_line_exist) {
            std::istringstream iss(linestring);
            std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                            std::istream_iterator<std::string>());

            if (tokens[0].find(">") != std::string::npos) {
                //remove the ">"
                std::string &name = tokens[0].erase(0, 1);

                //add the name to the taxon_names vector
                taxon_names.push_back(name);
                taxon_num++;
                matrix.push_back(std::vector<char>());

            } else {
                //add a vector to contain the sequence of the aforementioned taxa
                //but the assumption is the sequence only in one line
                const std::string &the_sequence = tokens[0];
                matrix[taxon_num].insert(matrix[taxon_num].end(), the_sequence.begin(), the_sequence.end());
            }
            more_line_exist = getline(in_stream, linestring).good();
        }


        if (!more_line_exist) {
            break;
        }
    }

    in_stream.close();

    for (int i =0; i < taxon_names.size(); i++)
    {
      std::cout << taxon_names[i] << std::endl;
    }

std::cout << taxon_names.at(0) << std::endl;

    for(int i =0; i < matrix.size();i++)
    {
        for(int j =0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

}

