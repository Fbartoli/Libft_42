/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:05:52 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 14:06:17 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		lettre_convert(char conv)
{
	if (conv == 'p' || conv == 'x')
		return ('a');
	else
		return ('A');
}

char			*ft_itoa_base_hex(uintmax_t num, int taille, char conv)
{
	int		i;
	char	*str;
	char	*hash;
	char	lettre;

	i = 0;
	while ((uintmax_t)(ft_pow(16, i) - 1) < num)
		i++;
	if ((str = (char *)malloc(sizeof(str) * (i + 1))) == NULL)
		return (NULL);
	str[i] = '\0';
	lettre = lettre_convert(conv);
	while (i-- > 0)
	{
		str[i] = (num % 16) + (num % 16 > 9 ? lettre - 10 : '0');
		num = num / 16;
	}
	if (conv == 'p' || taille == 2 || taille == 1)
	{
		hash = ft_hash(num, 16, lettre);
		str = ft_strjoinfree(hash, str);
		free(hash);
	}
	return (str);
}
