/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:54:22 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/14 23:23:08 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <sstream>
#include <string>

class HumanA
{
	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
		void				attack();
		void				setName(const std::string &name);
		const std::string	&getName(void);
		Weapon				&getWeapon(void);
		
	private:
		std::string	name;
		Weapon		&weapon;
};

#endif
