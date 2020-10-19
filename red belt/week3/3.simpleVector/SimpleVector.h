#include <cstdlib>
#include <cstring>



template <typename T>
class SimpleVector {
public:
	SimpleVector() = default;
	explicit SimpleVector(size_t size) {
		data = new T[size];
		end_ = data + size;
		capacity_ = size_ = size;
	}
	~SimpleVector() {
		delete[] data;
	}

	T& operator[](size_t index) {
		return data[index];
	}
	const T& operator[](size_t index) const {
		return data[index];
	}

	T* begin() { return data; }

	const T* begin() const { return data; }

	T* end() { return end_; }

	const T* end() const { return end_; }

	size_t Size() const {
		return size_;
	}
	size_t Capacity() const {
		return capacity_;
	}
	void PushBack(const T& value) {
		if (size_ == capacity_)
			helpfunc();

		data[size_] = value;
		++size_;
		++end_;
	}

private:
	void helpfunc() {
		if (capacity_ == 0)
			capacity_ = 1;
		else
			capacity_ *= 2;
		T* copy = new T[capacity_];

		for (size_t i = 0; i < size_; i++)
			copy[i] = data[i];

		delete[] data;
		data = copy;
		end_ = data + size_;
	}
	T* data = nullptr;
	T* end_ = nullptr;
	size_t size_ = 0;
	size_t capacity_ = 0;
};