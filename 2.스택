푼 문제 : 10828, 9012, 10799, 1406
(빅-오 찾아보기)

스택
- LIFO(Last in First out)
- push, pop, top, empty, size
- push : stack[size] & size += 1;
- pop : stack[size-1] 지우기 & size -= 1;
- 가장 가까운걸 O(1)만에 해결

괄호 문제의 경우 
스택을 이용하거나 카운트를 이용.
여는 괄호가 나오면 스택에 쳐 넣고 닫는 괄호가 나오면 pop
닫는 괄호가 나왔는데 스택이 비어있거나, 다 끝났는데 스택이 비어있지 않은 경우 -> 실패

레이져 문제의 경우 인덱스와 스택을 이용한다.
1차이가 나면 레이져, 레이져를 쏘고 스택에 남은 개수가 잘린 개수
쇠막대기가 끝날 때 1을 더해줘야한다. 예를 들어 2등분을 했다면 총 3조각이기 때문에.

10828번
문제 : 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다. (push, pop, size, empty, top)
입력 : 
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
문제에 나와있지 않은 명령이 주어지는 경우는 없다.
출력 : 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

(1) STL

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void){
	int n;
	cin >> n;
	
	stack<int> s;
	
	while(n--){
		string cmd;
		cin >> cmd;
		if(cmd == "push"){
			int num;
			cin >> num;
			s.push(num);
		}else if(cmd == "top"){
			cout << (s.empty() ? -1 : s.top()) << endl;
		}else if(cmd == "empty"){
			cout << s.empty() << endl;
		}else if(cmd == "pop"){
			cout << (s.empty() ? -1 : s.top()) << endl;
			if(!s.empty()){
				s.pop();
			}
		}
	}
	return 0;
}

(2) 구현

#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Stack{
	int data[10000];
	int size;
	Stack(){
		size = 0;
	}
	void push(int num){
		data[size] = num;
		size += 1;
	}
	bool empty(){
		if(size == 0){
			return true;
		}else{
			return false;
		}
	}
	int pop(){
		if(empty()){
			return -1;
		}else{
			size -= 1;
			return data[size];
		}
	}
	int top(){
		if(empty()){
			return -1;
		}else{
			return data[size-1];
		}
	}
};

int main(){
	int n;
	cin >> n;
	Stack s;
	
	while(n--){
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
            int num;
            cin >> num;
            s.push(num);
        } else if (cmd == "top") {
            cout << (s.empty() ? -1 : s.top()) << '\n';
        } else if (cmd == "size") {
            cout << s.size << '\n';
        } else if (cmd == "empty") {
            cout << s.empty() << '\n';
        } else if (cmd == "pop") {
            cout << (s.empty() ? -1 : s.top()) << '\n';
            if (!s.empty()) {
                s.pop();
            }
        }
    }
    return 0;	
}

9012번
문제 : 정상적인 괄호 문자열 파악하기
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다.
그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다.
한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다.
만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다.
그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다.
예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 
그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 
주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 

입력 : 입력 데이터는 표준 입력을 사용한다. 
입력은 T개의 테스트 데이터로 주어진다.
입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다.
각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다.
하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 

출력 : 출력은 표준 출력을 사용한다. 
만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 
아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 
N개의 데이터에 대해 모든 연산이 O(1) 이므로 총 O(N) 시간이 걸린다.

#include <iostream>
#include <string>
using namespace std;

string valid(string s){
	int cnt = 0;
	for(int i =0; i<s.size(); i++){
		if(s[i] == '('){
			cnt += 1;
		}else{
			cnt -= 1;
		}
		if(cnt<0){
			return "NO";
		}
	}
	if(cnt == 0){
		return "YES";
	}else{
		return "NO";
	}
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << valid(s) <<endl;
	}
	return 0;
}

10799번
문제 : 
여러 개의 쇠막대기를 레이저로 절단하려고 한다.
효율적인 작업을 위해서 쇠막대기를 아래에서 위로 겹쳐 놓고,
레이저를 위에서 수직으로 발사하여 쇠막대기들을 자른다.
쇠막대기와 레이저의 배치는 다음 조건을 만족한다.

- 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다.
- 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓는다.
- 각 쇠막대기를 자르는 레이저는 적어도 하나 존재한다.
- 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다. 

레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘( ) ’ 으로 표현된다.
또한, 모든 ‘( ) ’는 반드시 레이저를 표현한다.
쇠막대기의 왼쪽 끝은 여는 괄호 ‘ ( ’ 로, 오른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다.

입력 : 한 줄에 쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 공백없이 주어진다. 
괄호 문자의 개수는 최대 100,000이다.

출력 : 잘려진 조각의 총 개수를 나타내는 정수를 한 줄에 출력한다.

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
	int sum = 0;
	stack<int> s;
	string str;
	
	cin >> str;
	
	for(int i=0; i<str.size(); i++){
		if(str[i] == '('){
			s.push(i);
		}else{
			if(s.top()+1 == i){
				s.pop();
				sum += s.size();
			}else{
				s.pop();
				sum += 1;
			}
		}
	}
	
	cout << sum << endl;
	return 0;	
}

1406번 ; 스택으로 구현할 경우 모든 연산이 O(1)이므로 N개의 데이터에 대해 총 O(N)
문제 : 
한 줄로 된 간단한 에디터를 구현하려고 한다. 
이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.
이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽),
문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다.
즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.

이 편집기가 지원하는 명령어는 다음과 같다.
L ; 커서를 왼쪽으로 한 칸 옮김(커서가 문장의 맨 앞이면 무시됨)
D ; 커서를 오른쪽으로 한 칸 옮김(커서가 문장의 맨 뒤이면 무시됨)
B ; 커서 왼쪽에 있는 문자를 삭제함(커서가 문장의 맨 앞이면 무시됨)
    삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만,
    실제로 커서의 오른쪽에 있던 문자는 그대로임
P $ ; $라는 문자를 커서 왼쪽에 추가함
단 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.

입력 : 
첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 
이 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다.
둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M(1 ≤ M ≤ 500,000)이 주어진다.
셋째 줄부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 
명령어는 위의 네 가지 중 하나의 형태로만 주어진다.

출력 : 첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.
abc|xyz 가 있다고 생각해 보자. 커서를 기준으로 스택을 2개 만들면 되겠구나


#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char a[600000];

int main(void){
	scanf("%s", a);
	stack<char> left, right;
	for(int i = 0; i<strlen(a); i++){
		left.push(a[i]);
	}
	int t;
	scanf("%d", &t);
	while(t--){
		char what;
		scanf(" %c", & what);//공백 제끼려고
		if(what == 'L'){
			if(!left.empty()){
				right.push(left.top());
				left.pop();
			}
		}else if(what == 'D'){
			if(!right.empty()){
				left.push(right.top());
				right.pop();
			}
		}else if(what == 'B'){
			if(!left.empty()){
				left.pop();
			}
		}else if(what == 'P'){
			char c;
			scanf(" %c", &c);
			left.push(c);
		}
	}

	while(!left.empty()){
		right.push(left.top());
		left.pop();
	}
	while(!right.empty()){
		printf("%c", right.top());
		right.pop();
	}
	printf("\n");
	return 0;
}


