#include "itoa.h"

int	sign(int n)
{
	if (n >= 0)
		return 1;
	else
		return -1;
}

char	*putnbr_recursive(int n, char *ptr, int size, int is_first_call)
{
	/*
	 * helper function for itoa_basic
	 * takes the size of the buffer to avoid overflow
	 * nul-terminates
	 */

	if (size <= 1)//no place for a digit + nul ?
		return 0;
	if (n >= 10 || n <= -10)//n has more than one digit ?
		ptr = putnbr_recursive(n / 10, ptr, size - 1, 0); //write other digits first and return where to write next
	if (!ptr)//no space?
		return 0;
	*ptr = (n % 10) * sign(n) + '0'; //write last digit
	if (is_first_call)//this the very last digit ?
		*(ptr + 1) = 0;
	return ptr + 1; //return where to write next
}

int	itoa_basic(int n, char *buffer, int size)
{
	/*
	 * takes size of buffer to avoid overflow
	 * nul-terminates
	 * returns 1 if successful, 0 else
	 */

	if (n < 0)
	{
		*buffer = '-';
		buffer++;
		size--;
	}
	if (!putnbr_recursive(n, buffer, size, 1))
		return 0;
	return 1;
}

int	nbr_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*itoa_dynamic(int n)
{
	char	*str;
	int	len;

	len = nbr_len(n);
	str = malloc(len + 1);
	itoa_basic(n, str, len + 1);
	return (str);
}
