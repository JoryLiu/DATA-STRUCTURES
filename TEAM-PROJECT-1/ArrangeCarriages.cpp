#include "ArrangeCarriages.hpp"
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <limits>
using std::cin;
using std::cout;
using std::endl;

//  surpose that the inputs are all valid!
//  OPTIONAL: handle invaild inputs
void ArrangeCarriages::readWaitingCarriages() {
    int total, tmp;
    cout << "Please input the number of carriages : ";
    cin >> total;
    cout << "Please input the sequence of carriages." << endl;
    for (int i = 0; i < total; ++i) {
        cin >> tmp;
        waitingCarriages.push_back(tmp);
    }
}

void ArrangeCarriages::printSnapshot() {
    cout << endl;
    ++step;
    if (step == 0)
        cout << "Initial" << endl;
    else
        cout << "Step " << step << endl;

    cout << "Waiting   :";
    for (auto waitingCarriage : waitingCarriages)
        cout << ' ' << std::setw(3) << std::left << waitingCarriage;
    cout << endl;
    for (const auto& buffer : buffers) {
        cout << "Buffer  " << &buffer - &buffers[0] + 1 << " :";
        //  copy the buffer to print, in order not to modify buffers
        std::stack<int> tmp_buffer(buffer);
        while (tmp_buffer.size() > 1) {
            cout << ' ' <<  std::setw(3) << std::left << tmp_buffer.top();
            tmp_buffer.pop();
        }
        cout << endl;
    }
    cout << "Arranged  :";
    for (auto arrangedCarriage : arrangedCarriages)
        cout << ' ' << std::setw(3) << std::left << arrangedCarriage;
    cout << endl;
}

void ArrangeCarriages::arrangeCarriages() {
    //  print initial state
    printSnapshot();
    const int total = waitingCarriages.size();
    //  process each carriage
    for (int arrangingIndex = 1; arrangingIndex <= total; ++arrangingIndex) {
        //  check whether the needed carriage has been in some buffer
        bool gotCarriageFromBuffers = false;
        for (auto& buffer : buffers) {
            if (buffer.top() == arrangingIndex) {
                arrangedCarriages.push_back(buffer.top());
                buffer.pop();
                gotCarriageFromBuffers = true;
                printSnapshot();
                break;
            }
        }

        if (gotCarriageFromBuffers)
            continue;
        //  if not, process waiting carriages
        while (waitingCarriages.back() != arrangingIndex) {
            //  find the best buffer to push
            int minDiff = std::numeric_limits<int>::max();
            int targetIndex = buffers.size();
            for (int index = 0; index < buffers.size(); ++index) {
                int diff = buffers[index].top() - waitingCarriages.back();
                if (diff > 0 && diff < minDiff) {
                    minDiff = diff;
                    targetIndex = index;
                }
            }
            //  if a new buffer is needed
            if (targetIndex == buffers.size()) {
                buffers.push_back(std::stack<int>());
                //  push a guard at the bottom of each buffer
                buffers[targetIndex].push(std::numeric_limits<int>::max());
            }
            buffers[targetIndex].push(waitingCarriages.back());
            waitingCarriages.pop_back();
            printSnapshot();
        }
        //  found needed carriage in waiting carriages
        arrangedCarriages.push_back(waitingCarriages.back());
        waitingCarriages.pop_back();
        printSnapshot();
    }

    cout << endl << step << " step(s) needed." << endl;
    cout << buffers.size() << " buffer(s) used." << endl << endl;
}
