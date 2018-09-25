#include<stdio.h>
#include<time.h>

#include<algorithm>

using namespace std;

char arr[]={'0','1','2','3','4','5','6','7','8','9', 'a','b','c','d','e','f'};

void gen_perm_lexico(int sz){
	if(sz==1) return;

	while(true) {
		for(int i=0; i<sz; ++i)
			printf("%c",arr[i]);
		printf("\n");

		int pos=sz-2;
		for(; pos>=0; --pos){
			if(arr[pos]<arr[pos+1])
				break;
		}
		if(pos==-1) break;

		int pos2 = sz-1;
		for(;pos2>pos; --pos2)
			if(arr[pos]<arr[pos2])
				break;
		swap(arr[pos], arr[pos2]);
		reverse(arr+pos+1, arr+sz);
	}
}

int main() {
	//freopen("out2.txt", "w", stdout);
	while(1){
		printf("Input a number between 1 and 16 : ");
		int n; scanf("%d", &n);
		if(n>16) {
			printf("Too large!\n");
			continue;
		}
		if(n==0) break;
		
		clock_t last = clock();
		gen_perm_lexico(n);
		printf("%f\n", (clock()-last)/1.0/CLOCKS_PER_SEC);
	}
	return 0;
}
