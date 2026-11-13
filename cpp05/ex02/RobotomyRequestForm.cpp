/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 18:50:43 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/13 16:09:06 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm(" Robotomy Request Form", 72, 45), _target("Unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm(target + " Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {};

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
	{
		std::string error_msg = executor.getName() + " couldn't execute the form " + this->getName() + " because the grade is too low.";
		throw AForm::GradeTooLowException();
	}
	else if (!this->getSigned())
	{
		throw (AForm::NotSignedException());
	}
	std::cout << "*⚡BZZZZZ⚡ ⚡BZZZZ⚡" << std::endl;
	if ((rand() % 2) != 0)
	{
		std::cout << this->_target + " has been robotomized!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy has failed" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
	out	<< "[RobotomyRequestForm] " << form.getName() << "\n"
		<< " | Target: " << form.getTarget() << "\n"
		<< " | Sign: " << static_cast<unsigned>(form.getGradeToSign()) << "\n"
		<< " | Execute: " << static_cast<unsigned>(form.getGradeToExec()) << "\n"
		<< " | Signed: " << (form.getSigned() ? "Yes" : "No") << "\n";
	return (out);
}
