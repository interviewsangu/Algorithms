푼 문제 : 집합	https://www.acmicpc.net/problem/11723
다음 순열	https://www.acmicpc.net/problem/10972
이전 순열	https://www.acmicpc.net/problem/10973
모든 순열	https://www.acmicpc.net/problem/10974
순열의 순서	https://www.acmicpc.net/problem/1722

* 비트마스크
- 비트 연산을 사용해서 부분 집합을 표현할 수 있다.
- 두 수 A와 B를 비트 연산 하는 경우에는 가장 뒤의 자리부터 하나씩 연산을 수행하면 된다.
- not의 경우 자료형에 따라 결과가 달라진다.
- 또, unsigned, signed에 따라서 보여지는 값은 다르다.
- shift left(<<) : A<<B A를 왼쪽으로 B비트 만큼 민다.
- shift right(>>) : A>>B A를 오른쪽으로 B비트 만큼 민다.
- (A + B) / 2는 (A+B) >> 1로 쓸 수 있다.
- 어떤 수가 홀수 인지 판별하는 if(N%2 == 1)은 if(N&1)로 줄여 쓸 수 있다.
- 정수로 집합을 나타낼 수 있다.
- {1, 3, 4, 5, 9} = 570; 1승 + 3승 + 4승 + 5승 + 9승
- 길이가 N인 이진수로 0 ~ N-1 집합을 나타낼 수 있다.
- 전체 집합은 (1<<N) -1로 표현하며 공집합은 0으로 표현한다.
- 현재 집합이 S일 때
  i를 추가 : S | (1 << i)
  i를 검사 : S & (1 << i)
  i를 제거 : S & ~(1 << i)
  i를 토글 (0을 1로, 1을 0으로) : S ^ (1 << i)
- 배열을 사용하는 것이 편하지만, 비트마스크를 사용하는 이유는 집합을
  배열의 인덱스로 표현하 수 있기 때문이다.
- 상태 다이나믹을 할 때 자주 사용하게 된다.
- 비트마스크는 STL의 bitset을 이용해 더 쉽게 나타낼 수 있다.


11723번 : https://www.acmicpc.net/problem/11723

#include <cstdio>
#include <cstring>
using namespace std;
char str[111];
int main() {
	int m;
	int x;
	int s = 0;
	scanf("%d", &m);
	while (m--) {
		scanf("%s", str);
		if (!strcmp(str, "add")) {
			scanf("%d", &x);
			s = s | (1 << x);
		}
		else if (!strcmp(str, "remove")) {
			scanf("%d", &x);
			s = s & ~(1 << x);
		}
		else if (!strcmp(str, "check")) {
			scanf("%d", &x);
			if (s & (1 << x)) printf("%d\n", 1);
			else printf("%d\n", 0);
		}
		else if (!strcmp(str, "toggle")) {
			scanf("%d", &x);
			s = s ^ (1 << x);
		}
		else if (!strcmp(str, "all")) {
			s = (1 << 21) - 1;
		}
		else if (!strcmp(str, "empty")) {
			s = 0;
		}
	}
	return 0;
}

* 순열
- 1 ~ N 까지로 이루어진 수열
- 크기는 항상 N이 되어야 하고, 겹치는 숫자가 존재하지 않음
- 크기가 N인 순열을 총 N!개가 존재한다. N 번째 자리에 N개의 수, N-1 번째 자리에 N-1개... 곱셈
- 순열을 사전 순으로 나열한 경우 N = 3
  1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1
* 다음 순열
- 순열을 사전순으로 나열했을 때, 사전순으로 다음에 오는 순열과 이전에 오는 순열을 찾기
- STL의 algorithm에는 이미 next_permutation과 prev_permutation이 존재한다.
- 다음 순열을 찾는 방법
  1. A[i-1] < A[i]를 만족하는 가장 큰 i를 찾는다.
  - 즉 순열의 마지막 수에서 끝나는 가장 긴 감소수열을 찾아야 한다.
  2. j>=i 이면서 A[j] > A[i-1]을 만족하는 가장 큰 j를 찾는다.
  3. A[i-1]과 A[j]를 swap 한다.
  4. A[i] 부터 순열을 뒤집는다.
  
10972번 : https://www.acmicpc.net/problem/10972

#include <cstdio>
#include <vector>
using namespace std;
bool next_permutation(vector<int>& a, int n) {
	int index = n - 1;
	while (index > 0 && a[index - 1] >= a[index]) {
		index -= 1;
	}
	if (index <= 0) {
		return false;
	}
	int j = n - 1;
	while (a[j] <= a[index - 1]) {
		j -= 1;
	}
	swap(a[index - 1], a[j]);
	j = n - 1;
	int i = index;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (next_permutation(a, n)) {
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
	}
	else {
		printf("-1");
	}
	printf("\n");
	return 0;
}

- stl 사용
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (next_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
	cout << endl;
	return 0;
}

10973번 : 

- stl 사용
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (prev_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
	cout << endl;
	return 0;
}

- 구현
#include <iostream>
#include <vector>
using namespace std;
bool prev_permutation(vector<int>& a, int n) {
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) {
		i -= 1;
	}
	if (i <= 0) {
		return false;
	}
	int j = n - 1;
	while (a[j] >= a[i - 1]) {
		j -= 1;
	}
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (prev_permutation(a, n)) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
	cout << endl;
	return 0;
}

10974번 : https://www.acmicpc.net/problem/10974

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        a[i] = i+1;
    }
    do {
        for (int i=0; i<n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}

1722번 **
