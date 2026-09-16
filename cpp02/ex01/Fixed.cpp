/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 04:03:01 by mtakiyos         ###   ########.fr       */
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
	std::cout << "destructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	std::cout << "int constructor called" << std::endl;
	fixed_ = n << bits;
}

Fixed::Fixed(float const n)
{
	std::cout << "float constructor called" <<std::endl;
	fixed_ = roundf(n * (1 << bits));
}

int Fixed::ToInt() const
{
	return (int)fixed_ >> bits;
}

float Fixed::ToFloat() const
{
	return (float)fixed_ / (1 << bits);
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

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
	output << fixed.ToFloat();
	return (output);
}
