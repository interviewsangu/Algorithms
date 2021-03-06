푼 문제 : 
https://www.acmicpc.net/problem/1463
https://www.acmicpc.net/problem/11726
https://www.acmicpc.net/problem/11727
https://www.acmicpc.net/problem/9095
https://www.acmicpc.net/problem/11052
https://www.acmicpc.net/problem/10844
https://www.acmicpc.net/problem/11057
https://www.acmicpc.net/problem/2193
https://www.acmicpc.net/problem/9465
https://www.acmicpc.net/problem/2156
https://www.acmicpc.net/problem/11053
https://www.acmicpc.net/problem/11055
https://www.acmicpc.net/problem/11722
https://www.acmicpc.net/problem/11054
https://www.acmicpc.net/problem/1912
https://www.acmicpc.net/problem/2579
https://www.acmicpc.net/problem/1699
https://www.acmicpc.net/problem/2133
https://www.acmicpc.net/problem/9461
https://www.acmicpc.net/problem/2225
https://www.acmicpc.net/problem/2011

 
 * Dynamic programming
 두 가지 속성을 만족해야 다이나믹 프로그래밍으로 문제를 풀 수 있다.
 (1) Overlapping Subproblem
 - 부분 문제들이 겹쳐야 한다.
 - 큰 문제와 작은 문제를 같은 방법으로 풀 수 있다.
 - 문제를 작은 문제로 쪼갤 수 있다.
 - 쪼개진 작은 문제는 또 다른 큰 문제가 된다.
 (2) Optimal Substructure
 - 문제의 정답을 작은 문제의 정답에서 구할 수 있다.
 - 예 : 문제의 정답을 작은 문제의 정답을 합하는 것으로 구할 수 있다.
 - Optimal Substructure를 만족한다면, 크기에 상관없이 어떤 한 문제의 정답은 일정
 - 따라서 정답을 한 번 구했으면 Memoization 해 둔다.
 
 * Top down
 - 문제를 작은 문제로 나눈다.
 - 작은 문제를 푼다.
 - 작은 문제를 풀었으니, 이제 문제를 푼다.
 - 재귀 호출을 이용해서 문제를 쉽게 풀 수 있다.
 
 예) 피보나치 
 - 복잡도; 메모 채워야 하는 칸의 수 * 1칸을 채우는 복잡도 = N * O(1) = O(N)
 
 n 번째 피보나치 수를 구하기 위해서는
 작은 문제인 n-1 번째와 n-2 번째를 구한다.
 작은 문제를 풀었다면 n-1 번째와 n-2 번째를 더하여 문제를 푼다.
 
(1) memo가 없는 경우
int fibonnacci(int n){
  if(n <= 1){
    return n;
  }else{
    fibonnacci(n-1) + fibonnacci(n-2);
  }
}

(2) memo가 있는 경우 - 반드시 사용
메모를 읽고나서 써야한다.
int memo[100];
int fibonnacci(int n){
  if(n <= 1){
    return n;
  }else{
    if(memo[n] > 0){ // 존재한다면
      return memo[n]; 
    }
    memo[n] = fibonacci(n-1) + fibonnacci(n-2);
    return memo[n];
  }
}

* Bottom UP
- 문제를 크기가 작은 문제부터 차례대호 푼다.
- 문제의 크기를 조금씩 크게 만들면서 문제를 푼다.
- 반복하다보면 언젠간 큰 문제가 풀린다.
- 반복문을 사용하면 쉽게 구현 가능하다.

int d[100];
int fibonnacci(int n){
  d[0] = 0;
  d[1] = 1;
  for(int i = 2; i<=n; i++){
    d[i] = d[i-1] + d[i-2];
  }
  return d[n];
}

* 다이나믹 문제 풀이 전략
- 문제에서 구하려고 하는 답을 문장으로 나타낸다.
- 예 : 피보나치 수를 구하는 문제
- N 번째 피보나치 수
- 이제 그 문장에 나와있는 변수의 개수만큼 메모하는 배열을 만든다.
- Top-down인 경우에는 재귀 호출의 인자의 개수
- 문제를 작은 문제로 나누고, 수식을 이용해서 문제를 표현한다.

