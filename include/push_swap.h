/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamrabhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:41:49 by jamrabhi          #+#    #+#             */
/*   Updated: 2022/03/30 17:41:53 by jamrabhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data
{
	t_stack	*top_stack_a;
	int		stack_a_size;
	t_stack	*top_stack_b;
	int		stack_b_size;
}				t_data;

void	parse_args(char *argv[], t_data *data);
void	exit_error(void);
void	free_array(char **str);
char	**ft_split_whitespaces(char *s);
t_stack	*ft_stacknew(int nb);
void	ft_stackadd_front(t_stack **astack, t_stack *new);
void	ft_stackadd_back(t_stack **astack, t_stack *new);
void	ft_stackiter(t_stack *stack, void (*f)(int));
void	ft_stackdelone(t_stack *stack);
void	free_stack(t_stack **astack);
void	exit_free(t_data *data);

void	sa(t_data *data, int i);
void	sb(t_data *data, int i);
void	ss(t_data *data);

void	pa(t_data *data);
void	pb(t_data *data);

void	ra(t_data *data, int i);
void	rb(t_data *data, int i);
void	rr(t_data *data);

void	rra(t_data *data, int i);
void	rrb(t_data *data, int i);
void	rrr(t_data *data);

#endif
