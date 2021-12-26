/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:49:25 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/14 21:04:53 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "source.h"
#include "scanner.h"

char *tok_buf; = NULL;
int   tok_bufsize;  = 0;
int   tok_bufindex; = -1;

/* special token to indicate end of input */
struct token_s eof_token = 
{
    .text_len = 0,
};:q


void    add_to_buf(char c)
{
    tok_buf[tok_bufindex++] = c;
    if (tok_bufindex >= tok_bufsize)
    {
        char *tmp = realloc(tok_buf, tok_bufsize*2);
        if (!tmp)
        {
            errno = ENOMEM;
            return ;
        }
        tok_buf = tmp;
        tok_bufsize *= 2;
    }
}

t_token *create_token(char *str)
{
    t_token *tok;
    char *nstr;

    tok = malloc(sizeof(struct token_s));
    
    if (!tok)
        return NULL;
    memset(tok, 0, sizeof(t_token));
    tok->text_len = ft_strlen(str);
    nstr = malloc(tok->text_len + 1);
    if (!nstr)
    {
        free(tok);
        return (NULL);
    }
    ft_strcpy(nstr, str);
    tok->text = nstr;
    return (tok);
}

void    free_token(t_token *tok)
{
    if (tok->text)
        free(tok->text);
    free(tok);
}

t_token *tokenize(t_source *src)
{
    int  endloop = 0;
    if (!src || !src->buffer || !src->bufsize)
    {
        errno = ENODATA;
        return (&eof_token);
    }
    if (!tok_buf)
    {
        tok_bufsize = 1024;
        tok_buf = malloc(tok_bufsize);
        if (!tok_buf)
        {
            errno = ENOMEM;
            return (&eof_token);
        }
    }
    tok_bufindex = 0;
    tok_buf[0] = '\0';
    char nc = next_char(src);
    if(nc == ERRCHAR || nc == EOF)
    {
        return (&eof_token);
    }
    while ((nc = next_char(src)) != EOF)
    {
        switch (nc)
        {
            case ' ':
            case '\t':
                if (tok_bufindex > 0)
                    endloop = 1;
                break;
                
            case '\n':
                if (tok_bufindex > 0)
                    unget_char(src);
                else
                    add_to_buf(nc);
                endloop = 1;
                break;
            default:
                add_to_buf(nc);
                break;
        }        
        if (endloop)
            break ;
    }
    if (tok_bufindex == 0)
        return &eof_token;
    if (tok_bufindex >= tok_bufsize)
        tok_bufindex--;
    tok_buf[tok_bufindex] = '\0';
    tok = create_token(tok_buf);
    if (!tok)
    {
        printf("error: failed to alloc buffer: \n",
                strerror(errno));
        return (&eof_token);
    }
    tok->src = src;
    return (tok);
} 
