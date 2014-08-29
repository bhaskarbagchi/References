#include <stdio.h>
#include <stdlib.h>

static int t[10] = {-1};

void queens(int i);
int empty(int i);
void printSolution();

int main(int argc, char* argv[]){
	queens(1);
	printSolution();
	return 0;
}

void queens(int i) {
	for(t[i] = 1; t[i]<=8; t[i]++) {
		if(empty(i)) {
			if(i==8) {
				printSolution();
				exit(0);
				//return;
			}
			else {
				queens(i+1);
			}
		}
	}
}

int empty(int i) {
	int j = 1;
	while(t[i] != t[j] && abs(t[i] - t[j]) != (i-j) && j<i) {
		j++;
	}
	return ((i==j)?1:0);
}

void printSolution() {
	int i;
	for(i = 1; i <= 8; i++){
		printf("T[%d] = %d \n", i, t[i]);
	}
}