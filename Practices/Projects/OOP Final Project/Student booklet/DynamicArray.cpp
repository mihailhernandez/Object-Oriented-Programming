#pragma once
#include "DynamicArray.h"
#include "ostream"

const unsigned int INITIAL_CAPACITY = 4;

template <class T>
DynamicArray<T>::DynamicArray() : 
	size(0), 
	capacity(INITIAL_CAPACITY), 
	array(new T[INITIAL_CAPACITY]) {}

template <class T>
DynamicArray<T>::DynamicArray(const unsigned int capacity) :
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
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
	copy(other);
	return *this;
}

template <class T>
const T& DynamicArray<T>::operator[](const unsigned int index) const
{
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
	if (array[size] != nullptr)
		delete[] array[size];
	size--;
}

template <class T>
unsigned int DynamicArray<T>::get_size() const
{
	return size;
}

template <class T>
unsigned int DynamicArray<T>::get_capacity() const
{
	return capacity;
}

template <class T>
void DynamicArray<T>::copy(const DynamicArray<T>& other)
{
	this->size = other.get_size();
	this->capacity = other.get_capacity();
	if (this->array != nullptr)
		delete[] array;
	this->array = new T * [other.get_size()];
	for (unsigned int i = 0; i < other.size(); i++)
		this->array[i] = other[i];
}

template <class T>
void DynamicArray<T>::resize()
{
	capacity *= 2;
	T* resized = new T[capacity];
	for (unsigned int i = 0; i < size; i++)
		resized[i] = array[i];
	delete[] array;
	array = resized;
}

template <class T>
std::ostream& operator<<(std::ostream& output_stream, const DynamicArray<T>& array)
{
	for (auto T : array)
		output_stream << T << std::endl;
	return output_stream;
}

template <class T>
DynamicArray<T>::Iterator::Iterator(const DynamicArray<T>* array, const unsigned int index)
	: array(array),
	index(index) {}

template <class T>
typename DynamicArray<T>::Iterator& DynamicArray<T>::Iterator::operator++()
{
	++index;
	return *this;
}

template <class T>
bool DynamicArray<T>::Iterator::operator!=(const DynamicArray<T>::Iterator& other) const
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
	return DynamicArray<T>::Iterator{ this, this->size};
}


