struct List{                
    int val;
    List* next;
    List* prev;
    List(int x){ val = x; next = nullptr; prev = nullptr; }
};

class MyCircularDeque {
private:
    int capacity;
    int size;
    List* head;
    List* tail;

public:
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        List* node = new List(value);
        if(isEmpty()) head=tail=node;
        else{
            node -> next = head;
            head->prev = node;
            head = node;
        }
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        List* node = new List(value);
        if(isEmpty()) head=tail=node;
        else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        List* temp = head;
        if(head == tail) head=tail=nullptr; 
        else{
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        List* node = tail;
        if(head == tail) head=tail=nullptr;
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        size--;
        delete node;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
