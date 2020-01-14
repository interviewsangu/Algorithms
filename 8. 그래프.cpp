푼 문제 :
DFS와 BFS	https://www.acmicpc.net/problem/1260
연결 요소의 개수	https://www.acmicpc.net/problem/11724
이분 그래프	https://www.acmicpc.net/problem/1707
순열 사이클	https://www.acmicpc.net/problem/10451
반복수열	https://www.acmicpc.net/problem/2331
텀 프로젝트	https://www.acmicpc.net/problem/9466
단지번호붙이기	https://www.acmicpc.net/problem/2667
섬의 개수	https://www.acmicpc.net/problem/4963
미로 탐색	https://www.acmicpc.net/problem/2178
토마토	https://www.acmicpc.net/problem/7576
다리 만들기	https://www.acmicpc.net/problem/2146

* 그래프
- 자료구조의 일종
- 정점(Node, Vertex)
- 간선(Edge) : 정점간의 관계를 나타낸다.
- G = (V,E)로 나타낸다.
- 사이클은 경로 중에서 시작점과 도착점이 같은 경로를 의미한다.
- 특별한 말이 없으면, 일반적으로 사용하는 경로와 사이클은 단순 경로/사이클
  (경로/사이클에서 같은 정점을 두 번 이상 방문하지 않는 경로/사이클)
- 방향이 없는 그래프의 경우, 양 방향을 모두 저장한다.
- 간선을 효율적으로 저장하는 것이 그래프를 제대로 저장하는 것이다.
  이때 효율적이라는 말은 경로를 제대로 찾아갈 수 있음을 의미한다.
- 가중치가 0까지 포함하는 경우, 간선이 없을 때는 -1을 저장한다.
- 가중치가 정수의 범위이면 간선이 없을 때 무엇을 저장해야할지 알 수 없다.
  이 경우 행렬을 하나 더 만든다.
- 차수의 경우 in-degree와 out-degree를 각각 구해 더한다.

* 그래프의 표현
- 인접 행렬의 경우 정점의 개수를 V라고 할 때 V*V 크기의 이차원 배열을 이용한다.
  A[i][j] = 1(i->j 간선이 있을 때)
int a[10][10];
int main(){
  int n, m; // 정점의 개수, 간선의 개수
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++){
    int u,v;
    scanf("%d %d", &u, &v);
    a[u][v] = a[v][u] = 1; //방향 그래프의 경우 두번 째 항 삭제
  }
}
- 가중치가 주어진 경우 마지막 행렬에 1을 넣는 것을 가중치로 바꿔준다.
- 인접 리스트의 경우, 링크드 리스트를 이용하여 구현한다.
  이때 저장되는 값은 정점이 아니라 다음 경로를 가리킨다.
  A[1] 2 5
  A[2] 1 3 4 5..
#include ..
vector<int> a[10];
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++){
    int u,v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v); a[v].push_back(u);
  }
}
- 위의 경우 vector<int> a[10]은 이차원 배열을 나타내며 보통 다음과 같이 표현한다.
  vector<vector<int>> a(n+1);
- 가중치까지 포함하는 경우 다음과 같이 쓴다.
#include ...
vector<pair<int,int>> a[10];
int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++){
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    a[u].push_back(make_pair(v,w)); a[v].push_back(make_pair(u,w));
  }
}
- 인접 행렬의 경우 공간 복잡도는 O(V^2)이고 리스트의 경우 O(E)이다.
- 간선 리스트의 경우, 배열을 이용하여 구현하며 간선을 모두 저장하고 있다.
- 정렬한 후 E라는 배열에 간선을 모두 저장한다.
  각 간선의 앞 정점을 기준으로 개수를 센다.
  for(int i = 0; i<m; i++){
    cnt[e[i][0]] += 1;
  }
  누적합을 구한다.
  for(int i=1; i<n; i++){
    cnt[i] = cnt[i-1] + cnt[i];
  }
  i번 정점과 연결된 간선은 E배열에서 cnt[i-1]부터 cnt[i]-1까지이다.
  
