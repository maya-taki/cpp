/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:26:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 04:41:23 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <string>
#include <iostream>
#include <ostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed& src);
		~Fixed();
		Fixed(int const n);
		Fixed(float const n);
		int		ToInt() const;;
		float	ToFloat() const;
		int		GetRawBits(void) const;
		void	SetRawBits(int const raw );

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
	

	private:
		int		fixed_;
		static int const bits = 8;
};


std::ostream& operator<<(std::ostream& output, const Fixed& fixed);

#endif
