푼 문제 10845, 1158, 10866
큐
- FIFO 구조
- push, pop, front(조회), back(조회), empty, size
- 시작 인덱스 begin과 back의 다음을 가리키는 인덱스 end가 중요하다.
- push를 하는 것은 end에 자료를 넣는 것.
- pop을 하는 것은 begin 자리를 0처리하고 begin을 1 증가 시키는 것.
- size : end - begin
- empty : begin = end

10845
문제 : 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여섯 가지이다.

입력 : 
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력 : 출력해야 하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

STL

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
	int t;
	cin >> t;
	
	queue<int> q;
	
	while(t--){
		string cmd;
		cin >> cmd;
		if(cmd == "push"){
			int num;
			cin >> num;
			q.push(num);
		}else if(cmd == "pop"){
			if(q.empty()){
				cout << -1 << endl;
			}else{
				cout << q.front() << endl;
				q.pop();
			}
		}else if(cmd == "size"){
			cout << q.size() << endl;
		}else if(cmd == "empty"){
			cout << q.empty() << endl;
		}else if(cmd == "front"){
			if(q.empty()){
				cout << -1 << endl;
			}else
			{
				cout << q.front() << endl;
			}
		}else if(cmd == "back"){
			if(q.empty()){
				cout << -1 << endl;
			}else{
				cout << q.back() << endl;
			}
		}
	}
	return 0;
}

구현

#include <iostream>
#include <string>
using namespace std;

struct Queue{
	int data[10000];
	int begin, end;
	Queue(){
		begin = 0;
		end = 0;
	}
	void push(int num){
		data[end] = num;
		end += 1;
	}
	bool empty(){
		if(begin == end){
			return true;
		}else{
			return false;
		}
	}
	int size(){
		return end-begin;
	}
	int front(){
		return data[begin];
	}
	int back(){
		return data[end-1];
	}
	int pop(){
		if(empty()){
			return -1;
		}
		begin += 1;
		return data[begin-1];
	}
};

int main(void){
	int t;
	cin >> t;
	Queue q;
	
	while(t--){
		string cmd;
		cin >> cmd;
		if(cmd == "push"){
			int num;
			cin >> num;
			q.push(num);
		}else if(cmd == "pop"){
			if(q.empty()){
				cout << -1 << endl;
			}else{
				cout << q.front() << endl;
				q.pop();
			}
		}else if(cmd == "size"){
			cout << q.size() << endl;
		}else if(cmd == "empty"){
			cout << q.empty() << endl;
		}else if(cmd == "front"){
			if(q.empty()){
				cout << -1 << endl;
			}else{
				cout << q.front() << endl;
			}
		}else if(cmd == "back"){
			if(q.empty()){
				cout << -1 << endl;
			}else{
				cout << q.back() << endl;
			}
		}
	}
}

1158번 조세퍼스 문제
- 각각의 사람에 대해서 총 M번 순회를 하고 제거를 해야 하기 떄문에 O(NM)
- pop ; M-1 + 1
- push ; M-1

문제 : 
1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다.
이제 순서대로 K번째 사람을 제거한다. 
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.
원에서 사람들이 제거되는 순서를 (N, K)-조세퍼스 순열이라고 한다.
예를 들어 (7, 3)-조세퍼스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-조세퍼스 순열을 구하는 프로그램을 작성하시오.

입력 : 첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

출력 : 조세퍼스 순열을 출력한다.

#include <cstdio>
#include <queue>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d",&n,&m);
    queue<int> q;
    for (int i=1; i<=n; i++) {
        q.push(i);
    }
    printf("<");
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            q.push(q.front());
            q.pop();
        }
        printf("%d, ",q.front());
        q.pop();
    }
    printf("%d>\n",q.front());
    return 0;
}

덱(Deque; Double ended queue)
- 양 끝에서만 자료를 넣고 양 끝에서 뺄 수 있는 자료구조
- push_front, push_back, pop_front, pop_back, front, back, size, empty
- 중요한 자료구조이지만 덱의 특징을 이용하여 문제를 푸는 경우는 거의 없음

10866번 덱을 구현하는 문제
문제 : 정수를 저장하는 덱(Deque)를 구현한 다음, 
입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여덟 가지이다.

입력 : 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다.
둘쨰 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다.
문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력 : 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;

    deque<int> d;

    while (n--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push_front") {
            int num;
            cin >> num;
            d.push_front(num);
        } else if (cmd == "push_back") {
            int num;
            cin >> num;
            d.push_back(num);
        } else if (cmd == "pop_front") {
            if (d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        } else if (cmd == "size") {
            cout << d.size() << '\n';
        } else if (cmd == "empty") {
            cout << d.empty() << '\n';
        } else if (cmd == "front") {
            if (d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.front() << '\n';
            }
        } else if (cmd == "back") {
            if (d.empty()) {
                cout << -1 << '\n';
            } else {
                cout << d.back() << '\n';
            }
        }
    }

    return 0;
}
