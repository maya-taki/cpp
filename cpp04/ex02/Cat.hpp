/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:59:36 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:41:16 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &a);
		Cat& operator=(const Cat &a);
		void makeSound() const;
		Brain *getBrain() const ;
		
	private:
		Brain *brain;
};

#endif
