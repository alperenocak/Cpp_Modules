/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-02-20 22:21:17 by yuocak            #+#    #+#             */
/*   Updated: 2026-02-20 22:21:17 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain& operator=(const Brain& other);
    Brain(const Brain& other);
    ~Brain();
    const std::string& getIdea(int index) const;
    void setIdea(int index, const std::string& idea);
};

#endif