푼 문제 : 
동전 0	https://www.acmicpc.net/problem/11047
회의실배정	https://www.acmicpc.net/problem/1931
ATM	https://www.acmicpc.net/problem/11399
잃어버린 괄호	https://www.acmicpc.net/problem/1541
수 묶기	https://www.acmicpc.net/problem/1744
대회 or 인턴	https://www.acmicpc.net/problem/2875
30	https://www.acmicpc.net/problem/10610
병든 나이트	https://www.acmicpc.net/problem/1783
NMK	https://www.acmicpc.net/problem/1201
행렬	https://www.acmicpc.net/problem/1080
롤러코스터	https://www.acmicpc.net/problem/2873

* 그리디 알고리즘
- 결정해야 할 때, 그 순간에 가장 좋다고 생각하는 것을 선택하며 답을 찾아가는 알고리즘
- 그 때 그 때는 최적일지도 모르지만, 최종적으론느 답이 최적이 아닐 수도 있다.
- 언제 써야 하는가? : 지금 이 순간 가장 좋은 경우를 선택하는 것이 항상 최적인 경우
                    , 수학적 수식으로 풀 수 있는 경우
- 그것이 왜 최적이 되는지를 증명해야하기 때문에 어렵다.

11047번 : 동전 0	https://www.acmicpc.net/problem/11047

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> a;
	int input;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		a.push_back(input);
	}
	int ans = 0;
	for (int i = n-1; i >= 0; i--) {
		while (k - a[i] >= 0) {
			k = k - a[i];
			ans += 1;
		}
		if (k == 0) break;
	}
	printf("%d\n", ans);
	return 0;
}

- 더 빠른 구현
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i=n-1; i>=0; i--) {
        ans += k/a[i];
        k %= a[i];
    }
    cout << ans << '\n';
    return 0;
}

1931번 : https://www.acmicpc.net/problem/1931
- 고려해야 할 것 : 끝나는 시간과 시작하는 시간이 같은 경우 -> lambda
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Meeting {
	int begin, end;
};
int main() {
	int n;
	scanf("%d", &n);
	vector<Meeting> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].begin, &a[i].end);
	}
	sort(a.begin(), a.end(), [](const Meeting &u, const Meeting &v) {
		if (u.end == v.end) {
			return u.begin < v.begin;
		}
		else {
			return u.end < v.end;
		}
		});
	int now = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (now <= a[i].begin) {
			now = a[i].end;
			ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}

11399번 : https://www.acmicpc.net/problem/11399

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	sort(p.begin(), p.end());
	int sum_ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sum_ans += p[i];
		}
	}
	printf("%d\n", sum_ans);
	return 0;
}

- 포문 한번
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	sort(p.begin(), p.end());
	int sum_ans = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i];
		sum_ans += sum;
	}
	printf("%d\n", sum_ans);
	return 0;
}

1541번 : https://www.acmicpc.net/problem/1541

#include <iostream>
#include <vector>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<int> num;
	vector<int> sign;
	bool minus = false;
	int cur = 0;
	sign.push_back(1);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '+') {
				sign.push_back(1);
			}
			else {
				sign.push_back(-1);
			}
			num.push_back(cur);
			cur = 0;
		}
		else {
			cur = cur * 10 + (s[i] - '0');
		}
	}
	num.push_back(cur);
	int ans = 0;
	for (int i = 0; i < num.size(); i++) {
		if (sign[i] == -1) {
			minus = true;
		}
		if (minus) {
			ans -= num[i];
		}
		else {
			ans += num[i];
		}
	}
	cout << ans << endl;
	return 0;
}

1744번 : https://www.acmicpc.net/problem/1744

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> plus;
	vector<int> minus;
	int one = 0;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			one += 1;
		}
		else if (x > 0) {
			plus.push_back(x);
		}
		else if (x < 0) {
			minus.push_back(x);
		}
		else {
			zero += 1;
		}
	}
	sort(plus.begin(), plus.end());
	reverse(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());
	if (plus.size() % 2 == 1) {
		plus.push_back(1);
	}
	if (minus.size() % 2 == 1) {
		minus.push_back(zero > 0 ? 0 : 1);
	}
	int ans = one;
	for (int i = 0; i < plus.size(); i += 2) {
		ans += plus[i] * plus[i + 1];
	}
	for (int i = 0; i < minus.size(); i += 2) {
		ans += minus[i] * minus[i + 1];
	}
	printf("%d\n", ans);
	return 0;
}

2875번 : https://www.acmicpc.net/problem/2875

