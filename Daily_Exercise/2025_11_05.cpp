#include <iostream>
#include <cassert>
#include <cstring>
// using namespace std;

template <class T>
class vector
{
public:
    vector()
        : _a(nullptr), _size(0), _capacity(0)
    {
    }

    ~vector()
    {
        delete[] _a;
        _a = nullptr;
        _size = 0;
        _capacity = 0;
    }

    void push_back(const T &x);

    void pop_back();

    size_t size()
    {
        return _size;
    }

    T &operator[](size_t i)
    {
        assert(i < _size);
        return _a[i];
    }

private:
    T *_a;
    size_t _size;
    size_t _capacity;
};

template <class T>
void vector<T>::push_back(const T &x)
{
    if (_size == _capacity)
    {
        size_t new_capacity = _capacity == 0 ? 1 : _capacity * 2;
        T *tmp = new T[new_capacity];
        if (_a)
        {
            memcpy(tmp, _a, _size * sizeof(T));
            delete[] _a;
        }
        _a = tmp;
        _capacity = new_capacity;
    }

    _a[_size++] = x;
}

template <class T>
void vector<T>::pop_back()
{
    if (_size > 0)
    {
        _size--;
    }
}

int Add(int left, int right)
{
    return left + right;
}

template <class T>
T Add(T left, T right)
{
    return left + right;
}

int main()
{
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // for(size_t i = 0; i < v.size(); i++)
    // {
    //     v[i] *= 2;
    // }

    // for(size_t i = 0; i < v.size(); i++)
    // {
    //     std::cout << v[i] << " ";
    // }

    Add(1, 2);
    Add<int>(1, 2);
    return 0;
}
