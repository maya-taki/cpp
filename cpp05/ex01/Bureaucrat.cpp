/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 22:29:48 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/10 23:31:24 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("None"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	if (_grade > 150)
	{
		throw GradeTooLowException("Grade too low!");
	}
	else if (_grade < 1)
	{
		throw GradeTooHighException("Grade too high!");
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &a): _name(a._name), _grade(a._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &a)
{
	if (this != &a)
		_grade = a._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException("Grade too high!");
	std::cout << "==== Grade updated ====" << std::endl;
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException("Grade too low!");
	std::cout << "==== Grade updated ====" << std::endl;
	++_grade;
}

void Bureaucrat::signForm(const Form &form)
{
	try
	{
		const_cast<Form &>(form).beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because" << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << ".";
	return (out);
}
