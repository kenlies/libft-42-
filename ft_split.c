/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:52:52 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/08 14:34:40 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_free_all(char **splitted, int wc)
{
	int	i;

	i = 0;
	while (i < wc)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

static	int	ft_wrd_size(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static int	ft_wrd_count(char const *s, char c)
{
	int	counter;
	int	trigger;

	counter = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			counter++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (counter);
}

static char	**ft_build_split(char **splitted, const char *s, char c, int wc)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (j < wc)
	{
		while (s[i] == c)
			i++;
		size = ft_wrd_size(s, c, i);
		splitted[j] = ft_substr(s, i, size);
		if (!splitted[j])
			return (ft_free_all(splitted, wc));
		i = i + size;
		j++;
	}
	splitted[j] = 0;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		wrd_count;

	if (!s)
		return (NULL);
	wrd_count = ft_wrd_count(s, c);
	splitted = (char **)malloc(sizeof(char *) * wrd_count + 1);
	if (!splitted)
		return (NULL);
	splitted = ft_build_split(splitted, s, c, wrd_count);
	return (splitted);
}
