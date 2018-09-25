[MathTrauma](http://www.mathtrauma.com)
## Permutation(s)
#### permutation(순열?) : 정의역과 공역이 같은 일대일 대응함수
보통 수학 교재들에서는 위와 같이 정의한다. 한편, 일대일 대응을 통해 얻어진 수열을 일컫기도 한다.
시작부터 많은 합의가 필요하다. 사실 여기에 쓰고 있는 글들은 수학과 컴퓨터를 소재로 하지만, 내가 사용하는 언어의 모호함을 극복하고자 하는 노력의 한 부분이다.
왜 합의가 필요한가? 다음의 수의 나열
1->5->2->3->4
을 보고 2 '앞'의 수가 무엇인지 말해보라. 나을 포함하여 내가 물어본 대다수의 사람들은 '5'라고 대답했다.
그런데, 화살표 기호 '->'의 '앞'은 어는 방향인지 생각하고, 다시 같은 물음을 대했을 때 여전히 '5'가 '2'의 앞의 수라고 답할 것인가?

앞서 permutation 의 정의에서 정의역과 공역이 같다고 하였는데 이 글에서는 공집합이 아닌 유한집합 위에서 정의된 permutation 만을 다룰 것이다.

1. permutation이라는 용어는
    - bijection(일대일대응 함수)
    - 결과물로 표현된 순열 
두 가지 모두에 사용한다. 어떤 것으로 사용하는지 혼란이 있는 경우는 명시한다.

1. 함수의 합성은 우측함수가 먼저 적용되되록 가르치는 경우가 많은 듯하지만, 여기서는 좌측함수가 먼저 적용된다. 
다시 설명하자면 $$ (g\circ f)(x)=g(f(x))$$ 대신 $$(x)(g \circ f) = ((x)g)f$$ 를 사용할 것이다. 

이 글에서 가장 어려운(?) 것을 소개한다.
### 위치를 기준으로 사고할 것인지, 원소를 기준으로 사고할 것인지 명확히 할 것!
다음의 설명
'transposition (i, j)는 i와 j를 바꾸는 것이다.'
의 문제점은 무엇인가? 4가지 가능성이 존재한다.
1. i 번째 위치의 원소를 j 번째 위치로 옮긴다. (물론 j 번째 위치의 원소는 i 번째 위치로...)
2. i 번째 위치로 j 번째 위치의 원소를 가져온다. 
3.
4.
응? 모두 제 위치에 있는 정렬된 상태에서 4가지 모두 같은 결과를 얻는다. 
하지만 transposition들을 합성하여 적용한다면?


첫 과제는 가능한 순열을 모두 출력하는 것이다. 간단한 코드는 다음과 같다.
<script src="https://gist.github.com/MathTrauma/114fa34ad2b46a9eaa67923507e0c642.js"></script>
[코드보기](https://gist.github.com/MathTrauma/114fa34ad2b46a9eaa67923507e0c642)
{% MathTrauma/114fa34ad2b46a9eaa67923507e0c642 %}
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
크기 순서대로 출력하는 것이 다음 문제이다. 다음의 간단한 관찰
### 가장 큰 것은 역순으로 표현된다.###
이 모든 것을 설명해준다. 이 관찰로부터 마지막 원소부터 거슬러가면서 역순이 아닌 첫 원소를 찾는다.
이 원소를 a라 하자. 현재 a의 오른쪽의 원소들은 역순으로 정렬된 상태이다. 다시  

```c++
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

