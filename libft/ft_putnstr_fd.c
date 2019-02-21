/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:10:45 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/09 17:18:44 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr_fd(char *str, int len, int fd)
{
	int i;

	i = 0;
	if (!str || len <= 0)
		return (0);
	while (i < len && *str)
		ft_putchar_fd(str[i++], fd);
	return (i);
}
