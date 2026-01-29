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

#include "replacer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void replacer(std::string s1, std::string s2, std::string filename)
{
    if(s1 == "" || s2 == "")
        return;
    std::ifstream myfile(filename.c_str());
    std::ofstream replaceFile;
    std::string outFileName = filename.substr(0, filename.find(".")) + ".replace";

    if(!myfile)
        std::cerr << "yeter nurdan" << std::endl;
    
    replaceFile.open(outFileName.c_str());
    if(!replaceFile)
        std::cerr << "acilmadi"<< std::endl;
    
    /*-----------------------find string--------------------------------*/

    std::stringstream buffer;

    buffer << myfile.rdbuf();
    std::string content = buffer.str();
    std::string result;
    size_t pos = 0;
    size_t found;
    
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found -pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    replaceFile << result;
}
