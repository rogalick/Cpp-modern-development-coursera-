#include <iostream>
#include <vector>
#include <string>

using namespace std;

void step(vector<vector<string>>& affairs, vector<int>& months, int& month_num) {
	vector<vector <string>> next_month;

	if (month_num == 11)
		month_num = 0;
	else
		month_num++;
	next_month.insert(end(next_month), begin(affairs), end(affairs));
	next_month.resize(months[month_num]);
	if (next_month.size() < affairs.size()) {
		for (size_t i = next_month.size(); i < affairs.size(); ++i)
			for (const auto& a : affairs[i])
				next_month[months[month_num] - 1].push_back(a);
	}
	affairs.clear();
	affairs = next_month;
}

int main() {
	int q, month_num = 0;
	string action;
	vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	vector<vector<string>> affairs(months[month_num]);

	for (cin >> q; q > 0; --q) {
		cin >> action;
		if (action == "NEXT")
			step(affairs, months, month_num);
		else if (action == "DUMP"){
			int day;
	        cin >> day;
	        cout << affairs[day - 1].size() << " ";
	        for (auto d : affairs[day - 1])
		        cout << d << " ";
	        cout << endl;
        }
		else if (action == "ADD"){
		    int day;
	        string work;
	        cin >> day >> work;
	        affairs[day - 1].push_back(work);
        }
	}
	return 0;
}