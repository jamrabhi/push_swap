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

unsigned long long	dec_to_bin(int nb)
{
	unsigned long long	rt;
	unsigned long long	i = 1;
	int	rem;

	rem = 0;
	rt = 0;
	while (nb != 0)
	{
		rem = nb % 2;
		rt += rem * i;
		i = i * 10;
		nb = nb / 2;
	}
	return (rt);
}

void	get_index(t_data *data)
{
	int		i;
	t_stack	*stack;
	t_stack	*stack_cpy;

	stack = data->top_stack_a;
	// // //print_stack_a_b(data->top_stack_a, data->top_stack_b);
	while (stack)
	{
		i = 0;
		stack_cpy = data->top_stack_a;
		while (stack_cpy)
		{
			if (stack->nb > stack_cpy->nb)
				i++;
			stack_cpy=stack_cpy->next;
		}
		stack->index = i;
		stack = stack->next;
	}
	// // //print_stack_a_b(data->top_stack_a, data->top_stack_b);
}

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

void	case_five(t_data *data)
{
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
	int	index;
	int stack_a_size = data->stack_a_size;

	// get_index(data);
	i = 0;
	max_bits = 0;
	while (((data->stack_a_size -1) >> max_bits) != 0)
		++max_bits;
	// printf("array_size = %d max_bits = %d\n", data->stack_a_size, max_bits);
	// // //print_stack_a_b(data->top_stack_a, data->top_stack_b);
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_a_size)
		{
			index = data->top_stack_a->index;
			// printf("\n(nb >> i)&1) : (%d >> %d)&1) == %d\n", index, i, ((index >> i)&1));
			if (((index >> i)&1) == 1)
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
	find_max_a(data);
	get_index(data);
	if (data->stack_a_size == 3)
		case_three(data);
	else if (data->stack_a_size == 5)
		case_five(data);
	else
		sort_radix(data);
	//print_stack_a_b(data->top_stack_a, data->top_stack_b);
	
}
