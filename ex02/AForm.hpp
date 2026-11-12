/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:24:18 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/11 15:50:41 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm
{
	private:

		const std::string	_name;
		bool				_is_signed;
		const int		_sign_grade;
		const int		_exec_grade;

	public:
		AForm();
		AForm(const std::string &name, const int sign_grade, const int exec_grade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				beSigned(const Bureaucrat &other);
		virtual void		execute(Bureaucrat const &executor) const = 0;

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

std::ostream	&operator<<(std::ostream &a, const AForm &b);

#endif
