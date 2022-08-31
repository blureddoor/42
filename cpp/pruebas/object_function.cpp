/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_function.cpp                                :+:      :+:    :+:   */
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

class   Student
{
    public:
        string  name;
        string  major;
        double  gpa;
        Student(string aName, string aMajor, double aGpa)
        {
            name = aName;
            major = aMajor;
            gpa = aGpa;
        }
        bool    hasHonors()
        {
            if(gpa >= 2.0)
            {
                return (true);
            }
            return (false);
        }
};

int main()
{
    Student student1("Jim", "Business", 2.4);
    Student student2("Leo", "Art", 3.6);
    std::cout << student1.hasHonors() << std::endl;
    return (0);
}