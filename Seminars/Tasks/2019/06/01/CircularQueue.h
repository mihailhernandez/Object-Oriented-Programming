#pragma once

const unsigned int INITIAL_SIZE = 4;
const unsigned int RESIZE_BY = 2;

template <class T>
class CircularQueue
{
public:
	CircularQueue();
	CircularQueue(const CircularQueue<T>&);
	~CircularQueue();

	CircularQueue<T>& operator=(const CircularQueue<T>&);

	int get_size() const;
	int get_capacity() const;

	bool is_empty() const;

	void enqueue(const T&);
	T dequeue();
private:
	T* arr;
	int get_index;
	int put_index;
	int size;
	int capacity;

	void copy_from(const CircularQueue<T>&);
	void free();
	void resize();
};

template <class T>
CircularQueue<T>::CircularQueue() : 
	arr(new T[INITIAL_SIZE]), 
	capacity(INITIAL_SIZE),
	get_index(0),
	put_index(0) {}

template <class T>
CircularQueue<T>::CircularQueue(const CircularQueue<T>& queue) 
	: arr(nullptr),
	capacity(INITIAL_SIZE),
	get_index(0),
	put_index(0)
{
	copy_from(queue);
}

template <class T>
CircularQueue<T>::~CircularQueue()
{
	free();
}

template <class T>
void CircularQueue<T>::copy_from(const CircularQueue<T>& queue)
{
	this->arr = new T[queue.capacity];
	for (int i = 0; i < queue.size; i++)
		this->arr[i] = queue.arr[i];
	this->size = queue.size;
	this->capacity = queue.capacity;
	this->get_index = queue.get_index;
	this->put_index = queue.put_index;
}

template <class T>
void CircularQueue<T>::free()
{
	delete[] arr;
}

template <class T>
CircularQueue<T>& CircularQueue<T>::operator=(const CircularQueue& queue)
{
	copy_from(queue);
}

template <class T>
void CircularQueue<T>::enqueue(const T& elem)
{
	if (size == capacity)
		resize();
	arr[put_index++] = elem;
	put_index %= capacity;
	size++;
}

template <class T>
T CircularQueue<T>::dequeue()
{
	if (is_empty())
		throw "Queue is empty!";
	T elem = arr[get_index++];
	get_index %= capacity;
	size--;
	return elem;
}

template <class T>
void CircularQueue<T>::resize()
{
	T* temp = new T[capacity * RESIZE_BY];
	for (int i = 0; i < capacity; i++)
		temp[i] = dequeue();
	get_index = 0;
	put_index = capacity - 1;
	size = capacity - 1;
	capacity *= RESIZE_BY;
	delete[] arr;
	arr = temp;
}

template <class T>
int CircularQueue<T>::get_size() const
{
	return size;
}

template <class T>
int CircularQueue<T>::get_capacity() const
{
	return capacity;
}

template <class T>
bool  CircularQueue<T>::is_empty() const
{
	return size == 0;
}