/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:46 by agaspar           #+#    #+#             */
/*   Updated: 2016/01/05 14:51:35 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>
#include <stdio.h>

void	add_pos(t_pos *pos, int x, int y, int z)
{
	t_pos *new;
	if((new = malloc(sizeof(t_pos))) == NULL)
		error("malloc fail 'read_map.c'");
	if (!pos)
	{
		pos->x = x;
		pos->y = y;
		pos->z = z;
		pos->next = NULL;
	}
	else
	{
		while(pos->next != NULL)
			pos = pos->next;
		new->x = x;
		new->y = y;
		new->z = z;
		pos->next = new;
	}
}

t_pos	*read_map(int fd)
{
	t_pos	*pos;
	char	*s;
	int		x;
	int		y;

	y = 0;
	if((pos = malloc(sizeof(t_pos))) == NULL)
		error("malloc fail 'read_map.c'");
	while (get_next_line(fd, &s) > 0)
	{
		x = 0;
		while(*s)
		{
			if (!ft_isdigit(*s))
				s++;
			else
			{
				add_pos(pos, x, y, ft_atoi(s));
				ft_putnbr(pos->x);
				while (ft_isdigit(*s))
					s++;
			}
			x++;
		}
		y++;
	}
	return (pos);
}

void	load_map(char *file)
{
	t_pos	*pos;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error("Impossible d'ouvrire le fichier");
	pos = read_map(fd);
	while (pos)
	{
		ft_putchar('c');
		printf("x[%d], y[%d], z[%d]", pos->x, pos->y, pos->z);
		pos = pos->next;

	}
}
