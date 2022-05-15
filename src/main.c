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

void	print_stack_a_b(t_stack *stack, t_stack *stack2)
{
	printf("A B\n");
	printf("- -\n");
	while (stack || stack2)
	{
		if (stack)
		{
			printf("%d ", stack->nb);
		}
		if (stack2)
		{
			if (stack)
				printf("%d", stack2->nb);
			else
				printf("  %d", stack2->nb);
		}
		if (stack)
			stack = stack->next;
		if (stack2)
			stack2 = stack2->next;
		printf("\n");
	}
	printf("...\n\n");
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

	print_stack_a_b(data.top_stack_a, data.top_stack_b);
	pb(&data);
	print_stack_a_b(data.top_stack_a, data.top_stack_b);
	
	sort(&data);
	printf("FAILURE\n");
	free_stack(&data.top_stack_a);
	free_stack(&data.top_stack_b);
	return (0);
}
