/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:35:50 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/14 20:36:03 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H

# define SOURCE_H
# define EOF             (-1)
# define ERRCHAR         ( 0)
# define INIT_SRC_POS    (-2)

typedef struct  s_source
{   
    char *buffer;       /* the input text */
    long bufsize;       /* size of the input text */
    long  curpos;       /* absolute char position in source */
}               t_source;

char next_char(t_source *src);
void unget_char(t_source *src);
char peek_char(t_source *src);
void skip_white_spaces(t_source *src);

#endif 
