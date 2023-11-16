#include <string.h>

void    *ft_memmove(void*dest, const void*src, size_t len)
{
        size_t  i;
        unsigned char   *temp_dest;
        unsigned char   *temp_src;

        i = 0;
        temp_dest = (unsigned char *)dest;
        temp_src = (unsigned char *)src;
        if (!temp_dest && !temp_src)
                return (0);
        if (temp_src < temp_dest)
        {
                i = len;
                while (i > 0)
                {
                        i--;
                        temp_dest[i] = temp_src[i];
                }
        }
        else
        {
                i = 0;
                while (i < len)
                {
                        temp_dest[i] = temp_src[i];
                        i++;
                }
        }
        return (dest);
}

#include <stdio.h>

int	main() {
    // Test Scenario 1: Overlapping memory regions
    char str1[] = "Hello, World!";
    char buffer1[20];

    // Move the contents of str1 to buffer1 (overlapping)
    ft_memmove(buffer1, str1 + 6, 8);

    // Display the result
    printf("Scenario 1 - Overlapping: %s\n", buffer1);

    // Test Scenario 2: Non-overlapping memory regions
    char str2[] = "Hello, World!";
    char buffer2[20];

    // Move the contents of str2 to buffer2 (non-overlapping)
    ft_memmove(buffer2, str2, 8);

    // Display the result
    printf("Scenario 2 - Non-overlapping: %s\n", buffer2);

	// Test Scenario: src is bigger than dst
    char src[] = "This is a larger string";
    char dst[10];

    // Display the initial state of dst
    printf("Before memmove: %s\n", dst);

    // Use memmove to copy the content of src to dst
    ft_memmove(dst, src, sizeof(src));

    // Display the result
    printf("After memmove: %s\n", dst);

    return (0);
}

