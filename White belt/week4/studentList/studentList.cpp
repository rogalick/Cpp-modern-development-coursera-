#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
//Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения.
//Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.

struct student {
	student(string& name, string& surname, int& day, int& month, int& year) : name_m(name), surname_m(surname), day_m(day), month_m(month), year_m(year) {}
	string name_m;
	string surname_m;
	int day_m;
	int month_m;
	int year_m;
};

vector<student> getStudent(int n) {
	std::vector<student> data;
	std::string fname, lname;
	int y, m, d;

	for (int i = 0; i < n; ++i) {
		std::cin >> fname >> lname >> d >> m >> y;
		data.emplace_back(fname, lname, d, m, y);
	}
	return data;
}
int main() {
	int n, count = 0;
	string command;
	cin >> n;
	vector<student> vect = move(getStudent(n));
	cin >> count;
	for (int i = 0; i < count; ++i) {
		cin >> command;
		cin >> n;
		--n;
		if (command == "name") {
			if (n > vect.size() || n < 0)
				cout << "bad request" << endl;
			else
				cout << vect[n].name_m << ' ' << vect[n].surname_m << endl;
		}
		else if (command == "date") {
			if (n > vect.size() || n < 0)
				cout << "bad request" << endl;
			else
				cout << vect[n].day_m << '.' << vect[n].month_m << '.' << vect[n].year_m << endl;
		}
		else
			cout << "bad request" << endl;
	}

}
