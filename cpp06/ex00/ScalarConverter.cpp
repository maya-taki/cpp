/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:05:42 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/20 00:38:37 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>
#include <cctype>
#include <iomanip>
#include <ios>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		ScalarConverter::operator=(other);
	return (*this);
}


ScalarConverter::~ScalarConverter() {}

int			handle_type(const std::string literal)
{

}

void		handle_double(const std::string literal)
{
}

void		handle_int(const std::string literal)
{
}

void		handle_float(const std::string literal)
{
}

void		handle_char(const char c)
{
	std::cout << "char: ";
	if (c < ' ' || c > '~')
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<int>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<int>(c) << ".0" << std::endl;
	
}

void		impossible_conversion(double val)
{
}

void		ScalarConverter::convert(const std::string str)
{
	double	val;
	int type = handle_type(str);
	switch (type)
	{
		case 0 :
		{
			handle_char(str);
			break;
		}
		case 1 :
		{
			handle_double(str);
			break;
		}
		case 2 :
		{
			handle_int(str);
			break;
		}
		case 3 :
		{
			handle_float(str);
			break;
		}
		case 4 : 
		{
			handle_char(str.at(0));
			break;
		}
		default :

	}
}
