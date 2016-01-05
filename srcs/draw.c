/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:40:21 by agaspar           #+#    #+#             */
/*   Updated: 2016/01/05 19:00:39 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

void	draw_cube(t_env *e, int pos_x, int pos_y)
{
	int size = 8 + e->zoom * 1;
	double	xPos;
	double	yPos;
	double	x;
	double	y;

	xPos = ((e->height) + ((size * 19)) - size) / 2;
	yPos = ((e->width) + ((size * 11)) - size) / 2;
	x = xPos + pos_x * size;
	y = yPos + pos_y * size;
 	/*if (x > 0 && x < e->height && y > 0 && y < e->width)
	{*/
		printf("size :%d, x :%f, y :%f\n", size, x, y);
		mlx_pixel_put(e->mlx, e->win, x, y, rgb_color(255, 0, 0));
	/*}*/
}

void	draw_plan(t_env *e)
{
	t_pos	*tmp;
	tmp = e->pos;
	while (tmp)
	{
		draw_cube(e, tmp->x, tmp->y);
		tmp = tmp->next;
	}
}