* 그래프의 탐색
- DFS : 깊이 우선 탐색; 스택이나 재귀 사용
- BFS : 너비 우선 탐색; 큐 사용
- 목적 : 모든 정점을 1 번씩 방문
- BFS의 경우 모든 가중치를 1로 하면 최단거리 검색이 가능하다.
- 깊이우선 탐색 : Depth First Search
  스택을 이용해서 갈 수 있는 만큼 최대한 많이 가고
  갈 수 업으면 이전 정점으로 돌아간다.(pop)
  모든 정점을 다 돌면, 차례 대로 pop하면서 돌아오기 때문에
  empty()를 통해 탐색 완료를 확인할 수 있다.
  - 재귀 호출 및 인접 행렬을 통한 구현
  void dfs(int x){
    check[x] = true;
    printf("%d ", x);
    for(int i = 1; i<=n; i++){
      if(a[x][i] == 1 && check[i] == false) dfs(i);
    }
  }
  - 해당 경우 함수 호출이 V번 일어나고 for 문이 V번 돌기 때문에 O(V^2)
  - 재귀 호출 및 인접 리스트를 통한 구현
  void dfs(int x){
    check[x] = true;
    printf("%d ", x);
    for(int i = 0; i<a[x].size(); i++){
      int y = a[x][i];
      if(check[y] == false){
        dfs(y);
      }
    }
  }
  - 해당 경우 함수 호출이 V번 일어나고 for문이 간선 만큼 돌기 때문에 O(V+E)
- 너비 우선 탐색 : Breadth First Search
  큐를 이용해서 지금 위치에서 갈 수 있는 것을 모두 큐에 넣는 방식
  큐에 넣기 전에 방문했다고 체크
  모두 넣었으면 pop을 한뒤 다음 원소에서 체크 후 큐에 넣기
  - 인접 행렬을 통한 구현
  queue<int> q;
  check[1] = true; q.push(1);
  while(!q.empty()){
    int x = q.front(); q.pop();
    printf("%d ", x);
    for(int i = 1; i<=n; i++){
      if(a[x][i] == 1 && check[i] == false){
        check[i] = true;
        q.push(i);
      }
    }
  }
  - 인접 리스트를 통한 구현
  queue<int> q;
  check[1] = true; q.push(1);
  while(!q.empty()){
    int x = q.front(); q.pop();
    printf("%d ", x);
    for(int i = 0; i<a[x].size(); i++){
      int y = a[x][i];
      if(check[y] == false){
        check[y] = true; q.push(y);
      }
    }
  }
  
1260번 : https://www.acmicpc.net/problem/1260
- 인접 리스트 사용, 재귀
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
	check[node] = true;
	printf("%d ", node);
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		printf("%d ", node);
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(start);
	puts("");
	bfs(start);
	puts("");
	return 0;
}

