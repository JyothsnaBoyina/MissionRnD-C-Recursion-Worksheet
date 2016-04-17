/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"

int steps(int, int, int);
int steps1(int, int, int);
int fact(int);

int get_steps(int s)
{
	
	if (s == 0)
		return 0;
	else if (s == 1)
		return 1;
	else if (s%2==0)
		return steps(s, s, 0);
	else if (s%2==1 && s!=1)
		return steps1(s, s, 0);
}
int steps(int s, int i, int j)
{
	int temp = 0;
	if (i == 0 && j == s/2)
		return 1;
	else if (i == s&&j == 0)
		return 1+steps(s,i-2,++j);
	else if (i>0 && j<s/2)
	{
		temp = fact(i+j) / (fact(j)*fact(i));
		return temp + steps(s, i - 2, ++j);
	}

}
int steps1(int s, int i, int j)
{
	int temp = 0;
	
	if (i == 1 && j == s / 2)
	{
		temp = fact(1+j) / (fact(j)*fact(1));
		return temp;
	}
	else if (i == s&&j == 0)
		return 1 + steps1(s, i - 2, ++j);
	else if (i>1 && j<s / 2)
	{
		temp = fact(i+j) / (fact(j)*fact(i));
		return temp + steps1(s, i - 2, ++j);
	}

}
int fact(int n)
{
	if (n == 1)
		return 1;
	else
		return n*fact(n - 1);
}