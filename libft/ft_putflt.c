/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:15:14 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/08 20:12:25 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	ft_fabs(float f)
{
	f = (f < 0 ? -f : f);
	return (f);
}

int				print_decimals(long double nbr, int p)
{
	int			count;
	float		r;
	long long	l;

	count = 0;
	r = 0.5;
	write(1, ".", 1);
	count += 1;
	while (p--)
	{
		nbr = nbr * 10 + 0.000001;
		l = (long long)nbr;
		nbr = nbr - l;
		if (nbr >= r && p == 0)
			count += ft_putchar(l + 48);
		else
			count += ft_putnbr(l);
	}
	return (count);
}

int				ft_putflt(long double nbr, int p)
{
	long long	l;
	float		r;
	int			count;

	l = (long long)nbr;
	r = 0.5;
	count = 0;
	if ((ft_fabs(nbr - l) >= r) && (p == 0))
		l = ((l > 0) ? l + 1 : l - 1);
	count = ft_putnbr(l);
	nbr = ft_fabs(nbr - l);
	if (nbr > 0 && p != 0)
		count += print_decimals(nbr, p);
	return (count);
}
