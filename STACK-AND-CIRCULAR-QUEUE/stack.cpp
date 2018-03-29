#include "stack.hpp"

stack::stack() {
	this->storage = new char[MAX_SIZE]();
    this->max_size = MAX_SIZE;
    this->top = -1;
}
stack::~stack() {
	delete []this->storage;
}
void stack::push(char n) {
    if (top < max_size-1)
        storage[++top] = n;
}
void stack::pop(void) {
    if (top > -1) top--;
}
char stack::peek(void) {
    if (!isEmpty()) {
        return storage[top];
    } else {
        return 0;
    }
}
bool stack::isEmpty(void) {
    if (top == -1) return true;
    return false;
}
bool stack::isFull(void) {
    if (top == max_size-1) return true;
    return false;
}
void stack::clear(void) {
    top = -1;
}
string stack::toString(void) {
	string temp(storage, top + 1);
	return temp;
}
