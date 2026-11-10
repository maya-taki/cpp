/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:24:18 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/09 22:34:39 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:

		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;

	public:
		Form();
		Form();
		Form();
		Form &operator=(const Form &a);
		~Form() {};

		void				beSigned(const Bureaucrat &a);
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		const std::string	getName() const;

		class GradeTooHighException: public std::exception
		{
			GradeTooHighException() {};
			virtual ~GradeTooHighException() {};
		};
		class GradeTooLowException: public std::exception
		{
			GradeTooHighException() {};
			virtual ~GradeTooLowException() {};
		};
};

std::ostream	&operator<<(std::ostream &a, const Form &b);

#endif
