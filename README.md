## Permutation

첫 과제는 가능한 순열을 모두 출력하는 것이다. 간단한 코드는 다음과 같다.

```c++
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
    freopen("out.txt", "w", stdout);
 
    clock_t last = clock();
    gen_perm(10, 0);
    printf("%f second!\n", (clock()-last)/1.0/CLOCKS_PER_SEC);
    return 0;
}

```
hmmm
Next, print all permutaions 'lexicographical order'
```
#include<stdio.h>
#include<time.h>

#include<algorithm>

using namespace std;

char arr[]={'0','1','2','3','4','5','6','7','8','9'};

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
	freopen("out2.txt", "w", stdout);
	clock_t last = clock();
	gen_perm_lexico(10);
	printf("%f\n", (clock()-last)/1.0/CLOCKS_PER_SEC);
	return 0;
}

```

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/MathTrauma/MathTrauma.github.io/settings). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://help.github.com/categories/github-pages-basics/) or [contact support](https://github.com/contact) and we’ll help you sort it out.

