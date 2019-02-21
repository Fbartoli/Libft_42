/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:22:26 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/04 15:06:47 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(long n)
{
	int i;

	i = 0;
	if (n == -9223372036854775807 - 1)
	{
		i += ft_putnbr(-9);
		i += ft_putnbr(223372036854775808);
	}
	else if (n < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar((char)(n + 48));
	return (i);
}
