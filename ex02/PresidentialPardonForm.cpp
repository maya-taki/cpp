/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:27:24 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/12 01:18:31 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ostream>
#include <string>


PresidentialPardonForm::PresidentialPardonForm(): AForm("None", 25, 5), _target("Unknown") {};

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm(target + "Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{
	*this = other;
} 

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		return (*this);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string	&PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExec())
	{
		std::string error_msg = executor.getName() + " couldn't execute the form " + this->getName() + " because the grade is too low";
		throw AForm::GradeTooLowException(error_msg);
	}
	std::cout << "Informs that " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form)
{
	out << " [PresidentialPardonForm] " << form.getName() << "\n"
		<< " | Target: " << form.getTarget() << "\n"
		<< " | Sign: " << static_cast<unsigned>(form.getGradeToSign()) << "\n"
		<< " | Execute: " << static_cast<unsigned>(form.getGradeToExec()) << "\n"
		<< " | Signed: " << (form.getSigned() ? "Yes" : "No") << "\n";
	return (out);
}