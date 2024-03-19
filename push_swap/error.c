/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 12:04:20 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 18:12:46 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	int_error(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		if (matrix[i][j] == '+' || matrix[i][j] == '-')
			j++;
		if (j == 1 && (matrix[i][j] == '\0' || matrix[i][j] == '0'))
			return (0);
		if (matrix[i][j] == '0' && matrix[i][j + 1] != '\0')
			return (0);
		while (matrix[i][j])
		{
			if (matrix[i][j] < '0' || matrix[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	max_error(char **mat)
{
	int	i;
	int	size;

	i = 0;
	while (mat[i])
	{
		size = ft_strlen(mat[i]);
		if (size > 11)
			return (0);
		if ((size == 10 && mat[i][0] == '-') || size < 10)
		{
			i++;
			continue ;
		}
		if (ft_strncmp(mat[i], "-2147483648", size) > 0 && mat[i][0] == '-')
			return (0);
		if (ft_strncmp(mat[i], "+2147483647", size) > 0 && mat[i][0] == '+')
			return (0);
		if (ft_strncmp(mat[i], "2147483647", size) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	char_error(char **matrix)
{
	if (!max_error(matrix) || !int_error(matrix))
		return (0);
	return (1);
}

int	dublicat_error(int *stek, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (stek[i] == stek[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
