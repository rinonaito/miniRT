/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:29:17 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/24 13:52:21 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error_utils.h"
#include <errno.h>

void	*ft_xcalloc(size_t count, size_t size)
{
	void	*p;

	p = ft_calloc(count, size);
	if (p == NULL)
		exit_with_errno(errno);
	return (p);
}
