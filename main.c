/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:00:48 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/28 23:41:57 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_squaring(double a, double b, t_list *fractol)
{
	double	tmp;
	int		i;

	i = 0;
	while ((a * a + b * b <= fractol->r_max * fractol->r_max) && i < 80)
	{
		tmp = a;
		a = a * a - b * b;
		b = 2 * b * tmp;
		if (fractol->j == 'j')
		{
			a += fractol->r_j;
			b += fractol->i_j;
		}
		else
		{
			a += fractol->x;
			b += fractol->y;
		}
		i++;
	}
	fractol->color = i;
	return (i);
}

void	draw_frct_m(t_list *fractol)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 800)
	{
		fractol->x = map(i, 800, fractol->r_min,
				fractol->r_max) * fractol->zoom_factor;
		while (j < 800)
		{
			fractol->y = map(800 - j, 800, fractol->i_min,
					fractol->i_max) * fractol->zoom_factor;
			if (check_squaring(fractol->x, fractol->y, fractol) <= 0)
				my_mlx_pixel_put(fractol, i, j,
					get_color(fractol->color, fractol) >> 16);
			else
				my_mlx_pixel_put(fractol, i, j,
					get_color(fractol->color, fractol) >> 2);
			j++;
		}
		j = 0;
		i++;
	}
}

void	draw_julia(int ac, char **av, t_list *fractol)
{
	if (ac == 2)
	{
		fractol->j = 'j';
		draw_frct_m(fractol);
	}
	else if (ft_parcing(av[2]) && ft_parcing(av[3]) && ac == 4)
	{
		fractol->j = 'j';
		fractol->r_j = ft_atod(av[2]);
		fractol->i_j = ft_atod(av[3]);
		draw_frct_m(fractol);
	}
	else
		which_fract();
}

int	main(int ac, char **av)
{
	t_list	fractol;

	if (ac > 1 && ac < 5)
	{
		fractol = init_data_fractol();
		if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
			draw_frct_m(&fractol);
		else if ((ac == 2 || ac == 4) && ft_strcmp(av[1], "julia") == 0)
			draw_julia(ac, av, &fractol);
		else
			which_fract();
		mlx_mouse_hook(fractol.mlx_win, mouse_hook, &fractol);
		mlx_key_hook (fractol.mlx_win, &key_hook, &fractol);
		mlx_hook(fractol.mlx_win, 17, 0, &destroy, &fractol);
		mlx_put_image_to_window((fractol).mlx, (fractol).mlx_win,
			(fractol).img, 0, 0);
		mlx_loop(fractol.mlx);
	}
	else
		which_fract();
	return (0);
}
