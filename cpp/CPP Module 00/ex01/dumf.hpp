/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumf.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:01:35 by lvintila          #+#    #+#             */
/*   Updated: 2022/08/26 22:05:49 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef DUMF_HPP
#define DUMF_HPP

#include "contacts.hpp"

#define MAX_CONTACTS 8

class Agenda
{
	private:
		Contact contacts[MAX_CONTACTS];
		int in_use;

		void add();
		void display_search_table();
		void search();
		void rec_and_del_first();
	public:
		Agenda();
		void dumf_loop();
};

#endif
