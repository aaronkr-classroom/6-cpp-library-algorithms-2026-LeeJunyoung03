#include<iostream>
#include<string>
#include<vector>
#include<cctype>	//?먮즺?뺤쓽 ?⑥닔 ?щ윭 媛??덈떎
//isspace(a)?⑥닔??a媛 怨듬갚?대㈃ 李?媛믪쓣 諛섑솚

using namespace std;

//인수가 공백일 때는 false, 그렇지 않을 때느 true 반환
bool not_space(char c){
	return !isspace(c);
}

//인수가 공백일 때는 ture, 그렇지 않을 때느 false 반환
bool space(char c) {
	return isspace(c);
}

vector<string> split(const string& s) {
	vector<string>ret;
	typedef string::size_type str_sz;
	str_sz i = 0;

	//遺덈??? 吏湲덇퉴吏[?먮옒??i, ?꾩옱??i)踰붿쐞???덈뒗 臾몄옄?ㅼ쓣 泥섎━
	while (i != s.size()) {
		//?좏뻾?섎뒗 怨듬갚?ㅼ쓣 臾댁떆, 遺덈??? 吏湲덇퉴吏[?먮옒??i, ?꾩옱??i)
		// 踰붿쐞???덈뒗 臾몄옄?ㅼ쓣 紐⑤몢 怨듬갚(isspace() )
		while (i != s.size() && isspace(s[i])) {
			++i;
		}

		//?쒖꽌???ㅼ쓬 ?⑥뼱???앹쓣 李얠쓬
		str_sz j = i;

		//?좏뻾?섎뒗 怨듬갚?ㅼ쓣 臾댁떆, 遺덈??? 吏湲덇퉴吏[?먮옒??i, ?꾩옱??i)
		// 踰붿쐞???덈뒗 臾몄옄?ㅼ쓣 怨듬갚???꾨떂(isspace() )
		while (j != s.size() && !isspace(s[j])) {
			j++;
		}

		//怨듬갚???꾨땶 臾몄옄?ㅼ쓣 李俊英얠븯?꾨븣
		if (i != j) {
			//i?먯꽌遺??j-1媛쒖쓽 臾몄옄?ㅼ쓣 s??蹂듭궗
			ret.push_back(s.substr(i, j - 1));
			i = j;	//j?몃뜳?ㅺ? i?몃뜳?ㅻ줈 ?대룞
		}
	}
	return ret;
}

vector<string> lib_split(const string& s){
vector<string>ret;
typedef string::const_iterator iter;	//수정
iter i = s.begin();	//첫요소에 가리키는 포인터 (개념)

//遺덈??? 吏湲덇퉴吏[?먮옒??i, ?꾩옱??i)踰붿쐞???덈뒗 臾몄옄?ㅼ쓣 泥섎━
while (i != s.end()) {
	//선행 공백을 무시
	i = find_if(i, s.end(), not_space);
	
	//다음 단어의 끝을 찾음
	iter j = find_if(i, s.end(), space);

	//?좏뻾?섎뒗 怨듬갚?ㅼ쓣 臾댁떆, 遺덈??? 吏湲덇퉴吏[?먮옒??i, ?꾩옱??i)
	//문자들을 복사
	if (i != s.end()) {
		//i?먯꽌遺??j-1媛쒖쓽 臾몄옄?ㅼ쓣 s??蹂듭궗
		ret.push_back(string(i, j));
			}
	i = j; //j인덱스가 i인덱스로 이동
}
return ret;
}

int main(void) {
	string s;

	//무자열을 한 행씩 입력받아 분할
	while (getline(cin, s)) {
		vector<string> v1 = split(s);
		vector<string>v2 = lib_split(s);

		cout << "Original split(): " << endl;
		for (vector<string>::size_type i = 0; i != v1.size(); i++) {
			cout << v1[i] << endl;
		}

		cout << "NEW lib_split(): " << endl;
		for (vector<string>::size_type i = 0; i != v2.size(); i++) {
			cout << v2[i] << endl;
		}
	}
	return 0;
}
