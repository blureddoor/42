/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:00:07 by lvintila          #+#    #+#             */
/*   Updated: 2022/09/22 20:01:43 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
void Karen::complain(std::string level)
{
	for (int i = 0; i < 4 ; i++)
	{
		if (stat[i].name == level)
		{
			(this->*(stat[i].ptr))();
		}
	}
}

Karen::Karen(void)
{
	init();
}

void Karen::init(void)
{
	stat[0].name = "debug";
	stat[0].ptr = &Karen::debug;
	stat[1].name = "info";
	stat[1].ptr = &Karen::info;
	stat[2].name = "warning";
	stat[2].ptr = &Karen::warning;
	stat[3].name = "error";
	stat[3].ptr = &Karen::error;
}

void    Karen::debug(void)
{
	std::cout << std::endl;
    std::cout << "[ DEBUG ] " << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!." << std::endl;
}

void    Karen::info(void)
{
    std::cout << "[ INFO ] " << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!." << std::endl;
}

void    Karen::warning(void)
{
    std::cout << "[ WARNING ] " << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Karen::error(void)
{
    std::cout << "[ ERROR ] " << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}