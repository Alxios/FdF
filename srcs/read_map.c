/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:46 by agaspar           #+#    #+#             */
/*   Updated: 2016/01/04 17:17:41 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>

void	load_map(char *file)
{
	char	*s;
	int		fd;
	int		x;
	int		y;

	y = 0;
	if ((fd = open(file, O_RDONLY)) != 1)
		return (NULL);
	while (get_next_line(fd, &s) > 0)
	{
		x = 0;
		while(*s)
		{

		}
	}
}
