
#include <string.h>

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t	i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	i = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	while (i < n)
	{
		*temp_dest = *temp_src;
		temp_dest++;
		temp_src++;
		i++;
	}
	return (dest);
}

/*#include <stdio.h>

int	main() 
{
	char source[] = "Hello, World!";
	char destination[20];

	ft_memcpy(destination, source, 14);

	printf("Copied string: %s\n", destination);

	return (0);
}*/
