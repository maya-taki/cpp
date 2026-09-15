/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 20:54:31 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/15 00:51:42 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class	Weapon
{
	public:
		Weapon(const std::string &newType);
		~Weapon();
		const std::string	&getType(void) const;
		void				setType(const std::string &newType);

	private:
		std::string type;
};

#endif
