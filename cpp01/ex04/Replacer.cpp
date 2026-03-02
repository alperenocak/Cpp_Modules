/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-28 09:20:35 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-28 09:20:35 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

static std::string replaceAll(const std::string &content, const std::string &s1, const std::string &s2)
{
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    return result;
}

int replacer(std::string s1, std::string s2, std::string filename)
{
    std::ifstream inFile(filename.c_str());
    if (!inFile)
    {
        std::cerr << RED <<"Error: Cannot open input file '" << filename << "'" << RESET <<std::endl;
        return 0;
    }

    std::string outFileName = filename + ".replace";
    std::ofstream outFile(outFileName.c_str());
    if (!outFile)
    {
        std::cerr << RED <<"Error: Cannot create output file '" << outFileName << "'" <<RESET<< std::endl;
        return 0;
    }

    std::stringstream buffer;
    buffer << inFile.rdbuf();
    
    outFile << replaceAll(buffer.str(), s1, s2);
    inFile.close();
    outFile.close();
    return 1;
}
