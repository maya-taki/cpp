/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:13:57 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/03 16:14:03 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char *av[])
{
	int	i = 1;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	while (i < ac) 
	{
		std::string s = av[i];
		for (int j = 0; j < (int)s.size(); j++)
		{
			std::cout << (char)toupper(s[j]);
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
