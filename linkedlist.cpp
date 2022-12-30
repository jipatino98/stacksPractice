#include <iostream>
#include <string>
#include <algorithm>
#include "linkedlist.h"
using namespace std;

//Default Constructor sets head to NULL
LinkedList :: LinkedList()
{
    head = NULL;
}

//Insert Function
//Input: inserts string into the list
//Output: returns void, just inserts the new Node
void LinkedList :: insert(string word)
{
    Node* new_node = new Node; //creates New Node
    new_node->data = word; //stores word
    new_node->next = head; //store the next address
    head = new_node; //make new Node the head
}

string LinkedList :: print()
{
    string list_str = ""; //string that has list in order
    Node* start = head; //start at head of List
    while (start->next != NULL)
    {
        list_str = list_str + start->data + " "; //append string to List
        start = start->next; //proceed through list
    }
    if (list_str.length() > 0)
        list_str.pop_back(); //remove the last(extra) space from string
    
    return list_str;
}