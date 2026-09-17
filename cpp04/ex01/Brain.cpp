/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:59:12 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:06:11 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy contructor called" << std::endl;
	for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &src) {
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int i, const std::string& idea)
{
	ideas[i] = idea;
}

const std::string& Brain::getIdea(int i) const
{
	return (ideas[i]);
}
