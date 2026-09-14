/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:14:12 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/14 19:32:43 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int	main()
{
	int n = 3;

	Zombie* zombie_horde = zombieHorde(n, "zed");
	delete[] zombie_horde;
	return (0);
}
