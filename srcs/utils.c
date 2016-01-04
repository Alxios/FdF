/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:14:39 by agaspar           #+#    #+#             */
/*   Updated: 2016/01/04 17:16:00 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#define DEBUG 1

void	error(char *error)
{
	if (DEBUG == 1)
	{
		ft_putstr("\033[38;5;9m Error > ");
		ft_putendl(error);
	}
	else
		ft_putendl("error");
	exit(EXIT_FAILURE);
}
