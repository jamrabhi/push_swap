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

void	push_min_to_b(t_data *data)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = data->top_stack_a;
	while (stack->nb != data->stack_a_min && ++i)
		stack = stack->next;
	while (stack != NULL)
	{
		if (data->top_stack_a->nb == data->stack_a_min)
		{
			pb(data);
			break ;
		}
		else
		{
			while (data->top_stack_a->nb != data->stack_a_min)
			{
				if (i > 2)
					rra(data, 1);
				else
					ra(data, 1);
			}
		}
	}
}

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
	if (data->stack_a_size == 5)
		push_min_to_b(data);
	push_min_to_b(data);
	case_three(data);
	pa(data);
	pa(data);
}

void	sort_radix(t_data *data)
{
	int	max_bits;
	int	i;
	int	j;
	int	stack_a_size;

	i = 0;
	max_bits = 0;
	stack_a_size = data->stack_a_size;
	while (((data->stack_a_size -1) >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_a_size)
		{
			if (((data->top_stack_a->index >> i) & 1) == 1)
				ra(data, 1);
			else
				pb(data);
			j++;
		}
		i++;
		while (data->stack_b_size != 0)
			pa(data);
	}
}

void	sort(t_data *data)
{
	if (is_sorted(data) == EXIT_SUCCESS)
		exit_success(data);
	get_index(data);
	find_min_a(data);
	find_max_a(data);
	if (data->stack_a_size == 2)
		sa(data, 1);
	else if (data->stack_a_size == 3)
		case_three(data);
	else if (data->stack_a_size <= 5)
		case_five(data);
	else
		sort_radix(data);
}