** 문제풀이
- d[N]에 무슨 값이 저장되어야 하는지 먼저 파악
- 대부분의 경우 문제에서 구하라고 한 내용을 그대로 넣어주면 된다.

1463번; 1로 만들기
문제 : 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
연산을 사용하는 횟수의 최솟값을 출력하시오.

입력 : 첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.
출력 : 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

- d[N] = N => 1로 만드는데 필요한 연산의 최소값
- N에 무슨 연산을 할 수 있는가
- 그래프처럼 그리면 편하다.
- d[N/3]과 d[N/2]와 d[N-1]을 비교하면 되겠네. 여기에 1을 더하면 최종 값

Top - down
- Big-oh  ; 총 채워야하는 칸의 개수 N개 * 식 3번(O(1)) = O(N)


#include <iostream>
using namespace std;
int d[1000001];
int go(int n) {
    if (n == 1) {
        return 0;
    }
    if (d[n] > 0) {
        return d[n];
    }
    d[n] = go(n-1) + 1;
    if (n%2 == 0) {
        int temp = go(n/2) + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    if (n%3 == 0) {
        int temp = go(n/3) + 1;
        if (d[n] > temp) {
            d[n] = temp;
        }
    }
    return d[n];
}
int main() {
    int n;
    cin >> n;
    cout << go(n) << '\n';
    return 0;
}

Bottom - up

#include <iostream>
using namespace std;

int d[100001];
int main() {
	int n;
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1) {
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1) {
			d[i] = d[i / 3] + 1;
		}
	}

	cout << d[n] << endl;
	return 0;
}

11726번 - 2 X n 타일링
문제 : 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는
방법의 수를 구하는 프로그램을 작성하시오.

입력 : 첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력 : 첫째 줄에 2×n 크기의 직사각형을 채우는
방법의 수를 10,007로 나눈 나머지를 출력한다.

- d[n] = 2*n을 채우는 방법의 수
- d[n-1] + d[n-2] ; 경우의 수의 합
- 2*0은 1개로 따진다. 공집합과 같이 생각.
- d[1]은 d[0]에 사각형을 하나 놓으면 된다.
- d[2]는 d[1] + d[0]

bottom - up
#include <iostream>
using namespace std;

int d[100001];
int main() {
	d[1] = 1;
	d[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 10007;
	}
	cout << d[n] << endl;
	return 0;
}

top - down - N개를 채워야하며 구하는 과정 1 = O(N)

#include <iostream>
using namespace std;

int d[100001];

int rect(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}

	if (d[n] > 0) {
		return d[n];
	}

	d[n] = rect(n - 1) + rect(n - 2);

	return d[n] % 10007;
}

int main() {
	int n;
	cin >> n;
	cout << rect(n) << endl;
}

(2) 11727번
top - down ; 시간초과

#include <cstdio>
int d[100001];

int rect(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 3;
	}

	if (d[n] > 0) {
		return d[n];
	}

	d[n] = rect(n - 1) + 2 * rect(n - 2);

	return d[n]%10007;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n",rect(n));
    return 0;
}

bottom - up ; 

#include <iostream>
using namespace std;

int d[1001];

int main() {
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 3;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + 2 * d[i - 2];
		d[i] %= 10007; // 주의
	}

	cout << d[n] << endl;
	return 0;
}

9095번 - 1, 2, 3 더하기

문제 : 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다.
합을 나타낼 때는 수를 1개 이상 사용해야 한다.
정수 n이 주어졌을 때, 
n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력 : 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. 
n은 양수이며 11보다 작다.

출력 : 각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수 출력

top - down; O(N)

#include <iostream>
using namespace std;

int d[11];

int sum(int n) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	if (n == 3) {
		return 4;
	}

	if (d[n] > 0) {
		return d[n];
	}
	d[n] += sum(n - 1) + sum(n - 2) + sum(n - 3);
	return d[n];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << sum(n) << endl;
	}
	return 0;
}

bottom - up; N * O(1) + O(1) + O(1) = O(N)

#include <stdio.h>
int d[11];
int main() {
    d[0] = 1;
    for (int i=1; i<=10; i++) {
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",d[n]);
    }
}

11052번 : 카드모으기

