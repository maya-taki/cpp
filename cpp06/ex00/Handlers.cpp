/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handlers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:39:50 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/28 02:32:06 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void		handle_double(const std::string &literal)
{
	char	*end;
	errno = 0;
	double	d = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str() || *end != '\0' || errno == ERANGE)
	{
		handle_impossible();
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	int decimals = get_precision(literal);
	print_char(d);
	print_int(d);
	print_float(d, decimals);
	print_double(d, decimals);
}

void		handle_int(const std::string &literal)
{
	char	*end;
	double	d = std::strtod(literal.c_str(), &end);
	if (end == literal.c_str() || *end != '\0')
	{
		handle_impossible();
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	print_char(d);
	print_int(d);
	print_float(d, 0);
	print_double(d, 0);
}

void		handle_float(const std::string &literal)
{
	std::string value = literal;
	if (!value.empty() && value[value.length() - 1] == 'f')
		value.erase(value.length() - 1);
	char	*end;
	double	d = std::strtod(value.c_str(), &end);
	if (end == value.c_str() || *end != '\0')
	{
		handle_impossible();
		return ;
	}
	std::cout << std::fixed << std::setprecision(1);
	int decimals = get_precision(literal);
	print_char(d);
	print_int(d);
	print_float(d, decimals);
	print_double(d, decimals);
}

void	handle_char(const std::string &literal)
{
	char	c = static_cast<char>(literal[0]);
	double	d = static_cast<double>(c);
	std::cout << std::fixed << std::setprecision(1);
	print_char(d);
	print_int(d);
	print_float(d, 0);
	print_double(d, 0);
}

void	handle_pseudo(const std::string &literal)
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

void	handle_impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

int	get_precision(const std::string &literal)
{
	size_t	dot = literal.find(".");
	if (dot == std::string::npos)
		return (1);
	size_t	end = literal.length();
	if (literal[end - 1] == 'f')
		end -= 1;
	int decimals = static_cast<int>(end - dot - 1);
	return (decimals < 1? 1 : decimals);
}

void	print_char(double c)
{
	if (c >= 32 && c <= 126)
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else if (c >= 0 && (c == 31 || c == 127))
		std::cout << "char: Non displayable" << std::endl;
	else if (c < 0 || c > 127)
		std::cout << "char: impossible" << std::endl;
}

void	print_int(double i)
{
	if (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(0);
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	}
}

void	print_float(double f, int deci)
{
	std::cout << std::fixed << std::setprecision(1);
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "float: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(deci);
		std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	}
}

void	print_double(double d, int deci)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isinf(d) || std::isnan(d))
		std::cout << "double: impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(deci);
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	}
}
