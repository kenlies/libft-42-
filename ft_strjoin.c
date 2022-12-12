/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:05:46 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/11 19:43:35 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int		i;
	int		j;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_string = (char *)(malloc(sizeof(char) * (len1 + len2 + 1)));
	if (!new_string)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		new_string[i] = s1[i];
	while (s2[++j] != '\0')
		new_string[i + j] = s2[j];
	new_string[i + j] = '\0';
	return (new_string);
}
