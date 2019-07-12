/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:06:37 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/16 13:06:28 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				check_plus_spacel(long nb, t_flag *struc)
{
	int	count;

	count = 0;
	if (struc->force_sign && nb >= 0)
		count += ft_putchar_fd('+', struc->fd);
	else if (struc->blank_sign && nb >= 0)
		count += ft_putchar_fd(' ', struc->fd);
	return (count);
}

static int		check_complet_charl(long nb, int count,
	char letter, t_flag *struc)
{
	int	tmp;

	if ((struc->min + count) > ft_nbrlen(nb))
	{
		if (letter == ' ' && struc->blank_sign && struc->force_prefix
			&& !struc->right_pad)
			struc->min--;
		if (struc->prec >= ft_nbrlen(nb))
		{
			tmp = struc->min - count - struc->prec;
			if (nb < 0 && !struc->pad_zeroes)
				tmp--;
		}
		else
			tmp = struc->min - count - ft_nbrlen(nb);
		while (tmp-- > 0)
			ft_putchar_fd(letter, struc->fd);
		return (struc->min);
	}
	else
		count += ft_nbrlen(nb);
	return (count);
}

static int		with_min_zero(long nb, t_flag *struc)
{
	int count;

	count = 0;
	if (struc->prec != 0 || struc->prec_default == 0)
	{
		if (struc->force_sign || struc->blank_sign
			|| (struc->pad_zeroes && nb < 0))
			count++;
		count = check_complet_charl(nb, count, ' ', struc);
	}
	count += check_plus_spacel(nb, struc);
	if (nb < 0)
		ft_putchar_fd('-', struc->fd);
	if (struc->prec_default == 1)
		count = check_complet_charl(nb, count, '0', struc);
	if (nb < 0)
		nb = -nb;
	ft_putnbrpf(nb, struc->prec, struc->fd);
	return (count);
}

static int		with_minl(long nb, t_flag *struc)
{
	int count;

	count = 0;
	if (struc->right_pad)
	{
		count += check_plus_spacel(nb, struc);
		ft_putnbrpf(nb, struc->prec, struc->fd);
		count = check_complet_charl(nb, count, ' ', struc);
	}
	else if (struc->pad_zeroes)
		count = with_min_zero(nb, struc);
	else
	{
		if ((struc->force_sign || struc->blank_sign) && nb >= 0)
			count++;
		count = check_complet_charl(nb, count, ' ', struc);
		count += check_plus_spacel(nb, struc);
		if ((struc->force_sign || struc->right_pad) && nb >= 0)
			count--;
		ft_putnbrpf(nb, struc->prec, struc->fd);
	}
	return (count);
}

int				ft_print_d(long nb, t_flag *struc)
{
	int	count;

	count = 0;
	if (!nb && !struc->prec)
		return (nb_null_prec_null(nb, struc));
	if (struc->min)
	{
		count = with_minl(nb, struc);
		if (struc->force_sign == 1 && struc->prec_default == 0)
			count--;
	}
	else
	{
		count = check_plus_spacel(nb, struc) + ft_nbrlen(nb);
		ft_putnbrpf(nb, struc->prec, struc->fd);
		if (struc->prec >= ft_nbrlen(nb))
			count += struc->prec - ft_nbrlen(nb);
	}
	if (nb && struc->prec > ft_nbrlen(nb))
	{
		count = (nb < 0) ? struc->prec + 1 : struc->prec;
		count = (struc->min > struc->prec) ? struc->min : count;
	}
	return (count);
}
