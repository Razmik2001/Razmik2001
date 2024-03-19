/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comand_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:35:18 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 18:18:02 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rotate(t_list **stack, char stack_name)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	temp = temp->next;
	*stack = (*stack)->next;
	temp->next = NULL;
	if (stack_name == 'a')
		ft_putstr_fd("ra", 1);
	else
		ft_putstr_fd("rb", 1);
}

void	rotate_reverse(t_list **stack, char stack_name)
{
	t_list	*temp;
	t_list	*previous;

	temp = *stack;
	while (temp->next)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
	temp->next = *stack;
	*stack = temp;
	if (stack_name == 'a')
		ft_putstr_fd("rra", 1);
	else
		ft_putstr_fd("rrb", 1);
}

void	push(t_list **from, t_list **to, char stack_name)
{
	t_list	*temp;

	temp = *from;
	if (temp == NULL)
	{
		return ;
	}
	*from = temp->next;
	temp->next = *to;
	*to = temp;
	if (stack_name == 'a')
		ft_putstr_fd("pa", 1);
	else
		ft_putstr_fd("pb", 1);
}

void	swap_list(t_list *stack, char stack_name)
{
	int		swap;
	int		val1;
	int		val2;
	t_list	*temp;

	temp = stack;
	val1 = temp->val;
	temp = temp->next;
	val2 = temp->val;
	if (val1 > val2)
	{
		swap = stack->val;
		stack->val = stack->next->val;
		stack->next->val = swap;
		if (stack_name == 'a')
			ft_putstr_fd("sa", 1);
		else
			ft_putstr_fd("sb", 1);
	}
}

void	swap_list_for_three(t_list *stack, char stack_name)
{
	int	swap;

	swap = stack->val;
	stack->val = stack->next->val;
	stack->next->val = swap;
	if (stack_name == 'a')
		ft_putstr_fd("sa", 1);
	else
		ft_putstr_fd("sb", 1);
}
