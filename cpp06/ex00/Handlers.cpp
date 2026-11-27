/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handlers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:39:50 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/27 01:17:06 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void		handle_double(const std::string &literal)
{
	errno = 0;
	char	*end;
	double	d = std::strtod(literal.c_str(), &end);
	const double inf = std::numeric_limits<double>::infinity();
	if (end == literal.c_str() || *end != '\0'
		|| d != d || d == inf || d == -inf
		|| errno == ERANGE)
	{
		handle_impossible();
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	printChar(d);
	printInt(d);
	std::cout << std::fixed << std::setprecision(1);
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
}

void		handle_int(const std::string &literal)
{
	errno = 0;
	char	*end;
	double	d = std::strtod(literal.c_str(), &end);
	const double inf = std::numeric_limits<double>::infinity();
	if (end == literal.c_str() || *end != '\0'
		|| d != d || d == inf || d == -inf
		|| errno == ERANGE)
	{
		handle_impossible();
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	printChar(d);
	printInt(d);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void		handle_float(const std::string &literal)
{
	std::string value = literal;
	if (!value.empty() && value[value.length() - 1] == 'f')
		value.erase(value.length() - 1);
	errno = 0;
	char	*end;
	double	d = std::strtod(value.c_str(), &end);
	const double inf = std::numeric_limits<double>::infinity();
	if (end == value.c_str() || *end != '\0'
		|| d != d || d == inf || d == -inf
		|| errno == ERANGE)
	{
		handle_impossible();
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	printChar(d);
	printInt(d);
	std::cout << std::fixed << std::setprecision(1);
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
}

void		handle_char(const std::string &literal)
{
	char	c = static_cast<char>(literal[0]);
	int		i = static_cast<int>(c);
	double	d = static_cast<double>(c);
	float	f = static_cast<float>(c);
	printChar(d);
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void		handle_pseudo(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
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

void printChar(double c)
{
	const double inf = std::numeric_limits<double>::infinity();
	if (c != c || c == inf || c == -inf || c < 0 || c > 127)
		std::cout << "char: impossible" << std::endl;
	else if (c >= 32 && c <= 126)
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else if (c >= 0 && c <= 127)
		std::cout << "char: Non displayable" << std::endl;
}

void printInt(double i)
{
	const double inf = std::numeric_limits<double>::infinity();
	if (i != i || i == inf || i == -inf
		|| i < std::numeric_limits<int>::min()
		|| i > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(0);
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	}
}