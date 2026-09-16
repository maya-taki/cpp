/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:26:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 04:05:02 by mtakiyos         ###   ########.fr       */
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
	private:
		int		fixed_;
		static int const bits = 8;
};


std::ostream& operator<<(std::ostream& output, const Fixed& fixed);

#endif
