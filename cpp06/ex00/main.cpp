/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:34:38 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/11/25 22:44:34 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Can only accept 1 argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
