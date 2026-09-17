/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:55:27 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:42:14 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


void	print(const std::string &s)
{
	std::cout << s << std::endl;
}

int	main(void)
{
	std::cout << std::endl;
	print("==== Create AAnimal: Dog ====");
	std::cout << std::endl;
	const AAnimal* d = new Dog();
	std::cout << std::endl;
	print("==== Create AAnimal: Cat ====");
	std::cout << std::endl;
	const AAnimal* c = new Cat();
	std::cout << std::endl;
	print("==== Destroy AAnimal: Dog ====");
	std::cout << std::endl;
	delete d;
	std::cout << std::endl;
	print("==== Destroy AAnimal: Cat ====");
	std::cout << std::endl;
	delete c;
	std::cout << std::endl;
}
