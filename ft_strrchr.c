/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:16:15 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/10 14:15:47 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *sss, int c)
{
	int	i;

	i = 0;
	while (sss[i])
		i++;
	while (i >= 0)
	{
		if (sss[i] == (char)c)
			return ((char *)(sss + i));
		i--;
	}
	return (0);
}
