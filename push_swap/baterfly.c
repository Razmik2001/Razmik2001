/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baterfly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:14:40 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 18:16:18 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	meter_counter(int n)
{
	int	meter;

	if (n < 5)
		meter = 1;
	else if (n >= 6 && n < 50)
		meter = 3 + (((n - 6) / 44) * 7);
	else if (n >= 50 && n < 100)
		meter = 10 +(((n - 50) / 50) * 8);
	else if (n >= 100 && n < 350)
		meter = 18 + (((n - 100) / 250) * 9);
	else if (n >= 350 && n < 500)
		meter = 27 + (((n - 350) / 150) * 10);
	else
		meter = 37 + ((n - 500) / 20);
	return (meter);
}

void	baterfly(t_list *stack_a, int n)
{
	t_list	*stack_b;

	stack_b = NULL;
	baterfly_border(&stack_a, &stack_b, n);
	while (n > 0)
	{
		max_put(&stack_b, &stack_a, n, 'b');
		n--;
	}
	free_stack(&stack_a);
}

void	baterfly_border(t_list **stack_a, t_list **stack_b, int n)
{
	int	meter;
	int	counter;

	meter = meter_counter(n);
	counter = 0;
	while (*stack_a)
	{
		if ((*stack_a)->val <= counter)
		{
			push(stack_a, stack_b, 'b');
			if ((*stack_b)->next != NULL)
				rotate(stack_b, 'b');
			counter++;
		}
		else if ((*stack_a)->val <= counter + meter)
		{
			push(stack_a, stack_b, 'b');
			counter++;
		}
		else
			rotate(stack_a, 'a');
	}
}
