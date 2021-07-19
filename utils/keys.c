/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:58:21 by marvin            #+#    #+#             */
/*   Updated: 2021/07/19 20:58:59 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

int main (void)
{
    char k;

    printf("\n\n\n\n");

    while(1)
    {

       printf("Please press any key:");

       k = getchar();
       getchar();

       printf("ASCII code of given input key: %d",k);
       printf("\n\n\n");
    }
}
