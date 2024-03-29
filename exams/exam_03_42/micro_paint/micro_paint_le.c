#include "micro_paint_le.h"

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_perror(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	check_pos(float x, float y, float id_x, float id_y, float width, float height)
{
	if (x < id_x || x > id_x + width || y < id_y || y > id_y + height)
		return (0);
	else if (x - id_x < 1 || (id_x + width) - x < 1 || y -id_y < 1 || (id_y + height) - y < 1)
		return (1);
	return (2);
}

int main(int argc, char **argv)
{
	FILE	*file;
	char	*paper, background, id, color;
	int		read, pos, x, y, b_width, b_height;
	float	id_x, id_y, width, height;

	if (argc != 2)
		return (ft_perror(ERR1));
	if (!(file = fopen(argv[1], "r")) ||
			(fscanf(file, "%i %i %c\n", &b_width, &b_height, &background) != 3) ||
			(!(b_width > 0 && b_width <= 300 && b_height > 0 && b_height <= 300)) || 
			(!(paper = (char *)malloc(sizeof(char) * (b_width * b_height)))))
		return (ft_perror(ERR2));
	memset(paper, background, b_width * b_height);
	while ((read = fscanf(file, "%c %f %f %f %f %c\n", &id, &id_x, id_y, width, height, color)) == 6)
	{
		if (!(width > 0 && height > 0) || !(id == 'R' || id == 'r'))
			break ;
		x = -1;
		while (++x < b_width)
		{
			y = -1;
			while (++y < b_height)
			{
				pos = check_pos((float)x, (float)y, id_x, id_y, width, height);
				if (pos == 1 || (pos == 2 && id == 'R'))
				   paper[y * b_width + x] = color;	
			}
		}
	}
	if (read != -1)
	{
		free(paper);
		return (ft_perror(ERR2));
	}
	y = -1;
	while (++y < b_height)
	{
		write(1, paper + y * b_width, b_width);
		write(1, "\n", 1);
	}
	free(paper);
	fclose(file);
	return (0);
		  	
}
