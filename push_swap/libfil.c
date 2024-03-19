/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfil.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:23:19 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/21 14:25:02 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str++)
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			if ((unsigned char)s1[i] < (unsigned char)s2[i])
				return (-1);
			else
				return (1);
		}
		++i;
	}
	return (0);
}

int	ft_isspace(char c)
{
	char	*str;
	int		i;

	str = " \f\n\r\t\v";
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		++i;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	num;
	int	i;

	minus = 1;
	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -minus;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	num = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10;
		num = num + (str[i] - '0');
		++i;
	}
	num = num * minus;
	return (num);
}
