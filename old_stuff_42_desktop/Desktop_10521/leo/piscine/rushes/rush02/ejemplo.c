/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:20:33 by lvintila          #+#    #+#             */
/*   Updated: 2019/11/30 15:41:01 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_SOURCE
#include <fcntl.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>

int main() 
{
  int ret, fd;
  char buf[1024];

  if ((fd = open("numbers.dict", O_RDONLY)) < 0)
    perror("open() error");
  else 
  {
    while ((ret = read(fd, buf, sizeof(buf)-1)) > 0) 
	{
      buf[ret] = 0x00;
      printf("En el numbers.dict hay esto: \n<%s>\n", buf);
    }
	close(numbers.dict);
  }
}
