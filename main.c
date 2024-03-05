/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:00:48 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/05 02:52:42 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
double to_scal(double a,f_list fractol) 
{ 
	a = ((a /800) * 4) - 2; 
	return(a* fractol.zoom_factor); 
} 
int check_squaring(double a,double b,f_list *fractol) 
{ 
	double tmp; 
	int i; 
	i = 0; 
	while ((a * a + b *  b < 4) && i < 800) 
	{ 
		tmp = a; 
		a = a*a - b*b +  fractol->x; 
		b = 2 * b * tmp + fractol->y; 
		i++; 
	} 
	if (i >= 60) 
		return(1); 
	else 
		return (0); 
} 
void	my_mlx_pixel_put(f_list *data, int x, int y, int color) 
{ 
	char	*dst; 
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); 
	*(unsigned int*)dst = color; 
} 
void draw_frct_m(f_list *fractol) 
{ 
	int i; 
	int j; 
	i = 0; 
	j = 0; 
	while (i < 800) 
	{ 
		fractol->x = to_scal(i,*fractol); 
		while (j < 800) 
		{ 
			fractol->y = to_scal(j,*fractol); 
			if (check_squaring(fractol->x,fractol->y,fractol) == 1) 
				my_mlx_pixel_put(fractol, i, j, 0x00ffffff); 
			else 
				my_mlx_pixel_put(fractol, i, j, 0x000000ff); 
			j++; 
		} 
		j = 0; 
		i++; 
	} 
	mlx_put_image_to_window((*fractol).mlx,(*fractol).mlx_win, (*fractol).img, 0, 0); 
	
} 
int mouse_hook(int keycode, int x, int y, f_list *fractol) 
{ 
    double zoom_amount = 0.1; 
	(void)x; 
	(void)y; 
    if (keycode == 4) 
      	fractol->zoom_factor *= (1 + zoom_amount); 
    else if (keycode == 5 ) 
        fractol->zoom_factor /= (1 + zoom_amount); 
	draw_frct_m(fractol); 
    return 0; 
} 
int main(int ac , char **av) 
{ 
	(void)(ac); 
	(void)(av); 
 
	f_list fractol; 
	// fractol = malloc(sizeof(f_list)); 
	fractol.zoom_factor = 1; 
	fractol.mlx = mlx_init(); 
	fractol.mlx_win =  mlx_new_window(fractol.mlx, 800, 800, "Hello world!"); 
	fractol.img = mlx_new_image(fractol.mlx, 800, 800); 
	fractol.addr = mlx_get_data_addr(fractol.img,&fractol.bits_per_pixel,&fractol.line_length,&fractol.endian); 
	mlx_mouse_hook(fractol.mlx_win, mouse_hook, &fractol); 
	draw_frct_m(&fractol); 
	mlx_loop(fractol.mlx); 
}