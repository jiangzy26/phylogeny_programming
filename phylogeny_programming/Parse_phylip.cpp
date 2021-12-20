//
// Created by 姜志永 on 2021/11/22.
//

#include "Parse_phylip.h"

Phylip::Phylip()
{

}

Phylip::~Phylip()
{

}

Phylip Phylip::readPhylip(const std::string &fn)
{
    std::ifstream in_stream;
    in_stream.open(fn);
    std::string linestring="";

    bool taxon_names_read = false;
    // we also need the current taxon number
    size_t taxon_num = 0;

    getline(in_stream, linestring);
    std::cout << "The first line is " <<linestring << std::endl;


    // and then separate the line by whitespaces, but not familiar with the grammar
    std::istringstream word_iss(linestring);
    std::vector<std::string> words((std::istream_iterator<std::string>(word_iss)),std::istream_iterator<std::string>());

    std::cout << "taxa number is " << words[0] << std::endl;
    std::cout << "sites have " << words[1] << std::endl;
    // now we store the number of taxa and sites into our variables
    num_taxa = std::stoi( words[0] );
    num_sites = std::stoi( words[1] );

    // for the actual data, and for convenience, we create a data matrix that has num_taxa rows but no columns yet
    std::vector< std::vector<char> > matrix = std::vector< std::vector<char> >( num_taxa, std::vector<char>() );

    //then we loop then entire file

    while(true)
    {
        bool more_line_exist = getline(in_stream, linestring).good();

       // then, we skip forward over any empty line between the taxonNum_Seq_length_INFO and the sequence
        while (more_line_exist && linestring == "")
        {
            //std::cout << linestring << std::endl;
            more_line_exist = getline(in_stream, linestring).good();
        }

        if(more_line_exist == false)
        {
            break;
        }

        // now we split the line by whitespaces using again a stringstream
        std::istringstream iss(linestring);
        std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                        std::istream_iterator<std::string>());

        //then we loop each line
        for(int i = 0; i < tokens.size(); i++)
        {
            //the first part should be the taxa name, not only sequence
            if(i == 0 && taxon_names_read == false)
            {
                // so we push the first word to the end of the names of the taxa
                taxon_names.push_back(tokens[i]);
                //std::cout << tokens[i] << std::endl;
            }
            else
            {
                //now the line has only sequence
                const std::string &the_sequence = tokens[i];
                // so we add the sequence to the end of the sequence for this taxon
                // thus, we append our data matrix using the insert function
                //std::cout << tokens[i] << std::endl;

                matrix[taxon_num].insert(matrix[taxon_num].end(), the_sequence.begin(), the_sequence.end());
            }
        }

        // since we finished we this line, we need to move on to the next taxon.
        taxon_num ++;
        // if we have finished with all taxa, then we start with the first one again (for interleaved files)
        if(taxon_num == num_taxa)
        {
            // hence, set the taxon index to 0 (we start counting with 0)
            taxon_num = 0;
            //std::cout << "The end of read file name" << std::endl;
            // and remember that we read all taxon names
            taxon_names_read = true;
        }

    }

    in_stream.close();


}


