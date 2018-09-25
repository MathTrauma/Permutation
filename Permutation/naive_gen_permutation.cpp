#include<stdio.h>
#include<time.h>

#include<algorithm>

using namespace std;

char ter[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
static int cnt;

void gen_perm(int sz, int lev){
	if(sz==lev){ 
		for(int i=0; i<sz; ++i)
			printf("%c", ter[i]);
		printf("\n");
	}

	for(int i=lev; i<sz; ++i){
		swap(ter[i],ter[lev]);
		gen_perm(sz, lev+1);
		swap(ter[i], ter[lev]);
	}
}

int main(){
	//freopen("out.txt", "w", stdout);

	while(1){
		printf("Input a number between 1 and 12 : ");
		int n; scanf("%d", &n);

		if(n>12) {
			printf("Too large!\n");
			continue;
		}
		if(n==0) break;
		clock_t last = clock();
		gen_perm(10, 0);
		printf("%f second!\n", (clock()-last)/1.0/CLOCKS_PER_SEC);
	}
	return 0;
}


