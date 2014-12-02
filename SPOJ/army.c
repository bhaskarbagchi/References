#include <stdio.h>

int main() {
	int t, x, NG, NM, gMax = 0, mMax = 0;
	scanf("%d", &t);
	t++;
	while(--t) {
		scanf("%d %d", &NG, &NM);
		NG++; NM++;
		while(--NG) {
			scanf("%d", &x);
			gMax = (x>gMax)?x:gMax;
		}
		while(--NM) {
			scanf("%d", &x);
			mMax = (x > mMax)? x: mMax;
		}
		if(gMax>=mMax)
			printf("\nGodzilla");
		else
			printf("\nMechaGodzilla");
	}
	return 0;
}