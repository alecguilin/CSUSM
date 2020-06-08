#include "buffer.h"

//buffer vars
buffer_item buffer[BUFFER_SIZE];	//circular buffer
int front = 0;						//position of front item
int back = 0;						//position of back item
int count = 0;						//number of items in buffer

//PURPOSE: displays current items in the buffer within bounds
void display()
{
	int start = front;
	int end = back;
	int i = 0;
	int j = 0;

	std::cout << "current buffer: [ ";

	for (i = start; j < count; i = (i + 1) % BUFFER_SIZE) {
		std::cout << buffer[i] << " ";
		j++;

		if (i == (end - 1))
			break;
	}

	if (count == 0) {
		std::cout << "empty ";
	}

	std::cout << "] \n";
}

//PURPOSE: checks if buffer is full
//RETURN: true if count is equal to buffer size. if not then return false
bool isFull() {
	return (count == BUFFER_SIZE);
}

//PURPOSE: checks if buffer is empty
//RETURN: true if count is equal to 0. if not then return false
bool isEmpty() {
	return (count == 0);
}

//PURPOSE: inserts an item into the circular buffer by updating back pointer
//PARAMETER: item is the item to insert into buffer
//RETURN: 0 if insert was sucessful and -1 if insert was unsucessful
int insertItem(buffer_item item) {

	//check if buffer is not full first
	if (!isFull()) {
		buffer[back] = item;
		back = (back + 1) % BUFFER_SIZE;  //modulus used to wrap around
		count++;

		return 0;
	}

	return -1;
}

//PURPOSE: removes an item from circular buffer by updating front pointer
//PARAMETER: *item is the item removed from the buffer
//RETURN: 0 = if insert was sucessful and -1 = if insert was unsucessful
int removeItem(buffer_item *item) {

	//check if buffer is not empty first
	if (!isEmpty()) {
		*item = buffer[front];
		front = (front + 1) % BUFFER_SIZE;	//modulus used to wrap around
		count--;

		return 0;
	}

	return -1;
}