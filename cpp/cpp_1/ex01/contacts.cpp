/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:01:05 by lvintila          #+#    #+#             */
/*   Updated: 2022/09/21 20:12:39 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstring>
#include <cctype>


Contact::Contact()
{
	first_name.clear();
	last_name.clear();
	nickname.clear();
	phone_number.clear();
	darkest_secret.clear();
}

/*
 * This method checks if Contact::phone_number has a valid lenght and
 * is only composed by digits.
 */
bool    Contact::is_valid_phone_number()
{
	if (phone_number.length() != 9)
		return (false);
	for (size_t i = 0; i < phone_number.length(); i++)
		if (!isdigit(phone_number[i]))
			return (false);
	return (true);
}

/*
 * This method prompts the user to fill all the fields of the class.
 */
void    Contact::read_contact()
{
	std::cout << "First name: ";
	getline(std::cin, first_name);
	rtrim(first_name);
	std::cout << "Last name: ";
	getline(std::cin, last_name);
	rtrim(last_name);
	std::cout << "Nickname: ";
	getline(std::cin, nickname);
	rtrim(nickname);
	do
	{
		std::cout << "Phone number: ";
		getline(std::cin, phone_number);
	}
	while (!std::cin.eof() && !is_valid_phone_number());
 
	std::cout << "Darkest secret: ";
	getline(std::cin, darkest_secret);
	rtrim(darkest_secret);
}

/*
 * This method displays all the fields of the class.
 */
void    Contact::display_contact()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

std::string  Contact::get_first_name()
{
	return (first_name);
}

std::string  Contact::get_last_name()
{
	return (last_name);
}

std::string  Contact::get_nickname()
{
	return (nickname);
}

std::string  Contact::get_phone_number()
{
	return (phone_number);
}

std::string  Contact::get_darkest_secret()
{
	return (darkest_secret);
}

