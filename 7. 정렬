푼 문제 : 수 정렬하기 2	https://www.acmicpc.net/problem/2751
좌표 정렬하기	https://www.acmicpc.net/problem/11650
좌표 정렬하기 2	https://www.acmicpc.net/problem/11651
나이순 정렬	https://www.acmicpc.net/problem/10814
국영수	https://www.acmicpc.net/problem/10825
수 정렬하기 3	https://www.acmicpc.net/problem/10989
카드	https://www.acmicpc.net/problem/11652
K번째 수	https://www.acmicpc.net/problem/11004
버블 소트	https://www.acmicpc.net/problem/1377

* 정렬
- 정렬은 빠르면 빠를수록 좋기 때문에 NlogN 알고리즘을 사용한다.(퀵, 힙, 병합)
- 정렬은 직접 구현하기 보다는 STL에 있는 sort를 사용하는 것이 좋다.
- sort(begin, end); begin부터 end 바로 전까지를 정렬하는 함수이다; [begin, end)
- 다음은 a[0]부터 a[n-1]까지를 정렬하는 소스이다.
int n = 10;
int a[10] = {};
sort(a, a+n);

2751번 : https://www.acmicpc.net/problem/2751

- sort를 사용한 구현
#include <iostream>
#include <algorithm>
using namespace std;

int a[1000001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}

- quicksort 직접 구현
#include <iostream>
using namespace std;

int a[1000000];

void swap(int& x, int& y) {
	int z = x;
	x = y;
	y = z;
}
int choosePivot(int low, int high) {
	return low + (high - low) / 2;
}
int partition(int low, int high) {
	int pivotIndex = choosePivot(low, high);
	int pivotValue = a[pivotIndex];
	swap(a[pivotIndex], a[high]);
	int storeIndex = low;
	for (int i = low; i < high; i++) {
		if (a[i] < pivotValue) {
			swap(a[i], a[storeIndex]);
			storeIndex += 1;
		}
	}
	swap(a[storeIndex], a[high]);
	return storeIndex;
}
void quicksort(int low, int high) {
	if (low < high) {
		int pivot = partition(low, high);
		quicksort(low, pivot - 1);
		quicksort(pivot + 1, high);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}

- mergesort 직접 구현; 분할 정복에서 자세히
#include <cstdio>
int a[1000000];
int b[1000000];

void merge(int start, int end) {
    int mid = (start+end)/2;
    int i = start;
    int j = mid+1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) {
        b[k++] = a[i++];
    }
    while (j <= end) {
        b[k++] = a[j++];
    }
    for (int i=start; i<=end; i++) {
        a[i] = b[i-start];
    }
}
void sort(int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start+end)/2;
    sort(start, mid);
    sort(mid+1, end);
    merge(start, end);
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    sort(0, n-1);
    for (int i=0; i<n; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}

11650번 : https://www.acmicpc.net/problem/11650

- 구조체와 cmp 함수를 직접 구현한 경우
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
	int x, y;
};
bool cmp(const Point& u, const Point& v) {
	if (u.x < v.x) {
		return true;
	}
	else if (u.x == v.x) {
		return u.y < v.y;
	}
	else {
		return false;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < a.size(); i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
	return 0;
}

- 연산자를 오버로딩한 경우; sort에 3번째 인자를 전달할 필요가 없다.
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
	int x, y;
	bool operator < (const Point& v) const {
		if (x < v.x) {
			return true;
		}
		else if (x == v.x) {
			return y < v.y;
		}
		else {
			return false;
		}
	}
};

int main() {
	int n;
	scanf("%d", &n);
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		printf("%d %d\n", a[i].x, a[i].y);
	}
	return 0;
}

- pair를 사용하는 경우
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		printf("%d %d\n", a[i].first, a[i].second);
	}
	return 0;
}

11651번 : https://www.acmicpc.net/problem/11651
- cmp를 구현한 경우
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int>& u, const pair<int, int>& v) {
	if (u.second == v.second) return u.first < v.first;
	else return u.second < v.second;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < a.size(); i++) {
		printf("%d %d\n", a[i].first, a[i].second);
	}
	return 0;
}

- 뒤집어서 저장
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].second,&a[i].first);
    }
    sort(a.begin(),a.end());
    for (auto &p : a) {
        printf("%d %d\n",p.second, p.first);
    }
    return 0;
}

* stable sorting
- 같은 것이 있는 경우에 정렬하기 전의 순서가 유지되는 정렬 알고리즘을
  stable sorting 알고리즘이라고 한다. 
  시간 복잡도가 NlgN인 알고리즘 중에는 merge sort가 있다.
  STL에는 stable_sort 알고리즘을 사용하면 된다.
  시간 복잡도가 N^2인 알고리즘 중에는 Bubble sort가 있다.

10814번 : https://www.acmicpc.net/problem/10814

