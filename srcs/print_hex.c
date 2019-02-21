/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:50:38 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/15 10:39:51 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			padding_hex(t_flag *struc, char *str)
{
	if ((size_t)struc->prec <= ft_strlen(str) && struc->prec_default == 0)
		struc->pad_zeroes = 0;
	if (struc->pad_zeroes == 1)
	{
		while (struc->pad-- > 0)
			struc->i += ft_putchar_fd('0', struc->fd);
	}
	else
	{
		while (struc->pad-- > 0)
			struc->i += ft_putchar_fd(' ', struc->fd);
	}
	return (0);
}

static int	prec_null(t_flag *struc)
{
	if (struc->min && (struc->pad_zeroes == 0
		|| (struc->prec_default == 0 && struc->prec == 0)))
	{
		while (struc->min-- > 0)
			struc->i += ft_putchar_fd(' ', struc->fd);
	}
	else
	{
		while (struc->prec-- > 0
				|| (struc->min-- > 0 && struc->pad_zeroes == 1))
			struc->i += ft_putchar('0');
	}
	return (0);
}

char		*ft_pad_hash(char *str, t_flag *struc)
{
	if (struc->force_prefix == 1 && struc->conv == 'x'
			&& (struc->pad_zeroes == 1
				&& (struc->prec >= struc->min - 2
					|| struc->prec_default == 1)))
		struc->pad -= ft_putnstr("0x", 2);
	else if (struc->force_prefix == 1 && struc->conv == 'x'
			&& (struc->pad_zeroes == 0
				&& ((struc->prec >= struc->min - 2)
					|| struc->prec >= (int)ft_strlen(str))))
		struc->pad -= ft_putnstr("0x", 2);
	else if (struc->force_prefix == 1 && struc->conv == 'X'
			&& (struc->pad_zeroes == 1 || struc->prec >= 0))
		struc->pad -= ft_putnstr_fd("0X", 2, struc->fd);
	else if (struc->force_prefix == 1 && struc->conv == 'x'
			&& (struc->pad_zeroes == 0 || struc->prec == 0))
		str = ft_strjoinfree("0x", str);
	else if (struc->force_prefix == 1 && struc->conv == 'X'
			&& struc->pad_zeroes == 0)
		str = ft_strjoinfree("0X", str);
	return (str);
}

char		*ft_hex_prec(char *str, t_flag *struc)
{
	int		p;

	p = struc->prec - ft_strlen(str);
	while (p-- > 0)
		str = ft_strjoinfree("0", str);
	return (str);
}

int			ft_print_hex(char *str, t_flag *struc)
{
	if (ft_strcmp("0", str) == 0 && struc->prec_default == 1
		&& struc->min == 0)
		return (ft_putnstr_fd("0", 1, struc->fd));
	if (*str == '0')
		return (prec_null(struc));
	str = ft_pad_hash(str, struc);
	if (struc->pad < 0)
		struc->i += 2;
	if (struc->prec > (int)ft_strlen(str))
		str = ft_hex_prec(str, struc);
	struc->pad += ft_max_int(0, struc->min - ft_strlen(str));
	if (struc->right_pad == 1)
		struc->i += ft_putnstr_fd(str, ft_strlen(str), struc->fd);
	struc->i += padding_hex(struc, str);
	if (struc->right_pad == 0)
		struc->i += ft_putnstr_fd(str, ft_strlen(str), struc->fd);
	free(str);
	return (0);
}
