#include<stdio.h>
int strlen(const char*str)
{
	if (*str == '\0')
		return 0;
	else return 1 + strlen(str + 1);

}
int main()
{
	char *p = "abcdef";
	int len = strlen(p);
	printf("%d\n", len);
	return 0;



}

