#include <mlx.h>
#include <libft.h>
#include <unistd.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

void	draw(void *mlx, void *win)
{
	int y;
	int x;

	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF00000);
			x++;
		}
		y++;
	}

}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		main(int ac, char **av)
{
	ac = 0;
	av = 0;
	t_env e;

	ft_putstr("coucou");
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 480, 220, "Attention un renard");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
