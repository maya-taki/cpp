/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:05:42 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/24 13:34:57 by mtakiyos         ###   ########.fr       */
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
	IMPOSSIBLE
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

void		handle_double(const std::string literal)
{
	(void)literal;
	std::cout << "double" << std::endl;
}

void		handle_int(const std::string &literal)
{
	(void)literal;
	std::cout << "int" << std::endl;
}
void		handle_float(const std::string &literal)
{
	(void)literal;
	std::cout << "float" << std::endl;
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

void		handle_pseudo()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void		handle_impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
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
			handle_pseudo();
			std::cout << type << std::endl;
			break ;
		}
		case IMPOSSIBLE :
		{
			handle_impossible();
			std::cout << type << std::endl;
			break ; 
		}
		default :
		{
			std::cout << "unknown type" << std::endl;
			break ;
		}
	}
}

