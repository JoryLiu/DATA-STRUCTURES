#include "queue.hpp"

queue::queue() {
    this->storage = new char[MAX_SIZE + 1]();
    this->max_size = MAX_SIZE + 1;
    this->head = 0;
    this->rear = 0;
}
queue::~queue() {
	delete []storage;
}
void queue::push(char n) {
    if (!isFull()) {
        storage[rear%max_size] = n;
        rear++;
    }
}
void queue::pop(void) {
    if (!isEmpty()) {
        head++;
    }
}
char queue::front(void) {
    if (!isEmpty()) {
        return storage[head % max_size];
    } else {
        return 0;
    }
}
char queue::back(void) {
    if (!isEmpty()) {
        return storage[(rear - 1 + max_size) % max_size];
    } else {
        return 0;
    }
}
bool queue::isFull(void) {
    if (rear - head >= max_size - 1)
        return true;
    return false;
}
bool queue::isEmpty(void) {
    if (head == rear) return true;
    return false;
}
void queue::clear(void) {
    head = 0;
    rear = 0;
}
string queue::toString(void) {
	string temp(storage + head % max_size, rear - head);
	return temp;
}
