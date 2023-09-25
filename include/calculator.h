/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:52:45 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/25 21:31:46 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <stdlib.h>

size_t	get_num_of_positive_solutions(double a, double b, double c);
size_t	get_num_of_solutions(double a, double b, double c);

#endif