/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:18:06 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 13:52:21 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(char const *s, char c)
{
	int		nbstr;
	char	instr;

	nbstr = 0;
	instr = 0;
	while (*s != '\0')
	{
		if (*s != c && instr == 0)
		{
			instr = 1;
			nbstr++;
		}
		else if (*s == c)
			instr = 0;
		s++;
	}
	return (nbstr);
}

static void	free_result(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	*extract_substring(const char *s, int *start, char c)
{
	int		len;
	char	*substr;

	while (s[*start] == c)
		(*start)++;
	len = 0;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	substr = ft_substr(s, *start, len);
	*start += len;
	return (substr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**result;
	int		substr_count;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	substr_count = count_substrings(s, c);
	result = malloc((substr_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (s[start] && i < substr_count)
	{
		result[i] = extract_substring(s, &start, c);
		if (!result[i])
		{
			free_result(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
