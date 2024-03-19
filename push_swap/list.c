/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:34:34 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 18:20:05 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_list	*arr_list(int *arr, int n)
{
	int		i;
	t_list	*stack_a;
	t_list	*start;

	stack_a = (t_list *) malloc (sizeof(t_list));
	start = stack_a;
	i = -1;
	while (++i < n - 1)
	{
		stack_a->val = arr[i];
		stack_a->next = (t_list *) malloc (sizeof(t_list));
		stack_a = stack_a->next;
	}
	stack_a->val = arr[i];
	stack_a->next = NULL;
	return (start);
}

void	free_stack(t_list **stack)
{
	t_list	*temp;
	t_list	*head;

	temp = *stack;
	while (temp)
	{
		head = temp;
		temp = temp->next;
		free(head);
	}
}
