/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:28:53 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/14 09:21:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_struc(t_flag *struc)
{
	struc->force_prefix = 0;
	struc->force_sign = 0;
	struc->pad_zeroes = 0;
	struc->right_pad = 0;
	struc->blank_sign = 0;
	struc->min = 0;
	struc->prec = 0;
	struc->taille = 0;
	struc->conv = '\0';
	struc->is_neg = 0;
	struc->prec_default = 1;
	struc->pad = 0;
}

static void		ft_print(t_flag *struc, va_list *params)
{
	if (struc->conv == 's')
		ft_print_str(conv_s(params, struc), struc);
	else if (struc->conv == 'd' || struc->conv == 'i')
		struc->i += ft_print_d(conv_d(params, struc), struc);
	else if (struc->conv == 'c')
		ft_print_c(conv_c(params, struc), struc);
	else if (struc->conv == 'f' || struc->conv == 'F')
		struc->i += ft_print_f(conv_f(params, struc), struc);
	else if (struc->conv == 'S')
		ft_print_str(conv_unicode(params), struc);
	else if (struc->conv == 'C')
		ft_print_str(conv_unicode_single(params, struc), struc);
	else if (struc->conv == 'x' || struc->conv == 'X')
		struc->i += ft_print_hex(conv_p(params, struc), struc);
	else if (struc->conv == 'p')
		ft_print_p(conv_p(params, struc), struc);
	else if (struc->conv == 'u')
		struc->i += ft_print_ud(conv_ud(params, struc), struc);
	else if (struc->conv == 'b')
		ft_print_str(conv_b(params), struc);
	else if (struc->conv == '%')
		ft_print_per('%', struc);
	else if (struc->conv == 'o')
		struc->i += ft_print_o(conv_ud(params, struc), struc);
}

static int		my_printf(char *str, t_flag *struc, va_list *params)
{
	struc->i = 0;
	while (*str)
	{
		if (*str != '%')
			struc->i += ft_putchar_fd(*str, struc->fd);
		else
		{
			if (*(str + 1) == '\0')
				return (struc->i);
			init_struc(struc);
			str = parser(str, struc, params);
			if (*str == '\0')
				return (struc->i);
			if (struc->conv == '\0')
				ft_print_c(*str, struc);
			ft_print(struc, params);
		}
		str++;
	}
	return (struc->i);
}

int				ft_printf(const char *format, ...)
{
	t_flag	struc;
	int		nb_char;
	char	*start;
	va_list params;

	if ((start = (char *)format) == NULL)
		return (-1);
	struc.fd = 1;
	nb_char = 0;
	init_struc(&struc);
	va_start(params, format);
	nb_char = my_printf(start, &struc, &params);
	va_end(params);
	return (nb_char);
}

int				ft_printfd(int fd, const char *format, ...)
{
	t_flag	struc;
	int		nb_char;
	char	*start;
	va_list params;

	start = (char *)format;
	struc.fd = fd;
	nb_char = 0;
	init_struc(&struc);
	va_start(params, format);
	nb_char = my_printf(start, &struc, &params);
	va_end(params);
	return (nb_char);
}
