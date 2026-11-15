/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:22:32 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/14 21:25:58 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {};

AForm *Intern::makeShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

struct FormEntry
{
	const char *name;
	AForm *(*create)(const std::string &target);
};

AForm *Intern::makeForm(const std::string &formName, const std::string &targetName)
{
	static FormEntry table[] = {
		{ "shrubbery creation form", &makeShrubbery },
		{ "robotomy request form", &makeRobotomy },
		{ "presidential pardon form", &makePresidential }
	};

	const int size = sizeof(table) / sizeof(table[0]);

	std::cout << "Intern tries to make " << formName << std::endl;
	for (int i = 0; i < size; i++)
	{
		if (formName == table[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return table[i].create(targetName);
		}
	}
	throw AForm::WrongFormException();
	return (NULL);
}
