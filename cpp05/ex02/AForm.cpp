/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:24:16 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/11 15:50:16 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("name"), _is_signed(false), _sign_grade(150), _exec_grade(150) {}

AForm::AForm(const std::string &name, const int sign_grade, const int exec_grade): 
	_name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (sign_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1)
		throw GradeTooHighException();
	if (exec_grade > 150)
		throw GradeTooLowException();
	else if (exec_grade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other): _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_is_signed = other._is_signed;
	return (*this);
}

AForm::~AForm() {}

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool				AForm::getSigned() const
{
	return (this->_is_signed);
}

int					AForm::getGradeToSign() const
{
	return (this->_sign_grade);
}

int					AForm::getGradeToExec() const
{
	return (this->_exec_grade);
}

void				AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
	{
		throw GradeTooLowException();
	}
	this->_is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return (" form grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return (" form grade is too low!");
}

const char* AForm::NotSignedException::what() const throw() {
    return (" form is not signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << ", AForm signed: "
		<< (AForm.getSigned() ? "yes" : "no")
		<< ", sign grade " << AForm.getGradeToSign()
		<< ", exec grade " << AForm.getGradeToExec() << ".";
	return (out);
}