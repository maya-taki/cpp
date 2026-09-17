/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 22:33:37 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	std::cout << "Wrong Cat copy assignment operator called" << std::endl;
	if (this != &src)
		type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << type << " says * WEEEOOOOWEEEOOOWEEE *" << std::endl;
}
