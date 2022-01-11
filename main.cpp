#include <iostream>
using namespace std;

template <typename T>
class List {
public:
    List():_head(nullptr), _tail(nullptr), _size(0) {}
    ~List(){
        auto current = _head;
        do {
            auto tmp = _head;
            current = current->getNext();
            tmp-> ~Node();

        }while(current != _tail);
    }

    void push_front(T data){
        if(!_head){
            _head = new Node;
            _tail = _head;
            _head->setData(data);
            _head->setNext(nullptr);
            _head->setPrevious(nullptr);
            _size++;
        }else{
            auto tmp = new Node;
            tmp->setData(data);
            tmp->setNext(_head);
            tmp->setPrevious(nullptr);
            _head = tmp;
            _size++;
        }
    }

    void pop_back(){
        Node* tmp = _tail;
        _tail->setData(0);
        _tail = tmp;
        _size--;
    }

    void reverse(){
        for(int i=0; i<_size; i++){
            push_front(at(i));
            i++;
        }
        for(int i=0; i<_size; i++){
            pop_back();
        }
    }

    void push_back(T data){
        if(!_tail){
            _head = new Node;
            _tail = _head;
            _head->setData(data);
            _head->setNext(nullptr);
            _head->getPrevious(nullptr);
            _size++;
        }else{
            auto tmp = new Node;
            auto tmp1 = new Node;
            tmp->setData(data);
            tmp->setNext(nullptr);
            tmp1->setData(_tail->getData());
            _tail->setNext(tmp);
            _tail = tmp;
            _tail->getPrevious(tmp1);
            _size++;
        }
    }

    T& at(int index){
        Node* current = _head;
        for(size_t i=0; i<index; i++){
            current = current->getNext();
        }
        return current->getData();
    }

    int getSize(){
        return _size;
    }

private:
    class Node{
    public:
        T & getData(){
            return _data;
        }

        const T& getData()const {
            return _data;
        }

        void setData(T newData){
            _data = newData;
        }

        void setNext(Node* next){
            _next = next;
        }

        Node* getNext(){
            return _next;
        }

        const Node* getNext()const {
            return  _next;
        }

        void setPrevious(Node* previous){
            _previous = previous;
        }

        Node* getPrevious(){
            return _previous;
        }

        const Node* getPrevious()const {
            return _previous;
        }

    private:
        T _data;
        Node* _next;
        Node* _previous;
    };
    Node* _head;
    Node* _tail;
    int _size;

};

int main(int argc, const char * argv[]) {
    List<double> q;

    q.push_front(1.3);
    q.push_front(2.5);
    q.push_front(3.8);
    q.push_front(4.7);
    q.push_front(5.9);

    for(int i=0; i<q.getSize(); i++) {
        cout << q.at(i) << " ";
    }
    cout << endl;
    q.reverse();
    for(int i=0; i<q.getSize(); i++) {
        cout << q.at(i) << " ";
    }
    cout << endl;
    q.reverse();
    for(int i=0; i<q.getSize(); i++) {
        cout << q.at(i) << " ";
    }
    cout << endl;
    q.reverse();
    for(int i=0; i<q.getSize(); i++) {
        cout << q.at(i) << " ";
    }
    return 0;
}
