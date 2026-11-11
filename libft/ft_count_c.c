#include "libft.h"

/* int	ft_count_c(char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
} */

int	ft_count_c(char *s, char c)
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[k])
	{
		if (s[k] == c)
			count++;
		k++;
	}
	return (count);
}
