/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:05:42 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/20 21:07:09 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
	//check special
	//check simple char
	//check invalid double float
	//check double
	//check float
	(void)literal;
	return (0);
}

//void		handle_double(const std::string literal)
//{
//}

//void		handle_int(const std::string literal)
//{
//}

//void		handle_float(const std::string literal)
//{
//}

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

void		impossible_conversion()
{
	std::cout << "Conversion impossible" << std::endl;
}

void		ScalarConverter::convert(const std::string str)
{
	int type = handle_type(str);
	switch (type)
	{
		case 0 :
		{
			handle_char(str.at(0));
			break;
		}
		//case 1 :
		//{
		//	handle_double(str);
		//	break;
		//}
		//case 2 :
		//{
		//	handle_int(str);
		//	break;
		//}
		//case 3 :
		//{
		//	handle_float(str);
		//	break;
		//}
		//default :
		{
			impossible_conversion();
			break;
		}

	}
}

