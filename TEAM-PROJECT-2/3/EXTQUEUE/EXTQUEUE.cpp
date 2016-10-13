#include "EXTQUEUE.hpp"

template <class Queue_entry>
bool Extended_queue::full() const
/*   
Post:  Return true if the Extended_queue is full;
return false otherwise.
 */
{
   return count == maxqueue;
}
 
template <class Queue_entry>
void Extended_queue::clear()
/*   
Post:   All entries in the Extended_queue have
been deleted; the Extended_queue is empty.
 */
{
   count = 0;
   front = 0;
   rear = maxqueue - 1;
}

template <class Queue_entry>
int Extended_queue::size() const
/*   
Post:   Return the number of entries in the Extended_queue.
 */
{
   return count;
}

template <class Queue_entry>
Error_code Extended_queue::serve_and_retrieve(Queue_entry &item)
/*   
Post: Return underflow if the Extended_queue is empty. Otherwise
remove and copy
the item at the front of the Extended_queue to item.
 */
{
   if (count == 0) return underflow;
   else {
      count--;
      item = entry[front];
      front = ((front + 1) == maxqueue) ? 0 : (front + 1);
   }
   return success;
}
