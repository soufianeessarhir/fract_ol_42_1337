/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:01:30 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/09 04:21:32 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
typedef struct s_list
{
	void *mlx; 
	void *mlx_win;
	double           zoom_factor;
	double			x;
	double			y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	double off_x;
	double off_y;
	int height;
	int width;
	double r_max;
	double r_min;
	double i_max;
	double i_min;
	int    r_color;
	
}t_list;


int		main(int ac , char **av);
int		get_color(int iter,t_list *fractol);
void	my_mlx_pixel_put(t_list *data, int x, int y, int color);
void	rebuild(t_list *fractol);
void	draw_frct_m(t_list *fractol);
double	map(double x, double in_min, double in_max, double out_min, double out_max); 
t_list init_data_fractol(void);


#endif