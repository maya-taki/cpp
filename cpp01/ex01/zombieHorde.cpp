/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:03:45 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/14 19:33:04 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	if (n <= 0)
		return (NULL);
	Zombie* zed = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		zed[i].setName(name);
		zed[i].announce();
	}
	return (zed);
}
