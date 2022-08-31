/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:01:06 by pmontese          #+#    #+#             */
/*   Updated: 2022/08/31 21:37:39 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

class Book
{
    public:
        string  title;
        string  author;
        int     pages;
};

int main()
{
    Book    book1;
    Book    book2;
    book1.title = "Harry Potter";
    book1.author = "Leo Vintila";
    book1.pages = 569;

    book2.author = "Han Solo";
    book2.title = "Artemis";
    book2.pages = 302;

    std::cout << "El titulo del book1 es: " <<  book1.title << std::endl;
    std::cout << "El autor del book1 es: " <<  book1.author << std::endl;
    std::cout << "El book1 tiene " << book1.pages << " hojas" << std::endl;
    std::cout << "El titulo del book2 es: " <<  book2.title << std::endl;
    std::cout << "El titulo del book2 es: " <<  book2.author << std::endl;
    std::cout << "El book2 tiene " <<  book2.pages << " hojas" << std::endl;
    return (0);
}