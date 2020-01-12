푼 문제 : 
나머지	https://www.acmicpc.net/problem/10430
최대공약수와 최소공배수	https://www.acmicpc.net/problem/2609
최소공배수	https://www.acmicpc.net/problem/1934
GCD 합	https://www.acmicpc.net/problem/9613
진법 변환 2	https://www.acmicpc.net/problem/11005
진법 변환	https://www.acmicpc.net/problem/2745
2진수 8진수	https://www.acmicpc.net/problem/1373
8진수 2진수	https://www.acmicpc.net/problem/1212
-2진수	https://www.acmicpc.net/problem/2089
Base Conversion	https://www.acmicpc.net/problem/11576
소수 찾기	https://www.acmicpc.net/problem/1978
소수 구하기	https://www.acmicpc.net/problem/1929
골드바흐의 추측	https://www.acmicpc.net/problem/6588
소인수분해	https://www.acmicpc.net/problem/11653
팩토리얼	https://www.acmicpc.net/problem/10872
팩토리얼 0의 개수	https://www.acmicpc.net/problem/1676
조합 0의 개수	https://www.acmicpc.net/problem/2004

* 나머지 연산
- (A+B)%C = ((A%C) + (B%C))%C와 같다.
- dynamic programming에서 매번 나머지 연산을 해주는 이유는 계속해서 정수범위가
  넘어가지 않게 하기 위함이다.
- (A + B) mod M = ((A mod M) + (B mod M)) mod M
- (A X B) mod M = ((A mod M) X (B mod M)) mod M
- 나누기의 경우에는 성립하지 않는다. (Modular Inverse를 구해야 함)
- 뺄셈의 경우에는 먼저 mod 연산을 한 결과가 음수가 나올 수 있기 때문에 다음과 같이 한다.
  (A - B) mod M = ((A mod M) - (B mod M) + M) mod M

10430번 : https://www.acmicpc.net/problem/10430

#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b) % c << '\n' 
  << (a % c + b % c) % c << '\n' << (a * b) % c << '\n' << (a % c * b % c) % c;

	return 0;
}

* 최대공약수
- 최대공약수를 구하는 가장 쉬운 방법은 2부터 min(a,b)까지 모든 정수로 나누어 보는 방법
- 최대공약수가 1인 두 수를 서로소(Coprime)라고 한다.
int g = 1;
for(int i=2; i<=min(a,b); i++){
  if(a%i == 0 && b%i == 0){
    g = i;
  }
}
- 위의 방법보다 더 빠르게 구현하는 방법은 유클리드 알고리즘을 사용하는 것이다.
- a를 b로 나눈 나머지를 r이라고 했을 때
- GCD(a,b) = GCD(b, a%b)와 같다.
- r, 즉 A%B가 0이면 그 때 b가 최대 공약수이다.
- 재귀함수를 사용해서 구현
int gcd(int a, int b){
  if(b==0){
    return a;
  }else{
    return gcd(b, a%b);
  }
}
- 이때 a<b인 경우 따로 신경쓸 필요가 없다. 자동으로 바뀌기 때문이다.
- 재귀를 사용하지 않는 경우
int gcd(int a, int b){
  while(b!=0){
    r = a%b;
    a = b;
    b = r;
  }
  return a;
}
- 세 수의 최대 공약수는 다음과 같이 구한다.
- GCD(a,b,c) = GCD(a, GCD(b,c)) 순서는 바뀌어도 상관없다. 개수가 추가 되어도 상관없다.

* 최소공배수
- 최소공배수는 GCD를 응용해서 구할 수 있다.
- L = (A*B)/G
- 최소공배수와 최대공약수의 곱은 두 수의 곱과 같기 때문이다.

2609번 : https://www.acmicpc.net/problem/2609

#include <iostream>
using namespace std;

int _gcd(int a, int b) {
	int r;

	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {
	int a, b;
	cin >> a >> b;

	int gcd, lcm;
	gcd = _gcd(a, b);
	lcm = (a * b) / gcd;

	cout << gcd << '\n' << lcm << endl;

	return 0;
}

9613번 : https://www.acmicpc.net/problem/9613

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int d[101];

		for (int i = 1; i <= n; i++) {
			cin >> d[i];
		}

		long long ans = 0;
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans += gcd(d[i], d[j]);
			}
		}
		cout << ans << endl;
	}
}

* 진법 변환
- 10진법 수 N을 B진법으로 바꾸려면 N이 0이 될때 까지 나머지를 계속해서 구하면 된다.

