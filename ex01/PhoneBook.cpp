/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:13:33 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/03 20:06:27 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : contact_count(0), old_index(0) {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::add_contact(const Contact &contact)
{
	contacts[old_index] = contact;
	old_index = (old_index + 1) % 8;
	if (contact_count < 8)
		contact_count++;
}

std::string	PhoneBook::truncate(const std::string &str, int width)
{
	std::string	result = str;
	if (static_cast<int>(result.length()) > width)
	{
		result.resize(width - 1);
		result.append(".");
	}
	return (result);
}

void	PhoneBook::show_contacts()
{
	int			w = 10;
	std::string	separator(43, '-');

	std::cout << separator << std::endl;
	std::cout << std::right
		<< std::setw(w) << "Index "
		<< "|"
		<< std::setw(w) << " First name "
		<< "|"
		<< std::setw(w) << " Last name "
		<< "|"
		<< std::setw(w) << " Nickname "
		<< "|"
		<< std::endl;
	std::cout << separator << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::right
			<< std::setw(w) << i
			<< "|"
			<< std::setw(w) << truncate(contacts[i].get_first_name(), w)
			<< "|"
			<< std::setw(w) << truncate(contacts[i].get_last_name(), w)
			<< "|"
			<< std::setw(w) << truncate(contacts[i].get_nickname(), w)
			<< "|"
			<< std::endl;
	}
}

//void	PhoneBook::search_contacts(int index)
//{
	
//}
//int		PhoneBook::get_contact_count()
//{

//}
