/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 22:31:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 22:38:01 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "Wrong Animal";
	std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
	std::cout << "Wrong Animal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Wrong Animal copy assignment operator called" << std::endl;
	if (this != &src)
		type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << type << " says * BEEP BEEP BOOP *" << std::endl;
}

const	std::string &WrongAnimal::getType() const
{
	return (type);
}
