/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:16:55 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/14 16:08:55 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*block;
	unsigned int	i;
	unsigned int	max;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	max = nmemb * size;
	if (max / nmemb != size)
		return (NULL);
	block = malloc(max);
	if (!block)
		return (NULL);
	i = 0;
	while (max--)
	{
		block[i] = '\0';
		i++;
	}
	return ((void *)block);
}
