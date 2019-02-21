/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:30:07 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/05 16:45:11 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbchar(const char *s, int c)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}
