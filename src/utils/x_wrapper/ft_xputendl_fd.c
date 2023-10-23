/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xputendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:16:37 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 21:26:22 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void	ft_xputendl_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		if (write(fd, &s[i], 1) < 0)
			exit_with_errno(errno);
		i ++;
	}
	if (write(fd, "\n", 1) < 0)
		exit_with_errno(errno);
}
