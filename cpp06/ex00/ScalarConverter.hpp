/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 12:58:44 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/15 13:50:21 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVETER_HPP
# define SCALARCONVERTER_HPP

class ScalarConverter
{
	public:
		static void	convert(const std::string val);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
};

#endif
