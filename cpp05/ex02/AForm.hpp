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
		const int			_sign_grade;
		const int			_exec_grade;

	public:
		AForm();
		AForm(const std::string &name, const int _sign_grade, const int _exec_grade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				beSigned(const Bureaucrat &other);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException: public std::exception {
			public:
				const char *what () const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char *what () const throw();
		};
		class NotSignedException: public std::exception {
			public:
				const char *what () const throw();
		};
};

std::ostream	&operator<<(std::ostream &a, const AForm &b);

#endif