- 비재귀 구현
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
    stack<pair<int, int>> s;
    s.push(make_pair(node, 0));
    check[node] = true;
    printf("%d ", node);
    while (!s.empty()) {
        int node = s.top().first;
        int start = s.top().second;
        s.pop();
        for (int i = start; i < a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                printf("%d ", next);
                check[next] = true;
                s.push(make_pair(node, i + 1));
                s.push(make_pair(next, 0));
                break;
            }
        }
    }
}
void bfs(int start) {
    queue<int> q;
    memset(check, false, sizeof(check));
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ", node);
        for (int i = 0; i < a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(start);
    puts("");
    bfs(start);
    puts("");
    return 0;
}

- 간선 구현
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge {
    int from, to;
};
Edge edge[20001];
int cnt[1001];
bool check[1001];
bool cmp(const Edge &u, const Edge &v) {
    if (u.from == v.from) {
        return u.to < v.to;
    } else {
        return u.from < v.from;
    }
}
void dfs(int node) {
    check[node] = true;
    printf("%d ",node);
    for (int i=cnt[node-1]; i<cnt[node]; i++) {
        int next = edge[i].to;
        if (check[next] == false) {
            dfs(next);
        }
    }
}
void bfs(int start) {
    queue<int> q;
    q.push(start);
    check[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ",node);
        for (int i=cnt[node-1]; i<cnt[node]; i++) {
            int next = edge[i].to;
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    int n, m, start;
    scanf("%d %d %d",&n,&m,&start);
    for (int i=0; i<m; i++) {
        scanf("%d %d",&edge[i].from, &edge[i].to);
        edge[i+m].from = edge[i].to;
        edge[i+m].to = edge[i].from;
    }
    m *= 2;
    sort(edge, edge+m, cmp);
    for (int i=0; i<m; i++) {
        cnt[edge[i].from] += 1;
    }
    for (int i=1; i<=n; i++) {
        cnt[i] += cnt[i-1];
    }
    dfs(start);
    printf("\n");
    memset(check,false,sizeof(check));
    bfs(start);
    printf("\n");
    return 0;
}

    - 위에서 핵심 : 총 개수 엣지 * 2, 들어오는 간선의 개수 세주기, 누적 합 해주기
                   , cnt[node -1] ~ cnt[node]-1 까지 돌려주기

* 연결 요소(Connetcted Component)
- 나누어진 각각의 그래프를 연결 요소라고 한다.
- 연결 요소에 속한 모든 정점을 연결하는 경로가 있어야 한다.
- 또, 다른 연결 요소에 속한 정점과 연결하는 경로가 있으면 안된다.
	    
11724번 : https://www.acmicpc.net/problem/11724

#include <cstdio>
#include <vector>
using namespace std;
vector<int> a[1001];
bool check[1001];
void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}
int main() {
	int v, e;
	scanf("%d %d", & v, &e);
	for (int i = 0; i < e; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int components = 0;
	for (int i = 1; i <= v; i++) {
		if (check[i] == false) {
			dfs(i);
			components += 1;
		}
	}
	printf("%d\n", components);
	return 0;
}

* 이분 그래프
- 그래프를 두개로 나눌 수 있으면 이분 그래프라고 한다.
- 한 그룹에 속해 있는 정점끼리 연결된 간선이 없어야 한다.
- 모든 간선의 한 끝 점은 다른 그룹에 속한다.
	
1707번 : https://www.acmicpc.net/problem/1707

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> a[20001];
int check[20001];
void dfs(int node, int c) {
	check[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == 0) {
			dfs(next, 3-c);
		}
	}
}
int main() {
	int k;
	scanf("%d\n", &k);
	while (k--) {
		int v, e;
		scanf("%d %d", &v, &e);
		for (int i = 1; i <= v; i++) {
			a[i].clear();
			check[i] = 0;
		}
		for (int i = 0; i < e; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}
		bool ok = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int l = a[i][j];
				if (check[i] == check[l]) {
					ok = false;
				}
			}
		}
		printf("%s\n", ok ? "YES" : "NO");
	}
	return 0;
}

