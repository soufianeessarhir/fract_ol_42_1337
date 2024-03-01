/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:00:48 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/01 19:48:32 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
int to_scal(int a)
{
	return((a * 4)/(800 - 2));
}
int check_squaring(int a,int b,f_list *fractol)
{
	int tmp;
	int i;
	i = 0;
	while (a*a + b * b < 4 && i < 80)
	{
		tmp = a;
		a = a*a - b*b + fractol->x;
		b = 2 * b * tmp + fractol->y;
		i++;
	}
	if (i >= 80)
		return(1);
	else
		return (0);
	
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void draw_frct(f_list *fractol,t_data *img)
{
	int i;
	int j;
	while (i < 800)
	{
		fractol->x = to_scal(i);
		while (j < 800)
		{
			fractol->y = to_scal(j);
			if (check_squaring(fractol->x,fractol->y,fractol) == 0)
				
				my_mlx_pixel_put(img, 5, 5, 0x00ffffff);
			else
				my_mlx_pixel_put(img, 5, 5, 0x0000FF00);
			j++;
		}
		j = 0;
		i++;
	}
	
}
int main(int ac , char **av)
{
	(void)(ac);
	(void)(av);
	void *mlx;
	void *mlx_win;
	t_data img;
	f_list *fractol;
	
	mlx = mlx_init();
	mlx_win =  mlx_new_window(mlx, 800, 800, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img,&img.bits_per_pixel,&img.line_length,&img.endian);
	draw_frct(fractol,&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}