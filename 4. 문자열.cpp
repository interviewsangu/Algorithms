푼 문제 : 10808, 10809, 10820, 2743, 11655,10824, 11656

아스키코드
- 0은 아스키 코드로는 NULL을 나타낸다.
- 숫자가 저장되어 있는데, 출력만 글자로 해주는 것으로 이해하면 편하다.

단어의 길이를 재는 경우 NULL을 이용하여 for문을 작성할 수 있다.
** strlen 함수의 시간 복잡도는 O(N)이기 때문에 다음과 같이 작성하면 N^2이 나온다.
for(int i=0; i<strlen(s); i++)...
따라서 다음과 같이 두 줄로 작성하는 것이 올바르다.
int len = strlen(s);
for(int i=0; i<len; i++)....

단어의 길이를 재는 경우 strlen이나 string의 length, size를 쓸 수 없는 경우
다음과 같이 한다.
scanf("%s", s);
int len = 0;
for(int i=0; s[i]; i++){
  len += 1;
}...

string의 size함수나 length함수의 경우 O(1)이다..
string을 정수, 실수로 바꾸고 싶은 경우 #include <string>
- stoi (string to int), stol, stoll, stof, stod, stold, stoul, stoull
정수, 실수를 string으로 바꾸고 싶은 경우
- to_string 함수, 자료형과 상관 없이 그냥 쓰면 된다.

문자열의 부분 문자열은 substr를 이용해서 구할 수 있다.

10808번
문제 : 알파벳 소문자로만 이루어진 단어 S가 주어진다. 
각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.

입력 : 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

출력 : 단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


int main(){
	string s;
	cin >> s;
	
	for(int i='a'; i<='z'; i++){
		cout << count(s.begin(), s.end(), i) << ' ';
	}
	
	cout << endl;

	return 0;
}


**참고

    string s = "abc";

    cout << *s.begin() << endl;        // 'a' 출력
    cout << *(s.begin()+1) << endl;    // 'b' 출력
    cout << *(s.end()-1) << endl;      // 'c' 출력
    cout << *s.end() << endl;          // ''  출력(아무것도 출력하지 않음)
    
    int a[] = {1, 2, 3, 4, 5, 6, 6};
    cout << count(a, a+7, 6) << endl; // 2 출력
    
10809번
문제 : 알파벳 소문자로만 이루어진 단어 S가 주어진다. 
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를,
포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;

    for (int i='a'; i<='z'; i++) {
        auto it = find(s.begin(), s.end(), i);
        if (it == s.end()) {
            cout << -1 << ' ';
        } else {
            cout << (it - s.begin()) << ' ';
        }
    }

    cout << '\n';
    

    return 0;
}

**참고
# Iterator find (InputIterator first, InputIterator last, const T& val)

- val의 값이 어디의 위치에 존재하는지를 Iterator로 반환함
(val과 일치하는게 없을 시 마지막 end()를 반환)
- #include <algorithm> 을 포함시켜주어야 함

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    vector<int> myvector(a, a + 5);

    auto it = find(myvector.begin(), myvector.end(), 3);
    if (it == myvector.end())  // 존재하지 않는 경우
        cout << -1 << ' ';
    else
        cout << (it - myvector.begin());                    //2
}

10820번
문제 : 문자열 N개가 주어진다.
이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.
각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.

입력 : 첫째 줄부터 N번째 줄까지 문자열이 주어진다. (1 ≤ N ≤ 100) 문자열의 길이는 100을 넘지 않는다.

출력 : 첫째 줄부터 N번째 줄까지 각각의 문자열에 대해서 소문자, 대문자, 숫자,
공백의 개수를 공백으로 구분해 출력한다.

#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    while (getline(cin, s)) {
        int lower = 0;
        int upper = 0;
        int number = 0;
        int space = 0;
        for (char x: s) {
            if (x >= 'a' && x <= 'z') {
                lower += 1;
            } else if (x >= 'A' && x <= 'Z') {
                upper += 1;
            } else if (x >= '0' && x <= '9') {
                number += 1;
            } else if (x == ' ') {
                space += 1;
            }
        }
        cout << lower << ' '<< upper << ' ';
        cout << number << ' ' << space << '\n';
    }
    return 0;
}

2743번
문제 : 알파벳으로만 이루어진 단어를 입력받아, 그 길이를 출력하는 프로그램을 작성하시오.
입력 : 첫째 줄에 영어 소문자와 대문자로만 이루어진 단어가 주어진다. 단어의 길이는 최대 100이다.
출력 : 첫째 줄에 입력으로 주어진 단어의 길이를 출력한다.

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;

    cout << s.length() << endl;
    return 0;
}

11655번
문제 : 문자열이 주어졌을 때, "ROT13"으로 암호화한 다음 출력하는 프로그램을 작성하시오.
입력 : 첫째 줄에 알파벳 대문자, 소문자, 공백, 숫자로만 이루어진 문자열 S가 주어진다.
출력 : 첫째 줄에 S를 ROT13으로 암호화한 내용을 출력한다.

#include <iostream>
#include <string>
using namespace std;
string rot13(string s) {
    for (int i=0; i<s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'm') {
            s[i] = s[i] + 13;
        } else if (s[i] >= 'n' && s[i] <= 'z') {
            s[i] = s[i] - 13;
        } else if(s[i] >= 'A' && s[i] <= 'M') {
            s[i] = s[i] + 13;
        } else if(s[i] >= 'N' && s[i] <= 'Z') {
            s[i] = s[i] - 13;
        }
    }
    return s;
}
int main() {
    string s;
    getline(cin,s);
    cout << rot13(s) << '\n';
}

10824번
문제 : 네 자연수 A, B, C, D가 주어진다. 
이때, A와 B를 붙인 수와 C와 D를 붙인 수의 합을 구하는 프로그램을 작성하시오.
두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다. 즉, 20과 30을 붙이면 2030이 된다.

입력 : 첫째 줄에 네 자연수 A, B, C, D가 주어진다. (1 ≤ A, B, C, D ≤ 1,000,000)

출력 : A와 B를 붙인 수와 C와 D를 붙인 수의 합을 출력한다.

#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c, d;
	string s1;
	string s2;

	cin >> a >> b >> c >> d;
	s1 = to_string(a) + to_string(b);
	s2 = to_string(c) + to_string(d);

	long long l1 = stoll(s1);
	long long l2 = stoll(s2);

	cout << l1 + l2 << endl;
	return 0;
}

11656번
문제 : 접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.
baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고,
이를 사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon이 된다.
문자열 S가 주어졌을 때, 모든 접미사를 사전순으로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력 : 첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고,
길이는 1,000보다 작거나 같다.

출력 :첫째 줄부터 S의 접미사를 사전순으로 한 줄에 하나씩 출력한다.

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n = s.size();
    vector<int> a;
    for (int i=0; i<n; i++) a.push_back(i);
    sort(a.begin(),a.end(), [&s](int u, int v) {
        return strcmp(s.c_str()+u,s.c_str()+v) < 0;
    });
    for (auto &x : a) {
        cout << s.substr(x) << '\n';
    }
    return 0;
}
