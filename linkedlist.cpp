#include <assert.h>
#include <vector>
#include <iostream>

template <class T>
class List{
public:
    //constructor
    List(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    //methods
    void push_back(T value);
    void push_front(T value);
    T pop_back();
    T pop_front();
    bool empty();
    int getsize() const;
    void printlist();

private:
    struct Node{
        Node *previous;
        Node *next;
        T value;

        //constructor
        Node(T val):value(val){}
    };

    Node *head;
    Node *tail;
    int size;
};

template <class T> void List<T>::printlist(){
        if(head == nullptr)
            std::cout << "List Empty!" << std::endl;

        Node *temp;
        temp = head;
        while(temp != tail){
            std::cout << temp->value << "<-->";
            temp = temp->next;
        }
        std::cout << temp->value << std::endl;
}


template <class T> bool List<T>::empty(){
    if(head == nullptr)
        return true;
    return false;
}

template <class T> int List<T>::getsize() const {return size;}

template <class T> void List<T>::push_front(T value){
    std::cout <<"Pushing at the front of the list..." << std::endl;
    //create new node
    Node *temp;
    temp = new Node(value);

    if(!List::empty()){  //case 1: when the list is not empty

        //see what head is pointing to
        temp->next = head;
        head->previous = temp;
        //update the head
        head = head->previous;
        head->previous = nullptr;
    } else {            //case1: when the list is empty
        head = temp;
        temp->previous = nullptr;
        temp->next = nullptr;
        tail = head;

    }
    size += 1;
}

template <class T> void List<T>::push_back(T value){
    std::cout <<"Pusing at the back of the list ..." << std::endl;
    //create new node
    Node *temp;
    temp = new Node(value);

    if(!List::empty()){  //case 1: when the list is not empty

        //see what tail is pointing to
        tail->next = temp;
        temp->previous = tail;
        temp->next = nullptr;
        //update tail
        tail = tail->next;
    } else {            //case1: when the list is empty
        head = temp;
        temp->previous = nullptr;
        temp->next = nullptr;
        tail = head;

    }
    size += 1;
}

template <class T> T List<T>::pop_back(){
    std::cout <<"Popping the back/last element..." << std::endl;
    //get the value to return
    T val = tail->value;

    //need a new pointer to hold the last node so
    //that it can be deleted
    Node *temp;
    temp = tail;

    //case 1: only a single node in the list
    if(tail == head){
        tail = nullptr;
        head = nullptr;
    }else{
        //update tail to point to pen-ultimate node
        tail = tail->previous;
        tail->next = nullptr;
    }
    delete temp;
    size = size -1;
    return val;
}

template <class T> T List<T>::pop_front(){
    std::cout <<"Popping the front element..." << std::endl;
    //get the value to return
    T val = head->value;

    //need a new pointer to hold the last node so
    //that it can be deleted
    Node *temp;
    temp = head;

    //case 1: only a single node in the list
    if(tail == head){
        tail = nullptr;
        head = nullptr;
    }else{
        //update tail to point to pen-ultimate node
        head = head->next;
        head->previous = nullptr;
    }
    delete temp;
    size = size -1;
    return val;
}

int main(){
    List<int> list1;
    std::cout << "Initial list size =" << list1.getsize() << std::endl;
    std::cout << "Pushing elements into the list:" << std::endl;
    list1.push_front(3);
    list1.push_back(5);
    list1.push_front(6);
    list1.push_back(7);
    list1.printlist();
    std::cout << "List size = "<< list1.getsize() << std::endl;

    std::cout <<list1.pop_back() <<std::endl;
    std::cout << list1.pop_back() <<std::endl;
    list1.printlist();
    std::cout << "Size = " << list1.getsize() << std::endl;
    std::cout << "Popfront: " <<list1.pop_front() << std::endl;
    std::cout << "Size = "<< list1.getsize( ) << std::endl;
    list1.printlist();
    // List<double> list2;
    // list1.push_back();
    // list1.push_front();
    // list1.pop_front();
    // list1.pop_back();

    return 0;
}
