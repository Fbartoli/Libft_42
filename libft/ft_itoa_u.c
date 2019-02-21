/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:49:01 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/01 13:40:44 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_u(uintmax_t n)
{
	char	*str;
	int		len;
	long	n_long;

	n_long = n;
	len = ft_nbrlen(n_long);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	*str = n_long < 0 ? '-' : '0';
	if (n_long < 0)
		n_long *= -1;
	*(str + len) = '\0';
	while (len > (*str == '-' ? 1 : 0))
	{
		if (n_long >= 10)
		{
			*(str + --len) = n_long % 10 + '0';
			n_long /= 10;
		}
		else
			*(str + --len) = '0' + n_long;
	}
	return (str);
}
