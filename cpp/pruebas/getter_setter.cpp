/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:09:56 by lvintila          #+#    #+#             */
/*   Updated: 2022/08/31 21:20:29 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

class   Movie
{
    private:
        string  rating;
    public:
        string  title;
        string  director;
        
        Movie(string aTitle, string aDirector, string aRating)
        {
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        }
        void    setRating(string aRating)
        {
            if( aRating == "G" || aRating == "PG" || aRating == "PG-13" || aRating == "R")
            {
                rating = aRating;
            }
            else
            {
                rating = "Wrong Rating";
            }
        }
        string  getRating()
        {
            return rating;
        }
};

int main()
{
    Movie avengers("The Avengers", "Joss Whedon", "PG-18");
    avengers.setRating("Cat");
    std::cout << avengers.getRating() <<std::endl;

    return(0);
}