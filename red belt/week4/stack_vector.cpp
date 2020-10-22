#include <array>
#include "test_runner.h"
#include "profile.h"

#include <random>
#include <stdexcept>

using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) : size(a_size) {
        if (a_size > N)
            throw invalid_argument("Too much");
    }

    T& operator[](size_t index) {
        return data[index];
    }
    const T& operator[](size_t index) const {
        return data[index];
    }

    T* begin() {
        return data.begin();
    }
    T* end() {
        return data.end();
    }
    T* begin() const {
        return data.begin();
    }
    T* end() const {
        return data.end();
    }

    size_t Size() const {
        return size;
    }
    size_t Capacity() const {
        return N;
    }

    void PushBack(const T& value) {
        if (size >= N)
            throw overflow_error("Full");
        else
            data[size++] = value;

    }
    T PopBack() {
        if (size == 0) {
            throw underflow_error("Empty");
        }
        else {
            size--;
            return data[size];
        }
    }
private:
    size_t size = 0;
    array<T, N> data;
};


void TestConstruction() {
    StackVector<int, 10> v;
    ASSERT_EQUAL(v.Size(), 0u);
    ASSERT_EQUAL(v.Capacity(), 10u);

    StackVector<int, 8> u(5);
    ASSERT_EQUAL(u.Size(), 5u);
    ASSERT_EQUAL(u.Capacity(), 8u);

    try {
        StackVector<int, 10> u(50);
        Assert(false, "Expect invalid_argument for too large size");
    }
    catch (invalid_argument&) {
    }
    catch (...) {
        Assert(false, "Unexpected exception for too large size");
    }
}

void TestPushBack() {
    StackVector<int, 5> v;
    for (size_t i = 0; i < v.Capacity(); ++i) {
        v.PushBack(i);
    }

    try {
        v.PushBack(0);
        Assert(false, "Expect overflow_error for PushBack in full vector");
    }
    catch (overflow_error&) {
    }
    catch (...) {
        Assert(false, "Unexpected exception for PushBack in full vector");
    }
}

void TestPopBack() {
    StackVector<int, 5> v;
    for (size_t i = 1; i <= v.Capacity(); ++i) {
        v.PushBack(i);
    }
    for (int i = v.Size(); i > 0; --i) {
        ASSERT_EQUAL(v.PopBack(), i);
    }

    try {
        v.PopBack();
        Assert(false, "Expect underflow_error for PopBack from empty vector");
    }
    catch (underflow_error&) {
    }
    catch (...) {
        Assert(false, "Unexpected exception for PopBack from empty vector");
    }
}

int main() {
    {
        TestRunner tr;
        RUN_TEST(tr, TestConstruction);
        RUN_TEST(tr, TestPushBack);
        RUN_TEST(tr, TestPopBack);
    }

    cerr << "Running benchmark..." << endl;
    const size_t max_size = 2500;

    default_random_engine re;
    uniform_int_distribution<int> value_gen(1, max_size);

    vector<vector<int>> test_data(50000);
    for (auto& cur_vec : test_data) {
        cur_vec.resize(value_gen(re));
        for (int& x : cur_vec) {
            x = value_gen(re);
        }
    }

    {
        LOG_DURATION("vector w/o reserve");
        for (auto& cur_vec : test_data) {
            vector<int> v;
            for (int x : cur_vec) {
                v.push_back(x);
            }
        }
    }
    {
        LOG_DURATION("vector with reserve");
        for (auto& cur_vec : test_data) {
            vector<int> v;
            v.reserve(cur_vec.size());
            for (int x : cur_vec) {
                v.push_back(x);
            }
        }
    }
    {
        LOG_DURATION("StackVector");
        for (auto& cur_vec : test_data) {
            StackVector<int, max_size> v;
            for (int x : cur_vec) {
                v.PushBack(x);
            }
        }
    }
    cerr << "Done" << endl;
}