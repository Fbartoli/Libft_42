/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_csp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:09:23 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 14:10:43 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_c(va_list *params, t_flag *struc)
{
	wint_t	c;

	if (struc->taille == L || struc->conv == 'C')
		c = (wchar_t)va_arg(*params, wint_t);
	else
		c = (char)va_arg(*params, int);
	return (c);
}

void		*conv_s(va_list *params, t_flag *struc)
{
	void	*s;

	if (struc->taille == L)
		s = (wchar_t *)va_arg(*params, wchar_t *);
	else
		s = (char *)va_arg(*params, char *);
	return (s);
}

uintmax_t	get_type(va_list *params, t_flag *struc)
{
	uintmax_t n;

	if (struc->taille == HH)
		n = (unsigned char)va_arg(*params, unsigned int);
	else if (struc->taille == H)
		n = (unsigned short)va_arg(*params, unsigned int);
	else if (struc->taille == LL)
		n = (unsigned long long)va_arg(*params, unsigned long long int);
	else if (struc->taille == L)
		n = (unsigned long)va_arg(*params, unsigned long int);
	else if (struc->taille == J)
		n = (uintmax_t)va_arg(*params, uintmax_t);
	else if (struc->taille == Z)
		n = (size_t)va_arg(*params, size_t);
	else
		n = (unsigned int)va_arg(*params, unsigned int);
	n = (uintmax_t)n;
	return (n);
}

void		*gestion_p(char *hex, uintmax_t s, t_flag *struc, int p)
{
	if (p)
	{
		p -= (int)ft_strlen(hex);
		while (p-- > 0)
			hex = ft_strjoinfree("0", hex);
	}
	if (s == 0 && (!struc->prec && struc->prec_default == 1))
	{
		free(hex);
		return ("0x0");
	}
	hex = ft_strjoinfree("0x", hex);
	return (hex);
}

void		*conv_p(va_list *params, t_flag *struc)
{
	uintmax_t	s;
	char		*hex;
	int			p;

	p = struc->prec;
	if (struc->conv == 'x' || struc->conv == 'X')
		s = get_type(params, struc);
	else
		s = (uintmax_t)va_arg(*params, void *);
	if (s == 0 && struc->conv != 'p')
		return ("0");
	hex = ft_itoa_base_hex(s, struc->taille, struc->conv);
	if (struc->conv == 'p')
		hex = gestion_p(hex, s, struc, p);
	return (hex);
}
