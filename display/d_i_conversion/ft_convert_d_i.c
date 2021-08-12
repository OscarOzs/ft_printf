/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:15:14 by oozsertt          #+#    #+#             */
/*   Updated: 2021/08/12 14:27:16 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*fill_res(char *str, char *res)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

char	*ft_convert_d_i(va_list list, char *res)
{
	char	*str;
	int		nbr;

	nbr = va_arg(list, int);
	str = ft_itoa(nbr);
	res = fill_res(str, res);
	free(str);
	if (res == NULL)
		return (NULL);
	return (res);
}
