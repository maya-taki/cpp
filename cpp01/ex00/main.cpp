/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:14:12 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/14 15:29:44 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int	main()
{
	randomChump("(Zombie of random)1");
	Zombie* nz1 = newZombie("(Zombie of new)1");
	nz1->announce();
	randomChump("(Zombie of random)2");
	Zombie* nz2 = newZombie("(Zombie of new)2");
	nz2->announce();
	delete nz1;
	delete nz2;
}