문제 : 요즘 민규네 동네에서는 스타트링크에서 만든 PS카드를 모으는 것이 유행이다.

PS카드는 PS(Problem Solving)분야에서 유명한 사람들의 
아이디와 얼굴이 적혀있는 카드이다. 각각의 카드에는 
등급을 나타내는 색이 칠해져 있고, 다음과 같이 8가지가 있다.

전설카드
레드카드
오렌지카드
퍼플카드
블루카드
청록카드
그린카드
그레이카드

카드는 카드팩의 형태로만 구매할 수 있고,
카드팩의 종류는 카드 1개가 포함된 카드팩, 카드 2개가 포함된 카드팩
, ... 카드 N개가 포함된 카드팩과 같이 총 N가지가 존재한다.

민규는 카드의 개수가 적은 팩이더라도 가격이 비싸면 
높은 등급의 카드가 많이 들어있을 것이라는 미신을 믿고 있다.
따라서, 민규는 돈을 최대한 많이 지불해서 카드 N개 구매하려고 한다.
카드가 i개 포함된 카드팩의 가격은 Pi원이다.

예를 들어, 카드팩이 총 4가지 종류가 있고, 
P1 = 1, P2 = 5, P3 = 6, P4 = 7인 경우에 민규가 카드 4개를 
갖기 위해 지불해야 하는 금액의 최댓값은 10원이다. 
2개 들어있는 카드팩을 2번 사면 된다.

P1 = 5, P2 = 2, P3 = 8, P4 = 10인 경우에는 
카드가 1개 들어있는 카드팩을 4번 사면 20원이고, 
이 경우가 민규가 지불해야 하는 금액의 최댓값이다.

마지막으로, P1 = 3, P2 = 5, P3 = 15, P4 = 16인 경우에는
3개 들어있는 카드팩과 1개 들어있는 카드팩을 구매해 
18원을 지불하는 것이 최댓값이다.

카드 팩의 가격이 주어졌을 때, 
N개의 카드를 구매하기 위해 민규가 
지불해야 하는 금액의 최댓값을 구하는 프로그램을 작성하시오.
N개보다 많은 개수의 카드를 산 다음, 
나머지 카드를 버려서 N개를 만드는 것은 불가능하다.
즉, 구매한 카드팩에 포함되어 있는 카드 개수의 합은 N과 같아야 한다.

입력 : 첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)
둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. (1 ≤ Pi ≤ 10,000)

출력 : 첫째 줄에 민규가 카드 N개를 갖기 위해 
지불해야 하는 금액의 최댓값을 출력한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + p[j]);
		}
	}
	cout << d[n] << endl;
	return 0;
}

10844번 : 쉬운 계단 수
문제 : 45656이란 수를 보자.
이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N인 계단 수가 
총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

입력 : 첫째 줄에 N이 주어진다. N은 1보다 크거나 같고,
100보다 작거나 같은 자연수이다.

출력 : 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

이차 배열을 사용해야 하는 경우 탑 다운 방식으로 구현하기가 어렵구나

bottom - up

#include <iostream>
using namespace std;

int d[101][10];
int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2;
		i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j < 9) d[i][j] += d[i - 1][j + 1];
			if (j > 0) d[i][j] += d[i - 1][j - 1];
			d[i][j] %= 1000000000;
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
	}
	ans %= 1000000000;

	cout << ans << endl;
	
	return 0;
}

11057번 : 오르막 수
문제 : 오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다.
이때, 인접한 수가 같아도 오름차순으로 친다.
예를 들어, 2234와 3678, 11119는 오르막 수이지만,
2232, 3676, 91111은 오르막 수가 아니다.

수의 길이 N이 주어졌을 때, 
오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.

입력 : 첫째 줄에 N (1 ≤ N ≤ 1,000)이 주어진다.

출력 : 첫째 줄에 길이가 N인 오르막 수의 개수를 10,007로 나눈 나머지를 출력한다.

#include <iostream>
using namespace std;

int d[1001][10];

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= 10007;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
	}
	ans %= 10007;
	cout << ans << endl;
	return 0;
}

2193번 : 이친수 ** 범위 확인하기
https://www.acmicpc.net/problem/2193

1차원 bottom - up

