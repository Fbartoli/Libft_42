/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:14:38 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/14 18:23:40 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	inf(t_flag *struc)
{
	int count;

	count = 0;
	while ((struc->min) - 3 > 0 && !struc->right_pad)
	{
		count += ft_putchar_fd(' ', struc->fd);
		struc->min--;
	}
	write(struc->fd, "inf", 3);
	while ((struc->min) - 3 > 0 && struc->right_pad)
	{
		count += ft_putchar_fd(' ', struc->fd);
		struc->min--;
	}
	return (count + 3);
}

static int	minus_inf(t_flag *struc)
{
	int count;

	count = 0;
	while ((struc->min) - 4 > 0 && !struc->right_pad)
	{
		count += ft_putchar_fd(' ', struc->fd);
		struc->min--;
	}
	write(struc->fd, "-inf", 4);
	while ((struc->min) - 4 > 0 && struc->right_pad)
	{
		count += ft_putchar_fd(' ', struc->fd);
		struc->min--;
	}
	return (count + 4);
}

static int	nan(t_flag *struc)
{
	int count;

	count = 0;
	while ((struc->min) - 3 > 0 && !struc->right_pad)
	{
		count += ft_putchar_fd(' ', struc->fd);
		struc->min--;
	}
	write(struc->fd, "nan", 3);
	while ((struc->min) - 3 > 0 && struc->right_pad)
	{
		count += ft_putchar_fd(' ', struc->fd);
		struc->min--;
	}
	return (count + 3);
}

int			specialf_cases(t_flag *struc, long double nb)
{
	int count;

	count = 0;
	if (nb == 1.0 / 0.0)
		count += inf(struc);
	else if (nb == -1.0 / 0.0)
		count += minus_inf(struc);
	else
		count += nan(struc);
	return (count);
}
