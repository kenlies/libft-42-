/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:13:51 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/11 19:43:12 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	char	*new_s;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] != '\0' && ft_char_in_set(set, s1[i]))
		i++;
	while (len > i && ft_char_in_set(set, s1[len - 1]))
		len--;
	new_s = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!new_s)
		return (NULL);
	j = 0;
	while (i < len)
	{
		new_s[j] = s1[i];
		j++;
		i++;
	}
	new_s[j] = '\0';
	return (new_s);
}
