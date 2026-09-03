/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:13:37 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/03 20:44:09 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

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

}

//void	welcomeTitle() {
//	std::cout << "=================================" << std::endl;
//	std::cout << "Welcome to the AWESOME phonebook!" << std::endl;
//	std::cout << "=================================" << std::endl;
//	std::cout << "Please type the desired outputs:" << std::endl;
//	std::cout << "ADD:	save a new contact" << std::endl;
//	std::cout << "SEARCH:	display a specific contact" << std::endl;
//	std::cout << "EXIT:	quit the program" << std::endl;
//	std::cout << "=================================" << std::endl;
//}



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
				phonebook.show_contacts();
				get_contact_index(phonebook);
		}
	} while (command != "EXIT");
	//else
	//{
	//	std::cout << "too many args" << std::endl;
	//	return (1);
	//}
	//welcomeTitle();
	return (0);
}
