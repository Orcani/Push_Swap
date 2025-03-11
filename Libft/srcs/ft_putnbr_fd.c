/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:41:10 by desambou          #+#    #+#             */
/*   Updated: 2024/11/20 12:11:30 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

int main() {
	int fd = 1; // File descriptor for standard output (the terminal)

	printf("Testing ft_putnbr_fd:\n");

	// Test with positive numbers
	printf("Positive number: ");
	ft_putnbr_fd(12345, fd); // Should print: 12345
	printf("\n");

	// Test with negative numbers
	printf("Negative number: ");
	ft_putnbr_fd(-6789, fd); // Should print: -6789
	printf("\n");

	// Test with zero
	printf("Zero: ");
	ft_putnbr_fd(0, fd); // Should print: 0
	printf("\n");

	return (0);
}
