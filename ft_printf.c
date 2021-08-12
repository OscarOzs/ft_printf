/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:38:30 by oozsertt          #+#    #+#             */
/*   Updated: 2021/05/27 16:24:50 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	t_list	bool_list;
	t_data	data_list;
	va_list	list;
	int		i;

	va_start(list, form);
	i = 0;
	while (form[i] != '\0')
	{
		if (form[i] == '%')
		{
			ft_boolset(&bool_list);
			ft_dataset(&data_list);
			i = ft_parse_conversion(&data_list, form, &bool_list, i);
			ft_set_width_and_precision(list, form, &bool_list, &data_list);
			ft_convert(list, &bool_list, &data_list);
			i++;
		}
		else
		{
			ft_putchar(form[i]);
			i++;
		}
	}
	va_end(list);
	return (i);
}
