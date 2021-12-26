/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:44:18 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/14 20:48:28 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H


typedef struct  s_token
{
    struct source_s *src;       /* source of input */
    int    text_len;            /* length of token text */
    char   *text;               /* token text */
}               t_token;


/* the special EOF token, which indicates the end of input */

extern struct token_s eof_token;
struct token_s *tokenize(t_struct *src);

void free_token(t_token *tok);

#endif
