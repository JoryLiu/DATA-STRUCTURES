#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "../../C/UTILITY.hpp"
#include "../AIRPORT/PLANE.hpp"

const int maxqueue = 10; //  small value for testing
typedef Plane Queue_entry;

class Queue {
public:
   Queue();
   bool empty() const;
   Error_code serve();
   Error_code append(const Queue_entry &item);
   Error_code retrieve(Queue_entry &item) const;
protected:
   int count;
   int front, rear;
   Queue_entry entry[maxqueue];
};
#endif
