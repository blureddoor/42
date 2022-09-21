/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumf.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:55:06 by lvintila          #+#    #+#             */
/*   Updated: 2022/08/26 21:59:39 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dumf.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>


Agenda::Agenda()
{
	in_use = 0;
}

/*
 * This method adds a new contact to the array, after checking if its full.
 */
void    Agenda::add()
{
	std::string input;

	if (in_use == MAX_CONTACTS)
	{
		std::cout << "The limit of " << MAX_CONTACTS
            << " contacts has been reached";
		std::cout << std::endl << "Do you wish to overwrite the first contact to ";
		std::cout << "make room for a new one?" << std::endl;
		do
		{
			std::cout << "[y/n] > ";
            getline(std::cin, input);
            rtrim(input);
		}
		while (input.compare("y") != 0 && input.compare("n") != 0);
		if (input.compare("y") == 0)
		{
		rec_and_del_first();
			in_use--;
		}
		else
			return;
	}
	contacts[in_use].read_contact();
	if (in_use < MAX_CONTACTS)
		in_use++;
}


/*
 * This method displays the table for the SEARCH functionality with a
 * resume of the stored contacts.
 */
void    Agenda::display_search_table()
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10)
        << "first name";
	std::cout << "|" << std::setw(10) << "last name" << "|" << std::setw(10)
        << "nickname";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < in_use; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << cut_and_dot(contacts[i].get_first_name()
            , 10);
		std::cout << "|" << std::setw(10)
            << cut_and_dot(contacts[i].get_last_name(), 10);
		std::cout << "|" << std::setw(10)
            << cut_and_dot(contacts[i].get_nickname(), 10);
		std::cout << "|" << std::endl;
		std::cout << "---------------------------------------------"
            << std::endl;
	}
}


/*
 * This method shows the user a table with the stored contacts and then it
 * prompts to select one to display its full data.
 */
void    Agenda::search()
{
	std::string input;
	bool valid;

	if (in_use == 0)
	{
		std::cout << "No contacts stored yet" << std::endl;
		return;
	}
	
	display_search_table();

	valid = false;
	while (!valid)
	{
		std::cout << "Index > ";
		getline(std::cin, input);
		rtrim(input);

		if (is_natural_number(input) && atoi(input.c_str()) < in_use)
			valid = true;
		else
			std::cout << input << ": invalid index" << std::endl;
	}
	contacts[atoi(input.c_str())].display_contact();
}


/*
 * This method moves all the contacts one position down overwriting
 * the first element.
 */
void    Agenda::rec_and_del_first()
{
	for (int i = 1; i < MAX_CONTACTS; i++)
		contacts[i - 1] = contacts[i];
}

/*
 * This method keeps asking the user for commands until an EXIT is introduced.
 */
void    Agenda::dumf_loop()
{
	std::string input;
	bool keep;

	std::cout << "Welcome to My dummie fool Contacts Book !";
	std::cout << std::endl << "Available commands: ADD, SEARCH, EXIT"
        << std::endl;

	keep = true;
	while (keep && !std::cin.eof())
	{
		std::cout << "> ";
		getline(std::cin, input);
		rtrim(input);

		if (input.compare("EXIT") == 0)
			keep = false;
		else if (input.compare("ADD") == 0)
			add();
		else if (input.compare("SEARCH") == 0)
			search();
		else
		{
			std::cout << "Invalid command: " << input << std::endl;
            std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
		}
	}
}