- dfs가 bool을 반환 하는 경우의 구현
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[20001];
int color[20001];
bool dfs(int node, int c) {
    color[node] = c;
    for (int i=0; i<a[node].size(); i++) {
        int next = a[node][i];
        if (color[next] == 0) {
            if (dfs(next, 3-c) == false) {
                return false;
            }
        } else if (color[next] == color[node]) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    scanf("%d\n",&t);
    while (t--) {
        int n, m;
        scanf("%d %d",&n,&m);
        for (int i=1; i<=n; i++) {
            a[i].clear();
            color[i] = 0;
        }
        for (int i=0; i<m; i++) {
            int u,v;
            scanf("%d %d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        bool ok = true;
        for (int i=1; i<=n; i++) {
            if (color[i] == 0) {
                if (dfs(i, 1) == false) {
                    ok = false;
                }
            }
        }
        printf("%s\n",ok ? "YES" : "NO");
    }
    return 0;
}

10451번 : https://www.acmicpc.net/problem/10451

- 재귀 구현
#include <cstdio>
int a[1001];
bool check[1001];
void dfs(int node) {
	check[node] = true;
	if (check[a[node]] == false) {
		dfs(a[node]);
	}
	return;
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		int v;
		scanf("%d\n", &v);
		int ans = 0;
		for (int i = 1; i <= v; i++) {
			scanf("%d", &a[i]);
			check[i] = false; // 초기화!!!!!!
		}
		for (int i = 1; i <= v; i++) {
			if (check[i] == false) {
				dfs(i);
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

- 반복 구현
#include <cstdio>
int a[1001];
bool check[1001];
void dfs(int node) {
	check[node] = true;
	int next;
	next = a[node];
	while (check[next] == false) {
		check[next] = true;
		next = a[next];
	}
}

int main() {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		int v;
		scanf("%d\n", &v);
		int ans = 0;
		for (int i = 1; i <= v; i++) {
			scanf("%d", &a[i]);
			check[i] = false; // 초기화!!!!!!
		}
		for (int i = 1; i <= v; i++) {
			if (check[i] == false) {
				dfs(i);
				ans += 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

2331번 : https://www.acmicpc.net/problem/2331

#include <iostream>
using namespace std;
int check[1000000];
int pow(int x, int p) {
    int ans = 1;
    for (int i=0; i<p; i++) {
        ans = ans * x;
    }
    return ans;
}
int next(int a, int p) {
    int ans = 0;
    while (a > 0) {
        ans += pow(a%10, p);
        a /= 10;
    }
    return ans;
}
int length(int a, int p, int cnt) {
    if (check[a] != 0) {
        return check[a]-1;
    }
    check[a] = cnt;
    int b = next(a, p);
    return length(b, p, cnt+1);
}
int main() {
    int a, p;
    cin >> a >> p;
    cout << length(a, p, 1) << '\n';
    return 0;
}

9466번 : https://www.acmicpc.net/problem/9466

- 재귀 구현
#include <cstdio>

int a[100001];
int d[100001];
int s[100001];
int n;
int dfs(int x, int cnt, int& step) {
	if (d[x] != 0) {
		if (step != s[x]) {
			return 0;
		}
		return cnt - d[x];
	}
	d[x] = cnt;
	s[x] = step;
	return dfs(a[x], cnt + 1, step);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			d[i] = 0;
			s[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				ans += dfs(i, 1, i);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}

- 비재귀 구현

#include <cstdio>

int a[100001];
int d[100001];
int s[100001];
int n;
int dfs(int x, int cnt, int& step) {
	while (true) {
		if (d[x] != 0) {
			if (s[x] != step) {
				return 0;
			}
			return cnt - d[x];
		}
		d[x] = cnt;
		s[x] = step;
		x = a[x];
		cnt++;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			d[i] = 0;
			s[i] = 0;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				ans += dfs(i, 1, i);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}

* Flood Fill; 어떤 위치와 연결된 모든 위치를 찾는 알고리즘

2667번 : https://www.acmicpc.net/problem/2667

- bfs

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[30][30];
int d[30][30];
int ans[25 * 25];
int n;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && d[i][j] == 0) {
				bfs(i, j, ++cnt);
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[d[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

- dfs

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[30][30];
int d[30][30];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int n;
int ans[25*25];
void dfs(int x, int y, int cnt) {
    d[x][y] = cnt;
    for (int k=0; k<4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }
    }
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (a[i][j] == 1 && d[i][j] == 0) {
                dfs(i, j, ++cnt);
            }
        }
    }
    printf("%d\n",cnt);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans[d[i][j]]+=1;
        }
    }
    sort(ans+1, ans+cnt+1);
    for (int i=1; i<=cnt; i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}

4963번 : https://www.acmicpc.net/problem/4963

- dfs

#include <cstdio>
int a[100][100];
int d[100][100];
int m, n;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
void dfs(int x, int y, int cnt) {
    d[x][y] = cnt;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && 0 <= ny && ny < m) {
            if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                dfs(nx, ny, cnt);
            }
        }

    }
}
int main() {
    while (true) {
        scanf("%d %d", &m, &n);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%1d", &a[i][j]);
                d[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && d[i][j] == 0) {
                    dfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

- bfs 구현

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[100][100];
int d[100][100];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int n,m;
void bfs(int x, int y, int cnt) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k=0; k<8; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 1 && d[nx][ny] == 0) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = cnt;
                }
            }
        }
    }
}
int main() {
    while (true) {
        scanf("%d %d",&m,&n);
        if (n == 0 && m == 0) break;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%1d",&a[i][j]);
                d[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j] == 1 && d[i][j] == 0) {
                    bfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

2178번 : https://www.acmicpc.net/problem/2178

#include <cstdio>
#include <queue>
using namespace std;
int n, m;
int a[100][100];
int dist_and_check[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist_and_check[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (dist_and_check[nx][ny] == 0 && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					dist_and_check[nx][ny] = dist_and_check[x][y] + 1;
				}
			}
		}
	}
	printf("%d\n", dist_and_check[n-1][m-1]);
	return 0;
}

7576번 : https://www.acmicpc.net/problem/7576

#include <cstdio>
#include <queue>
using namespace std;
int a[1000][1000];
int d[1000][1000];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
    int n,m;
    scanf("%d %d",&m,&n);
    queue<pair<int,int>> q;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d",&a[i][j]);
            d[i][j] = -1;
            if (a[i][j] == 1) {
                q.push(make_pair(i,j));
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 0 && d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (ans < d[i][j]) {
                ans = d[i][j];
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 0 && d[i][j] == -1) {
                ans = -1;
            }
        }
    }

    printf("%d\n",ans);
    return 0;
}
