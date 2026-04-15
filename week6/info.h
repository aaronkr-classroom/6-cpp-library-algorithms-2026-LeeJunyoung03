#pragma once
#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include<iostream>
#include<string>
#include<vector>

using namespace std;

//?닌듼쒙㎗ ? 
struct Student_info {
	//??욧쉐
	string name;
	double midterm, fin;
	vector<double>homework;
};

//??λ땾 ?癒곗굨 ?類ㅼ벥
bool compare(const Student_info&, const Student_info&);	//??已???쑨???띾┛
istream& read(istream&, Student_info&);	//????덇문???類ｋ궖 ??꾨┛
istream& read_hw(istream&, vector<double>&);	//筌뤴뫀諭??⑥눘???癒?땾 ??꾨┛

#endif // !GUARD_Student_info_h
