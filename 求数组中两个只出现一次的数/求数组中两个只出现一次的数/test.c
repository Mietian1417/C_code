#include<stdio.h>
void finedif(int arr[], int lenght)
{
	int left = 0;
	int right = lenght - 1;
	int ret = 0;
	int sign = 0;;
	int first = 0;
	int second = 0;
	for (int i = 0; i <= right; i++)
	{
		ret ^= arr[i];
	}
	for (int i = 0; i < 32; i++)
	{
		if ((ret & 1 << i) == 1)
		{
			sign = i;
			break;
		}
	}
	for (int i = 0; i <= right; i++)
	{
		if ((arr[i] & 1 << sign) == 1)
		{
			first ^= arr[i];
		}
		else
		{
			second ^= arr[i];
		}
	}
	printf("%d %d\n", first, second);
}

int main()
{
	int arr[] = { 1,1,2,2,3,4,4,5,5,6 };
	finedif(arr, 10);
	return 0;
}
