/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:34:38 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/13 01:32:07 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ostream>


int main (void)
{
	Bureaucrat				a("Amanda", 1);
	Bureaucrat				b("Brittany", 150);
	Bureaucrat				c("Chelsea", 138);
	
	ShrubberyCreationForm	form1("Homer");
	// RobotomyRequestForm		form2("Claus");
	// PresidentialPardonForm	form3("Swaler");
	
	ShrubberyCreationForm	form4(form1);
	// RobotomyRequestForm		form5(form2);
	// PresidentialPardonForm	form6(form3);

	std::cout << form4 << std::endl;
	// std::cout << form5 << std::endl;
	// std::cout << form6 << std::endl;
	{
		std::cout << "==== Executing ShrubberyCreationForm ====" << std::endl;
		try {
			a.executeForm(form1);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			b.signForm(form1);
			c.signForm(form1);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			a.signForm(form1);
			a.executeForm(form1);
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		
		// std::cout << "\n\nExecuting RobotomyRequestForm" << std::endl;
		// try {
		// 	a.executeForm(form2);
		// }
		// catch (const std::exception &e) {
		// 	std::cerr << e.what() << std::endl;
		// }
		// try {
		// 	b.executeForm(form2);
		// }
		// catch (const std::exception &e) {
		// 	std::cerr << e.what() << std::endl;
		// }
		// std::cout << "\n\nExecuting PresidentialPardonForm" << std::endl;
		// try {
		// 	a.executeForm(form3);
		// }
		// catch (const std::exception &e) {
		// 	std::cerr << e.what() << std::endl;
		// }
		// try {
		// 	b.executeForm(form3);
		// }
		// catch (const std::exception &e) {
		// 	std::cerr << e.what() << std::endl;
		// }
	}
	return 0;
}