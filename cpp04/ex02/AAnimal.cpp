/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:37:28 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) : type(src.type)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &src)
		type = src.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "[...]" << std::endl;
}

const	std::string &AAnimal::getType() const
{
	return (type);
}

Brain* AAnimal::getBrain() const {
	return NULL;
}
