/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sessarhi <sessarhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 06:13:34 by sessarhi          #+#    #+#             */
/*   Updated: 2024/03/09 06:56:53 by sessarhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str)
{
	double	nb;
	double	n;
	int			s;

	nb = 0;
	s = 1;
	n = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str && ((*str >= '0' && *str <= '9') || *str == '.'))
	{
		if (*str == '.')
		{
			n = 10;
			str++;
		}
		nb = nb * 10 + (*str - '0') / n;
		str++;
	}
	return (s * nb);
}
