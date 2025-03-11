/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:17:48 by desambou          #+#    #+#             */
/*   Updated: 2024/11/15 14:16:13 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// To handle edge cases, like returning an empty string
// when the input is empty or entirely composed of characters to be trimmed.

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	result = malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
// To allocate memory for the new trimmed string.

// int	main(void)
// {
// 	char *str;

// 	// Test case 1
// 	str = ft_strtrim("   Magnificent!   ", " ");
// 	printf("Test 1: '%s'\n", str);
// 	free(str);

// 	// Test case 2
// 	str = ft_strtrim("...Listening to Dangerous Woman by Ariana Grande!...",
// 			".");
// 	printf("Test 2: '%s'\n", str);
// 	free(str);

// 	// Test case 3
// 	str = ft_strtrim("Flip a Switch.", "Fh.");
// 	printf("Test 3: '%s'\n", str);
// 	free(str);

// 	// Test case 4
// 	str = ft_strtrim("", "");
// 	printf("Test 4: '%s'\n", str);
// 	free(str);

// 	return (0);
// }