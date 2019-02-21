/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:22:26 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/09 15:39:09 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrpf(long nb, int prec, int fd)
{
	short count;

	if (prec > 0)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = -nb;
		}
		count = ft_nbrlen(nb);
		count = prec - count;
		while (count-- > 0)
			ft_putchar_fd('0', fd);
	}
	if (nb || prec)
		ft_putnbr_fd(nb, fd);
}