#include <iostream>
using namespace std;

long long d[91];
int main() {
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 1;

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	cout << d[n] << endl;
	
	return 0;
}

1차원 top - down

#include <iostream>
using namespace std;

long long d[91];

long long bi(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (d[n] > 0) {
		return d[n];
	}

	d[n] = bi(n - 1) + bi(n - 2);

	return d[n];
}

int main() {
	int n;
	cin >> n;

	cout << bi(n) << endl;
	
	return 0;
}

2차원 구현

#include <iostream>
using namespace std;

long long d[91][2];


int main() {
	int n;
	cin >> n;
	d[1][0] = 0;
	d[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[n][0] + d[n][1] << endl;
	
	return 0;
}

9465번 : https://www.acmicpc.net/problem/9465
** 마지막 조건에서 포함되지 않더라도 이전 조건에서 사용을 위해
정의해줘야 할 수도 있음.. 즉, 조건을 꼼꼼하게 살피자

#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))
long long d[100001][3];
long long a[100001][2];

int main() { 
	int t;
	scanf("%d", &t);
	
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i][0]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i][1]);
		}
		
		d[0][0] = 0;
		d[0][1] = 0;
		d[0][2] = 0;

		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][1], d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][1];
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(d[i][0], max(d[i][1], d[i][2]));
		}

		printf("%lld\n", ans);
	}
	return 0;
}

2156번 : https://www.acmicpc.net/problem/2156

1차원 bottom - up

#include <iostream>
using namespace std;
#define max(a,b) (((a)>(b)) ? (a) : (b))

long long d[10001];
long long a[10001];

int main() {
	int n;
	cin >> n;
	d[0] = 0;
	a[0] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = max(d[i - 1], max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]));
	}

	long long ans = 0;

	ans = d[n];
	cout << ans << endl;

	return 0;
}

1차원 top - down

#include <iostream>
using namespace std;
#define max(a,b) (((a)>(b)) ? (a) : (b))

long long d[10001];
long long a[10001];

long long wine(int n) {
	if (n < 1) {
		return 0;
	}
	if (d[n] > 0) {
		return d[n];
	}
	d[n] = max(wine(n - 1), max(wine(n - 2) + a[n], wine(n - 3) + a[n - 1] + a[n]));

	return d[n];
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	long long ans = 0;

	ans = wine(n);

	cout << ans << endl;

	return 0;
}

2차원 구현
#include <iostream>
using namespace std;
#define max(a,b) (((a)>(b)) ? (a) : (b))

long long d[10001][2];
long long a[10001];

int main() {
	int n;
	cin >> n;
	a[0] = 0;
	d[0][0], d[0][1], d[0][2] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = d[i - 1][0] + a[i];
		d[i][2] = d[i - 1][1] + a[i];
	}

	long long ans = 0;

	ans = max(d[n][0], max(d[n][1], d[n][2]));
	cout << ans << endl;

	return 0;
}


* 11053번 : https://www.acmicpc.net/problem/11053


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    for (int i=0; i<n; i++) {
        d[i] = 1;
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
            }
        }
    }
    
    cout << *max_element(d.begin(),d.end()) << '\n';
    return 0;
}

&

#include <cstdio>

int d[1001];
int a[1001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}

	int ans = d[1];
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	printf("%d\n", ans);

	return 0;

}


11055번 : https://www.acmicpc.net/problem/11055

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> d(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		d[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[j] + a[i] > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}

	cout << *max_element(d.begin(), d.end()) << endl;
	return 0;
}

11722번 : https://www.acmicpc.net/problem/11722

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
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i] && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
            }
        }
    }

    cout << *max_element(d.begin(), d.end()) << '\n';
    return 0;
}

#include <cstdio>
int a[1001];
int d[1001];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=n; i>=1; i--) {
        d[i] = 1;
        for (int j=i+1; j<=n; j++) {
            if (a[i] > a[j] && d[i] < d[j]+1) {
                d[i] = d[j]+1;
            }
        }
    }
    int ans = d[1];
    for (int i=2; i<=n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}

