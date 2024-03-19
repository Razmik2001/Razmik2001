/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spilt_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:25:17 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/21 14:27:01 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**char_matrix(int argc, char **argv)
{
	int		i;
	int		count;
	char	**matrix;
	char	**temp;
	int		j;

	i = 0;
	count = 0;
	while (argv[++i])
		count += find_str(argv[i], ' ');
	i = 0;
	matrix = (char **) malloc ((count + 1) * sizeof(char *));
	count = 0;
	while (++i < argc)
	{
		j = 0;
		temp = ft_split(argv[i], ' ');
		count = put(temp, matrix, count);
		while (temp[j])
			free(temp[j++]);
		free(temp);
	}
	matrix[count] = NULL;
	return (matrix);
}

int	put(char **temp, char **matrix, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i])
	{
		matrix[count] = (char *) malloc (ft_strlen(temp[i]) * sizeof(char));
		while (temp[i][j])
		{
			matrix[count][j] = temp[i][j];
			j++;
		}
		count++;
		j = 0;
		i++;
	}
	return (count);
}

void	unused_matrix_free(char **matrix)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}
