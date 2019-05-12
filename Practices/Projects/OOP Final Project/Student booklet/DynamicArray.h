#pragma once

#include <iostream>
#include <fstream>

template <class T>
class DynamicArray
{
public:
	class Iterator
	{
	public:
		Iterator(const DynamicArray<T>*, const  int);
		Iterator& operator++();
		bool operator!=(const Iterator&) const;
		const T& operator*() const;

	private:
		const DynamicArray<T>* array;
		int index;
	};

	DynamicArray();
	DynamicArray(const int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();
	DynamicArray<T>& operator=(const DynamicArray<T>&);
	const T& operator[](const int) const;

	Iterator begin() const;
	Iterator end() const;

	void clear();
	void push_back(const T&);
	void pop_back();
	int get_size() const;
	int get_capacity() const;
	bool is_empty() const;
	
private:
	T* array;
	int capacity;
	int size;

	void copy(const DynamicArray&);
	void resize();
};

template <class T>
std::ostream& operator<<(std::ostream&, const DynamicArray<T>&);
template <class T>
std::istream& operator>>(std::istream&, DynamicArray<T>&);

const int INITIAL_CAPACITY = 4;

template <class T>
DynamicArray<T>::DynamicArray() :
	size(0),
	capacity(INITIAL_CAPACITY),
	array(new T[INITIAL_CAPACITY]) {}

template <class T>
DynamicArray<T>::DynamicArray(const int capacity) :
	size(0),
	capacity(capacity),
	array(new T[capacity]) {}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
	copy(other);
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
	delete[] array;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	copy(other);
	return *this;
}

template <class T>
const T& DynamicArray<T>::operator[](const int index) const
{
	if (index < 0 || index >= size)
		return nullptr;
	return array[index];
}

template <class T>
void DynamicArray<T>::push_back(const T& elem)
{
	if (size == capacity)
		resize();
	array[size++] = elem;
}

template <class T>
void DynamicArray<T>::pop_back()
{
	size--;
}

template <class T>
int DynamicArray<T>::get_size() const
{
	return size;
}

template <class T>
int DynamicArray<T>::get_capacity() const
{
	return capacity;
}

template <class T>
void DynamicArray<T>::copy(const DynamicArray<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->array = new T[other.size];
	for (int i = 0; i < other.size; i++)
		this->array[i] = other[i];
}

template <class T>
void DynamicArray<T>::resize()
{
	capacity *= 2;
	T* resized = new T[capacity];
	for (int i = 0; i < size; i++)
		resized[i] = array[i];
	delete[] array;
	array = resized;
}

template <class T>
void DynamicArray<T>::clear()
{
	while (!is_empty())
		pop_back();
}

template <class T>
bool DynamicArray<T>::is_empty() const
{
	return size == 0;
}

template <class T>
DynamicArray<T>::Iterator::Iterator(const DynamicArray<T> * array, const int index)
	: array(array),
	index(index) {}

template <class T>
typename DynamicArray<T>::Iterator& DynamicArray<T>::Iterator::operator++()
{
	index++;
	return *this;
}

template <class T>
bool DynamicArray<T>::Iterator::operator!=(const DynamicArray<T>::Iterator & other) const
{
	return this->index != other.index;
}

template <class T>
const T& DynamicArray<T>::Iterator::operator*() const
{
	return array->operator[](index);
}

template <typename T>
typename DynamicArray<T>::Iterator DynamicArray<T>::begin() const
{
	return DynamicArray<T>::Iterator{ this, 0 };
}

template <typename T>
typename DynamicArray<T>::Iterator DynamicArray<T>::end() const
{
	return DynamicArray<T>::Iterator{ this, this->size };
}

template <class T>
std::ostream& operator<<(std::ostream& output_stream, const DynamicArray<T>& array)
{
	for (auto elem : array)
		output_stream << elem;
	return output_stream;
}

template <class T>
std::istream& operator>>(std::istream& input_stream, DynamicArray<T>& array)
{
	T elem;
	input_stream >> elem;
	array.push_back(elem);
	return input_stream;
}