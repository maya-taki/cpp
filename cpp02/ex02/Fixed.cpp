/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 04:54:13 by mtakiyos         ###   ########.fr       */
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
		fixed_ = src.fixed_;
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
	return (fixed_ >> bits);
}

float Fixed::ToFloat() const
{
	return (static_cast<float>(fixed_) / (1 << bits));
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

Fixed& Fixed::operator++() {
	fixed_ += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	fixed_ -= 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	fixed_ += 1;

	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	fixed_ -= 1;

	return (temp);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed add;
	add.SetRawBits(fixed_ + rhs.fixed_);
	return (add);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed sub;
	sub.SetRawBits(fixed_ - rhs.fixed_);
	return (sub);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed multi;
	multi.SetRawBits((fixed_ * rhs.fixed_) >> bits);
	return (multi);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed div;
	div.SetRawBits((fixed_ << bits) / rhs.fixed_);
	return (div);
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return (fixed_ > rhs.fixed_);
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return (fixed_ < rhs.fixed_);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return (fixed_ >= rhs.fixed_);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return (fixed_ <= rhs.fixed_);
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return (fixed_ == rhs.fixed_);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (fixed_ != rhs.fixed_);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
	output << fixed.ToFloat();
	return (output);
}
