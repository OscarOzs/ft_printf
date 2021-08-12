/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:34:31 by oozsertt          #+#    #+#             */
/*   Updated: 2021/08/12 16:13:24 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*zero_case(t_data *data_list, char c, char *res)
{
	res = (char *)malloc(sizeof(char) * 1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	ft_putchar(c);
	data_list->count += 1;
	return (res);
}

static char	*fill_res(char c, char *res)
{
	res = (char *)malloc(sizeof(char) * (2));
	if (res == NULL)
		return (NULL);
	res[1] = '\0';
	res[0] = c;
	return (res);
}

char	*ft_convert_c(va_list list, t_data *data_list, char *res)
{
	char	c;

	c = va_arg(list, int);
	if (c == 0)
		res = zero_case(data_list, c, res);
	else
		res = fill_res(c, res);
	if (res == NULL)
		return (NULL);
	return (res);
}
