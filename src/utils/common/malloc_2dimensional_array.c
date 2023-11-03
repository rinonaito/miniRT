/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_2dimensional_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:14:40 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/29 21:36:31 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "x_wrapper.h"
#include <stdlib.h>

//2次元配列をマロック
void	malloc_2dimensional_array(
	void ***array,
	const size_t size1,
	const size_t size2,
	const size_t count_num)
{
	size_t	i;

	*array = ft_xcalloc(size1, sizeof(void *));
	i = 0;
	while (i < count_num)
	{
		(*array)[i] = ft_xcalloc(size2, 1);
		i++;
	}
}
