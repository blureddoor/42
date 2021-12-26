/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:48:11 by lvintila          #+#    #+#             */
/*   Updated: 2021/12/20 21:56:36 by lvintila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int get_cmd()
{
	printf("gasoil-sh@~ : ");
	//ft_strlcpy(buff, rl_gets(), (ft_strlen(rl_gets()) + 1)); 
	buff = rl_gets();
	// rl_gets sustituye al fgets - lee la input linea con readline()
	// y devuelve un puntero al texto leido;
	// fgets(buff, MAX_CMD - 1, stdin); 
	// nota LE: hacer que line read que se 
	// esta devolviendo/leyendo con "rl_gets()" se almacene en buff.
	// entrar
	return 0;
}

char **parse(char *buff)
{
	char	*ptr;
	int		argc;
	static char *argv[255];
	// Se guardan todos los comandos extraídos en argv, 
	// porque se utilizan en todo el dominio de vida del programa 
	// y se declaran estáticos

	ptr = buff;
	//free(buff);
	argc = 0;
	while(*ptr != '\0')
	{
		if(*ptr != ' ')
		{
			argv[argc++] = ptr;
			while(*ptr != '\0' && *ptr != ' ')
			{
				ptr++;
			}
			*ptr = '\0';
		}
		ptr++;
	}
	// delete spaces and pull cmds
	argv[argc] = NULL;
	//  NULL terminated
	return argv;
}

void    redirect(char *buff)
{
	int		redirect_flag;
	// times of ">" 
	char	*redirect_file;
	int		fd;
	char	*ptr;

	ptr = buff;
	free(buff);
    redirect_flag = 0;
    redirect_file = NULL;
	while(*ptr != '\0')
	{
		if(*ptr == '>')
		{
			ptr++;
			++redirect_flag;
			// Si este bit es>, la cuenta se incrementa en uno y este bit 
			// se reescribe como \0 para evitar que se interprete
			// como un comando

			if(*ptr == '>')
			{
				++redirect_flag;
				ptr++;
			}
			
			while(*ptr == ' ' && *ptr != '\0')
			{
				ptr++;
			}

			redirect_file = ptr;
			// Después de la detección >>, el siguiente es el nombre del
			// archivo redirigido, que será analizado
			
			while(*ptr != ' ' && *ptr != '\0')
			{
				ptr++;
			}				
			*ptr = '\0';
		}
		ptr++;
	}

	if(redirect_flag == 1)
	{
		fd = open(redirect_file, O_WRONLY|O_CREAT|O_TRUNC, 0664);
		dup2(fd, 1);
		// Redirigir la salida estándar al archivo
		// Si solo aparece uno>, significa que es una redirección de sobrescritura, abrir en modo de sobrescritura O_TRUNC
	}
	else if(redirect_flag == 2)
	{
		fd = open(redirect_file, O_WRONLY | O_CREAT|O_APPEND, 0664);
		dup2(fd, 1);
		// > aparece dos veces, lo que indica que es una redirección adicional,
		// se abre en el modo de anexar O_APPEND
	}
}

int execute(char *buff, char **envp)
{
	char	**argv;
	char	*str;
	char	**cmd;


	argv = NULL;
	int pid = fork();
	// Crea un proceso hijo, reemplaza el programa en el proceso hijo
	if(pid == 0)
	{	
		redirect(buff);
		// Redirigir
		argv = parse(buff);
		// Analizar el comando
		
		if(argv[0] != NULL)
		{
			cmd = ft_split(argv[0], ' ');
			str = find_path(cmd[0], envp);
			if (execve(str, cmd, envp) == -1)
			{
				perror("error: cmd not found");
				free_arr(cmd);
				free(str);
			}
			// Proceso de reemplazo
		}
		else
		{
			//perror("Error: comando o archivo no existe");
			exit(-1);
			/* 
			 * Si ingresa un error de comando, salga del proceso
			 */
		}			
	}	
	else
	{
		waitpid(pid, NULL, 0);
		/*
		 * Espere a que salga el proceso hijo para evitar procesos zombies
		 */
	}	
	return 0;
}

int main(int argc, char **argv, char **envp)
{
	while(1)
	{
		/* Si la entrada del comando es correcta, se habilita la sustitución 
		 * del programa.
		 */
		if(!get_cmd())
			execute(buff, envp);
	}
	free(buff);
    return (0);
}
