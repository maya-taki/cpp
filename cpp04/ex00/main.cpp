/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 01:55:27 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 22:50:54 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *giraffe = new Animal();
	const Animal *bulldog = new Dog();
	const Animal *siamese = new Cat();
	std::cout << "========================" << std::endl;
	giraffe->makeSound();
	std::cout << "========================" << std::endl;
	bulldog->makeSound();
	std::cout << "========================" << std::endl;
	siamese->makeSound();
	std::cout << "========================" << std::endl;
	delete giraffe;
	delete bulldog;
	delete siamese;
	std::cout << "========================\n" << std::endl;
	const WrongAnimal *parrot = new WrongAnimal();
	const WrongAnimal *cuckoo = new WrongCat();
	std::cout << "========================" << std::endl;
	parrot->makeSound();
	std::cout << "========================" << std::endl;
	cuckoo->makeSound();
	std::cout << "========================" << std::endl;
	delete parrot;
	delete cuckoo;
	return (0);
}
