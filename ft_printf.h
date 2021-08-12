/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:58:13 by oozsertt          #+#    #+#             */
/*   Updated: 2021/08/12 16:13:54 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data_conversion
{
	char	conversion;
	int		count;
}				t_data;

int		ft_printf(const char *form, ...);

// parsing
void	set_data(t_data *data_list);
int		parse_conversion(t_data *data_list, const char *form, int i);

// display
int		ft_convert_and_print(va_list list, t_data *data_list);
char	*ft_convert_percent(char *res);
char	*ft_convert_c(va_list list, t_data *data_list, char *res);
char	*ft_convert_d_i(va_list list, char *res);
char	*ft_convert_p(va_list list, char *res);
char	*ft_convert_s(va_list list, char *res);
char	*ft_convert_x(va_list list, t_data *data_list, char *res);
char	*ft_convert_u(va_list list, char *res);

// utils
char	*ft_itoa(int n);
void	ft_putchar(unsigned char c);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_utoa_base_uppercase(unsigned long long int n, char *base);
char	*ft_utoa_base(unsigned long long int n, char *base);
char	*ft_utoa(unsigned int n);

#endif