/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:32:01 by desambou          #+#    #+#             */
/*   Updated: 2024/11/15 14:15:10 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		length_s;
	char	*result;
	int		i;

	if (!s || !f)
		return (NULL);
	length_s = ft_strlen(s);
	result = malloc((length_s + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < length_s)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// Function ft_strmapi(string s, function f):
//     // Hint: Check for invalid inputs
//     If s is NULL or f is NULL:
//         Return NULL

//     // Hint: Get the length of the string
//     length = calculate length of s

//     // Hint: Allocate memory for the new string
//     new_string = allocate memory for (length + 1) characters
//     If memory allocation failed:
//         Return NULL

//     // Hint: Apply the function to each character
//     For index from 0 to (length - 1):
//         new_character = call f with (index, s[index])
//         store new_character in new_string[index]

//     // Hint: Don't forget to null-terminate the new string
//     Add null terminator to new_string

//     Return new_string

// End Function

// int	main(void)
// {
// 	char	*input;
// 	char	*result;

// 	input = "hello world";
// 	printf("Original string: \"%s\"\n", input);
// 	result = ft_strmapi(input, &f);
// 	// Expected output: "HhLlOwOrLd"
// 	printf("Expected Output: \"HhLlOwOrLd\"\n");
// 	if (result)
// 	{
// 		printf("Actual Output:   \"%s\"\n", result);
// 		free(result); // Free the allocated memory
// 	}
// 	else
// 	{
// 		printf("ft_strmapi failed\n");
// 	}
// 	return (0);
// }
