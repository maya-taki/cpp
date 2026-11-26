/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 13:05:42 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/25 22:57:49 by mtakiyos         ###   ########.fr       */
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

void		handle_double(const std::string &literal)
{
	double	d = std::atof(literal.c_str());
	float	f = static_cast<double>(d);
	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else if ((i >= 0 && i <= 31) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	 else
		std::cout << "char: impossible" << std::endl;


	//if (i > INT_MAX || i < INT_MIN)
	//	std::cout << "int: impossible" << std::endl;
	//else
	//	std::cout << "int: " << i << std::endl;


	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void		handle_int(const std::string &literal)
{
	int		i = std::atoi(literal.c_str());
	float	f = static_cast<float>(i);
	char	c = static_cast<char>(i);
	double	d = static_cast<double>(i);

	//double	v = d;
	//if (v < INT_MIN || v > INT_MAX)
	//	std::cout << "int: impossible" << std::endl;
	//else
	//	std::cout << "int: " << v << std::endl;
	

	if (i >= 32 && i <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else if ((i >= 0 && i <= 31) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	 else
		std::cout << "char: impossible" << std::endl;


	//if (i > INT_MAX || i < INT_MIN)
	//	std::cout << "int: impossible" << std::endl;
	//else
	//	std::cout << "int: " << i << std::endl;


	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
void		handle_float(const std::string &literal)
{
	float	f = std::atof(literal.c_str());
	char	c = static_cast<char>(f);
	int		i = static_cast<int>(f);
	double	d = static_cast<double>(f);
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else if ((i >= 0 && i <= 31) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	 else
		std::cout << "char: impossible" << std::endl;


	//if (i > INT_MAX || i < INT_MIN)
	//	std::cout << "int: impossible" << std::endl;
	//else
	//	std::cout << "int: " << i << std::endl;


	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}


void		handle_char(const std::string &literal)
{
	char	c = static_cast<char>(literal[0]);
	int		i = static_cast<int>(c);
	double	d = static_cast<double>(c);
	float	f = static_cast<float>(c);
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else if ((i >= 0 && i <= 31) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	 else
		std::cout << "char: impossible" << std::endl;


	//if (i > INT_MAX || i < INT_MIN)
	//	std::cout << "int: impossible" << std::endl;
	//else
	//	std::cout << "int: " << i << std::endl;


	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void		handle_pseudo(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
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

