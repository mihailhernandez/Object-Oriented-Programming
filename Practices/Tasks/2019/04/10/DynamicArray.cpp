#include <iostream>
#include <cstddef>

const size_t DYNAMIC_ARRAY_INITIAL_SIZE = 10;
const size_t RESIZE_SIZE = 10;

class DynamicArray
{

public:
	DynamicArray()
	{
		set_capacity(DYNAMIC_ARRAY_INITIAL_SIZE);
		init_array();
	}

	DynamicArray(size_t capacity)
	{
		set_capacity(capacity);
		init_array();
	}

	DynamicArray(const DynamicArray& other)
	{
		set_capacity(other.get_capacity());
		set_size(other.get_size());
		init_array();
		copy_array(other.get_array(), array, size);
	}

	~DynamicArray()
	{
		delete[] array;
	}

	void clear()
	{
		for (size_t i = 0; i != capacity; ++i)
			array[i] = 0;
	}

	void push_back(int elem)
	{
		if (size == capacity)
			resize();
		array[size++] = elem;
	}

	void print() const
	{
		for (size_t i = 0; i != size; ++i)
			std::cout << array[i] << " ";
		std::cout << std::endl;
	}

	size_t get_size() const
	{
		return size;
	}

	size_t get_capacity() const
	{
		return capacity;
	}

	int* get_array() const
	{
		return array;
	}

	void pop_back()
	{
		if (size == 0)
		{
			std::cout << "Cannot pop back! Size is 0!" << std::endl;
			return;
		}
		array[size--] = 0;
	}

	DynamicArray& operator=(const DynamicArray& other)
	{
		set_size(other.get_size());
		set_capacity(other.get_capacity());
		copy_array(other.get_array(), array, size);
		return *this;
	}

	int& operator[](const size_t index)
	{
		return array[index];
	}

private:

	size_t capacity;
	size_t size = 0;
	int* array;

	void init_array()
	{
		array = new int[this->capacity];
		clear();
	}

	void resize()
	{
		set_capacity(capacity + RESIZE_SIZE);
		int* new_array = new int[capacity];
		copy_array(array, new_array, size);
		delete[] array;
		array = new_array;
	}

	void set_capacity(size_t capacity)
	{
		if (capacity < 0)
			this->capacity = DYNAMIC_ARRAY_INITIAL_SIZE;
		else
			this->capacity = capacity;
	}

	void set_size(size_t size)
	{
		if (size > 0)
			this->size = size;
		else
			this->size = 0;
	}

	void copy_array(int* source, int* dest, int size)
	{
		for (size_t i = 0; i != size; ++i)
			dest[i] = source[i];
	}
};

int main()
{
	DynamicArray array(5);
	for (int i = 0; i != 2 * DYNAMIC_ARRAY_INITIAL_SIZE; ++i)
		array.push_back(i);
	std::cout << "Array 1:         ";
	array.print();
	DynamicArray array2(array);
	std::cout << "Array 2:         ";
	array2.print();

	for (int i = 0; i != DYNAMIC_ARRAY_INITIAL_SIZE; ++i)
		array.pop_back();
	std::cout << "Array 1:         ";
	array.print();

	DynamicArray array3;
	std::cout << "Array 3:         ";
	array3 = array2;
	array3.print();

	std::cout << "Array 1 with []: ";
	for (size_t i = 0; i < array.get_size(); ++i)
		std::cout << array[i] << " ";
	std::cout << std::endl;

	return 0;
}
