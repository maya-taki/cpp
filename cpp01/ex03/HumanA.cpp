/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:54:19 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/15 00:47:22 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: name(name), weapon(weapon)
{
}
HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}

void	HumanA::setName(const std::string &name)
{
	this->name = name;
}

const std::string	&HumanA::getName(void)
{
	return (this->name);
}

Weapon	&HumanA::getWeapon(void)
{
	return (this->weapon);
}
