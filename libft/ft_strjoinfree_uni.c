/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree_uni.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:48:27 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 14:20:16 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree_uni(char *s1, char *s2)
{
	char *string;

	if (!s1 || !s2)
		return (NULL);
	if (!(string = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(string, s1);
	ft_strcpy(&string[ft_strlen(s1)], s2);
	free(s2);
	free(s1);
	return (string);
}
