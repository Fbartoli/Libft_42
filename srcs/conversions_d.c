/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:49:11 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/07 09:00:13 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long			conv_d(va_list *params, t_flag *struc)
{
	if (!struc->taille)
		return (va_arg(*params, int));
	if (struc->taille == L || struc->taille == LL
	|| struc->taille == J || struc->conv == 'D')
		return (va_arg(*params, long));
	else if (struc->taille == HH)
		return ((char)va_arg(*params, int));
	else if (struc->taille == H)
		return ((short)va_arg(*params, int));
	else
		return (va_arg(*params, size_t));
}

unsigned long	conv_ud(va_list *params, t_flag *struc)
{
	if (!struc->taille)
		return (va_arg(*params, unsigned int));
	else if (struc->taille == L || struc->taille == LL || struc->taille == J)
		return (va_arg(*params, unsigned long));
	else if (struc->taille == H)
		return ((unsigned short)va_arg(*params, unsigned int));
	else if (struc->taille == HH)
		return ((unsigned char)va_arg(*params, unsigned int));
	else
		return (va_arg(*params, ssize_t));
}

long double		conv_f(va_list *params, t_flag *struc)
{
	if (!struc->taille || struc->taille == L)
		return (va_arg(*params, double));
	else if (struc->prec == 0)
		return (va_arg(*params, long));
	else if (struc->taille == LLL)
		return (va_arg(*params, long double));
	else
		return (va_arg(*params, double));
}
