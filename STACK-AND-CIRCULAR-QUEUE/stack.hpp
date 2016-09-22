#ifndef STACK_H_
#define STACK_H_
#include <string>
using namespace std;
#define MAX_SIZE 1000
 
class stack {
private:
  char * storage;
  int max_size;
  int top;
public:
  stack();
  ~stack();
  void push(char);
  void pop(void);
  char peek(void);
  bool isEmpty(void);
  bool isFull(void);
  void clear(void);
  string toString(void);
};
 
#endif
