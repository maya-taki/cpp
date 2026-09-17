/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:59:36 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:40:36 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &a);
		Dog&	operator=(const Dog &a);
		void	makeSound() const;
		Brain *getBrain() const ;
		
	private:
		Brain *brain;
};

#endif
