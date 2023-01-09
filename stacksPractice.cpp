#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include "linkedlist.h"
using namespace std;

class Pair{
    public:
        string in_str;
        string fixed_str;
        int k;
};

//Functions written using Stacks
LinkedList languange(string input_str, unsigned int k)
{
    //This set is to insure that there is only one unique letter per languange
    set<char> alphabet; //intialize a set container of chars
    for (char c : input_str) //for char in input_str
    {
        if (alphabet.count(c) <= 0) //if char is not in set already
            alphabet.insert(c); //insert char into the list
    }

    //vector is used to store alphabet set
    vector<char> alpha;
    for (char c: alphabet)
        alpha.push_back(c); //store into vector

    LinkedList final_output; //intialize an empty LinkedList
    stack<class Pair> s; //intialize an empty stack
    Pair initial, stacktop; //two pair to help initiate the stack
    initial.in_str = ""; //start with the empty string
    initial.k = 0; //start with repetitions = 0
    s.push(initial); // push "initial" pair onto the stack

    while(!s.empty())
    {
        stacktop = s.top(); //get pair on top

        if (stacktop.k == 0){ //Base Case 1: if repetitions(k) reaches 0/ensures empty string is included
            final_output.insert(stacktop.in_str); //store strings into list
        }
        
        if (stacktop.k >= alpha.size() || stacktop.in_str.size() >= k){ //Base Case 2: when repetition limit is met
            s.pop(); //pop top from stack
        }

        //now, time for recursive process
        else
        {
            s.top().k++; //increment the repetition of element on top of stack
            Pair to_push; //get new pair ready for recursive call
            to_push.in_str = stacktop.in_str + alpha[stacktop.k]; //append next char in input_str to stacktop.in_str
            to_push.k = 0; //set repetition of new string = 0;
            s.push(to_push); //push new pair into the stack
        }
    }
    return final_output;
}

//function that returns bubbly stirng using Stacks
LinkedList bubblingStack(string input_str)
{
    LinkedList final_output; //create empty list
    stack <class Pair> s; //create empty stack
    Pair initial, stacktop; //create "initial" object that will push onto stack
    initial.in_str = input_str;
    initial.k = 0; //this will keep track of the index of input string
    s.push(initial); //push this onto the stack

    while(!s.empty())
    {
        stacktop = s.top(); //get top of stack and store in stacktop
        s.pop(); //remove it from the stack

        if (stacktop.k >= input_str.length() - 1) //Base Case: if index reaches end of string
        {
            final_output.insert(stacktop.in_str); //insert string into list
            continue;
        }

        Pair to_push; //get new pair ready for recursive call
        to_push.in_str = stacktop.in_str;
        to_push.k = stacktop.k + 1; //increment index by one
        s.push(to_push); //make recursive call without swap

        swap(stacktop.in_str[stacktop.k], stacktop.in_str[stacktop.k + 1]); //swap input string at index k and k+1;
        to_push.in_str = stacktop.in_str; //place swapped string into to_push
        s.push(to_push); //make recursive call with swapped string
     }
     return final_output;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        throw std::invalid_argument("Usage: ./hello <INPUT.TXT> <OUTPUT.TXT>"); //throw an error
    }

    ifstream input; //stream for input
    ofstream output; //stream for output
    string word; //stores next substring in input file

    input.open(argv[1]); //open input file
    output.open(argv[2]); //open output file

    while(getline(input, word))
    {
        if (word.length() == 0) {continue;} //if command is empty, next line
        
         //LinkedList myList = languange(word,2); //create an instance of LinkedList
         LinkedList myList = bubblingStack(word);
         output << myList.print() << endl;
    }
    input.close();
    output.close();
}

//Functions written recursively

//Recursive Function for Bubbling()
/*LinkedList bubblingRecursive(string input_str, int index, LinkedList* list_ptr)
{
    LinkedList *final_output = new LinkedList(); // create a new LinkedList
    bubblingRecursive(input_str, 0, final_output);
    return final_output;
}*/