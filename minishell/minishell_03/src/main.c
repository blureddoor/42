/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:40:47 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/14 20:25:56 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char *read_cmd(void)
{
    char buf[1024];
    char *ptr;
    char ptrlen;
    int buflen;

    ptrlen = 0;
    ptr = NULL;
    while(fgets(buf, 1024, stdin))
    {
        buflen = ft_strlen(buf);
        if (!ptr)
        {
            ptr = malloc(buflen + 1);
        }
        else
        {
            char *ptr2 = realloc(ptr, ptrlen + buflen + 1);
            if (ptr2)
            {
                ptr = ptr2;
            }
            else
            {
                free(ptr);
                ptr = NULL;
            }
        }
        if (!ptr)
        {
            perror("error: failed to alloc buffer");
            return NULL;
        }
        strcpy(ptr + ptrlen, buf);
        if (buf[buflen - 1] == '\n')
        {
            if (buflen == 1 || buf[buflen - 2] != '\\')
            {
                return ptr;
            }

            ptr[ptrlen + buflen - 2] = '\0';
            buflen -= 2;
            print_prompt2();
        }
        ptrlen += buflen;
    }
    return (ptr);
}

int main(int argc, char **argv)
{
    char *cmd;
    while(1)    
    {
        print_prompt1();        
        cmd = read_cmd();        
        if(!cmd)
            exit(EXIT_SUCCESS);        
        if(cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
        {
            free(cmd);
            continue;
        }        
        if(ft_strcmp(cmd, "exit\n") == 0)
        {
            free(cmd);
            break;
        }       
        printf("%s\n", cmd);
        free(cmd);
    }
    exit(EXIT_SUCCESS);
}
