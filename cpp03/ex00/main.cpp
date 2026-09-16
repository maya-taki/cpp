/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:55:27 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 13:08:44 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Chippy");
	ClapTrap b("Boxer");
	ClapTrap c = a;
	
	std::cout << "A name: " << a.getName() << std::endl;
	std::cout << "B name: " << b.getName() << std::endl;
	std::cout << "C name: " << c.getName() << std::endl;

	std::cout << std::endl;
	std::cout << "------------- THE FINAL BATTLE -------------" << std::endl;
	std::cout << std::endl;
	
	b.attack("Handsome Jack");
	b.takeDamage(5);
	b.takeDamage(5);
	std::cout << "--------------------------------------------" << std::endl;
	a.attack("Handsome Jack");
	a.takeDamage(9);
	a.beRepaired(15);
	a.attack("Handsome Jack");
	a.takeDamage(5);
	a.takeDamage(9);
	return (0);
}
