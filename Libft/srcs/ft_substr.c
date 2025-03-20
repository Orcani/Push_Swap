/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:46:10 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 13:51:50 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		substr = malloc(sizeof(char));
		if (!substr)
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	substr[len] = '\0';
	return (substr);
}

// size_t i;
// i = 0;
// while (i < len && s[start + i])
//    {
//        substr[i] = s[start + i];
//        i++;
//    }
//    substr[i] = '\0';

// int	main(void)
// {
// 	char test[] = "Une voiture jaune.";
// 	printf("%s\n", test);
// 	// printf("%s\n", substr(test, 2, 3));
// 	printf("%s\n", ft_substr(test, 2, 5));
// 	return (0);
// }