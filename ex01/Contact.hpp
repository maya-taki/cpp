/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:13:40 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/12 17:52:38 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>

class Contact
{
	private: 
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _secret;
	public:
		Contact();
		~Contact();
		void set_first_name(std::string name);
		std::string get_first_name(void);

		void set_last_name(std::string name);
		std::string get_last_name(void);
		
		void set_nickname(std::string name);
		std::string get_nickname(void);
		
		void set_phone_number(std::string name);
		std::string get_phone_number(void);

		void set_secret(std::string name);
		std::string get_secret(void);
};

#endif