11005번 : https://www.acmicpc.net/problem/11005

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n, b;
	cin >> n >> b;
	string ans = "";

	while (n > 0) {
		int r = n % b;
		if (r < 10) {
			ans += (char)(r + '0');
		}
		else {
			ans += (char)(r - 10 + 'A');
		}

		n /= b;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}

- B진법 수 N을 10진수로 바꾸려면 B^k을 곱하면서 더해가면 된다.

2745번 : https://www.acmicpc.net/problem/2745

#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans = 0;
	string s;
	int b;

	cin >> s >> b;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			ans = ans * b + (s[i] - '0');
		}
		else {
			ans = ans * b + (s[i] - 'A' + 10);
		}
	}
	cout << ans << endl;
	return 0;
}

1373번 : https://www.acmicpc.net/problem/1373
- 왜 n%3을 쓰는가, 3개씩 끊어야 하기 때문에 ==1, ==2를 미리 처리해주고 그다음부터 시작
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	if (n % 3 == 1) {
		cout << s[0];
	}else if (n % 3 == 2) {
		cout << (s[0] - '0') * 2 + (s[1] - '0');
	}

	for (int i = n % 3; i < n; i += 3) {
		cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
	}
	cout << endl;

	return 0;
}

** 1212번 : https://www.acmicpc.net/problem/1212
- 배열을 이용하면 편하구나..
- 함수가 생각나지 않거나 개수가 얼마 되지 않으면 조건문으로

#include <iostream>
#include <string>
using namespace std;
string eight[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
int main() {
	string s;
	cin >> s;
	bool start = true;
	if (s.length() == 1 && s[0] - '0' == 0) {
		cout << "0";
	}
	for (int i = 0; i < s.length(); i++) {
		int n = s[i] - '0';
		if (start == true && n < 4) {
			if (n == 0) {
				continue;
			}
			else if (n == 1) {
				cout << "1";
			}
			else if (n == 2) {
				cout << "10";
			}
			else if (n == 3) {
				cout << "11";
			}
			start = false;
		}
		else {
			cout << eight[n];
			start = false;
		}
	}
	return 0;
}

*** 2089번 : https://www.acmicpc.net/problem/2089

#include <cstdio>

void go(int n) {
    if (n == 0) {
        return;
    }
    if (n % 2 == 0) {
        go(-(n / 2));
        printf("0");
    }
    else {
        if (n > 0) {
            go(-(n / 2));
        }
        else {
            go((-n + 1) / 2);
        }
        printf("1");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
    }
    else {
        go(n);
    }
    return 0;
}


11576번 : https://www.acmicpc.net/problem/11576

#include <iostream>
using namespace std;

void convert(int num, int base) {
	if (num == 0) {
		return;
	}
	convert(num / base, base);
	cout << (num % base) << ' ';
}

int main() {
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ans = ans * a + x;
	}
	convert(ans, b);
	return 0;
}

