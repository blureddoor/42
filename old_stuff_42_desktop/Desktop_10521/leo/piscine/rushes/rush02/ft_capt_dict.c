/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capt_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:58:09 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/30 15:53:42 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
//	FILE *fp;
	int fp;
	char buffer[1024];
	int numbytes;

	if (argc > 3) // el programa puede recibir solo 2 argumentos
	{
		printf("Dict Error\n");
		exit (1);
	}
	else if ((fp = open((argv[1]), O_RDONLY)) < 0)
		perror("open() error");
//	else if (fp == null) // comprobar que el archivo existe
//	{
//		printf("Dict Error");
//		exit (1);
//	}
//	fp = open(argv[1], O_RDONLY); // abrimos el archivo origen
//	fp1 = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0700);// abrimos el archivo de origen donde queremos copiar/reproducir el archivo de origen
	else
	{
		while((numbytes = read(fp, buffer, sizeof(buffer)-1)) > 0)
		{	
			buffer[numbytes] = 0x00;
			write(fp, &buffer, numbytes);
			printf("\n%s\n", buffer);
		}
		close(fp);
	}
//	close(fp1);
//	printf("%d\n%d", fp, fp1);
	return (0);
}
