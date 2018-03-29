#include <cstdio>
#include <queue>
using namespace std;

struct position {
    char character;
    int number;
    position(char c, int n) : character(c), number(n) {}
    bool topLeft() {
        return (character - 2 >= 'a' && number - 1 >= 1);
    }
    bool topRight() {
        return (character - 2 >= 'a' && number + 1 <= 8);
    }
    bool leftTop() {
        return (character - 1 >= 'a' && number - 2 >= 1);
    }
    bool leftBottom() {
        return (character + 1 <= 'h' && number - 2 >= 1);
    }
    bool rightTop() {
        return (character - 1 >= 'a' && number + 2 <= 8);
    }
    bool rightBottom() {
        return (character + 1 <= 'h' && number + 2 <= 8);
    }
    bool bottomLeft() {
        return (character + 2 <= 'h' && number - 1 >= 1);
    }
    bool bottomRight() {
        return (character + 2 <= 'h' && number + 1 <= 8);
    }
    bool operator==(const position& other) {
        return (character == other.character && number == other.number);
    }
};

int bfs(char a, int x, char b, int y) {
    queue<position*> q1, q2;
    int board[8][8];
    position* temp;
    position terminal(b, y);
    int dis = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = -1;
    q1.push(new position(a, x));
    while (!q1.empty()) {
        temp = q1.front();
        board[temp->character - 'a'][temp->number - 1] = dis;
        if (*temp == terminal) return dis;
        if (temp->topLeft() && board[temp->character - 'a' - 2][temp->number - 1 - 1] == -1) {
            board[temp->character - 'a' - 2][temp->number - 1 - 1] = -2;
            q2.push(new position(temp->character - 2, temp->number - 1));
        }
        if (temp->topRight() && board[temp->character - 'a' - 2][temp->number - 1 + 1] == -1) {
            board[temp->character - 'a' - 2][temp->number - 1 + 1] = -2;
            q2.push(new position(temp->character - 2, temp->number + 1));
        }
        if (temp->leftTop() && board[temp->character - 'a' - 1][temp->number - 1 - 2] == -1) {
            board[temp->character - 'a' - 1][temp->number - 1 - 2] = -2;
            q2.push(new position(temp->character - 1, temp->number - 2));
        }
        if (temp->leftBottom() && board[temp->character - 'a' + 1][temp->number - 1 - 2] == -1) {
            board[temp->character - 'a' + 1][temp->number - 1 - 2] = -2;
            q2.push(new position(temp->character + 1, temp->number - 2));
        }
        if (temp->rightTop() && board[temp->character - 'a' - 1][temp->number - 1 + 2] == -1) {
            board[temp->character - 'a' - 1][temp->number - 1 + 2] = -2;
            q2.push(new position(temp->character - 1, temp->number + 2));
        }
        if (temp->rightBottom() && board[temp->character - 'a' + 1][temp->number - 1 + 2] == -1) {
            board[temp->character - 'a' + 1][temp->number - 1 + 2] = -2;
            q2.push(new position(temp->character + 1, temp->number + 2));
        }
        if (temp->bottomLeft() && board[temp->character - 'a' + 2][temp->number - 1 - 1] == -1) {
            board[temp->character - 'a' + 2][temp->number - 1 - 1] = -2;
            q2.push(new position(temp->character + 2, temp->number - 1));
        }
        if (temp->bottomRight() && board[temp->character - 'a' + 2][temp->number - 1 + 1] == -1) {
            board[temp->character - 'a' + 2][temp->number - 1 + 1] = -2;
            q2.push(new position(temp->character + 2, temp->number + 1));
        }
        q1.pop();
        delete temp;
        if (q1.empty()) {
            dis++;
            swap(q1, q2);
        }
    }
}

int main() {
    int t, x, y, step;
    char a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("\n%c%d %c%d", &a, &x, &b, &y);
        step = bfs(a, x, b, y);
        printf("To get from %c%d to %c%d takes %d knight moves.\n", a, x, b, y, step);
    }
    return 0;
}
