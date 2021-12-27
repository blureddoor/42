/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgilazan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 20:11:59 by sgilazan          #+#    #+#             */
/*   Updated: 2020/07/30 20:16:07 by sgilazan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j;
    int x[255];

    if (argc == 3)
    {
        i = 0;
        while (i < 255)
            x[i++] = 0;
        i = 1;
        while (i < 3)
        {
            j = 0;
            while (argv[i][j])
            {
                if (!x[(unsigned char)argv[i][j]])
                {
                    x[(unsigned char)argv[i][j]] = 1;
                    write (1, &argv[i][j], 1);
                }
                j++;
            }
            i++;
        }    
    }
    write (1, "\n", 1);
    return (0);
}