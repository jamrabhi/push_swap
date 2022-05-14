/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:37:55 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/03/30 17:37:58 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>
#include <limits.h>

void	print_list_elt(int nb)
{
	printf("%d\n", nb);
}

void	print_stack_a(t_data *data)
{
	printf("STACK A :\n---------\n");
	ft_stackiter(data->top_stack_a, &print_list_elt);
	printf("\n");
}

void	print_stack_b(t_data *data)
{
	printf("STACK B :\n---------\n");
	ft_stackiter(data->top_stack_b, &print_list_elt);
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 1)
		return (0);
	ft_bzero(&data, sizeof(data));
	parse_args(argv, &data);
	if (data.stack_a_size < 2)
		exit_free(&data);
	print_stack_a(&data);
	print_stack_b(&data);
	rra(&data, 1);
	print_stack_a(&data);
	print_stack_b(&data);
	rb(&data, 1);
	print_stack_a(&data);
	print_stack_b(&data);
	ra(&data, 1);
	rb(&data, 1);
	print_stack_a(&data);
	print_stack_b(&data);
	free_stack(&data.top_stack_a);
	free_stack(&data.top_stack_b);
	return (0);
}
