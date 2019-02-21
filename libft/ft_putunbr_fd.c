/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:42:00 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/09 17:11:14 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putunbr_fd(unsigned long n, int fd)
{
	int i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr_fd((n / 10), fd);
		i += ft_putnbr_fd((n % 10), fd);
	}
	else
		i += ft_putchar_fd((char)(n + 48), fd);
	return (i);
}
