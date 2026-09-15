/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:54:27 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/14 23:48:13 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	Bob("Bob", club);
		Bob.attack();
		club.setType("some other type of club");
		Bob.attack();
	}

	{
		Weapon club = Weapon("crude spiked club");
		HumanB	Jim("Jim");
		Jim.setWeapon(club);
		Jim.attack();
		club.setType("some other type of club");
		Jim.attack();
	}
}
