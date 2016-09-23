#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
#include <vector>
#include <string>
using namespace std;

void operationLoop() {
	vector<stack* > s;
	vector<queue* > q;
	string operation, tmp;
	char temp;
	int n;
	do {
		cout << "-------------------------Experiment 2-------------------------" << endl;
		cout << "bs: build a new stack" << endl;
		cout << "pss: push character(s) into a stack" << endl;
		cout << "pps: pop a character from a stack" << endl;
		cout << "bq: build a new queue" << endl;
		cout << "psq: push character(s) into a queue" << endl;
		cout << "ppq: pop a character from a queue" << endl;
		cout << "pa: print all stacks and queues" << endl;
		cout << "q : quit" << endl;
		cout << "--------------------------------------------------------------" << endl;
		cin >> operation;
		if (operation == "bs") {
			s.push_back(new stack());
		}
		if (operation == "pss") {
			cout << "We have " << s.size() << " stack(s) with index from 1" << endl;
			do {
				cout << "Input the number of the stack you want to push in" << endl;
				cin >> n;
			} while (n <= 0 || n > s.size());
            do {
                cout << "Input a character(finish by inputting ~)" << endl;
                cin >> temp;
                if (temp != '~') s[n - 1]->push(temp);
            } while (temp != '~');
		}
		if (operation == "pps") {
			cout << "We have " << s.size() << " stack(s) with index from 1" << endl;
			do {
				cout << "Input the number of the stack you want to pop from" << endl;
				cin >> n;
			} while (n <= 0 || n > s.size());
			s[n - 1]->pop();
		}
		if (operation == "bq") {
			q.push_back(new queue());
		}
		if (operation == "psq") {
			cout << "We have " << q.size() << " queue(s) with index from 1" << endl;
			do {
				cout << "Input the number of the queue you want to push in" << endl;
				cin >> n;
			} while (n <= 0 || n > q.size());
            do {
                cout << "Input a character(finish by inputting ~)" << endl;
                cin >> temp;
                if (temp != '~') q[n - 1]->push(temp);
            } while (temp != '~');
		}
		if (operation == "ppq") {
			cout << "We have " << q.size() << " queue(s) with index from 1" << endl;
			do {
				cout << "Input the number of the queue you want to pop from" << endl;
				cin >> n;
			} while (n <= 0 || n > q.size());
			q[n - 1]->pop();
		}
		if (operation == "pa") {
			for (int i = 1; i <= s.size(); i++) {
				cout << "stack " << i << ":" << endl;
				tmp = s[i - 1]->toString();
				cout << tmp << endl;
			}
			for (int i = 1; i <= q.size(); i++) {
				cout << "queue " << i << ":" << endl;
				tmp = q[i - 1]->toString();
				cout << tmp << endl;
			}
		}
	} while (operation != "q");
}
int main() {
	operationLoop();
	return 0;
}
