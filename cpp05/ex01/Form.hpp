/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:24:18 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/12 23:52:55 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		bool				_is_signed;
		const int		_sign_grade;
		const int		_exec_grade;

	public:
		Form();
		Form(const std::string &name, const int sign_grade, const int exec_grade);
		Form(const Form &a);
		Form &operator=(const Form &a);
		~Form();

		const std::string	getName() const;
		bool				getSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExec() const;
		void			beSigned(const Bureaucrat &a);

		class GradeTooHighException: public std::exception
		{
			public:
				GradeTooHighException(const std::string &message): _message(message) {}
				virtual ~GradeTooHighException() throw() {}
				virtual const char *what() const throw() { return (_message.c_str()); }
			private:
				std::string	_message;
		};
		class GradeTooLowException: public std::exception
		{
			public:
				GradeTooLowException(const std::string &message): _message(message) {}
				virtual ~GradeTooLowException() throw() {}
				virtual const char *what() const throw() { return (_message.c_str()); }
			private:
				std::string	_message;
		};
};

std::ostream	&operator<<(std::ostream &a, const Form &b);

#endif