- 구조체 변수를 사용
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Person {
	int age;
	string name;
	int join;
};
int main() {
	int n;
	cin >> n;
	vector<Person> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].age >> a[i].name;
		a[i].join = i;
	}
	sort(a.begin(), a.end(), [](Person u, Person v) {
		return (u.age < v.age) || (u.age == v.age && u.join < v.join);
	});

	for (auto p : a) {
		cout << p.age << ' ' << p.name << endl;
	}
	return 0;
}

- 구조체 변수 없이 stable을 사용한 경우
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Person {
	int age;
	string name;
};
int main() {
	int n;
	cin >> n;
	vector<Person> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].age >> a[i].name;
	}
	stable_sort(a.begin(), a.end(), [](Person u, Person v) {
		return (u.age < v.age);
	});

	for (auto p : a) {
		cout << p.age << ' ' << p.name << endl;
	}
	return 0;
}

- 람다 식 보다 cmp를 구현하는게 속도가 빠르네..
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Person {
    int age;
    string name;
};
bool cmp(const Person &u, const Person &v) {
    return u.age < v.age;
}
int main() {
    int n;
    cin >> n;

    vector<Person> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].age >> a[i].name;
    }

    stable_sort(a.begin(), a.end(), cmp);

    for (int i=0; i<n; i++) {
        cout << a[i].age << ' ' << a[i].name << '\n';
    }

    return 0;
}

10825번 : https://www.acmicpc.net/problem/10825
- tuple을 사용하지 않은 구현
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Person {
    string name;
    int kor, eng, math;
};
bool cmp(const Person &u, const Person &v) {
    if (u.kor > v.kor) {
        return true;
    } else if (u.kor == v.kor) {
        if (u.eng < v.eng) {
            return true;
        } else if (u.eng == v.eng) {
            if (u.math > v.math) {
                return true;
            } else if (u.math == v.math) {
                return u.name < v.name;
            }
        }
    }
    return false;
}
int main() {
    int n;
    cin >> n;

    vector<Person> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }

    sort(a.begin(), a.end(), cmp);

    for (int i=0; i<n; i++) {
        cout << a[i].name << '\n';
    }

    return 0;
}

- tuple을 사용한 구현
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
struct Person {
    string name;
    int kor, eng, math;
};
bool cmp(const Person &u, const Person &v) {
    return make_tuple(-u.kor, u.eng, -u.math, u.name) < make_tuple(-v.kor, v.eng, -v.math, v.name);
}
int main() {
    int n;
    cin >> n;

    vector<Person> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }

    sort(a.begin(), a.end(), cmp);

    for (int i=0; i<n; i++) {
        cout << a[i].name << '\n';
    }

    return 0;
}

10989번 : https://www.acmicpc.net/problem/10989

- 메모리 초과
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int a[10000001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}


- 다른 방식의 구현; 최대값이 10000임을 이용
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int c[10001];

int main() {
	int n;
	int a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		c[a] += 1;
	}
	for (int i = 1; i <=10000; i++) {
		if (c[i] > 0) {
			for (int j = 0; j < c[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
	return 0;
}

11652번 : https://www.acmicpc.net/problem/11652

#include <cstdio>
#include <algorithm>
using namespace std;
long long a[1000000];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    long long ans = a[0];
    int ans_cnt = 1;
    int cnt = 1;
    for (int i=1; i<n; i++) {
        if (a[i] == a[i-1]) {
            cnt += 1;
        } else {
            cnt=1;
        }
        if (ans_cnt < cnt) {
            ans_cnt = cnt;
            ans = a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}

- map을 이용한 구현
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    scanf("%d",&n);
    map<long long, int> d;
    while (n--) {
        long long x;
        scanf("%lld",&x);
        d[x] += 1;
    }
    int m = 0;
    long long ans = 0;
    for (auto &p : d) {
        if (p.second > m) {
            m = p.second;
            ans = p.first;
        }
    }
    printf("%lld\n",ans);
    return 0;
}

11004번 : https://www.acmicpc.net/problem/11004

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[5000000];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    k -= 1;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    nth_element(a,a+k,a+n);
    printf("%d\n",a[k]);
    return 0;
}

- quicksort를 이용해 앞에서부터 k만 정렬시켜 정렬이 완료되면 k번째를 출력하는 식으로
  문제를 풀 수 있다.

1377번 : https://www.acmicpc.net/problem/1377
- 정렬 횟수를 결정하는 문제. 다음 코드를 빠르게 만들어야 한다.
  N^2으로 돌리면 50만의 제곱이기 때문에 무조건 시간 초과이다.
bool change = false;
for (int i=1; i<=n+1; i++) {
    change = false;
    for (int j=1; j<=n-i; j++) {
        if (a[j] > a[j+1]) {
            change = true;
            swap(a[j], a[j+1]);
        }
    }
    if (change == false) {
        cout << i << '\n';
        break;
    }
}

- 버블 소트를 할 필요 없이 그냥 정렬을하고 인덱스를 이용하면 되겠네

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i <n; i++) {
        if (ans < a[i].second - i) {
            ans = a[i].second - i;
        }
    }
    ans += 1;//뒤에 달아줘야해 포문 다 돌리고
    cout << ans << endl;
    return 0;
}

