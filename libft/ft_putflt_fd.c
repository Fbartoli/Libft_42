/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflt_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:13:02 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/16 13:14:24 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "float.h"

static float	ft_fabs(float f)
{
	f = (f < 0 ? -f : f);
	return (f);
}

int				print_decimals(long double nbr, int p, int fd)
{
	int			count;
	float		r;
	long long	l;

	count = 0;
	r = 0.5;
	write(fd, ".", 1);
	count += 1;
	if (p <= 6 && nbr > 0)
		nbr += 0.0000001;
	while (p--)
	{
		nbr = nbr * 10;
		l = (long long)nbr;
		nbr = nbr - l;
		if (nbr >= r && p == 0)
			count += ft_putchar_fd(l + 1 + 48, fd);
		else
			count += ft_putnbr_fd(l, fd);
	}
	return (count);
}

int				ft_putflt_fd(long double nbr, int p, int fd, int hash)
{
	long long	l;
	float		r;
	int			count;

	l = (long long)nbr;
	r = 0.51;
	count = 0;
	if ((ft_fabs(nbr - l) >= r) && (p == 0))
		l = ((l > 0) ? l + 1 : l - 1);
	count = ft_putnbr_fd(l, fd);
	nbr = ft_fabs(nbr - l);
	if (nbr >= 0 && (p || hash))
		count += print_decimals(nbr, p, fd);
	return (count);
}
