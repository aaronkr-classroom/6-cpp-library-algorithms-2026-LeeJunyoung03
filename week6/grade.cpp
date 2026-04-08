#include<vector>
#include<stdexcept>
#include"Student_info.h"
#include"grade.h"
#include"median.h"


//??낆젾 ??쎈뱜?깆눘肉???⑥눘???癒?땾????뽦봺??곴퐣vector<double>???節뚯벉
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		//??곸읈 ??곸뒠????볤탢
		hw.clear();

		//?⑥눘???癒?땾????뚯벉
		double x;

		while (in >> x) {
			hw.push_back(x);
		}

		//??쇱벉 ??덇문???癒?땾 ??낆젾 ?臾믩씜???⑥쥓?????쎈뱜?깆눘??筌왖??
		in.clear();
		return in;
	}
}

//餓λ쵌而숁⑥쥙沅??癒?땾, 疫꿸퀡彛싨⑥쥙沅??癒?땾, ?⑥눘???癒?땾??甕겸돧苑ｆ에???덇문???ル굟鍮
//?癒?땾???닌뗫맙. ????λ땾???紐꾨땾??癰귣벊沅??? ??꾪?median ??λ땾揶쎛
// ????臾믩씜????쎈뻬
double grade(double mid, double fin, vector<double>& hw) {
	if (hw.size() == 0) {
		throw domain_error("NO homework!");
	}


	//return (mid * 0.2 + fin * 0.4 +(hw1 + hw2 + ...) / hw.size())
	//new grade() ??λ땾
	return grade(mid, fin, median(hw));
}

//?④쑴沅??롫뮉 grade() ??λ땾
double grade(double midterm, double final, double homework) {
	return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}
list<Student_info>extract_fails(list<Student_info>&students) {
	list<Student_info>fail;
	//vector<Student_info>::size_type i = 0;
	list<Student_info>::iterator iter = students.begin;

	//遺덈??쒖씠students 踰≫꽣??[0,i)踰붿쐞???덈뒗 ?붿냼?ㅼ? 怨쇰ぉ???듦낵???숈깮?ㅼ쓽 ?뺣낫\
	//while (iter != students.size()) {
	while (iter != students.end()) {
		//if (fgrade(students[i])) {
		if(fgrade(*iter)){
			//fail.push_back(students[i]);
			//students.erase(students.begin() + i);	//i踰덉㎏ ?쒓굅
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			//++i;
			++iter;
		}
	}
	return fail;
}
