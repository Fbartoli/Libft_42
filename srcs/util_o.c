/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:55:43 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/14 17:22:23 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puto(char *str, t_flag *struc)
{
	int i;

	if ((struc->prec != 0) && ((size_t)struc->prec > ft_strlen(str)))
	{
		i = struc->prec - ft_strlen(str);
		while (i--)
			ft_putchar_fd('0', struc->fd);
	}
	if (ft_strlen(str) == 1 && *str == '0'
			&& !struc->prec_default && !struc->prec && !struc->force_prefix)
		return ;
	ft_putstr(str);
}

int		ft_print_o_null(t_flag *struc)
{
	if ((struc->prec_default == 1
		|| (struc->prec_default == 0 && struc->prec != 0)))
		struc->pad = struc->min - struc->prec - 1;
	else
		struc->pad = struc->min - struc->prec;
	if (struc->force_prefix && struc->prec > 0)
	{
		struc->prec--;
		struc->pad++;
	}
	if (struc->right_pad == 0)
		padding(struc);
	if ((struc->prec_default == 1) || (struc->min != 0 && struc->prec != 0)
		|| struc->force_prefix == 1)
		struc->i += ft_putnbr_fd(0, struc->fd);
	if (struc->right_pad == 1)
		padding(struc);
	return (0);
}
