#include <stdio.h>

int main(int argc, char* argv[]){
	int n, temp, sum1 = 0, sum2 = 0;
	scanf("%d", &n);
	while(n>0){
		scanf("%d", &temp);
		if(temp == 100)
			sum1++;
		else
			sum2+=2;
		n--;
	}
	if((sum2%4 == 2 && sum1%2 == 0 && sum1!=0)||(sum2%4 == 0 && sum1%2 == 0))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}