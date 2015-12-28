/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaspar <agaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:48:30 by agaspar           #+#    #+#             */
/*   Updated: 2015/12/28 16:59:40 by agaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>
#include <time.h>
#include <stdlib.h>

int		expose_hook(t_env *e)
{
	draw_cube(e, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (e)
	{
		ft_putendl("--mouse--");
		ft_putstr("button :");
		ft_putnbr(button);
		ft_putchar('\n');
		ft_putstr("x :");
		ft_putnbr(x);
		ft_putstr(", y :");
		ft_putnbr(y);
		ft_putchar('\n');
	}
	return (0);
}

int		loop_hook(void)
{
	static clock_t	lastime;
	static int		i;
	clock_t			times;

	times = clock();
	i++;
	if (times/CLOCKS_PER_SEC - lastime/CLOCKS_PER_SEC >= 1.0)
	{
		lastime = clock();
		ft_putstr("fps :");
		ft_putnbr(i);
		ft_putchar('\n');
		i = 0;
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		e->zoom += 1;
	else if(keycode == 125)
		e->zoom -= 1;
	expose_hook(e);
	return (0);
}


