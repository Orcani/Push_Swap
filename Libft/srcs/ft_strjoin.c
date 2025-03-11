/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:27:21 by desambou          #+#    #+#             */
/*   Updated: 2024/11/15 14:14:57 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcat(result + s1_len, s2, s2_len + 1);
	return (result);
}

// int main()
// {
//     char *result;

//     // Test case 1: Normal strings
//     result = ft_strjoin("Amazing ", "Delphine!");
//     if (result)
//     {
//         printf("Test 1: %s\n", result);
//         free(result);
//     }
//     else
//         printf("Test 1 failed: NULL returned\n");

//     // Test case 2: Empty strings
//     result = ft_strjoin("", "");
//     if (result)
//     {
//         printf("Test 2: '%s'\n", result);
//         free(result);
//     }
//     else
//         printf("Test 2 failed: NULL returned\n");

//     // Test case 3: One empty string
//     result = ft_strjoin("It is", "");
//     if (result)
//     {
//         printf("Test 3: %s\n", result);
//         free(result);
//     }
//     else
//         printf("Test 3 failed: NULL returned\n");

//     // Test case 4: Strings with spaces
//     result = ft_strjoin("   Beautiful   ", "   World   ");
//     if (result)
//     {
//         printf("Test 4: '%s'\n", result);
//         free(result);
//     }
//     else
//         printf("Test 4 failed: NULL returned\n");

//     // Test case 5: NULL inputs (if your function handles them)
//     result = ft_strjoin(NULL, "Life");
//     if (result)
//     {
//         printf("Test 5: %s\n", result);
//         free(result);
//     }
//     else
//         printf("Test 5: NULL returned (expected for NULL input)\n");

//     return (0);
// }