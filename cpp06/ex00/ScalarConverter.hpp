/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 12:58:44 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/25 22:05:03 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cctype>
#include <iomanip>
#include <ios>
#include <cctype>
#include <cstdlib>

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


#endif

void NewFunction();
