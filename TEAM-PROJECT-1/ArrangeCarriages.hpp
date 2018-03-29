#ifndef ARRANGECARRIAGES_HPP_
#define ARRANGECARRIAGES_HPP_
#include <vector>
#include <stack>

class ArrangeCarriages {
  public:
    ArrangeCarriages() : step(-1) {}
    void readWaitingCarriages();
    void arrangeCarriages();

  private:
    std::vector<int> waitingCarriages;
    std::vector<std::stack<int> > buffers;
    std::vector<int> arrangedCarriages;
    int step;

    void printSnapshot();
};

#endif
