#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Deque {
    vector<T> head, tail;
public:
    Deque() = default;

    bool Empty() const {
        return head.empty() & tail.empty();
    }
    size_t Size() const {
        return head.size() + tail.size();
    }

    T& operator[](size_t index) {
        size_t size = head.size();
        return index < size ? head[size - index - 1] : tail[index - size];
    }
    const T& operator[](size_t index) const {
        size_t size = head.size();
        return index < size ? head[size - index - 1] : tail[index - size];
    }

    T& At(size_t index) {
        size_t size = head.size();
        return index < size ? head.at(size - index - 1) : tail.at(index - size);
    }
    const T& At(size_t index) const {
        size_t size = head.size();
        return index < size ? head.at(size - index - 1) : tail.at(index - size);
    }

    T& Front() {
        return head.empty() ? tail.front() : head.back();
    }
    const T& Front() const {
        return head.empty() ? tail.front() : head.back();
    }

    T& Back() {
        return tail.empty() ? head.front() : tail.back();
    }
    const T& Back() const {
        return tail.empty() ? head.front() : tail.back();
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }
    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};