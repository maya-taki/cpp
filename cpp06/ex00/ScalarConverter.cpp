/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:05:42 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/15 20:44:35 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <stdint.h>
#include <iostream>
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

//char
//int
//float
//double

static void		convert_double(double val)
{
	if (std::isinf(val))
		std::cout << "double: " << (val > 0 ? "+" : "-") << "inf" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(val) << std::endl;
}

void		convert_int()
{

}

void		convert_float()
{

}

void		convert_char()
{

}

void		impossible_conversion()
{

}

void		ScalarConverter::convert(const std::string str)
{
	char	*end;
	double	val;

	end = NULL;

	if (str.empty())
		return (impossible_conversion());
	if (str.length() == 1 && !std::isdigit(str[0]))
		val = static_cast<char>(str[0]);
	else if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		val = static_cast<char>(str[1]);
	else
	{
		val = std::strtod(str.c_str(), &end);
		if (*end != '\0' && !(*end) == 'f' && *(end + 1) == '\0')
			return (impossible_conversion());
	}

	convert_char(val);
	convert_int(val);
	convert_float(val);
	convert_double(val);
}
