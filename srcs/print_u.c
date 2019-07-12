/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:44:49 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/16 13:03:04 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_characters(t_flag *struc)
{
	int count;

	if (struc->prec >= struc->min)
		count = struc->prec;
	else
		count = struc->min;
	return (count);
}

static int		check_complet_charul(unsigned long nb, int count,
	char letter, t_flag *struc)
{
	int	tmp;

	if (ft_unbrlen(nb) < (struc->min + count))
	{
		if (letter == ' ' && struc->blank_sign && struc->force_prefix
			&& !struc->right_pad)
			struc->min--;
		if (struc->prec >= ft_unbrlen(nb))
			tmp = struc->min - count - struc->prec;
		else
			tmp = struc->min - count - ft_unbrlen(nb);
		while (tmp-- > 0)
			ft_putchar_fd(letter, struc->fd);
		return (struc->min);
	}
	else
		count += ft_unbrlen(nb);
	return (count);
}

static int		with_min_zero(unsigned long nb, t_flag *struc)
{
	int count;

	count = 0;
	if (struc->prec != 0 || struc->prec_default == 0)
		count = check_complet_charul(nb, count, ' ', struc);
	if (struc->prec_default == 1)
		count = check_complet_charul(nb, count, '0', struc);
	ft_putunbrpf(nb, struc->prec, struc->fd);
	return (count);
}

static int		with_minul(unsigned long nb, t_flag *struc)
{
	int count;

	count = 0;
	if (struc->right_pad)
	{
		ft_putunbrpf(nb, struc->prec, struc->fd);
		count = check_complet_charul(nb, count, ' ', struc);
	}
	else if (struc->pad_zeroes)
		count = with_min_zero(nb, struc);
	else
	{
		if ((struc->force_sign || struc->blank_sign))
			count++;
		count = check_complet_charul(nb, count, ' ', struc);
		if ((struc->force_sign || struc->right_pad))
			count--;
		ft_putunbrpf(nb, struc->prec, struc->fd);
	}
	return (count);
}

int				ft_print_ud(unsigned long nb, t_flag *struc)
{
	int	count;

	count = 0;
	if (!nb && !struc->prec)
	{
		if (struc->prec_default == 1)
			return (with_plus_zero(nb, struc));
		count = struc->min > 0 ? struc->min : 0;
		while (struc->min-- > 0)
			ft_putchar_fd(' ', struc->fd);
		return (count);
	}
	if (struc->min)
		count = with_minul(nb, struc);
	else
	{
		count = ft_unbrlen(nb);
		ft_putunbrpf(nb, struc->prec, struc->fd);
		if (struc->prec >= ft_unbrlen(nb))
			count += struc->prec - ft_unbrlen(nb);
	}
	if (nb && struc->prec > ft_unbrlen(nb))
		count = count_characters(struc);
	return (count);
}
