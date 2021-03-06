/*
 
 题目描述
 
 给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
 
 
 
 A1 = 能被5整除的数字中所有偶数的和；
 
 A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
 
 A3 = 被5除后余2的数字的个数；
 
 A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
 
 A5 = 被5除后余4的数字中最大数字。
 
 
 输入描述:
 
 每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
 
 
 
 输出描述:
 
 对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
 
 若其中某一类数字不存在，则在相应位置输出“N”。
 
 
 输入例子:
 
 13 1 2 3 4 5 6 7 8 9 10 20 16 18
 
 
 输出例子:
 
 30 11 2 9.7 9
 

 */


#include <iostream>

using namespace std;

int main() {
	int N;
	scanf("%d",&N);
	int array[N];
	int i = 0;
	while(i < N) {
		int num;
		scanf("%d",&num);
		array[i] = num;
		i++;
	}
	int numArray[5] = {0};
	int tempA2 = 0,tempA4 = 0;
	for (int i = 0; i < (sizeof(array) / sizeof(array[0])); ++i)
	{
		int temp = array[i];
		if (temp%10 == 0)
		{
			numArray[0] += temp;
		}
		if (temp%5 == 1)
		{
			if (tempA2 == 0)
			{
				tempA2 = 1;
				numArray[1] += temp;
			}else{
				tempA2 = 0;
				numArray[1] -= temp;
			}
		}
		if (temp%5 == 2)
		{
			numArray[2]++;
		}
		if (temp%5 == 3)
		{
			tempA4 += temp;
			numArray[3]++;
		}
		if (temp%5 == 4) {
			if (temp > numArray[4])
			{
				numArray[4] = temp;
			}
		}
	}


	for (int i = 0; i < 5; ++i)
	{
		 if (numArray[i] == 0)
		 {
		 	printf("N");
		 }else{
		 	if (i == 3)
		 	{
		 	 	printf("%.1f",(double)tempA4/numArray[i]);
		 	}else{
		 		printf("%d",numArray[i]);
		 	}
		 }
		 if (i != 4)
		 {
		 	printf(" ");
		 }
	}



	return 0;
}
