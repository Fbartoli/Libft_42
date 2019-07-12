/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:35:26 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 15:10:44 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*conv_u(va_list *params, t_flag *struc)
{
	uintmax_t	s;
	char		*str;

	s = get_type(params, struc);
	str = ft_itoa_u(s);
	return (str);
}
