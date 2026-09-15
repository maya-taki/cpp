/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:54:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/14 22:39:59 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <sstream>
#include <string>

class HumanB
{
	public:
		HumanB(const std::string &name);
		~HumanB();
		void				attack();
		void				setName(const std::string &name);
		const std::string	&getName(void);
		void				setWeapon(Weapon &weapon);
		Weapon				*getWeapon(void);

	private:
		std::string	name;
		Weapon		*weapon;
};

#endif
