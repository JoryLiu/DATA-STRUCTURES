#ifndef EXTENDED_QUEUE_HPP_
#define EXTENDED_QUEUE_HPP_
#include "../QUEUE/QUEUE.hpp"

class Extended_queue: public Queue {
public:
   bool full() const;
   int size() const;
   void clear();
   Error_code serve_and_retrieve(Queue_entry &item);
};
#endif
