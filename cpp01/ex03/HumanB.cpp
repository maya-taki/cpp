/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:54:24 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/15 00:47:35 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
	: name(name)
{
}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	std::cout << getName() << " attacks with their " << getWeapon()->getType() << std::endl;
}

void	HumanB::setName(const std::string &name)
{
	this->name = name;
}

const std::string	&HumanB::getName(void)
{
	return (this->name);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

Weapon *HumanB::getWeapon(void)
{
	return (this->weapon);
}
