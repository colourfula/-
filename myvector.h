#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class Vector
{
public:

	Vector(size_t capacity = 3)
		:_data(new T[capacity])
		,_capacity(capacity)
		,_size(0)
	{}

	Vector(const T* array, size_t size)
	{}

	Vector(const Vector& v)
		:_capacity(v._capacity)
		, _size(v._size)
	{
		int* temp = new T[_capacity];
		for (size_t i = 0; i < _size; i++)
			temp[i] = v._data[i];

		delete temp;
		temp = NULL;
	}

	
	Vector& operator=(const Vector& v)
	{
		if (this != &v)
		{
			int* temp = new T[_capacity];
			for (size_t i = 0; i < v._size; i++)
				temp[i] = (int)v._data;

			delete _data;
			_data = temp;
			_capacity = v._capacity;
			_size = v._size;
		}
		return *this;
	}


	~Vector()
	{
		if (this != NULL)
		{
			delete _data;
			_data = NULL;
			_size = 0;
			_capacity = 0;
		}
	}

		/////////////////////Modify////////////////////////////////
	void Printf(const Vector& v)
	{
		for (size_t i = 0; i < v._size; i++)
		{
			printf("%d ", v._data[i]);
		}
		printf("\n");
	}


	void PushBack(const T& data)
	{
		_CheckCapacity();
		_data[_size] = data;
		_size++;
	}

	void PopBack()
	{
		  _data[_size--];
	}

	void Insert(size_t pos, const T& data)
	{
		assert(pos);
		assert(data);
		_CheckCapacity();
		for (size_t i = _size; i >= pos; i--)
		{
			_data[i] = _data[i-1];
		}
		_data[pos] = data;
		_size++;
	}

	void Erase(size_t pos)
	{
		assert(pos);
		if (pos < _size)
		{
			for (size_t i = _size; i >= pos; i--)
			{
				_data[i] = _data[i - 1];
			}
			_size--;
		}
	}

		////////////////////capacity//////////////////////////// 
	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return _size == 0;
	}

	void Resize(size_t newSize, const T& data = T())
	{
		if (newSize < _size)
		{
			_size = newSize;
		}
		else if (newSize>_size)
		{
			size_t oldSize = _size;
			_size = newSize;
			if (newSize < _capacity)
				return;
			else
				_CheckCapacity();

			for (size_t i = 0; i <= oldSize; i++)
			{
				_data[i] = data;
			}
		}
	}

		////////////////Acess/////////////////////////// 
	T& operator[](size_t index)
	{
		assert(index>0 && index<_size);
		return _data[index];
	}

	const T& operator[](size_t index)const
	{
		assert(index>0 && index<_size);
		return _data[index];
	}

	T& Front()
	{
		return _data[0];
	}

	const T& Front()const
	{
		return _data[0];
	}

	T& Back()
	{
		return _data[_size - 1];
	}

	const T& Back()const
	{
		return _data[_size - 1];
	}

	void Clear()
	{
		_size = 0;
		_capacity = 0;
	}
private:
	void _CheckCapacity()
	{
		if (_size >= _capacity)
		{
			int* temp = new T[_capacity * 2];
			for (size_t i = 0; i < _size; i++)
			{
				temp[i] = _data[i];
			}
			delete _data;
			_data = NULL;
			_data = temp;
			_capacity *= 2;
		}
	}

private:
	T* _data;
	size_t _capacity;
	size_t _size;
};

void TestVector()
{
	Vector<int> v1;
	Vector<int> v2(v1);
	Vector<int> v3;
	v3 = v2;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.Printf(v1);

	v1.PopBack();
	v1.Printf(v1);

	v1.Insert(3, 4);
	v1.Printf(v1);

	v1.Erase(3);
	v1.Printf(v1);

	v1.Resize(5, 5);
	v1.Printf(v1);

	size_t data1 = v1.Front();
	printf("%d\n", data1);

	size_t data2 = v1.Back();
	printf("%d\n", data2);
}
