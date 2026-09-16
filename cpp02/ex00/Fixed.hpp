/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:26:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 01:57:21 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed& src);
		~Fixed();
		int		GetRawBits(void) const;
		void	SetRawBits(int const raw );
	private:
		int		fixed_;
		static int const bits = 8;
};

#endif
