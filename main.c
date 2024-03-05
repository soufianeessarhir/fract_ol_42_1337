/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:00:48 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/05 01:09:50 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
double to_scal(double a) 
{ 
	a = ((a /800) * 4) - 2; 
	return(a); 
} 
int check_squaring(double a,double b,f_list *fractol) 
{ 
	double tmp; 
	int i; 
	i = 0; 
	while ((a * a + b *  b < 4) && i < 800) 
	{ 
		tmp = a; 
		a = a*a - b*b +  fractol->x * fractol->zoom_factor; 
		b = 2 * b * tmp + fractol->y* fractol->zoom_factor; 
		i++; 
	} 
	if (i >= 60) 
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
void draw_frct_m(f_list *fractol,t_data *img) 
{ 
	int i; 
	int j; 
	i = 0; 
	j = 0; 
	while (i < 800) 
	{ 
		fractol->x = to_scal(i); 
		while (j < 800) 
		{ 
			fractol->y = to_scal(j); 
			if (check_squaring(fractol->x,fractol->y,fractol) == 1) 
				my_mlx_pixel_put(img, i, j, 0x00ffffff); 
			else 
				my_mlx_pixel_put(img, i, j, 0x0000FF00); 
			j++; 
		} 
		j = 0; 
		i++; 
	} 
} 
int mouse_hook(int keycode, int x, int y, f_list **fractol) 
{ 
    double zoom_amount = 0.1; 
	(void)x; 
	(void)y; 
    if (keycode == 4) 
        (*fractol)->zoom_factor *= (1 + zoom_amount); 
    else if (keycode == 5 && (*fractol)->zoom_factor > 0.1) 
        (*fractol)->zoom_factor /= (1 + zoom_amount); 
    return 0; 
} 
int main(int ac , char **av) 
{ 
	(void)(ac); 
	(void)(av); 
	void *mlx; 
	void *mlx_win; 
	t_data img; 
	f_list *fractol; 
	fractol = malloc(sizeof(f_list)); 
	fractol->zoom_factor = 1; 
	mlx = mlx_init(); 
	mlx_win =  mlx_new_window(mlx, 800, 800, "Hello world!"); 
	img.img = mlx_new_image(mlx, 800, 800); 
	img.addr = mlx_get_data_addr(img.img,&img.bits_per_pixel,&img.line_length,&img.endian); 
	draw_frct_m(fractol,&img); 
	mlx_mouse_hook(mlx_win, mouse_hook, &fractol); 
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); 
	mlx_loop(mlx); 
}