/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:05:42 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/23 22:52:09 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum eType
{
	CHAR,
	FLOAT,
	DOUBLE,
	INT,
	PSEUDO,
	IMPOSSIBLE,
	FAIL
};

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


static eType	getType(const std::string &literal)
{
	if (literal == "+inff" || literal == "-inff" || literal == "nanf"
		|| literal == "-inf" || literal == "+inf" || literal == "nan")
			return (PSEUDO);
	
	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
		return (CHAR);

	int	len = literal.length();
	int	i = 0;
	int dots = 0;
	bool has_digits = false;

	if (literal[i] == '-' || literal[i] == '+') {
		i += 1;
		std::cout << "index: " << i << std::endl;
		if (i == len) {
			std::cout << "error one" << std::endl;
			return (IMPOSSIBLE);
		}
	}

	for (; i < len; i++) {
		if (literal[i] == '.')
			dots += 1;
		else if (i == len - 1 && literal[i] == 'f') {
			if (dots <= 1 && has_digits)
				return (FLOAT);
			else
				return (IMPOSSIBLE);
		}		
		else if (!std::isdigit(literal[i])) {
			return (IMPOSSIBLE);
		}
		else if (i == len - 1 && std::isdigit(literal[i]) && dots == 1)
			return (DOUBLE);
		has_digits = true;
	}
	if (dots > 1)
		return (IMPOSSIBLE);

	return (INT);
}

int		handle_double(const std::string literal)
{
	(void)literal;
	return (DOUBLE);
}

int		handle_int(const std::string &literal)
{
	(void)literal;
	return (INT);
}
int		handle_float(const std::string &literal)
{
	(void)literal;
	return (FLOAT);
}

int		handle_char(const char c)
{
	std::cout << "char: ";
	if (c < ' ' || c > '~')
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<int>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<int>(c) << ".0" << std::endl;
	return (CHAR);
}

int		impossible_conversion()
{
	std::cout << "Conversion impossible" << std::endl;
	return (IMPOSSIBLE);
}

void		ScalarConverter::convert(const std::string &str)
{
	int type = getType(str);
	switch (type)
	{
		case CHAR :
		{
			handle_char(str.at(0));
			std::cout << type << std::endl;
			break ;
		}
		case FLOAT :
		{
			handle_float(str);
			std::cout << type << std::endl;
			break ;
		}
		case DOUBLE :
		{
			handle_double(str);
			std::cout << type << std::endl;
			break ;
		}
		case INT :
		{
			handle_int(str);
			std::cout << type << std::endl;
			break ;
		}
		case PSEUDO :
		{
			std::cout << type << std::endl;
			break ;
		}
		case FAIL :
		{
			std::cout << "failed, something's wrong" << std::endl; //DELETE
			break ;
		}
		default :
		{
			impossible_conversion();
			std::cout << type << std::endl;
			break;
		}
	}
}

