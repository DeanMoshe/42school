#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}


size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t src_len;

	i = 0;
	if(!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if(!size)
		return (src_len);
	while (src[i] != '\0' && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}


int main (void)
{
	char dst[8];
	char src[16] = "qweerwtrrytyruu";
	size_t size;

	size = 8;
	printf("%s\n", ft_strlcpy(dst, src, size));
}
