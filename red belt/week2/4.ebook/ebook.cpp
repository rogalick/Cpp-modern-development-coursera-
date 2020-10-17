#include <iomanip>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class ReadingManager {
public:
    ReadingManager()
        : pages(MAX_USER_COUNT_ + 1, 0),
        last_page(0) {};

    void Read(int user_id, int page_count) {
        if (data.count(user_id) > 0) {
            pages[data[user_id]]--;
        }
        data[user_id] = page_count;
        pages[page_count]++;
    }

    double Cheer(int user_id) const {
        if (data.count(user_id) == 0) {
            return 0;
        }
        if (data.size() == 1) {
            return 1;
        }
        const int page_count = data.at(user_id);

        int count = 0;
        for (int i = 1; i < page_count; ++i) {
            count += pages[i];
        }

        return count * 1.0 / (data.size() - 1);
    }

private:
    static const int MAX_USER_COUNT_ = 100'000;
    unordered_map<int, int> data;
    vector<int> pages;
    int last_page;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        }
        else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}