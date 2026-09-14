/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:49:47 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/14 19:37:39 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const std::string &name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << getName() + ": is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << getName() + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string &name)
{
	this->name = name;
	std::cout << getName() + ": has spawned" << std::endl;
}

std::string	Zombie::getName(void)
{
	return (this->name);
}
