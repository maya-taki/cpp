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

//abstraction == hiding unnecessary data from outside a class
//getter == function that makes a private attribute READABLE
//setter == function that makes a private attribute WRITABLE

class Bureaucrat{
	public:
		Bureaucrat();										// default constructor
		Bureaucrat(const std::string *name, int grade);		// converting constructor
		Bureaucrat(const Bureaucrat &a);					// copy constructor
		Bureaucrat &operator=(const Bureaucrat &a);			// copy assignment
		~Bureaucrat();										//destructor
	private:
		const std::string	_name;
		int					_grade;
};

#endif