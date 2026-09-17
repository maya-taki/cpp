/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 18:49:41 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "[ Scavtrap DEFAULT constructor called ]" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_dmg = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "[ Scavtrap CONSTRUCTOR called ]" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "[ Scavtrap COPY constructor called ]" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "[ Scavtrap COPY ASSIGNMENT operator called ]" << std::endl;
	ClapTrap::operator=(src);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ Scavtrap DESTRUCTOR called ]" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hit_points && _energy_points)
	{
		std::cout << _name << " attacks " << target << ", causing " << _attack_dmg << " points damage!" << std::endl;
		_energy_points -= 1;
	}
	if (!_energy_points)
		std::cout << _name << " ran out of energy. Can't attack" << std::endl;
	if (!_hit_points)
		std::cout << _name << " is dead. Can't attack" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_hit_points)
		std::cout << _name << " is keeping the gate secured" << std::endl;
	else
		std::cout << _name << " is dead. " << _name << " is no longer keeping the gate secured." << std::endl;
}
