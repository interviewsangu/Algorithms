푼 문제 : 
랜선 자르기	https://www.acmicpc.net/problem/1654
나무 자르기	https://www.acmicpc.net/problem/2805
공유기 설치	https://www.acmicpc.net/problem/2110
중량제한	https://www.acmicpc.net/problem/1939
놀이 공원	https://www.acmicpc.net/problem/1561
사다리	https://www.acmicpc.net/problem/2022

* 이분 탐색
- 정답을 구하는 것은 어렵지만 가능한지 아닌지를 알아내는 것은 쉬운 것들이 있다.
- 정답을 구하는 문제는 최적화가 필요하나 가능성을 알아보는 경우 필요하지 않다.
- 정답을 구하는 문제는 가능여부를 판별하는 문제로 바꿀 수 있다.
- 예, A에서 B가지 가는 가장 빠른 시간이 M인 경우에
  M보다 빠른 시간은 모두 불가능, M보다 큰 시간은 모두 가능
- 어떤 기준 X를 가지고 Yes/No로 나누어지는 것만 정답을 찾을 수 있다.
  이때 정답은 기준선이 되며, 그 값은 최대 혹은 최소이다.

1654번 : https://www.acmicpc.net/problem/1654
- 최소(left)와 최대(right)를 찾는게 중요하다.
#include <cstdio>
int k, n;
long long a[10000];
bool check(long long x) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += a[i] / x;
	}
	return cnt >= n;
}
int main() {
	scanf("%d %d", &k, &n);
	long long max = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		if (max < a[i]) {
			max = a[i];
		}
	}
	long long ans = 0;
	long long l = 1;
	long long r = max;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

2805번 : https://www.acmicpc.net/problem/2805

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool check(vector<long long> &a, long long mid, long long m) {
    int n = a.size();
    long long cnt = 0;
    for (int i=0; i<n; i++) {
        if (a[i]-mid > 0) {
            cnt += a[i]-mid;
        }
    }
    return cnt >= m;
}
int main() {
    int n;
    long long m;
    scanf("%d %lld",&n,&m);
    vector<long long>a(n);
    long long l=0;
    long long r=0;
    for (int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
        if (r < a[i]) {
            r = a[i];
        }
    }
    long long ans = 0;
    while (l <= r) {
        long long mid = (l+r)/2;
        if (check(a,mid,m)) {
            ans = max(ans,mid);
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

* 2110번 : https://www.acmicpc.net/problem/2110

#include <cstdio>
#include <algorithm>
using namespace std;
int n, c;
long long x[200000];
bool check(long long length) {
	int cnt = 1;
	int last = x[0];
	for (int i = 1; i < n; i++) {
		if (x[i] - last >= length) {
			cnt += 1;
			last = x[i];
		}
	}
	return cnt >= c;
}
int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x[i]);
	}
	sort(x, x + n);
	long long l = 1;
	long long r = x[n - 1]- x[0];
	long long ans = 1;
	while (l <= r) {
		long long mid = (l+r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%lld", ans);
	return 0;
}

** 1939번 : https://www.acmicpc.net/problem/1939

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int>> a[10001];
bool c[10001];
int n, m;
int st, ed;
bool go(int node, int limit) {
	if (c[node]) {
		return false;
	}
	c[node] = true;
	if (node == ed) {
		return true;
	}
	for (auto& p : a[node]) {
		int next = p.first;
		int cost = p.second;
		if (cost >= limit) {
			if (go(next, limit)) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	scanf("%d %d", &st, &ed);
	int l, r;
	l = 1;
	r = 1000000000;
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		memset(c, false, sizeof(c));
		if (go(st, mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

** 1561번 : https://www.acmicpc.net/problem/1561
#include <iostream>
using namespace std;
int a[10000];
int p,n;
int main() {
    cin >> p >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    if (p <= n) {
        printf("%d\n",p);
        return 0;
    }
    long long left = 0;
    long long right = 2000000000LL * 1000000LL;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long begin, end;
        begin = end = 0;
        end = n;
        for (int i=0; i<n; i++) {
            end += mid/a[i];
        }
        begin = end;
        for (int i=0; i<n; i++) {
            if (mid % a[i] == 0) {
                begin -= 1;
            }
        }
        begin += 1;
        if (p < begin) {
            right = mid-1;
        } else if (p > end) {
            left = mid+1;
        } else {
            for (int i=0; i<n; i++) {
                if (mid % a[i] == 0) {
                    if (p == begin) {
                        printf("%d\n",i+1);
                        return 0;
                    }
                    begin += 1;
                }
            }
        }
    }
    return 0;
}

2022번 : https://www.acmicpc.net/problem/2022

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	double x, y, c;
	scanf("%lf %lf %lf", &x, &y, &c);
	double left = 0;
	double right = min(x, y);
	while (abs(left - right) > 1e-6) {
		double mid = (left + right) / 2;
		double d = mid;
		double h1 = sqrt(x * x - d * d);
		double h2 = sqrt(y * y - d * d);
		double h = (h1 * h2) / (h1 + h2);
		if (h > c) left = mid;
		else right = mid;
	}
	printf("%.3lf\n", left);
	return 0;
}
