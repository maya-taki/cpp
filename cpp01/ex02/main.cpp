/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 18:14:12 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/14 19:57:31 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	res = "HI THIS IS BRAIN";
	
	std::string	*stringPTR = &res;
	std::string	&stringREF = res;

	std::cout << "memory address of res: " << &res << std::endl;
	std::cout << "memory adress of stringPTR: " << stringPTR << std::endl;
	std::cout << "memory adress of stringREF: " << &stringREF << std::endl;

	std::cout << "value of res: " + res << std::endl;
	std::cout << "value of stringPTR: " + *stringPTR << std::endl;
	std::cout << "value of stringREF: " + stringREF << std::endl;
	return (0);
}
