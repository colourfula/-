 #pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
public:
	Stack()
		:_data(new T[10])
		, _capacity(0)
		, _size(0)
	{}

	void Push(const T& data)
	{
		_CheckCapacity();
		_data[_size] = data;
		++_size;
	}


	void Pop()
	{
		_size--;
	}


	T& Top()
	{
		return _data[_size - 1];
	}


	/*const T& Top()
	{
		return _data[_size - 1];
	}*/


	size_t Size()
	{
		return _size;
	}


	bool Empty()
	{
		return _size == 0;
	}


private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			size_t newCapacity = _capacity * 2 + 3;

			T* temp = new T[newCapacity];
			for (size_t i = 0; i < _size; i++)
				temp[i] = _data[i];

			delete[] _data;
			_data = temp;
			_capacity = newCapacity;
		}
	}

private:
	T* _data;
	size_t _capacity;
	size_t _size;
};



void StackTest()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);

	s.Pop();
	cout<<s.Top()<<endl;
	cout<<s.Size()<<endl;

	s.Pop();
	cout << s.Top() << endl;
	cout << s.Size() << endl;

}

 
