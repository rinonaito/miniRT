/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_wrapper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:18:34 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/27 14:35:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X_WRAPPER_H
# define X_WRAPPER_H

# include <stdlib.h>

void	*ft_xcalloc(size_t count, size_t size);

void	ft_xputendl_fd(char *s, int fd);

char	*ft_xsubstr(char const *s, unsigned int start, size_t len);

void	ft_xputstr_fd(char *s, int fd);

#endif
