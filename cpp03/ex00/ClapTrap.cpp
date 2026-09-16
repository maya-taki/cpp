/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 13:08:26 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hit_points(10), _attack_dmg(10), _energy_points(10)
{
	std::cout << "[ DEFAULT constructor called ]" << std::endl;
};

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit_points(10), _attack_dmg(10), _energy_points(10)
{
	std::cout << "[ CONSTRUCTOR called ]" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& src) : _name(src._name), _hit_points(src._hit_points), _attack_dmg(src._attack_dmg), _energy_points(src._energy_points)
{
	std::cout << "[ COPY constructor called ]" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "[ COPY ASSIGNMENT operator called ]" << std::endl;
	if (this != &src)
	{
		_name = src._name;
		_hit_points = src._hit_points;
		_energy_points = src._energy_points;
		_attack_dmg = src._attack_dmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ DESTRUCTOR called ]" << std::endl;
};

void	ClapTrap::attack(const std::string &target)
{
	if (_hit_points && _energy_points)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_dmg << " points damage!" << std::endl;
		_energy_points -= 1;
	}
	if (!_energy_points)
		std::cout << "ClapTrap " << _name << " ran out of energy. Can't attack" << std::endl;
	if (!_hit_points)
		std::cout << "ClapTrap " << _name << " is dead. Can't attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead ):" << std::endl;
		return ;
	}
	if (_hit_points <= amount)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "[ ClapTrap " << _name << " has died! ]" <<std::endl;
	}
	if (_hit_points)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		_hit_points -= amount;
		if (_hit_points >= amount)
			std::cout << "[ ClapTrap " << _name << " has " << _hit_points << " health points left ]" <<std::endl;
		else if ((_hit_points - amount) <= 0)
		{
			_hit_points = 0;
			std::cout << "[ ClapTrap " << _name << " has died! ]" <<std::endl;
		}
	}
};

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points && _hit_points)
	{
		std::cout << "ClapTrap " << _name << " repaired " << amount << " points of damage" << std::endl;
		_hit_points += amount;
		_energy_points -= 1;
		if (_hit_points > 10)
			_hit_points = 10;
		std::cout << "[ ClapTrap " << _name << " has " << _hit_points << " health points left ]" <<std::endl;
	}
	if (!_energy_points)
		std::cout << "ClapTrap " << _name << " ran out of energy. Can't be repaired" << std::endl;
	else if (!_hit_points)
		std::cout << "ClapTrap " << _name << " is dead. Can't be repaired" << std::endl;
};

std::string ClapTrap::getName() const
{
	return (_name);
}
