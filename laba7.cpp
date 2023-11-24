#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

class LinkedList {
public:
    LinkedList();
    LinkedList(int data);
    LinkedList(std::vector<int> data);
    bool add_element(int data);
    int delete_element(int data);
    bool find_element(int data);
    bool find_pos(int pos);
    bool insert_list(int data, int pos);
    void print_list();
    void sort_list();
    ~LinkedList();

private:
    Node* first;
    Node* last;
};

LinkedList::LinkedList() {
    first = nullptr;
    last = nullptr;
}

LinkedList::LinkedList(int data) {
    Node* nd = new Node{ data, nullptr, nullptr };
    first = nd;
    last = nd;
    last->next = nullptr;
}

LinkedList::LinkedList(std::vector<int> data) {
    first = nullptr;
    last = nullptr;
    for (int element : data) {
        add_element(element);
    }
}

bool LinkedList::add_element(int data) {
    Node* newNode = new Node{ data, nullptr, nullptr };
    if (first == nullptr) {
        first = newNode;
        last = newNode;
    }
    else {
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
    newNode->next = nullptr;
    return true;
}

int LinkedList::delete_element(int data) {
    if (first == nullptr) {
        return -1;
    }
    Node* current = first;
    Node* previous = nullptr;
    while (current != nullptr) {
        if (current->data == data) {
            if (current == first) {
                Node* temp = first;
                first = first->next;
                delete temp;
            }
            else if (current == last) {
                Node* temp = last;
                last = previous;
                last->next = nullptr;
                delete temp;
            }
            else {
                Node* temp = current;
                previous->next = current->next;
                delete temp;
            }
            return current->data;
        }
        previous = current;
        current = current->next;
    }
    return -1;
}

bool LinkedList::find_element(int data) {
    if (first == nullptr) {
        return 0;
    }
    Node* current = first;
    while (current != nullptr) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

bool LinkedList::find_pos(int pos) {
    Node* current = first;
    int counter = 0;
    while (current != nullptr) {
        ++counter;
        if (counter == pos) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

bool LinkedList::insert_list(int data, int pos) {
    if (!this->find_pos(pos)) {
        return false;
    }
    Node* nd = new Node{ data, nullptr, nullptr };
    if (pos == 1) {
        nd->next = first;
        first = nd;
    }
    else {
        Node* current = first;
        for (int i = 1; i < pos - 1; ++i) {
            current = current->next;
        }
        nd->next = current->next;
        nd->prev = current;
        current->next = nd;
    }
    return true;
}

void LinkedList::print_list() {
    if (first == nullptr) {
        return;
    }
    Node* current = first;
    while (current != nullptr) {
        std::cout << current->data << " ";
       current = current->next;
   }
   std::cout << std::endl;
}

void LinkedList::sort_list() {
    Node* nd = new Node;  
    Node* left = first;
    Node* right = first->next;
    while (left->next) {                 
        while (right) {             
            if ((left->data) > (right->data)) {       
                nd->data = left->data;              
                left->data = right->data;            
                right->data = nd->data;             
            }
            right = right->next;                    
        }
        left = left->next;                              
        right = left->next;                            
    }
    return;
}

LinkedList::~LinkedList() {
    Node* current = first;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
int main() {

    LinkedList lst; //Объявляем переменную, тип которой есть список
    lst.add_element(1); //Добавляем в список элементы
    lst.add_element(5);
    lst.add_element(7);
    lst.add_element(0);
    lst.add_element(9);
    lst.print_list();
    cout << endl;
    lst.sort_list();

    lst.print_list(); //Отображаем список на экране
    return 0;
}