* 11054번 : https://www.acmicpc.net/problem/11054

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> d(n);
    vector<int> d2(n);
    for (int i=0; i<n; i++) {
        d[i] = 1;
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[j]+1 > d[i]) {
                d[i] = d[j]+1;
            }
        }
    }
    for (int i=n-1; i>=0; i--) {
        d2[i] = 1;
        for (int j=i+1; j<n; j++) {
            if (a[i] > a[j] && d2[j]+1 > d2[i]) {
                d2[i] = d2[j]+1;
            }
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (ans < d[i]+d2[i]-1) {
            ans = d[i]+d2[i]-1;
        }
    }

    cout << ans << '\n';
    return 0;
}

1912번 : https://www.acmicpc.net/problem/1912

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
    vector<int> d(n);

    for (int i = 0; i < n; i++) {
        d[i] = a[i];
        if (i == 0) continue; // 벡터 범위 주의
        if (d[i] < d[i - 1] + a[i]) {
            d[i] = d[i - 1] + a[i];
        }
    }

    cout << *max_element(d.begin(), d.end()) << endl;

    return 0;

}

2579번 : https://www.acmicpc.net/problem/2579
O(N)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long> a(n+1);
	vector<long> d(n+1);

	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[0] = a[0];
	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 3] + a[i - 1] + a[i], d[i - 2] + a[i]);
	}

	cout << d[n] << endl;
	return 0;
}

2차원 구현
굳이..?

#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
int a[301];
int d[301][3];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    d[1][1] = a[1];
    for (int i=2; i<=n; i++) {
        d[i][2] = d[i-1][1] + a[i];
        d[i][1] = max(d[i-2][1], d[i-2][2]) + a[i];
    }
    printf("%d\n",max(d[n][1], d[n][2]));
    return 0;
}

1699번 : https://www.acmicpc.net/problem/1699
O(N*root(N))

#include <iostream>
using namespace std;
int d[100001];
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        d[i] = i;
        for (int j=1; j*j <= i; j++) {
            if (d[i] > d[i-j*j]+1) {
                d[i] = d[i-j*j]+1;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}

2133번 : https://www.acmicpc.net/problem/2133
*이전거 X 나타낼수 있는 개수

#include <iostream>
using namespace std;
long long d[31];
int main(){
    int n;
    cin >> n;
    d[0] = 1;
    for (int i=2; i<=n; i+=2) {
        d[i] = d[i-2]*3;
        for (int j=i-4; j>=0; j-=2) {
            d[i] += d[j]*2;
        }
    }
    cout << d[n] << '\n';
    return 0;
}

9461번 : https://www.acmicpc.net/problem/9461
* 범위가 틀려서 틀릴수도 있다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long p[101];

int main() {
	int t;
	cin >> t;
	
	
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			if (i == 1 || i == 2 || i == 3) {
				p[i] = 1;
				continue;
			}
			p[i] = p[i - 2] + p[i - 3];
		}
		cout << p[n] << endl;
	}
	return 0;
}


2225번 : https://www.acmicpc.net/problem/2225
** 범위를 제대로 확인하고 무슨 변수 먼저 도는지 확인하자,
먼저도는 변수를 배열의 낮은 차원으로 돌리자.

#include <iostream>
using namespace std;

long long d[201][201];

int main() {
	int n, k;
	cin >> n >> k;

	d[0][0] = 1;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = j; l >= 0; l--) {
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= 1000000000;
			}
		}
	}
	cout << d[k][n] << endl;

	return 0;
}

2011번 : https://www.acmicpc.net/problem/2011

왜 += 인가? ; 2번 나눠서 연산을 해주기 때문에,, 1자리, 2자리 모두 각각 더해지도록 하기 위해서
#include <iostream>
using namespace std;
int d[5001];
int mod = 1000000;
int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    d[0] = 1;
    for (int i=1; i<=n; i++) {
        int x = s[i] - '0';
        if (1 <= x && x <= 9) {
            d[i] += d[i-1];
            d[i] %= mod;
        }
        if (i==1) {
            continue;
        }
        if (s[i-1] == '0') {
            continue;
        }
        x = (s[i-1]-'0')*10 + (s[i]-'0');
        if (10 <= x && x <= 26) {
            d[i] += d[i-2];
            d[i] %= mod;
        }
    }
    cout << d[n] << '\n';
    return 0;
}
