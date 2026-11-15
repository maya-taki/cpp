/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 22:29:51 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/12 23:50:14 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class AForm;

//abstraction == hiding unnecessary data from outside a class
//getter == function that makes a private attribute READABLE
//setter == function that makes a private attribute WRITABLE

class Bureaucrat{
	public:
		Bureaucrat();										// default constructor
		Bureaucrat(const std::string &name, int grade);		// converting constructor
		Bureaucrat(const Bureaucrat &other);				// copy constructor
		Bureaucrat &operator=(const Bureaucrat &other);		// copy assignment
		~Bureaucrat();										//destructor

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(const AForm &other);
		void 				executeForm(const AForm &form) const;

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what () const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what () const throw();
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &a, const Bureaucrat &b);

#endif
