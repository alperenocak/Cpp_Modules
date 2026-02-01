/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-28 09:23:18 by yuocak            #+#    #+#             */
/*   Updated: 2026-01-28 09:23:18 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int replacer(std::string s1, std::string s2, std::string filename);

#endif