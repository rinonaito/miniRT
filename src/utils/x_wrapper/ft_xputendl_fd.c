/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xputendl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:16:37 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/08 12:18:54 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

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
