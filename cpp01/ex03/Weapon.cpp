/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:54:29 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/15 00:51:36 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(const std::string &newType)
	: type(newType)
{
}

Weapon::~Weapon() {}

const std::string	&Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(const std::string &newType)
{
	this->type = newType;
}
