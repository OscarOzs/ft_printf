/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:00:25 by oozsertt          #+#    #+#             */
/*   Updated: 2021/08/12 15:33:37 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_convert_and_print(va_list list, t_data *data_list)
{
	char	*res;

	res = NULL;
	if (data_list->conversion == 's')
		res = ft_convert_s(list, res);
	else if (data_list->conversion == 'c')
		res = ft_convert_c(list, data_list, res);
	else if (data_list->conversion == 'x' || data_list->conversion == 'X')
		res = ft_convert_x(list, data_list, res);
	else if (data_list->conversion == '%')
		res = ft_convert_percent(res);
	else if (data_list->conversion == 'p')
		res = ft_convert_p(list, res);
	else if (data_list->conversion == 'd' || data_list->conversion == 'i')
		res = ft_convert_d_i(list, res);
	else if (data_list->conversion == 'u')
		res = ft_convert_u(list, res);
	if (res == NULL)
		data_list->count = -1;
	else
		data_list->count += ft_strlen(res);
	ft_putstr(res);
	free(res);
	return (1);
}
