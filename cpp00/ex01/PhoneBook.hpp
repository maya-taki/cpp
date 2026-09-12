/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:13:29 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/11 18:50:38 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contacts[8];
		int			contact_count;
		int			old_index;
		std::string	truncate(const std::string &str, int width);
	public:
		PhoneBook();
		~PhoneBook();
		void		add_contact(const Contact &contact);
		void		show_contacts();
		void		search_contacts(int index);
		int			get_contact_count();
};

#endif
