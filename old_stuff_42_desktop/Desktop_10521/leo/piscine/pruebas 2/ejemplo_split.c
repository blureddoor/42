/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:59:07 by lvintila          #+#    #+#             */
/*   Updated: 2019/12/01 22:13:53 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
******************************************************************
* @brief Extrae palabras de una cadena y las coloca en un puntero
*        doble E/S (triple, por tanto).
*
* @param orig     Cadena inicial
* @param delim    Las palabras vendrán delimitadas por uno de los
*                 caracteres de esta cadena
* @param args     El primer puntero hace reservas de las direcciones
*                 donde se colocarán los fragmentos de cadena.
*
* @return Número de palabras extraídas. (max_args+1) si en la
*         cadena hay más de max_args palabras.
*
******************************************************************/
int extrae_argumentos_dd(char *orig, char *delim, char ***args)
{
char *tmp;
int num=0;
/* Reservamos memoria para copiar la cadena ... pero la memoria justa */
char *str= malloc(strlen(orig)+1);
char **aargs;

strcpy(str, orig);

aargs=malloc(sizeof(char**));

tmp=strtok(str, delim);
do
{
aargs[num]=malloc(sizeof(char*));

/*       strcpy(aargs[num], tmp); */
aargs[num]=tmp;
num++;

/* Reservamos memoria para una palabra más */
aargs=realloc(aargs, sizeof(char**)*(num+1));

/* Extraemos la siguiente palabra */
tmp=strtok(NULL, delim);
} while (tmp!=NULL);

*args=aargs;
return num;
}

int main()
{
char cadena[]="Bienvenido al blog Poesía Binaria. Esto es una prueba del extractor de argumentos con puntero triple";
char **args4;
int i;
int nargs;

nargs=extrae_argumentos_dd(cadena, " ", &args4);

printf("CADENA: %s\n", cadena);
i = 0;
while (i < nargs)
{
	++i;
	printf("Palabra %d: %s\n", i, args4[i]);
}
}
