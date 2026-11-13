/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:51:01 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/13 01:12:21 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), _target("Unknown") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(target + " Shrubbery Creation Form", 145, 137), _target(target)
{
	this->_target = "_shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
	{
		throw AForm::GradeTooLowException();
	}
	else if (!this->getSigned())
	{
		throw (AForm::NotSignedException());
	}
	std::ofstream outfile(this->_target.c_str());
	if (outfile.is_open())
	{
		outfile << "               # #### ####              " << std::endl <<
            "                   ### \\/#|### |/####          " << std::endl <<
            "                  ##\\/#/ \\||/##/_/##/_#        " << std::endl <<
            "                ###  \\/###|/ \\/ # ###          " << std::endl <<
            "              ##_\\_#\\_\\## | #/###_/_####       " << std::endl <<
            "             ## #### # \\ #| /  #### ##/##      " << std::endl <<
            "              __#_--###`  |{,###---###-~       " << std::endl <<
            "                        \\ }{                   " << std::endl <<
            "                         }}{                   " << std::endl <<
            "                         }}{                   " << std::endl <<
            "                         {{}                   " << std::endl <<
            "                   , -=-~{ .-^- _              " << std::endl <<
            "                         `}                    ";
		outfile.close();
	}
	else
		std::cout << "Error opening the file" << std::endl;
} 