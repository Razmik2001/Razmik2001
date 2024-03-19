/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:46:29 by ragrigor          #+#    #+#             */
/*   Updated: 2022/08/24 18:22:51 by ragrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define  UTILS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct t_list
{
	int				val;
	struct t_list	*next;
}	t_list;

int			*sort(char **matrix, int *count);
void		selectionsort(int array[], int size);
void		swap(int *a, int *b);
void		ft_index(int *sort, int *sort_stek, int n);
int			dublicat_error(int *stek, int n);
int			int_error(char **matrix);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		**ft_split(char const *s, char c);
void		unused_matrix_free(char **matrix);
int			put(char **temp, char **matrix, int count);
char		**char_matrix(int argc, char **argv);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isspace(char c);
int			max_error(char **mat);
int			char_error(char **matrix);
int			*atoi_matrix(char **matrix, int n);
int			ft_atoi(const char *str);
int			ft_putstr_fd(char *s, int fd);
void		error_message(char *s);
void		ft_putchar_fd(char c, int fd);
int			find_str(char const *s, char c);
t_list		*arr_list(int *arr, int n);
void		rotate(t_list **stack, char stack_name);
void		rotate_reverse(t_list **stack, char stack_name);
void		push(t_list **from, t_list **to, char stack_name);
void		swap_list(t_list *stack, char stack_name);
void		free_stack(t_list **stack);
void		for_two(t_list *stack);
void		for_three(t_list **stack);
void		for_three2(t_list *stack, int i);
void		for_four(t_list *stack_a);
void		for_five(t_list *steac_a);
void		max_put(t_list **from, t_list **to, int n, char stack_name);
void		push_swap(int n, t_list *stack);
int			meter_counter(int n);
void		baterfly(t_list *stack_a, int n);
int			meter_counter(int n);
void		baterfly_border(t_list **stack_a, t_list **stack_b, int n);
int			is_sorted(t_list *stack);
void		swap_list_for_three(t_list *stack, char stack_name);

#endif
