/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:55:27 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 19:28:27 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap a("Aloy");
	ScavTrap b("Boxer");
	FragTrap c("Chippy");
	
	std::cout << "ClapTrap name: " << a.getName() << std::endl;
	std::cout << "ScavTrap name: " << b.getName() << std::endl;
	std::cout << "FragTrap name: " << c.getName() << std::endl;

	std::cout << std::endl;
	std::cout << "------------- THE FINAL BATTLE -------------" << std::endl;
	std::cout << std::endl;
	
	a.attack("Generic goon");
	a.takeDamage(2);
	a.beRepaired(15);
	a.takeDamage(4);
	a.attack("Generic goon");
	a.takeDamage(8);
	std::cout << "--------------------------------------------" << std::endl;
	b.attack("Handsome Jack");
	b.takeDamage(53);
	b.guardGate();
	b.attack("Handsome Jack");
	b.takeDamage(35);
	c.beRepaired(10);
	b.takeDamage(29);
	b.guardGate();
	std::cout << "--------------------------------------------" << std::endl;
	c.attack("Psycho");
	c.highFivesGuys();
	c.takeDamage(9);
	c.beRepaired(9);
	c.attack("Psycho");
	c.takeDamage(15);
	c.takeDamage(39);
	c.highFivesGuys();
	std::cout << "--------------------------------------------" << std::endl;
	return (0);
}
