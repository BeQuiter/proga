#include <iostream>

using namespace std;

template<class T>
struct Node {
    int id = 0;
    int accessCount = 0;
    T data;
    Node* next, * prev;
};


template<class T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
    int id_counter;
public:
    List() {
        head = tail = nullptr;
        count = 0;
        id_counter = 0;
    }
    //===============================================================================================
    List(List& L) {
        head = tail = nullptr;
        count = 0;
        id_counter = 0;

        Node<T>* temp = L.head;
        while (temp != 0)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    //===============================================================================================
    ~List() {
        Node<T>* temp = head;
        Node<T>* current = head;
        while (count != 0) {
            current = temp;
            temp = temp->next;
            delete current;
        }
    }
    //===============================================================================================
    void push_back(T _data) {
        Node<T>* temp = new Node<T>;

        temp->next = nullptr;
        temp->prev = nullptr;
        temp->data = _data;
        temp->id = id_counter;
        temp->accessCount = 0;

        if (tail != nullptr) {
            tail->next = temp;
        }

        if (count == 0) {
            head = tail = temp;
        }
        else {
            temp->prev = tail;
            tail = temp;
        }

        count++;
        id_counter++;
    }
    //===============================================================================================
    void PrintByID(int _id) {
        Node<T>* temp = head;
        while (temp->id != _id) {
            temp = temp->next;
        }

        temp->accessCount++;
        cout << temp->id << ' ' << temp->accessCount << ' ' << temp->data << endl;
        Sort();
    }
    //===============================================================================================
    void Print() {
        Node<T>* temp = head;
        cout << temp->id << ' ' << temp->accessCount << ' ' << temp->data << endl;
        while (temp->next != nullptr) {
            temp = temp->next;
            cout << temp->id << ' ' << temp->accessCount << ' ' << temp->data << endl;
        };
    }
    //===============================================================================================
    void Sort() {

        for (Node<T>* i = head; i; i = i->next) {
            for (Node<T>* j = head; j; j = j->next) {
                if (i->accessCount > j->accessCount) {

                    Node<T>* temp = nullptr;
                    //                    cout << i->id << ' ' << temp->id << endl;
                    int tempId = i->id;
                    //                    cout << i->id << ' ' << temp->id << endl;
                    int tempAccessCount = i->accessCount;
                    T tempData = i->data;

                    i->id = j->id;
                    i->accessCount = j->accessCount;
                    i->data = j->data;

                    j->id = tempId;
                    j->accessCount = tempAccessCount;
                    j->data = tempData;
                }
            }
        }
    }
    //===============================================================================================
};


int main()
{
    List<int> a;
    a.push_back(5);
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.Print();
    a.Print();
    cout << endl;
    a.PrintByID(3);
    cout << endl;
    a.PrintByID(3);
    cout << endl;
    a.PrintByID(1);
    cout << endl;

    //    a.Print();
    a.Print();
    return 0;
}