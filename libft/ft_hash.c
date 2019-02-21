/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:29:06 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/05 18:57:02 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hash(uintmax_t num, uintmax_t base, char lettre)
{
	int			i;
	char		*hash;
	uintmax_t	val;

	val = num;
	i = 0;
	while (val > 0)
	{
		val = val / base;
		i++;
	}
	if ((hash = (char *)malloc(sizeof(hash) * (i + 1))) == NULL)
		return (NULL);
	hash[i] = '\0';
	while (i--)
	{
		hash[i] = (num % base) + (num % base > 9 ? lettre - 10 : '0');
		num = num / base;
	}
	return (hash);
}
