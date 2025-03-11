/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:18:06 by desambou          #+#    #+#             */
/*   Updated: 2025/03/06 11:51:25 by desambou         ###   ########.fr       */
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

// int main()
// {
//     char *str = "Hello,World,This,Is,A,Test";
//     char delimiter = ',';
//     char **result;
//     int count = 0;

//     result = ft_split(str, delimiter);

//     if (result == NULL)
//     {
//         printf("ft_split returned NULL\n");
//         return 1;
//     }

//     printf("Original string: \"%s\"\n", str);
//     printf("Delimiter: '%c'\n", delimiter);
//     printf("Split result:\n");

//     // Count the number of substrings and print them
//     while (result[count] != NULL)
//     {
//         printf("[%d]: \"%s\"\n", count, result[count]);
//         count++;
//     }

//     // Free the allocated memory
//     free_result(result, count);

//     return 0;
// }
// // int main(void)
// // {
// //      char **result;

// //     printf("Test 1: Basic splitting\n");
// //     result = ft_split("hello world how are you", ' ');
// //     print_split_result(result);
// //     free_split_result(result);

// //     printf("Test 2: Multiple consecutive delimiters\n");
// //     result = ft_split("  hello   world  ", ' ');
// //     print_split_result(result);
// //     free_split_result(result);

// //     printf("Test 3: No delimiters\n");
// //     result = ft_split("hello", ' ');
// //     // print_split_result(result);
// //     // free_split_result(result);

// //     printf("Test 4: Empty string\n");
// //     result = ft_split("", ' ');
// //     // print_split_result(result);
// //     // free_split_result(result);

// //     printf("Test 5: String with only delimiters\n");
// //     result = ft_split("     ", ' ');
// //     // print_split_result(result);
// //     // free_split_result(result);

// //     printf("Test 6: NULL input\n");
// //     result = ft_split(NULL, ' ');
// //     // print_split_result(result);
// //     // free_split_result(result);

// //     return (0);
// // }
// // Count how; many substrings we'll have
// // Allocate memory for the array of substrings
// // For each substring:
// //   - Find the next delimiter
// //   - Extract the substring
// //   - Add it to the array
// // Add a NULL pointer at the end of the array
// // Return the array
// // Purpose: To break a string into 
// //smaller parts (substrings) at specified points.

// // Input:
// // A string to be split
// // A delimiter (character or string) that marks where to split
// // Output: An array of substrings

// // Process:
// // The function searches for the delimiter in the string
// // It cuts the string at each occurrence of the delimiter
// // It stores each resulting substring in an array

// // Example:
// // If we split "apple,banana,cherry" using "," as the delimiter, we get:
// // ["apple", "banana", "cherry"]

// // ft_strlen: To calculate string lengths
// // ft_substr: To extract substrings
// // ft_strchr: To find the delimiter in the string

// // malloc: To allocate memory for the array of substrings