#include <iostream>
using namespace std;
int main() {
	int n, m, k;
	int ans = 0;
	cin >> n >> m >> k;
	while ((n + m - k >= 3) && (n >= 2) && (m >= 1)) {
		n -= 2;
		m -= 1;
		ans += 1;
	}
	cout << ans << endl;
}

10610번 : https://www.acmicpc.net/problem/10610

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	int sum = 0;
	for (char c : s) {
		sum += c - '0';
	}
	sort(s.begin(), s.end());
	if (s[0] == '0' && sum % 3 == 0) {
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}

1783번 : https://www.acmicpc.net/problem/1783

#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int h, w;
	cin >> h >> w;
	if (h == 1) {
		cout << 1 << endl;
	}
	else if (h == 2) {
		cout << min(4, (w + 1) / 2) << endl;
	}
	else if (h >= 3) {
		if (w < 7) {
			cout << min(4, w) << endl;
		}
		else {
			cout << w - 2 << endl;
		}
	}
	return 0;
}

*** 1201번 : https://www.acmicpc.net/problem/1201

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n);
    if (m+k-1 <= n && n <= m*k) {
        for (int i=0; i<n; i++) {
            a[i] = i+1;
        }
        vector<int> g;
        g.push_back(0);
        g.push_back(k);
        n -= k;
        m -= 1;
        int gs = m == 0 ? 1 : n/m;
        int r = m == 0 ? 0 : n%m;
        for (int i=0; i<m; i++) {
            g.push_back(g.back()+gs + (r > 0 ? 1 : 0));
            if (r > 0) {
                r -= 1;
            }
        }
        for (int i=0; i<g.size()-1; i++) {
            reverse(a.begin()+g[i], a.begin()+g[i+1]);
        }
        for (int i=0; i<a.size(); i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
    return 0;
}

1080번 : https://www.acmicpc.net/problem/1080

#include <cstdio>
using namespace std;
int a[50][50];
int b[50][50];
void flip(int x, int y) {
    for (int i=x; i<=x+2; i++) {
        for (int j=y; j<=y+2; j++) {
            a[i][j] = 1-a[i][j];
        }
    }
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&b[i][j]);
        }
    }
    int ans = 0;
    for (int i=0; i<n-2; i++) {
        for (int j=0; j<m-2; j++) {
            if (a[i][j] != b[i][j]) {
                ans += 1;
                flip(i, j);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] != b[i][j]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

******2873번 : https://www.acmicpc.net/problem/2873

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[1000][1000];
void append(string& s, char c, int cnt) {
    for (int i = 0; i < cnt; i++) {
        s += c;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    string s = "";
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                append(s, 'R', m - 1);
                if (i != n - 1) {
                    append(s, 'D', 1);
                }
            }
            else {
                append(s, 'L', m - 1);
                append(s, 'D', 1);
            }
        }
    }
    else if (m % 2 == 1) {
        for (int j = 0; j < m; j++) {
            if (j % 2 == 0) {
                append(s, 'D', n - 1);
                if (j != m - 1) {
                    append(s, 'R', 1);
                }
            }
            else {
                append(s, 'U', n - 1);
                append(s, 'R', 1);
            }
        }
    }
    else {
        int x, y;
        x = 0;
        y = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 1) {
                    if (a[x][y] > a[i][j]) {
                        x = i;
                        y = j;
                    }
                }
            }
        }
        int x1 = 0;
        int y1 = 0;
        int x2 = n - 1;
        int y2 = m - 1;
        string s2 = "";
        while (x2 - x1 > 1) {
            if (x1 / 2 < x / 2) {
                append(s, 'R', m - 1);
                append(s, 'D', 1);
                append(s, 'L', m - 1);
                append(s, 'D', 1);
                x1 += 2;
            }
            if (x / 2 < x2 / 2) {
                append(s2, 'R', m - 1);
                append(s2, 'D', 1);
                append(s2, 'L', m - 1);
                append(s2, 'D', 1);
                x2 -= 2;
            }
        }
        while (y2 - y1 > 1) {
            if (y1 / 2 < y / 2) {
                append(s, 'D', 1);
                append(s, 'R', 1);
                append(s, 'U', 1);
                append(s, 'R', 1);
                y1 += 2;
            }
            if (y / 2 < y2 / 2) {
                append(s2, 'D', 1);
                append(s2, 'R', 1);
                append(s2, 'U', 1);
                append(s2, 'R', 1);
                y2 -= 2;
            }
        }
        if (y == y1) {
            append(s, 'R', 1);
            append(s, 'D', 1);
        }
        else {
            append(s, 'D', 1);
            append(s, 'R', 1);
        }
        reverse(s2.begin(), s2.end());
        s += s2;
    }
    cout << s << '\n';
    return 0;
}
