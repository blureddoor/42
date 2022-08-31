/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inheritance.cpp                                    :+:      :+:    :+:   */
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

class Chef
{
private:
    /* data */
public:
    void makeChicken(/* args */)
    {
    std::cout << "The chef makes chicken" << endl;
    }
    void makeSalad(/* args */)
    {
    std::cout << "The chef makes salad" << endl;
    }
    void makeSpecialDish(/* args */)
    {
    std::cout << "The chef makes bbq ribs" << endl;
    }
};

class ItalianChef: public Chef
{
    public:
        void    makePasta()
        {
            cout << "The Italian Chef makes Pasta" << endl;
        }
        void makeSpecialDish(/* args */)
        {
        std::cout << "The chef makes pizza" << endl;
        }
};

int main()
{
    Chef    chef;
    chef.makeSpecialDish();

    ItalianChef italianChef;
    italianChef.makeSpecialDish();
    italianChef.makePasta();
    return (0);
}
