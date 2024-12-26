#include <iostream>

using namespace std;

class BaseArray {
private:
    int capacity;
    int *mem;
protected:
    BaseArray(int capacity = 100) : capacity(capacity), mem(new int[capacity]) {}
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) const { return mem[index]; }
    int getCapacity() const { return capacity; }
};

class MyQueue : public BaseArray {
private:
    int front;
    int rear;
public:
    MyQueue(int capacity = 100) : BaseArray(capacity), front(0), rear(0) {}

    void enqueue(int val) {
        put(rear, val);
        rear = (rear + 1) % getCapacity();
    }

    int dequeue() {
        int val = get(front);
        front = (front + 1) % getCapacity();
        return val;
    }

    bool isEmpty() const {
        return front == rear;
    }

    bool isFull() const {
        return (rear + 1) % getCapacity() == front;
    }

    int size() const {
        return (rear - front + getCapacity()) % getCapacity();
    }

    void printQueue() {
        cout << "큐의 용량 : " << getCapacity() << ", 큐의 크기 : " << size() << endl;
        cout << "큐의 원소를 순서대로 제거하여 출력한다 >> ";
        while (!isEmpty()) {
            cout << dequeue() << " ";
        }
        cout << endl;
        cout << "큐의 현재 크기 : " << size() << endl;
    }
};

int main() {
    int size;
    cout << "큐에 삽입할 정수 개수를 입력하시오 >> ";
    cin >> size;

    MyQueue queue;
    for (int i = 0; i < size; i++) {
        int val;
        cout << i + 1 << " ) ";
        cin >> val;
        queue.enqueue(val);
    }

    queue.printQueue();
}