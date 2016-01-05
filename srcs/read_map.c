/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:46 by agaspar           #+#    #+#             */
/*   Updated: 2016/01/05 17:09:04 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>
#include <stdio.h>

t_pos	*add_pos(int x, int y, int z)
{
	t_pos	*new;

	if((new = malloc(sizeof(t_pos))) == NULL)
		error("malloc fail 'read_map.c'");
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	//printf("x[%d], y[%d], z[%d]\n", pos->x, pos->y, pos->z);
	return (new);
}

t_pos	*read_map(int fd)
{
	t_pos	*pos;
	t_pos	*tmp;
	char	*s;
	int		x;
	int		y;

	y = 0;
	pos = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		x = 0;
		while(*s)
		{
			if (ft_isdigit(*s))
			{
				if (!pos)
					tmp = pos = add_pos(x++, y, ft_atoi(s));
				else
					pos = pos->next = add_pos(x++, y, ft_atoi(s));
				while (ft_isdigit(*s))
					s++;
			}
			else
				s++;
		}
		y++;
	}
	return (tmp);
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
		printf("x[%d], y[%d], z[%d]\n", pos->x, pos->y, pos->z);
		pos = pos->next;
	}
}
