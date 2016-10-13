#ifndef EXTENDED_QUEUE_HPP_
#define EXTENDED_QUEUE_HPP_
#include "../QUEUE/QUEUE.hpp"

template <class Queue_entry>
class Extended_queue: public Queue<Queue_entry> {
public:
   bool full() const;
   int size() const;
   void clear();
   Error_code serve_and_retrieve(Queue_entry &item);
};
#endif
