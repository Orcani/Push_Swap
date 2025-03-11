/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:44:09 by desambou          #+#    #+#             */
/*   Updated: 2024/11/13 14:03:53 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	example_function(unsigned int index, char *c)
// {
// 	if (index % 2 == 0)
// 	{
// 		*c = 'A'; // Change even indexed characters to 'A'
// 	}
// 	else
// 	{
// 		*c = 'B'; // Change odd indexed characters to 'B'
// 	}
// }
// int main() {
//     char str[] = "hello"; // Original string
//     char expected_output[] = "ABABA"; // Expected output after modification

//     printf("Original string: \"%s\"\n", str);

//     ft_striteri(str, example_function);
	// Apply example_function to each character

//     printf("Expected Output: \"%s\"\n", expected_output);
//     printf("Actual Output:   \"%s\"\n", str); // Print modified string

//     return (0);
// }

// FUNCTION ft_striteri(s, f):
//     IF s is NULL OR f is NULL:
//         RETURN

//     SET i = 0  // Initialize index

//     WHILE s[i] is not the null terminator:
//         CALL f with index i and address of s[i]
//         INCREMENT i by 1  // Move to the next character

//     RETURN  // No return value since we modify the string in place