/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:37:27 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/14 20:42:59 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "source.h"

void unget_char(t_source *src)
{
    if (src->curpos < 0)
        return;
    src->curpos--;
}

char next_char(t_source *src)
{
    if (!src || !src->buffer)
    {
        errno = ENODATA;
        return (ERRCHAR);
    }
    char c1 = 0;
    if (src->curpos == INIT_SRC_POS)
        src->curpos  = -1;
    else
        c1 = src->buffer[src->curpos];
    if (++src->curpos >= src->bufsize)
    {
        src->curpos = src->bufsize;
        return EOF;
    }
    return src->buffer[src->curpos];
}

char peek_char(t_source *src)
{
    if (!src || !src->buffer)
    {
        errno = ENODATA;
        return (ERRCHAR);
    }
    long pos = src->curpos;
    if (pos == INIT_SRC_POS)
        pos++;
    pos++;
    if (pos >= src->bufsize)
        return (EOF);
    return (src->buffer[pos]);
}

void skip_white_spaces(struct source_s *src)
{
    char c;

    if (!src || !src->buffer)
        return ;
    while(((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
        next_char(src);
}
