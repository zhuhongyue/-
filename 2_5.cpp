#include<iostream>
#include<stdio.h>
#include<math.h>
#include<time.h>
//using namespace std;
int main(){
	int a, b,c;
	int kase = 0;
	while (scanf_s("%d %d %d", &a, &b,&c) && !(a ==0&&b==0&&c==0)){
		int d = a/ b;
		printf("case %d: %d.", kase++, d);
		int m = a%b;
		for (int i = 1; i <= c; i++){
			m = 10 * m;
			int e = (m/b)%10;
			if (i == c)e = ((10 * m / b) % 10 > 5) ? (e+1):e;
			printf("%d", e);	
		}
		printf("\n");

	}
}
