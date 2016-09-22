#ifndef QUEUE_H_
#define QUEUE_H_
#include <string>
using namespace std;
#define MAX_SIZE 1000
 
class queue {
private:
  char * storage;
  int max_size;
  int head;
  int rear;
public:
  queue();
  ~queue();
  void push(char);
  void pop(void);
  char front(void);
  char back(void);
  bool isFull(void);
  bool isEmpty(void);
  void clear(void);
  string toString(void);
};
 
#endif
