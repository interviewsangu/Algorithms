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
