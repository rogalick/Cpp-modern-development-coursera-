#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;


struct Specialization {
	explicit Specialization(string spec) {
		m_spec = spec;
	}
	string m_spec;
};

struct Week {
	explicit Week(string week) {
		m_week = week;
	}
	string m_week;
};

struct Course {
	explicit	Course(string course) {
		m_course = course;
	}
	string m_course;
};

struct LectureTitle {
	explicit LectureTitle(Specialization spec, Course cors, Week wek) {
		course = cors.m_course;
		specialization = spec.m_spec;
		week = wek.m_week;
	}
	string specialization;
	string course;
	string week;
};

int main() {

	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	cout << title.course;
}