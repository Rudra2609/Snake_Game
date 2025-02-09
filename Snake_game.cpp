#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int width, height, hs = 0;
int fruitX, fruitY, score;
bool gameover;
bool gameStarted = false;
bool firstRun = true;

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

struct Node {
    int x, y;
    Node* next;
    Node(int x, int y) : x(x), y(y), next(nullptr) {}
};

Node* head = nullptr;
Node* tail = nullptr;

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void HideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void setup() {
    if (firstRun) {
        cout << "Enter grid width: ";
        cin >> width;
        cout << "Enter grid height: ";
        cin >> height;
        firstRun = false;
    }

    gameover = false;
    gameStarted = false;
    dir = STOP;
    score = 0;

    head = new Node(width / 2, height / 2);
    tail = head;

    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw() {
    HideCursor();

    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    for (int i = 0; i < width + 2; i++)
        cout << "*";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "*";

            bool printed = false;
            Node* temp = head;
            while (temp) {
                if (temp->x == j && temp->y == i) {
                    SetColor(10);
                    cout << (temp == head ? 'O' : 'o');
                    SetColor(7);
                    printed = true;
                    break;
                }
                temp = temp->next;
            }

            if (!printed) {
                if (i == fruitY && j == fruitX)
                    cout << "&";
                else
                    cout << " ";
            }

            if (j == width - 1) cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "*";
    cout << endl;

    cout << "Score: " << score << endl;
    cout << "Highest Score: " << hs << endl;
}

void Input() {
    if (_kbhit()) {
        char key = _getch();
        switch (key) {
            case 'a':
                if (gameStarted && dir == RIGHT) gameover = true;
                else { dir = LEFT; gameStarted = true; }
                break;
            case 'd':
                if (gameStarted && dir == LEFT) gameover = true;
                else { dir = RIGHT; gameStarted = true; }
                break;
            case 'w':
                if (gameStarted && dir == DOWN) gameover = true;
                else { dir = UP; gameStarted = true; }
                break;
            case 's':
                if (gameStarted && dir == UP) gameover = true;
                else { dir = DOWN; gameStarted = true; }
                break;
            case 'x':
                gameover = true;
                break;
        }
    }
}

void MoveSnake() {
    int newX = head->x, newY = head->y;
    switch (dir) {
        case LEFT: newX--; break;
        case RIGHT: newX++; break;
        case UP: newY--; break;
        case DOWN: newY++; break;
        default: return;
    }

    if (newX >= width || newX < 0 || newY >= height || newY < 0) {
        gameover = true;
        return;
    }

    Node* temp = head;
    while (temp) {
        if (temp->x == newX && temp->y == newY) {
            gameover = true;
            return;
        }
        temp = temp->next;
    }

    Node* newHead = new Node(newX, newY);
    newHead->next = head;
    head = newHead;

    if (newX == fruitX && newY == fruitY) {
        score += 5;
        hs = max(hs, score);
        fruitX = rand() % width;
        fruitY = rand() % height;
    } else {
        Node* prev = nullptr;
        Node* current = head;
        while (current->next) {
            prev = current;
            current = current->next;
        }
        if (prev) {
            prev->next = nullptr;
            delete current;
        }
    }
}

void Clean() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void GameOverScreen() {
    cout << "Game Over!" << endl;
    cout << "Press 'r' to restart or 'x' to exit: ";
    char choice;
    cin >> choice;
    if (choice == 'r') {
        Clean();
        setup();
    } else {
        exit(0);
    }
}

int main() {
    srand(time(0));
    setup();
    while (true) {
        while (!gameover) {
            Draw();
            Input();
            MoveSnake();
            Sleep(70);
        }
        GameOverScreen();
    }
    return 0;
}
