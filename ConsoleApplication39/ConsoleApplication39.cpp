#include <iostream>

using namespace std;

class DynamicArrayStack {
private:
    int* stackArray; 
    int capacity;     
    int top;         

public:
    
    DynamicArrayStack(int capacity) {
        this->capacity = capacity;
        stackArray = new int[capacity];
        top = -1; 
    }

    ~DynamicArrayStack() {
        delete[] stackArray;
    }

    void Push(int value) {
        if (IsFull()) {
            cout << "Стек повний. Неможливо додати елемент." << endl;
            return;
        }
        stackArray[++top] = value;
        cout << "Додано елемент " << value << " до стеку." << endl;
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == capacity - 1;
    }

    bool Contains(int value) {
        for (int i = 0; i <= top; ++i) {
            if (stackArray[i] == value) {
                return true;
            }
        }
        return false;
    }

    int Peek() {
        if (IsEmpty()) {
            cout << "Стек порожній. Неможливо взяти елемент." << endl;
            return -1; 
        }
        return stackArray[top];
    }
};

int main() {
    setlocale(LC_ALL, "");

    DynamicArrayStack stack(5);

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    cout << "Верхній елемент стеку: " << stack.Peek() << endl;
    cout << "Стек " << (stack.IsEmpty() ? "порожній" : "не порожній") << endl;

    stack.Push(4);
    stack.Push(5);

    cout << "Стек " << (stack.IsFull() ? "повний" : "не повний") << endl;

    int searchValue = 3;
    cout << "Стек " << (stack.Contains(searchValue) ? "містить" : "не містить")
        << " елемент " << searchValue << endl;

    return 0;
}
