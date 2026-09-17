/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:41:17 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain;
	type = "Dog";
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	type = src.type;
	brain = new Brain;
	*brain = *src.brain;
}

Dog& Dog::operator=(const Dog &src)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &src)
	{
		if (brain)
			delete brain;
		type = src.type;
		brain = new Brain;
		*brain = *src.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << type << " says * woof woof woof woof *" << std::endl;
}


Brain* Dog::getBrain() const
{
	return (brain);
}
