/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:23 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/08 18:56:01 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	default_setting(t_flag *struc)
{
	convup_to_min(struc);
	if (struc->conv == 'f' && (struc->prec_default == 1))
		struc->prec = 6;
	else if (struc->conv == 'c' && (struc->min == 0))
		struc->min = 1;
	if (struc->pad_zeroes == 1 && struc->right_pad == 1)
		struc->pad_zeroes = 0;
	if (struc->blank_sign == 1 && struc->force_sign == 1)
		struc->blank_sign = 0;
}

static char	*parse_flags(char *str, t_flag *struc)
{
	while (is_flag(*str) == 1)
	{
		if (*str == '#')
			struc->force_prefix = 1;
		else if (*str == '+')
			struc->force_sign = 1;
		else if (*str == '-')
			struc->right_pad = 1;
		else if (*str == ' ')
			struc->blank_sign = 1;
		else if (*str == '0')
			struc->pad_zeroes = 1;
		str++;
	}
	return (str);
}

static char	*input_field_prec(char *str, t_flag *struc, va_list *params)
{
	struc->min = 0;
	while (*str >= '0' && *str <= '9')
		str = get_min(str, struc, params);
	if (*str == '.' && *(str + 1) >= '0' && *(str + 1) <= '9')
	{
		str++;
		struc->prec = 0;
		while (*str >= '0' && *str <= '9')
			struc->prec = (struc->prec) * 10 + (*(str++) - '0');
		struc->prec_default = 0;
	}
	if (*str == '.' && !(*(str + 1) >= '0' && *(str + 1) <= '9'))
	{
		str++;
		struc->prec_default = 0;
	}
	return (str);
}

static char	*input_to_struct(char *str, t_flag *struc, va_list *params)
{
	if (is_flag(*str) == 1)
		str = parse_flags(str, struc);
	while (ft_is_space(*str) == 1)
		str++;
	if (*str == '*')
	{
		struc->min = va_arg(*params, int);
		str++;
	}
	if ((*str >= '0' && *str <= '9') || *str == '.')
		str = input_field_prec(str, struc, params);
	if (*str == '*')
	{
		struc->prec = va_arg(*params, int);
		struc->prec_default = 0;
		str++;
	}
	if (is_taille(*str) == 1)
		str = taille_to_int(str, struc);
	if (is_conv(*str) == 1)
		struc->conv = *str;
	return (str);
}

char		*parser(char *str, t_flag *struc, va_list *params)
{
	str++;
	if (*str == '\0')
		return (str);
	str = input_to_struct(str, struc, params);
	default_setting(struc);
	if (struc->min < 0)
	{
		struc->min = -struc->min;
		struc->right_pad = 1;
	}
	if (struc->prec < 0)
	{
		struc->prec = 0;
		struc->prec_default = 1;
	}
	return (str);
}
