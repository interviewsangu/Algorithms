 푼 문제 : 
 숫자 카드	https://www.acmicpc.net/problem/10815
숫자 카드 2	https://www.acmicpc.net/problem/10816
배열 합치기	https://www.acmicpc.net/problem/11728
종이의 개수	https://www.acmicpc.net/problem/1780
하노이 탑 이동 순서	https://www.acmicpc.net/problem/11729
트리의 순회	https://www.acmicpc.net/problem/2263
쿼드트리	https://www.acmicpc.net/problem/1992
별찍기 - 10	https://www.acmicpc.net/problem/2447
별찍기 - 11	https://www.acmicpc.net/problem/2448
Z	https://www.acmicpc.net/problem/1074
버블 소트	https://www.acmicpc.net/problem/1517
가장 가까운 두 점	https://www.acmicpc.net/problem/2261

* 분할 정복
- 문제를 2개 또는 그 이상의 작은 부분 문제로 나눈 다음 푸는 것(분할)
- 푼 다음에는 다시 합쳐 정답을 구할 때도 있음(정복)
- 대표적인 분할 정복 알고리즘 : 퀵 소트, 머지 소트, 큰 수 곱셈, FFT
- 분할 정복은 문제가 겹치지 않고 다이나믹은 문제가 겹치는 것이 다른 점
- 분할 정복 문제는 어떻게 함수를 만들어야 할지 결정해야 한다.
- 함수 -> 문제를 푸는 함수
- 그 함수 내에서는 작은 문제를 어떻게 호출해야 할지 결정
- 만약에 부분 문제의 정답을 합쳐야 하는 경우에는 합치는 것을 어떻게 해야 할지 결정

* 이분 탐색
- lgN의 시간이 걸린다.
while(left <= right){
  int mid = left + (right - left)/2;
  if(a[mid] == x){
    position = mid;
    break;
  }else if(a[mid] > x){
    right = mid - 1;
  }else{
    left = mid + 1;
  }
}

10815번 : https://www.acmicpc.net/problem/10815

- 이분 탐색 구현
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int a[500000];
int binary(int num) {
	int l = 0;
	int r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == num) {
			return 1;
		}
		else if (a[mid] > num) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	scanf("%d", &m);
	while (m--) {
		int num;
		scanf("%d", &num);
		printf("%d ", binary(num));
	}
	printf("\n");
	return 0;
}

- STL 사용
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m;
int a[500000];
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    scanf("%d",&m);
    while (m--) {
        int num;
        scanf("%d",&num);
        printf("%d ",binary_search(a,a+n,num));
    }
    printf("\n");
    return 0;
}

10816번 : https://www.acmicpc.net/problem/10816

- equal range
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    
    sort(a.begin(), a.end());

    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int number;
        scanf("%d",&number);
        auto p = equal_range(a.begin(), a.end(), number);
        printf("%d ",p.second - p.first);
    }

    printf("\n");
    return 0;
}

- lower, upper bound
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    
    sort(a.begin(), a.end());

    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int number;
        scanf("%d",&number);
        auto l = lower_bound(a.begin(), a.end(), number);
        auto r = upper_bound(a.begin(), a.end(), number);
        printf("%d ",r-l);
    }

    printf("\n");
    return 0;
}

- multiset
#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);

    multiset<int> s;
    for (int i=0; i<n; i++) {
        int x;
        scanf("%d",&x);
        s.insert(x);
    }

    int m;
    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int x;
        scanf("%d",&x);
        printf("%d ",s.count(x));
    }

    printf("\n");

    return 0;
}

* 머지 소트
- N개를 정렬하는 알고리즘
- 반씩 나누고 각각 정렬한 후 하나로 합친다.
- 나누는 시간 lgN
- 합치는 시간 lgN과 N 
- 총 NlgN의 시간이 걸린다. 
void sort(int start, int end){
  if(start == end){
    return;
  }
  int mid = (start + end) / 2;
  sort(start, mid);
  sort(mid + 1, end);
  merge(start, end);
}
void merge(int start, int end){
  int mid = (start + end) / 2;
  int i = start, j = mid + 1, k = 0;
  while(i <= mid && j <=end){
    if(a[i] <= a[j]) b[k++] = a[i++];
    else b[k++] = a[j++];
  }
  while(i <= mid) b[k++] = a[i++];
  while(j <= end) b[k++] = a[j++];
  for(int i = start; i<=end; i++){
    a[i] = b[i-start];
  }
}

11728번 : https://www.acmicpc.net/problem/11728

#include <cstdio>
int a[1000000];
int b[1000000];
int c[2000000];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	int k = 0;
	int i = 0;
	int j = 0;
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}
	while (i < n) {
		c[k++] = a[i++];
	}
	while (j < m) {
		c[k++] = b[j++];
	}
	for (int i = 0; i < n + m; i++) {
		printf("%d ", c[i]);
	}
	puts("");
	return 0;
}

- 반복문 하나로 합치기
#include <cstdio>
int a[1000000];
int b[1000000];
int c[2000000];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
	int k = 0;
	int i = 0;
	int j = 0;
	while (i < n || j < m) {
		if (j >= m || (i < n && a[i] < b[j])) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}
	for (int i = 0; i < n + m; i++) {
		printf("%d ", c[i]);
	}
	puts("");
	return 0;
}

1780번 : https://www.acmicpc.net/problem/1780
함수를 어떻게 만들어야 할까요

