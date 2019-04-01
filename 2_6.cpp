include<iostream>
#include<stdio.h>
#include<math.h>
#include<time.h>
//using namespace std;
int main(){
	int abc, def, ghi;
	int count[10];
	memset(count, 0, sizeof(count));
	for (int i = 123; i <= 329; i++){
		int sum = 0;
		abc = i;
		def = abc * 2;
		ghi = abc * 3;
		count[abc % 10] = count[abc / 10 % 10] = count[abc / 100]=1;
		count[def % 10] = count[def / 10 % 10] = count[def / 100]=1;
		count[ghi % 10] = count[ghi / 10 % 10] = count[ghi / 100]=1;
		for (int j = 0; j < 9; j++){
			sum += count[j];
		}
		if (sum == 9)
			printf("%d,%d,%d\n", abc, def, ghi);
		memset(count, 0, sizeof(count));
	}				
}
