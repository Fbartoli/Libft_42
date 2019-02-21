/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:01:33 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/11 18:17:22 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	n_long;

	n_long = n;
	len = ft_nbrlen(n_long);
	if (!(s = (char *)malloc(len + 1)))
		return (NULL);
	*s = n_long < 0 ? '-' : '0';
	if (n_long < 0)
		n_long *= -1;
	*(s + len) = '\0';
	while (len > (*s == '-' ? 1 : 0))
	{
		if (n_long >= 10)
		{
			*(s + --len) = n_long % 10 + '0';
			n_long /= 10;
		}
		else
			*(s + --len) = '0' + n_long;
	}
	return (s);
}
