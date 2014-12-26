#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int min(int a, int b, int c) {
	int less = (a < b) ? a : b;
	return (less < c) ? less : c;
}

int editDistance(char * str1, char * str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int ** distances = (int **) malloc (len2 * sizeof(int *));
	for(int i = 0; i < len2; i++) {
		distances[i] = (int *) malloc (len1 * sizeof(int));
	}
	for(int i = 0; i < len1; i++)
		distances[0][i] = i;
	for(int i = 0; i < len2; i++)
		distances[i][0] = i;
	for(int i = 1; i < len2; i++) {
		for(int j = 1; j < len1; j++) {
			if(str2[i] == str1[j]) {
				distances[i][j] = distances[i-1][j-1];
			} else {
				int ins = distances[i-1][j] + 1;
				int del = distances[i][j-1] + 1;
				int rep = distances[i-1][j-1] + 1;
				distances[i][j] = min(ins, del, rep);
			}
		}
	}
	return distances[len2-1][len1-1];
}

int main(int argc, char * argv[]) {
	char str1[] = "Sunday";
	char str2[] = "saturday";
	cout<<editDistance(str1, str2)<<endl;
	return 0;
}