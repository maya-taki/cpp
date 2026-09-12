/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 19:53:41 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/12 19:57:04 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie
{
	public:
		void	announce(void)
		{
			std::cout << name << ":" << "BraiiiiiiinnnzzzZ..." << std::endl;
		}
	private:
		std::string name;
		
};
