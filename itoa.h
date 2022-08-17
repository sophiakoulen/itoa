#ifndef ITOA_H
# define ITOA_H
# include <stdlib.h>

int	sign(int n);

char	*putnbr_recursive(int n, char *ptr, int size, int is_first_call);

int	itoa_basic(int n, char *buffer, int size);

int	nbr_len(int n);

char	*itoa_dynamic(int n);

#endif
