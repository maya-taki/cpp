/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:51:25 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 19:12:36 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "[ FragTrap DEFAULT constructor called ]" << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_dmg = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "[ FragTrap CONSTRUCTOR called ]" << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_dmg = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "[ FragTrap COPY constructor called ]" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	std::cout << "[ FragTrap COPY ASSIGNMENT operator called ]" << std::endl;
	ClapTrap::operator=(src);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[ FragTrap DESTRUCTOR called ]" << std::endl;
}

void	FragTrap::attack(const std::string &target)
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

void	FragTrap::highFivesGuys(void)
{
	if (_hit_points)
		std::cout << _name << " high fives " << std::endl;
	else
		std::cout << _name << " cant high five cus he dead " << std::endl;
}
