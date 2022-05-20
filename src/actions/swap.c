/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:59:10 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/05/14 15:59:11 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sa(t_data *data, int i)
{
	int		tmp;
	int		tmp_index;
	t_stack	*stack_first;
	t_stack	*stack_sec;

	// print_stack_a_b(data->top_stack_a, data->top_stack_b);
	if (data->stack_a_size > 1)
	{
		stack_first = data->top_stack_a;
		tmp = stack_first->nb;
		tmp_index = stack_first->index;
		stack_sec = stack_first->next;
		stack_first->nb = stack_sec->nb;
		stack_sec->nb = tmp;
		stack_sec->index = tmp_index;
		if (i == 1)
			ft_putstr_fd("sa\n", 1);
	}
	// print_stack_a_b(data->top_stack_a, data->top_stack_b);

}

void	sb(t_data *data, int i)
{
	int		tmp;
	int		tmp_index;
	t_stack	*stack_first;
	t_stack	*stack_sec;

	// print_stack_a_b(data->top_stack_a, data->top_stack_b);
	if (data->stack_b_size > 1)
	{
		stack_first = data->top_stack_b;
		tmp = stack_first->nb;
		tmp_index = stack_first->index;
		stack_sec = stack_first->next;
		stack_first->nb = stack_sec->nb;
		stack_sec->nb = tmp;
		stack_sec->index = tmp_index;
		if (i == 1)
			ft_putstr_fd("sb\n", 1);
	}
	// print_stack_a_b(data->top_stack_a, data->top_stack_b);

}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	ft_putstr_fd("ss\n", 1);
}