* 소수
- 2보다 크거나 같고, N-1보다 작거나 같은 자연수로 나누어 떨어지면 안된다.
- 일반적인 구현
bool prime(int n){
  if(n<2){
    return false;
  }
  for(int i=2; i<=n-1; i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
- 더 빠르게 구현하는 방법은 N = a*b에서 가능 a 값 중 가장 작은 값이 2이기 때문에
  b는 N/2를 넘지 않음을 이용하여 i = n/2까지만 구현하면 된다.
bool prime(int n){
  if(n<2){
    return false;
  }
  for(int i=2; i<=n/2; i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
- 이보다 더 빠르게 구현하는 방법은 N = a*b에서 a<=b일 때 a값으로 가능한 가장 최대 값은
  루트 N 이므로 루트 N 까지만 구현하면 된다.
- 24의 약수는 2, 3, 4, 6, 8, 12이고 루트 24 = 4.xx 를 기준으로 2, 3, 4 - 6, 8, 12
  이므로 뒤의 수가 나오기 위해서는 반드시 앞의 수와 짝을 지어 나와야 하는 원리를 이용
bool prime(int n){
  if(n<2){
    return false;
  }
  for(int i=2; i*i<=n; i++){
    if(n%i==0){
      return false;
    }
  }
  return true;
}
- 이 때 O(root(N))이 되므로 N이 1억이라고 치면 1만이 되기 때문에 큰 차이를 보인다.
- 컴퓨터에서 실수는 근사값으로 인해 오차를 나타내므로 i*i를 통해 루트를 대신함이 좋다.

1978번 : https://www.acmicpc.net/problem/1978

#include <iostream>
using namespace std;

bool prime(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (prime(x)) {
			cnt += 1;
		}
	}
	cout << cnt << endl;
	return 0;
}

- 위에서 어떤 수 N이 소수인지 아닌지 알아내는데 걸리는 시간 복잡도는 O(루트N)이었다.
- 따라서 O(N루트N)을 나타내며 여러 소수를 구할때 시간이 너무 오래 걸린다.
- 예를 들어 N이 백만인 경우 10억 = 10초를 경과한다.
- 에라토스테네스의 체를 통하여 해결할 수 있다.
- 1부터 N까지 범위 안에 들어가는 모든 소수를 구하려면 에라토스테네스의 체를 사용한다.
  (1) 2부터 N까지 모든 수를 써놓는다.
  (2) 아직 지워지지 않은 수 중에서 가장 작은 수를 찾는다.
  (3) 그 수는 소수이다.
  (4) 이제 그 수의 배수를 모두 지운다.
- 시뮬레이션을 해보면 다음 소수로 넘어갈때 해당 수의 제곱수 앞까지는 이미 지워져있는 상태이다.
- 다음과 같이 구현하며 i*i가 정수 범위를 넘어갈 경우 i*2로 대체한다.
  그 이유는, 지웠던 곳을 한번더 지우던 말던 상관없기 때문이다. 중요한건 공간이니까.
int p[100]; // 소수 저장
int pn = 0; // 소수의 개수
bool c[101]; // 지워졌으면 true
int n = 100; // 100까지 소수 찾기
for(int i = 2; i<=n; i++){
  if(c[i] == false){
    p[pn++] = i;
    for(int j = i*2; j<=n; j+=i){
      c[j] = true;
    }
  }
}
- 해당 알고리즘은 O(NlnlnN)을 나타낸다.

1929번 : https://www.acmicpc.net/problem/1929

#include <iostream>
using namespace std;
const int MAX = 1000000;
bool check[MAX + 1]; // true 지워짐
int main() {
	check[0], check[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (check[i] == false) {
			cout << i << endl;
		}
	}
	return 0;
}

* 골드바흐의 추측
- 2보다 큰 모든 짝수는 두 소수의 합으로 표현 가능하다.
- 위의 문장에 3을 더하면
- 5보다 큰 모든 홀수는 세 소수의 합으로 표현 가능하다.

6588번 : https://www.acmicpc.net/problem/6588

#include <iostream>
using namespace std;
const int MAX = 1000000;
int prime[MAX];
int pn;
bool check[MAX+1]; // true: 지워진것 (소수가 아님), false: 지워지지 않음 (소수)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 2; i <= MAX; i++) {
        if (check[i] == false) {
            prime[pn++] = i;
            for (int j = i + i; j <= MAX; j += i) {
                check[j] = true;
            }
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 1; i < pn; i++) {
            if (check[n - prime[i]] == false) {
                cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
                break;
            }
        }
    }
    return 0;
}



* 소인수분해
- 정수 N을 소수의 곱으로 분해
- 소수를 구하지 않고 해결 가능
- N을 소인수분해 했을 때, 나타날 수 있는 인수 중 가장 큰 값은 루트N이다.
- 따라서 2부터 루트N까지 for문을 돌면서
- N을 나눌 수 있으면, 나눌 수 없을 때 까지 계속해서 나누면 된다.
for(int i=2; i*i <=n; i++){
	while(n%i == 0){
		printf("%d\n", i);
		n /= i;
	}
}
if(n>1) printf("%d\n",);

11653번 : https://www.acmicpc.net/problem/11653

#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			printf("%d\n", i);
			n /= i;
		}
	}
	if (n > 1) {
		printf("%d\n", n);
	}
	return 0;
}

10872번 : https://www.acmicpc.net/problem/10872

#include <cstdio>

int main() {
	int n;
	scanf("%d",&n);
	long long ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
	}
	printf("%lld\n", ans);
	return 0;
}

- 다른 구현
#include <iostream>
using namespace std;
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}
int main() {
    int n;
    cin >> n;
    cout << factorial(n) << '\n';
    return 0;
}

1676번 : https://www.acmicpc.net/problem/1676
- 소인수 분해 해서 5의 개수를 세면 되겠네
#include <iostream>
using namespace std;
int main() {
    int ans = 0;
    int n;
    cin >> n;
    for (int i=5; i<=n; i*=5) {
        ans += n/i;
    }
    cout << ans << '\n';
    return 0;
}

#include <cstdio>

int main() {
	int n;
	scanf("%d",&n);
	int cnt = 0;
	int temp;
	for (int i = 1; i <= n; i++) {
		temp = i;
		while (temp % 5 == 0) {
			cnt += 1;
			temp = temp / 5;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
