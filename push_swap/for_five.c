/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_five.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 21:48:20 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 18:19:11 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	for_five(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	max_put(&stack_a, &stack_b, 5, 'a');
	max_put(&stack_a, &stack_b, 4, 'a');
	for_three(&stack_a);
	push(&stack_b, &stack_a, 'a');
	rotate(&stack_a, 'a');
	push(&stack_b, &stack_a, 'a');
	rotate(&stack_a, 'a');
	free_stack(&stack_a);
}

void	max_put(t_list **from, t_list **to, int n, char stack_name)

{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *from;
	while (i < n)
	{
		if (temp->val == (n - 1))
			break ;
		i++;
		temp = temp->next;
	}
	if (i < ((n / 2) + 1))
		while (i-- != 0)
			rotate(from, stack_name);
	else
		while (i++ != n)
			rotate_reverse(from, stack_name);
	push(from, to, stack_name - 1);
}

void	push_swap(int n, t_list *stack)
{
	int		i;
	
	i = is_sorted(stack);
	if (i)
		exit (1);
	if (n == 1)
		free_stack(&stack);
	else if (n == 2)
		for_two(stack);
	else if (n == 3)
	{
		for_three(&stack);
		free_stack(&stack);
	}
	else if (n == 4)
		for_four(stack);
	else if (n == 5)
		for_five(stack);
	else
		baterfly(stack, n);
	exit (1);
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}
