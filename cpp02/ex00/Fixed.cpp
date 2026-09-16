/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 02:25:16 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_(0)
{
	std::cout << "default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) : fixed_(src.fixed_)
{
	std::cout << "copy constructor called" <<std::endl;
}

Fixed& Fixed::operator=(const Fixed& src)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &src)
		SetRawBits(src.GetRawBits());
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "constructor destroyed" << std::endl;
}

void	Fixed::SetRawBits(int const raw)
{
	this->fixed_ = raw;
}

int		Fixed::GetRawBits(void) const
{
	std::cout << "GetRawBits member function called" << std::endl;
	return (this->fixed_);
}
