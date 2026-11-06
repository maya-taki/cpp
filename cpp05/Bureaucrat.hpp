/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 22:29:51 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/05 00:14:12 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

//abstraction == hiding unnecessary data from outside a class
//getter == function that makes a private attribute READABLE
//setter == function that makes a private attribute WRITABLE

class Bureaucrat{
	public:
		int					_grade;
		const std::string	_name;

		const std::string	&getName();
		int					getGrade();
		void				incrementGrade();
		void				decrementGrade();

		class GradeTooHigh: public std::exception
		{
			public:
				GradeTooHigh(const std::string &message): _message(message) {};
				~GradeTooHigh() {};	//throw() {}
			private:
				std::string	_message = "Grade too high!";
		}
		class GradeTooLow: public std::exception
		{
			public:
				GradeTooLow(const std::string &message): 	_message(message) {};
				~GradeTooLow() {}; //throw() {}
			private:
				std::string	_message = "Grade too low!";
		}

	private:
		Bureaucrat();										// default constructor
		Bureaucrat(const std::string &name, int grade);		// converting constructor
		Bureaucrat(const Bureaucrat &a);					// copy constructor
		Bureaucrat &operator=(const Bureaucrat &a);			// copy assignment
		~Bureaucrat();										//destructor
}

std::ostream	&operator<<(std::ostream &a, const Bureaucrat &a);

#endif
