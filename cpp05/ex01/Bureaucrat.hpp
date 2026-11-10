/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 22:29:51 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/09 21:20:59 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

//abstraction == hiding unnecessary data from outside a class
//getter == function that makes a private attribute READABLE
//setter == function that makes a private attribute WRITABLE

class Bureaucrat{
	public:
		Bureaucrat();										// default constructor
		Bureaucrat(const std::string &name, int grade);		// converting constructor
		Bureaucrat(const Bureaucrat &a);					// copy constructor
		Bureaucrat &operator=(const Bureaucrat &a);			// copy assignment
		~Bureaucrat();										//destructor

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(const Form &a);

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

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &a, const Bureaucrat &b);

#endif
