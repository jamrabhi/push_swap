/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 03:03:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/21 03:03:13 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_max_a(t_data *data)
{
	t_stack	*stack;

	stack = data->top_stack_a;
	if (stack)
	{
		data->stack_a_max = stack->nb;
		stack = stack->next;
		while (stack)
		{
			if (stack->nb > data->stack_a_max)
					data->stack_a_max = stack->nb;
			stack = stack->next;
		}
	}
}

void	find_min_a(t_data *data)
{
	t_stack	*stack;

	stack = data->top_stack_a;
	data->stack_a_min = stack->nb;
	stack = stack->next;
	while (stack)
	{
		if (stack->nb < data->stack_a_min)
				data->stack_a_min = stack->nb;
		stack = stack->next;
	}
}
