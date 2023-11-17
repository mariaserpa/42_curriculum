#include <stdlib.h>

int	ft_strlen(char*str)
{
	int	n;
	
	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_strdup(char*src)
{
	int	i;
	int	len;
	char*	str;
	
	len = ft_strlen(src);
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>

int	main(void) 
{
	char *test1 = "Hello World";

	printf("%s\n", ft_strdup(test1));
	return (0);
}*/
