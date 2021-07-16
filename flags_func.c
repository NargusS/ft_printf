/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:04:24 by achane-l          #+#    #+#             */
/*   Updated: 2021/07/14 12:04:28 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->space = 0;
	flags->sharp = 0;
	flags->number_sign = 0;
}

void	append_flags(t_flags *flags, char c)
{
	if (c == '0' && flags->minus == 0)
		flags->zero++;
	else if (c == '-')
	{
		flags->minus++;
		if (flags->zero > 0)
			flags->zero = 0;
	}
	else if (c == '+')
		flags->number_sign++;
	else if (c == ' ')
		flags->space++;
	else if (c == '#')
		flags->sharp++;
}

void	change_state_flags(t_flags *flags)
{
	if (flags->precision >= 0)
		flags->zero = 0;
	if (flags->width < 0)
	{
		flags->zero = 0;
		flags->minus += 1;
		flags->width = -(flags->width);
	}
}
