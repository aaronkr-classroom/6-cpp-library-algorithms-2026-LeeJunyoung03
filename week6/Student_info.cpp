#include"Student_info.h"

bool compare(const Student_info& a, const Student_info& b) {
	return a.name < b.name;	//True or False 獄쏆꼹??}
istream& read(istream& is, Student_info& s) {
	//??덇문 ??已? 餓λ쵌而숁⑥쥙沅? 疫꿸퀡彛싨⑥쥙沅??癒?땾 ??뚮선 ????	is >> s.name >> s.midterm >> s.final;
	//?⑥눘??癒?땾????뚯벉
	read_hw(is, s.homework);
	return is;
}

//筌뤴뫀諭??⑥눘???癒?땾 ??꾨┛
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
	}
	return in;
}
