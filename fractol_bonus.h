/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:01:30 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/10 12:42:46 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
#define FRACTOL_BONUS_H

#include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

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
	double r_j;
	double i_j;
	char j;
	int if3d;
	
}t_list;

typedef struct d_atod
{
	double result;
    double  decimal_place;
   	double         sign;
}t_atod;


int		main(int ac , char **av);
int		get_color(int iter,t_list *fractol);
void	my_mlx_pixel_put(t_list *data, int x, int y, int color);
void	rebuild(t_list *fractol);
void	draw_frct_m(t_list *fractol);
double	map(double x, double in_min, double in_max, double out_min, double out_max); 
t_list	init_data_fractol(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atod(char *str);
int ft_parcing(char *av);
size_t	ft_strlen(const char *s);
int mouse_hook(int keycode, int x, int y, t_list *fractol) ;
int key_hook(int keycode, t_list *fractol);
int destroy(t_list *fractol);
void which_fract();
int	ft_strncmp(const char *s1, const char *s2, size_t n);


#endif