#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int sum= 0;
	int sum1= 0;
	for (int i = 0; i <5; i++)
	{
		int a =2;
		sum = sum* 10 + a;
		sum1=sum+sum1;
	}
	printf("%d", sum1);
	system("pause");
	return 0;

}