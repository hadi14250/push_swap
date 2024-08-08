/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:37:51 by hakaddou          #+#    #+#             */
/*   Updated: 2022/04/17 00:55:48 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>

void push (int *array, int content, int *a_top)
{
	*a_top += 1;
	array[*a_top] = content;
}

int pop (int *array, int *a_top)
{
	int tmp;
	*a_top += 1;
	tmp = array[*a_top];
	array[*a_top] = 0;
	return (tmp);
}

int main()
{
	int array[] = {4,6,1,7,3};
	int n = sizeof (array) / sizeof (4);
	int stack[n];
	int i = -1;
	int a_top = -1;
	int b_top = -1;
	// push (stack, 2323, &b_top);
	// push (stack, 69, &b_top);
	while (++i < n && a_top < n-1-1 && b_top < n-1)
	{
		int tmp = pop (array, &a_top);
		push (stack, tmp, &b_top);
	}

	i = -1;
	printf ("array is: \n");
	while (++i < n)
		printf ("%d ", array[i]);
	i = -1;
		printf ("\nstack is: \n");
	while (++i < n)
		printf ("%d ", stack[i]);
}