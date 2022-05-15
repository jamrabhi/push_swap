/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:52:01 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/15 17:52:23 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// void	case_three(t_data *data)
// {
// 	if (data->top_stack_a->nb)
// }

void	find_min_a(t_data *data)
{
	t_stack *stack;

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

int		is_sorted(t_data *data)
{
	t_stack	*stack;
	int		nb;

	stack = data->top_stack_a;
	while (stack)
	{
		nb = stack->nb;
		stack = stack->next;
		if (stack && nb > stack->nb)
			return (EXIT_FAILURE);
	}
	if (data->top_stack_b)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	sort(t_data *data)
{
	if (is_sorted(data) == EXIT_SUCCESS)
		exit_success(data);
	find_min_a(data);
	// if (data->stack_a_size == 3)
	// 	case_three(&data);
}
