/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:24:16 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/12 23:52:59 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("name"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}

Form::Form(const std::string &name, const int sign_grade, const int exec_grade): 
	_name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade > 150)
		throw GradeTooLowException("Out of Range. Grade too low");
	else if (sign_grade < 1)
		throw GradeTooHighException("Out of Range. Grade too high");
	if (exec_grade > 150)
		throw GradeTooLowException("Out of Range. Grade too low");
	else if (exec_grade < 1)
		throw GradeTooHighException("Out of Range. Grade too high");
}

Form::Form(const Form &a): _name(a._name), _is_signed(a._is_signed), _sign_grade(a._sign_grade), _exec_grade(a._exec_grade)
{
	*this = a;
}

Form &Form::operator=(const Form &a)
{
	if (this != &a)
		this->_is_signed = a._is_signed;
	return (*this);
}

Form::~Form() {}

const std::string	Form::getName() const
{
	return (this->_name);
}

bool				Form::getSigned() const
{
	return (this->_is_signed);
}

int					Form::getGradeToSign() const
{
	return (this->_sign_grade);
}

int					Form::getGradeToExec() const
{
	return (this->_exec_grade);
}

void				Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
	{
		std::string error_msg = " grade is too low.";
		throw Form::GradeTooLowException(error_msg);
	}
	this->_is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", form signed: "
		<< (form.getSigned() ? "yes" : "no")
		<< ", sign grade " << form.getGradeToSign()
		<< ", exec grade " << form.getGradeToExec() << ".";
	return (out);
}