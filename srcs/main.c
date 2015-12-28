#include <mlx.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	size_t	height;
	size_t	width;
	float	zoom;
	float	cam_x;
	float	cam_y;
}				t_env;

int		rgb_color(int red, int green, int blue)
{
	int	res;

	res = red * 65536 + green * 256 + blue;
	return (res);
}



void	draw_cube(t_env *e, int pos_x, int pos_y)
{
	int size = 64 + e->zoom * 10;
	int	xPos;
	int	yPos;
	int	y = 0;
	int	x = 0;

	xPos = (e->height / 2) - size / 2  + pos_x * size;
	yPos = (e->width / 2) - size/ 2 + pos_y * size;
	while (y++ < size)
	{
		x = 0;
		while (x++ < size)
		{
			mlx_pixel_put(e->mlx, e->win, xPos + x , yPos + y, rgb_color(x, y, 100));
		}
	}
}

/*void	draw_plan(t_env *e)
{
	//int	xPos;
	int	yPos;
	int	y = 0;
	//int	x = 0;

	//xPos = (e->height / 2) - 32 / 2;
	yPos = (e->width / 2) - 32 / 2;
	while (y++ < e->width / 32)
	{
		x = 0;
		while (x++ > e->height)
			mlx_pixel_put(e->mlx, e->win, x, yPos
	}
}*/

int		expose_hook(t_env *e)
{
	draw_cube(e, 0, 0);
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

int		main(void)
{
	t_env e;

	e.height = 420;
	e.width = 420;
	e.zoom = 1;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.height, e.width, "Attention un renard");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
