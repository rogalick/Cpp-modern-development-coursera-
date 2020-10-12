#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

template <typename Iterator>
class Page {
    Iterator first_, last_;
    size_t size_;
public:
    Page(Iterator first, Iterator last, size_t size)
        : first_(first), last_(last), size_(size) {}

    Iterator begin() const {
        return first_;
    }
    Iterator end() const {
        return last_;
    }
    size_t size() const {
        return size_;
    }
};

template <typename Iterator>
class Paginator {
    vector<Page<Iterator>> data_;
public:
    Paginator(Iterator b, Iterator e, size_t size) {
        size_t dist = distance(b, e);
        size_t blocks = dist / size;
        size_t pages = blocks + (dist % size != 0);

        for (size_t i = 0; i < blocks; ++i, b += size)
            data_.emplace_back(b, b + size, size);
        if (blocks != pages)
            data_.emplace_back(b, e, distance(b, e));
    }

    auto begin() const {
        return data_.begin();
    }
    auto end() const {
        return data_.end();
    }
    size_t size() const {
        return data_.size();
    }
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator(begin(c), end(c), page_size);
}