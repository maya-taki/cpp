/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 16:22:29 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/14 21:34:23 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(const std::string &formName, const std::string &targetName);
	private:
		static AForm *makePresidential(const std::string &target);
		static AForm *makeRobotomy(const std::string &target);
		static AForm *makeShrubbery(const std::string &target);
};

#endif
