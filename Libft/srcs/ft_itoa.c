/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:20:17 by desambou          #+#    #+#             */
/*   Updated: 2024/11/19 15:24:26 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigit(int n)
{
	int	count;
	int	num;

	count = 0;
	if (n < 0)
		num = -n;
	else
		num = n;
	if (n == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_minmax(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	return (NULL);
}

static void	write_str(int i, int is_negative, char *result, long num)
{
	while (i-- > is_negative)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		count;
	int		i;
	int		is_negative;
	long	num;

	result = ft_minmax(n);
	if (result || n == 0 || n == -2147483648 || n == 2147483647)
		return (result);
	count = ft_countdigit(n);
	is_negative = (n < 0);
	num = n;
	i = count + is_negative;
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (is_negative)
		num = -num;
	if (is_negative)
		result[0] = '-';
	write_str(i, is_negative, result, num);
	result[i] = '\0';
	return (result);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int		test_cases[] = {156, -156, -1, 1, 1473378406};
// 	int		num_tests;
// 	char	*result;

// 	num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
// 	printf("Testing ft_itoa function:\n");
// 	printf("===========================\n");
// 	for (int i = 0; i < num_tests; i++)
// 	{
// 		printf("Test case %d: Input = %d\n", i + 1, test_cases[i]);
// 		result = ft_itoa(test_cases[i]);
// 		if (result)
// 		{
// 			printf("Expected Output: \"%d\"\n", test_cases[i]);
// 			printf("Actual Output:   \"%s\"\n\n", result);
// 			free(result); // Free the allocated memory
// 		}
// 		else
// 		{
// 			printf("Error: ft_itoa returned NULL for input: %d\n\n",
// 				test_cases[i]);
// 		}
// 	}
// 	return (0);
// }
