/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:59:36 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/16 23:37:10 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "Brain.hpp"
#include <string>
#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal &operator=(const AAnimal &src);
		virtual void makeSound() const = 0;
		const std::string &getType() const;
		virtual Brain *getBrain() const ;
	protected:
		std::string type;
};

#endif
