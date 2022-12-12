/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 03:04:10 by aotsala           #+#    #+#             */
/*   Updated: 2022/11/11 19:44:17 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str, int len)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < len--)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
	}
	return (str);
}

static int	ft_length(long int num, int length)
{
	while (num)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

static char	*ft_itoa_helper(char *str, long int num, int index, int len)
{
	int	i;

	i = 0;
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (index < 0)
	{
		str[len -1] = '-';
	}
	while (num > 0)
	{
		str[i] = '0' + (num % 10);
		num = num / 10;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			length;
	char		*str;
	int			index;
	long int	num;

	num = n;
	index = 1;
	length = 0;
	if (num <= 0)
	{
		length++;
		num = num * (-1);
		index = -1;
	}
	length = ft_length(num, length);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str = ft_itoa_helper(str, num, index, length);
	str = ft_strrev(str, length);
	str[length] = '\0';
	return (str);
}
