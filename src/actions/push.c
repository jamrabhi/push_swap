/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:35:05 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/14 16:35:09 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pa(t_data *data)
{
	t_stack	*stack_b;
	t_stack	*tmp;
	t_stack	*stack_a;

	print_stack_a_b(data->top_stack_a, data->top_stack_b);
	if (data->stack_b_size > 0)
	{
		stack_b = data->top_stack_b;
		if (stack_b->next)
			tmp = stack_b->next;
		else
			tmp = NULL;
		stack_a = ft_stacknew_index(stack_b->nb, stack_b->index);
		if (!stack_a)
			exit_free(data);
		ft_stackadd_front(&data->top_stack_a, stack_a);
		free(stack_b);
		data->top_stack_b = tmp;
		data->stack_a_size++;
		data->stack_b_size--;
		ft_putstr_fd("pa\n", 1);
	}
	print_stack_a_b(data->top_stack_a, data->top_stack_b);

}

void	pb(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	t_stack	*stack_b;

	print_stack_a_b(data->top_stack_a, data->top_stack_b);
	if (data->stack_a_size > 0)
	{
		stack_a = data->top_stack_a;
		if (stack_a->next)
			tmp = stack_a->next;
		else
			tmp = NULL;
		stack_b = ft_stacknew_index(stack_a->nb, stack_a->index);
		if (!stack_b)
			exit_free(data);
		ft_stackadd_front(&data->top_stack_b, stack_b);
		free(stack_a);
		data->top_stack_a = tmp;
		data->stack_a_size--;
		data->stack_b_size++;
		ft_putstr_fd("pb\n", 1);
	}
	print_stack_a_b(data->top_stack_a, data->top_stack_b);

}
