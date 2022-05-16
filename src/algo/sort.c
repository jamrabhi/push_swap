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

void	case_three(t_data *data)
{
	t_stack	*stack;
	int		second;
	int		third;

	stack = data->top_stack_a;
	second = stack->next->nb;
	third = stack->next->next->nb;
	if (stack->nb > second && second < third && stack->nb < third)
		sa(data, 1);
	else if (stack->nb > second && second > third && stack->nb > third)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (stack->nb > second && second < third && stack->nb > third)
		ra(data, 1);
	else if (stack->nb < second && second > third && stack->nb < third)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if (stack->nb < second && second > third && stack->nb > third)
		rra(data, 1);
}

void	case_five(t_data *data)
{
	// t_stack	*stack_a;

	print_stack_a_b(data->top_stack_a, data->top_stack_b);
	pb(data);
	pb(data);
	case_three(data);
	pa(data);
	// stack_a = data->top_stack_a;
	print_stack_a_b(data->top_stack_a, data->top_stack_b);
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

int	is_sorted(t_data *data)
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
	if (data->stack_a_size == 3)
		case_three(data);
	if (data->stack_a_size == 5)
		case_five(data);
}
