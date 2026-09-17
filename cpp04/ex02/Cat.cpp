/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:40:32 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain;
	type = "Cat";
}

Cat::Cat(const Cat &src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	type = src.type;
	brain = new Brain;
	*brain = *src.brain;
}

Cat& Cat::operator=(const Cat &src)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
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

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << type << " says * meow meow meow *" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (brain);
}
