/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:13:37 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/12 17:59:20 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>

std::string get_field(std::string field_name)
{
	std::string	value;
	do
	{
		std::cout << field_name << ": ";
		std::getline(std::cin, value);
		if (std::cin.eof())
			return (value);
		if (value.empty())
			std::cout << field_name
				<< " cannot be empty, try again"
				<< std::endl;
	} while (value.empty());
	return (value);
}

void	get_contact_index(PhoneBook &phonebook)
{
	int			i = 0;
	std::string	input;

	do
	{
		std::cout << "Enter contact index to view more: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		std::stringstream stream(input);
		char extra;
		if (!(stream >> i) || (stream >> extra))
		{
			std::cout << "Not a number" << std::endl;
		}
		else
		{
			try
			{
				phonebook.search_contacts(i);
				break;
			}
			catch (std::runtime_error &e)
			{
				std::cout << "Error: " << e.what()  << std::endl;
			}
		}
	}
	while (true);
}

int	main()
{
	PhoneBook	phonebook = PhoneBook();
	std::string	command;

	std::cout << "Enter command: ADD, SEARCH or EXIT" << std::endl;
	
	do
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (0);
		if (command.empty())
			std::cout << "Type something!" << std::endl;
		if (command == "ADD")
		{
			std::cout << "Adding new contact" << std::endl;
			Contact new_contact = Contact();
			new_contact.set_first_name(get_field("First name"));
			new_contact.set_last_name(get_field("Last name"));
			new_contact.set_nickname(get_field("Nickname"));
			new_contact.set_phone_number(get_field("Phone number"));
			new_contact.set_secret(get_field("Secret"));
			phonebook.add_contact(new_contact);
		}
		else if (command == "SEARCH")
		{
			if (phonebook.get_contact_count() == 0)
			{
				std::cout << "No contacts saved" << std::endl;
			}
			else
			{
				phonebook.show_contacts();
				get_contact_index(phonebook);
			}
		}
	} while (command != "EXIT");
	return (0);
}
