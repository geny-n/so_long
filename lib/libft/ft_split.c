/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:30:59 by ngeny             #+#    #+#             */
/*   Updated: 2024/04/01 13:15:37 by ngeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *str, char c)
{
	int	i;
	int	count;
	int	flag;

	flag = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		else if (str[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (count);
}

static void	free_dest(int word, char **dest)
{
	while (word > 0)
	{
		word--;
		free(dest[word]);
	}
	free(dest);
}

static char	**print_word(char **dest, char *str, char c, size_t count)
{
	size_t	start;
	size_t	end;
	size_t	word;

	start = 0;
	word = 0;
	while (word < count)
	{
		end = 0;
		while (str[start] == c && str[start])
			start++;
		while (str[start + end] != c && str[start + end])
			end++;
		dest[word] = ft_substr(str, start, end);
		if (dest[word] == 0)
		{
			free_dest(word, dest);
			return (NULL);
		}
		while (str[start] != c && str[start])
			start++;
		word++;
	}
	dest[word] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	char	*str;
	size_t	count;

	str = (char *)s;
	if (!str)
		return (NULL);
	count = count_word(str, c);
	if (count == 0)
		return (NULL);
	dest = (char **) malloc(sizeof(char *) * (count + 1));
	if (dest == NULL)
		return (NULL);
	dest = print_word(dest, str, c, count);
	return (dest);
}
