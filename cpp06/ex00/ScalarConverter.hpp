/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 12:58:44 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/26 23:42:26 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cctype>
#include <iomanip>
#include <ios>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <cfloat>
#include <cmath>

class ScalarConverter
{
	public:
		static void	convert(const std::string &str);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
};

void		handle_double(const std::string &literal);
void		handle_int(const std::string &literal);
void		handle_float(const std::string &literal);
void		handle_char(const std::string &literal);
void		handle_pseudo(const std::string &literal);
void		handle_impossible();
void		printChar(double c);
void		printInt(double i);


#endif