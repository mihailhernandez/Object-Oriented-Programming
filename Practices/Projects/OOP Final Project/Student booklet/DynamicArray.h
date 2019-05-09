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
		Iterator(const DynamicArray<T>*, const unsigned int);
		Iterator& operator++();
		bool operator!=(const Iterator&) const;
		const T& operator*() const;

	private:
		const DynamicArray<T>* array;
		unsigned int index;
	};

	DynamicArray();
	DynamicArray(const unsigned int);
	DynamicArray(const DynamicArray&);
	~DynamicArray();
	DynamicArray& operator=(const DynamicArray&);
	const T& operator[](const unsigned int) const;

	Iterator begin() const;
	Iterator end() const;

	void push_back(const T&);
	void pop_back();
	unsigned int get_size() const;
	unsigned int get_capacity() const;
	
private:
	T* array;
	unsigned int capacity;
	unsigned int size;

	void copy(const DynamicArray&);
	void resize();
};
/*
template <class T>
std::ostream& operator<<(std::ostream&, const DynamicArray<T>&);

template <class T>
std::ofstream& operator<<(std::ofstream&, const DynamicArray<T>&);

template <class T>
std::istream& operator>>(std::istream&, DynamicArray<T>&);

template <class T>
std::ifstream& operator>>(std::ifstream&, DynamicArray<T>&);
*/