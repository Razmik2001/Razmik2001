/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:18:14 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 17:54:55 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**matrix;
	int		*stack;
	int		n;
	t_list	*stack_a;

	if (argc == 1)
		exit (1);
	matrix = char_matrix(argc, argv);
	if (!char_error(matrix))
		error_message("[UNCORECT SIMVOLS]: ");
	stack = sort(matrix, &n);
	stack_a = arr_list(stack, n);
	push_swap(n, stack_a);
}
