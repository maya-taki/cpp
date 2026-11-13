/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:34:38 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/13 16:14:26 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ostream>
#include <ctime>
#include <cstdlib>

int main (void)
{
	srand(static_cast<unsigned int>(time(0)));
	Bureaucrat				a("Amanda(1)", 1);
	Bureaucrat				b("Brittany(150)", 150);
	Bureaucrat				c("Chelsea(138)", 138);
	Bureaucrat				d("Donna(70)", 70);
	Bureaucrat				e("Emma(20)", 20);
	
	std::cout << "==== Executing ShrubberyCreationForm ====\n" << std::endl;
	ShrubberyCreationForm	form1("Delta");
	std::cout << form1 << std::endl;
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
	
	std::cout << "\n\n==== Executing RobotomyRequestForm ====\n" << std::endl;
	RobotomyRequestForm		form2("Echo");
	std::cout << form2 << std::endl;
	try {
		a.executeForm(form2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		b.signForm(form2);
		e.signForm(form2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		a.signForm(form2);
		a.executeForm(form2);
		e.executeForm(form2);
		a.executeForm(form2);
		e.executeForm(form2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\nExecuting PresidentialPardonForm ====\n" << std::endl;
	PresidentialPardonForm	form3("Foxtrot");
	std::cout << form3 << std::endl;
	try {
		a.executeForm(form3);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		e.signForm(form3);
		e.executeForm(form3);
		a.signForm(form3);
		a.executeForm(form3);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
