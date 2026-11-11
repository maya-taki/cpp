/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:34:38 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/10 23:55:14 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <ostream>


int	main(void)
{
	try
	{
		Form	voxotron("Voxotron", 10, 5);
		Form	ninjaReport("Ninja Report", 5, 10);
		Bureaucrat d("Dora", 5);
		d.signForm(ninjaReport);
		std::cout << d << std::endl;
		while (d.getGrade() != 10)
		{
			d.decrementGrade();
		}
		std::cout << d << std::endl;
		d.signForm(ninjaReport);
		d.signForm(voxotron);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
