푼 문제 :
트리 순회	https://www.acmicpc.net/problem/1991
트리의 부모 찾기	https://www.acmicpc.net/problem/11725
트리의 지름	https://www.acmicpc.net/problem/1167
트리의 지름	https://www.acmicpc.net/problem/1967

* 트리
- 자료구조의 일종
- 사이클이 없는 그래프
- 조건 : 정점의 개수 v, 간선의 개수 v-1, + 연결
- 같은 부모를 가지면 형제
- Depth : 루트에서 부터 거리, 루트의 깊이를 0으로 하는 경우와 1로 하는 경우 존재
- Hegiht : 깊이 중 가장 큰 값
- Ancestor, Descendent는 자신을 포함한다.

* 트리의 표현
- 트리는 그래프이기 때문에, 그래프의 표현과 같은 방식으로 저장할 수 있다.
- 트리의 모든 노드는 부모를 하나 또는 0개만 가지기 때문에 부모만 저장하는 방식으로 저장 가능
- 부모가 0개인 경우 루트인데, 이 경우 부모를 -1이나 0으로 처리
- 이진 트리의 경우 배열로 표현 가능하다.
- 부모의 노드가 x인 경우 자식의 노드는 2*x, 2*x + 1로 표현한다.
- 또는 A[i][0]에 i의 왼쪽 자식, A[i][1]에 i의 오른쪽 자식을 저장할 수 있다.

* 트리의 순회
- 트리에서 DFS와 BFS를 사용할 수 있지만, 트리에서만 사용할 수 있는 세 방법이 있다.
- preorder, inorder, postorder


1991번 : https://www.acmicpc.net/problem/1991

#include <iostream>
using namespace std;
int tree[50][2];
void preorder(int x) {
	if (x == -1) return;
	cout << (char)(x + 'A');
	preorder(tree[x][0]);
	preorder(tree[x][1]);
}
void inorder(int x) {
	if (x == -1) return;
	inorder(tree[x][0]);
	cout << (char)(x + 'A');
	inorder(tree[x][1]);
}
void postorder(int x) {
	if (x == -1) return;
	postorder(tree[x][0]);
	postorder(tree[x][1]);
	cout << (char)(x + 'A');
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		x = x - 'A';
		if (y == '.') {
			tree[x][0] = -1;
		}
		else {
			tree[x][0] = y - 'A';
		}
		if (z == '.') {
			tree[x][1] = -1;
		}
		else {
			tree[x][1] = z - 'A';
		}
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
	return 0;
}

* 트리의 탐색
- 트리의 탐색은 DFS/BFS를 이용해서 할 수 있다.
- 트리는 사이클이 없는 그래프이기 때문에 
  임의의 두 정점 사이의 경로는 1개이다.
- 따라서 BFS 알고리즘으로 최단 거리를 구할 수 있다.
  경로가 1개이기 때문에 찾은 경로 자체가 최단 경로가 된다.
  
11725번 : https://www.acmicpc.net/problem/11725

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 100001;
vector<int> a[MAX];
int parent[MAX];
bool check[MAX];
int depth[MAX];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	depth[1] = 0;
	check[1] = true;
	queue<int> q;
	q.push(1);
	parent[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : a[x]) {
			if (!check[y]) {
				depth[y] = depth[x] + 1;
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;
}

1167번 : https://www.acmicpc.net/problem/1167

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
	int to;
	int cost;
	Edge(int to, int cost): to(to), cost(cost){}
};
vector<Edge> a[100001];
bool check[100001];
int dist[100001];
void  bfs(int start) {
	memset(dist, 0, sizeof(dist));
	memset(check, false, sizeof(check));
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge& e = a[x][i];
			if (check[e.to] == false) {
				dist[e.to] = dist[x] + e.cost;
				q.push(e.to);
				check[e.to] = true;
			}
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		while (true) {
			int y, z;
			scanf("%d", &y);
			if (y == -1) break;
			scanf("%d", &z);
			a[x].push_back(Edge(y, z));
		}
	}
	bfs(1);
	int start = 1;
	for (int i = 2; i <= n; i++) {
		if (dist[i] > dist[start]) {
			start = i;
		}
	}
	bfs(start);
	int ans = dist[1];
	for (int i = 2; i <= n; i++) {
		if (ans < dist[i]) {
			ans = dist[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}

1967번 : https://www.acmicpc.net/problem/1967

#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct Edge {
    int to;
    int cost;
    Edge(int to, int cost) : to(to), cost(cost) {
    }
};
vector<Edge> a[10001];
bool check[10001];
int dist[10001];
void bfs(int start) {
    memset(dist,0,sizeof(dist));
    memset(check,false,sizeof(check));
    queue<int> q;
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i=0; i<a[x].size(); i++) {
            Edge &e = a[x][i];
            if (check[e.to] == false) {
                dist[e.to] = dist[x] + e.cost;
                q.push(e.to);
                check[e.to] = true;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back(Edge(v,w));
        a[v].push_back(Edge(u,w));
    }
    bfs(1);
    int start = 1;
    for (int i=2; i<=n; i++) {
        if (dist[i] > dist[start]) {
            start = i;
        }
    }
    bfs(start);
    int ans = dist[1];
    for (int i=2; i<=n; i++) {
        if (ans < dist[i]) {
            ans = dist[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}
