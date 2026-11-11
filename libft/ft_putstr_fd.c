#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
}

// int main()
// {
//     char *s = "Hello";
//     ft_putstr_fd(s, 1);
//     return (0);
// }
