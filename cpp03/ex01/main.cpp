/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:55:27 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 18:40:51 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap a("Chippy");
	ScavTrap b("Boxer");
	
	std::cout << "ClapTrap name: " << a.getName() << std::endl;
	std::cout << "ScavTrap name: " << b.getName() << std::endl;

	std::cout << std::endl;
	std::cout << "------------- THE FINAL BATTLE -------------" << std::endl;
	std::cout << std::endl;
	
	b.attack("Handsome Jack");
	b.takeDamage(83);
	b.guardGate();
	b.takeDamage(52);
	b.guardGate();
	std::cout << "--------------------------------------------" << std::endl;
	a.attack("Handsome Jack");
	a.takeDamage(9);
	a.beRepaired(15);
	a.attack("Handsome Jack");
	a.takeDamage(5);
	a.takeDamage(9);
	return (0);
}
