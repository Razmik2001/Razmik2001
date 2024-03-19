/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:23:09 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 18:21:22 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	for_two(t_list *stack)
{
	if (stack->val > stack->next->val)
		swap_list(stack, 'a');
	free_stack(&stack);
}

void	for_three(t_list **stack)
{
	t_list	*temp;
	int		i;
	int		val1;

	i = 0;
	if (is_sorted(*stack))
		return ;
	temp = (*stack);
	while (i < 3)
	{
		val1 = temp->val;
		if (val1 == 0)
			break ;
		i++;
		temp = temp->next;
	}
	for_three2(*stack, i);
}

void	for_three2(t_list *stack, int i)
{
	if (i == 0)
	{
		swap_list_for_three(stack, 'a');
		rotate(&stack, 'a');
	}
	else if (i == 1)
	{
		if (stack->val == 1)
			swap_list(stack, 'a');
		else
			rotate(&stack, 'a');
	}
	else
	{
		swap_list(stack, 'a');
		rotate_reverse(&stack, 'a');
	}
}

void	for_four(t_list *stack_a)
{
	int		i;
	t_list	*temp;
	t_list	*stack_b;

	stack_b = NULL;
	i = 0;
	temp = stack_a;
	while (i < 4)
	{
		if (temp->val == 3)
			break ;
		i++;
		temp = temp->next;
	}
	if (i < 2)
		while (i-- != 0)
			rotate(&stack_a, 'a');
	else
		while (i++ != 4)
			rotate_reverse(&stack_a, 'a');
	push(&stack_a, &stack_b, 'b');
	for_three(&stack_a);
	push(&stack_b, &stack_a, 'a');
	rotate(&stack_a, 'a');
	free_stack(&stack_a);
}
