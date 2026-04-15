﻿#pragma once

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include<vector>
#include<list>
#include"Student_info.h"

using std::vector;	//異붽?

//?癒곗굨?類ㅼ벥??double grade(double, double, const vector<double>&);
double grade(double, double, const vector<double>&);
double grade(double, double, double);
double grade(const Student_info&);


//Student_info ?④쑴沅?double grade(const Student_info& s) {
return grade(s.midterm, s.fin, s.homework);
}

bool fgrade(const Student_info&);
vector<Student_info>extract_fails(vector<Student_info>&);
list<Student_info>extract_fails(list<Student_info>&);
#endif // GUARD_grade_h
