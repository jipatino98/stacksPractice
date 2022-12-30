#ifndef LIST_H
#define LIST_H
#include <string>
using namespace std;

struct Node
{
    string data; //stores the string values
    Node* next; //stores the address for the next node
};

class LinkedList
{
    private:
        Node *head; //stores the head of LL
    public:
        LinkedList(); //Default constructor sets head to NULL
        void insert(string); //insert string into the list
        void deleteList(); //deletes list and clears the memory
        string print(); //prints the entire LL
};

#endif