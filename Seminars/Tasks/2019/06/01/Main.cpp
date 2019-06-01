#include <iostream>

#include "CircularQueue.h"

int main()
{
	CircularQueue<int> queue;
	for (int i = 0; i < 100; i++)
		queue.enqueue(i + 1);
	while (!queue.is_empty())
		std::cout << queue.dequeue() << std::endl;
	return 0;
}