/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:38:46 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/28 18:24:04 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fcntl.h>

void	load_map(char *file)
{
	char			*s;
	int				fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &s) > 0)
		ft_putendl(s);
}
