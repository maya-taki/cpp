/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:34:38 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/14 21:46:24 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ostream>

int main (void)
{
	Bureaucrat	a("Bureaucrat 1", 1);
	Intern		someRandomIntern;
	AForm		*form;

	std::cout << "=== Valid Forms ===" << std::endl;
	{
		form = someRandomIntern.makeForm("robotomy request form", "Bender");
		std::cout << *form << std::endl;
		try {
			a.signForm(*form);
			a.executeForm(*form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete (form);
		form = NULL;
	}
	std::cout << "=========================================" << std::endl;
	{
		form = someRandomIntern.makeForm("shrubbery creation form", "Homer");
		std::cout << *form << std::endl;
		try {
			a.signForm(*form);
			a.executeForm(*form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete (form);
		form = NULL;
	}
	std::cout << "=========================================" << std::endl;
		{
		form = someRandomIntern.makeForm("presidential pardon form", "Rick Sanchez");
		std::cout << *form << std::endl;
		try {
			a.signForm(*form);
			a.executeForm(*form);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete (form);
		form = NULL;
	}
	std::cout << "=========================================" << std::endl;


	std::cout << "=== Invalid Forms ===" << std::endl;
	try
	{
		form = someRandomIntern.makeForm("Ninja protocol", "Barney");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		form = NULL;
	}
	std::cout << "=========================================" << std::endl;

	return (0);
}
