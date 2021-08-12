/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:16:30 by oozsertt          #+#    #+#             */
/*   Updated: 2021/08/11 20:51:32 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*zero_case(char *res)
{
	res = (char *)malloc(sizeof(char) * 2);
	if (res == NULL)
		return (NULL);
	res[1] = '\0';
	res[0] = '0';
	return (res);
}

static char	*casual_case(char *str, char *res)
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

char	*ft_convert_x(va_list list, t_data *data_list, char *res)
{
	char			*str;
	unsigned int	nbr;

	nbr = va_arg(list, unsigned int);
	if (data_list->conversion == 'x')
		str = ft_utoa_base(nbr, "0123456789abcdef");
	else
		str = ft_utoa_base_uppercase(nbr, "0123456789abcdef");
	if (nbr == 0)
		res = zero_case(res);
	else
		res = casual_case(str, res);
	if (res == NULL)
		return (NULL);
	free(str);
	return (res);
}
