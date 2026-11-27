/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:05:42 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/26 23:49:01 by mtakiyos         ###   ########.fr       */
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
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter() {}


static eType	getType(const std::string &literal)
{
	if (literal[0] == '\0')
		return (IMPOSSIBLE);
	if (literal == "+inff" || literal == "-inff" || literal == "nanf"
		|| literal == "-inf" || literal == "+inf" || literal == "nan")
			return (PSEUDO);
	
	if (literal.length() == 1
		&& !std::isdigit(static_cast<unsigned char>(literal[0]))
		&& std::isprint(static_cast<unsigned char>(literal[0])))
		return (CHAR);

	int	len = literal.length();
	int	i = 0;
	int dots = 0;
	bool has_digits = false;

	if (literal[i] == '-' || literal[i] == '+') {
		i += 1;
		if (i == len) {
			return (IMPOSSIBLE);
		}
	}

	for (; i < len; i++) {
		if (literal[i] == '.')
			dots += 1;
		else if (i == len - 1 && literal[i] == 'f') {
			if (dots == 1 && has_digits && !(literal[i] == 'f' && literal[i - 1] == '.'))
				return (FLOAT);
			else
			{
				return (IMPOSSIBLE);
			}
		}		
		else if (!std::isdigit(literal[i])) {
			return (IMPOSSIBLE);
		}
		else if (i == len - 1 && std::isdigit(literal[i]) && dots == 1)
			return (DOUBLE);
		has_digits = true;
	}
	if (dots > 0)
	{
		if (has_digits && dots == 1)
			return (DOUBLE);
		return (IMPOSSIBLE);
	}

	return (INT);
}

void		ScalarConverter::convert(const std::string &str)
{
	int		type = getType(str);
	// char 	*end;
	// double	value = strtod(str.c_str(), &end);
	switch (type)
	{
		case CHAR :
		{
			handle_char(str);
			break ;
		}
		case FLOAT :
		{
			handle_float(str);
			break ;
		}
		case DOUBLE :
		{
			handle_double(str);
			break ;
		}
		case INT :
		{
			handle_int(str);
			break ;
		}
		case PSEUDO :
		{
			handle_pseudo(str);
			break ;
		}
		case IMPOSSIBLE :
		{
			handle_impossible();
			break ; 
		}
		default :
		{
			std::cout << "unknown type" << std::endl;
			break ;
		}
	}
}

