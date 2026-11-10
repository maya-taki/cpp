/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:34:38 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/09 18:04:09 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include <ostream>


int	main(void)
{
	try
	{
		Bureaucrat a("Bob", 149);
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "==============================" << std::endl;
	try
	{
		Bureaucrat b("Emily", 2);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "==============================" << std::endl;
	try
	{
		Bureaucrat c("Calisto", 25);
		std::cout << c << std::endl;
		while (c.getGrade() != 10)
		{
			c.incrementGrade();
		}
		std::cout << c << std::endl;
	}

	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
