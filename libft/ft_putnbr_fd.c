/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:46:00 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/09 15:37:34 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(long n, int fd)
{
	int i;

	i = 0;
	if (n == -9223372036854775807 - 1)
	{
		i += ft_putnbr_fd(-9, fd);
		i += ft_putnbr_fd(223372036854775808, fd);
	}
	else if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		i += ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		i += ft_putnbr_fd(n / 10, fd);
		i += ft_putnbr_fd(n % 10, fd);
	}
	else
		i += ft_putchar_fd((char)(n + 48), fd);
	return (i);
}
