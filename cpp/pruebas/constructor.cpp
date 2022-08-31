/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:01:06 by lvintila          #+#    #+#             */
/*   Updated: 2022/08/31 21:37:39 by lvintila         ###   ########.fr       */
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

        Book()
        {
            title = "no title"; 
            author = "no author";
            pages = 0;           
        }

        Book(string aTitle, string aAuthor, int aPages)
        {
            author = aAuthor;
            title = aTitle;
            pages = aPages;

        }
};

int main()
{
    Book    book1 ("Harry Potter", "Leo Vintila", 569);
    Book    book2 ("Han Solo", "Artemis", 302);
    Book    book3;
    book3.pages = 129;
    std::cout << book3.pages << std::endl;
    return (0);
}