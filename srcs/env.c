/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:03:32 by agaspar           #+#    #+#             */
/*   Updated: 2016/01/05 17:23:26 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>
#include <hook.h>

void	env_init(t_env *e, t_pos *pos)
{
	e->height = 420;
	e->width = 420;
	e->zoom = 1;
	e->pos = pos;

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->height, e->width,
			"Attention un renard");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}

int		rgb_color(int red, int green, int blue)
{
	int	res;

	res = red * 65536 + green * 256 + blue;
	return (res);
}
