/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtakiyos <mtakiyos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 16:13:42 by mtakiyos          #+#    #+#             */
/*   Updated: 2026/09/03 19:34:38 by mtakiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::set_first_name(std::string name){
	this->_first_name = name;
}

void Contact::set_last_name(std::string name){
		this->_last_name = name;
}

void Contact::set_nickname(std::string name){
	this->_nickname = name;
}

void Contact::set_phone_number(std::string name){
	this->_secret = name;
}

void Contact::set_secret(std::string name){
	this->_secret = name;
}

std::string Contact::get_first_name(void){
	return (this->_first_name);
}

std::string Contact::get_last_name(void){
	return (this->_last_name);
}

std::string Contact::get_nickname(void){
	return (this->_nickname);
}

std::string Contact::get_phone_number(void){
	return (this->_secret);
}

std::string Contact::get_secret(void){
	return (this->_secret);
}
