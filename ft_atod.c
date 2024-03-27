/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 06:13:34 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/27 03:21:58 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_sp_nl(char *av)
{
	int	j;

	j = 0;
	while ((av[j] >= 9 && av[j] <= 13) || av[j] == 32)
		j++;
	if (av[j] == '\0')
		return (0);
	return (1);
}

int	ft_parcing(char *av)
{
	int	j;
	int	flag;

	flag = 0;
	j = 0;
	if (check_sp_nl(av) == 0)
		return (0);
	while ((av[j] >= 9 && av[j] <= 13) || av[j] == 32)
		j++;
	if (av[j] == '-' || av[j] == '+')
		j++;
	while (av[j])
	{
		if (av[j] == '.' && j != 0)
		{
			flag++;
			j++;
		}
		if ((ft_isdigit(av[j]) == 0 && av[j] != '\0') || flag > 1)
			return (0);
		j++;
	}
	return (1);
}

char	*skiping(char *str, t_atod *f)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			f->sign = -1;
		str++;
	}
	return (str);
}

double	ft_atod(char *str)
{
	t_atod	f;

	f.result = 0.0;
	f.sign = 1.0;
	f.decimal_place = 0.0;
	str = skiping(str, &f);
	while (*str != '\0' && ((*str >= '0' && *str <= '9') || *str == '.'))
	{
		if (*str == '.')
			f.decimal_place = 1;
		else
		{
			f.result = f.result * 10.0 + (*str - '0');
			if (f.decimal_place != 0)
				f.decimal_place *= 10.0;
		}
		str++;
	}
	if (f.decimal_place == 0.0)
		f.decimal_place = 1;
	return (f.sign * f.result / f.decimal_place);
}
