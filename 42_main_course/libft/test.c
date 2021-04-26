#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int		ft_isalpha (int c)
{
	return((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

int		ft_isdigit(int c)
{
	return(c >= 48 && c <= 57);
}

int		ft_isalnum(int c)
{
	return(ft_isalpha(c) || ft_isdigit(c));
}
