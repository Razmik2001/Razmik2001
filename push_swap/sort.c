/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:20:56 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 17:54:56 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	*sort(char **matrix, int *count)
{
	int	*sort_stek;
	int	i;
	int	n;
	int	*stek;

	n = 0;
	i = 0;
	while (matrix[n++])
		;
	stek = atoi_matrix(matrix, n);
	n = n - 1;
	if (!dublicat_error(stek, n))
		error_message("[DUBLICAT ERROR]: ");
	sort_stek = (int *) malloc (sizeof(int) * (n + 1));
	while (i < n)
	{
		sort_stek[i] = stek[i];
		i++;
	}
	selectionsort(sort_stek, n);
	ft_index(stek, sort_stek, n);
	*count = n;
	free(sort_stek);
	return (stek);
}

int	*atoi_matrix(char **matrix, int n)
{
	int	i;
	int	*stek;

	i = 0;
	while (matrix[i])
		i++;
	i = 0;
	stek = (int *) malloc ((n - 1) * sizeof(int));
	while (matrix[i])
	{
		stek[i] = ft_atoi(matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix[i]);
	free(matrix);
	return (stek);
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	selectionsort(int array[], int size)
{
	int	step;
	int	min_idx;
	int	i;

	step = 0;
	i = 0;
	while (step < size - 1)
	{
		min_idx = step;
		i = step + 1;
		while (i < size)
		{
			if (array[i] < array[min_idx])
				min_idx = i;
			i++;
		}
		swap(&array[min_idx], &array[step]);
		step++;
	}
}

void	ft_index(int *stek, int *sort_stek, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (stek[i] == sort_stek[j])
			{
				stek[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/*
int main ()
{
	int x[] = {23,4214,313,13,3123,-23,1243,-3213,0,-2};
	int n = sizeof(x) / sizeof(x[0]);
	if (dublicat_error(x,n)){
		printf("ERROR");
		return 0;
	}
	int *y = sort(x,n);
	for (int i=0;i<n;i++)
		printf("%d\n",y[i]);
}
*/
