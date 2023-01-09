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
        string word;
        string fixed_str;
        int k;
};

//Function that returns the anagrams of an input string using Stacks
LinkedList allAnagramsStack(string input_str)
{
    LinkedList final_output; //create empty list
    stack<class Pair> s; //create empty stack that holds class Pair members (inputStr, fixedStr)
    Pair initial, stacktop; //create two pair objects, one that starts the stack and one that will store top element
    initial.word = input_str;
    initial.fixed_str = "";
    s.push(initial); //push (input_str , "") onto the stack

    while(!s.empty()) //while stack is not empty
    {
        stacktop = s.top(); //get the top of stack and store into stacktop
        s.pop(); //remove stacktop from the top of stack
        if (stacktop.word.length() == 0) //once word is empty
        {
            final_output.insert(stacktop.fixed_str); //insert fixed_str into the list
            continue; //and continue
        }

        for(unsigned int i = 0; i < stacktop.word.length(); i++) //iterate through each character of the input string
        {
            char fixed_character = stacktop.word[i]; //for each iteration, save the fixed character to append later
            string leftSubstring = stacktop.word.substr(0,i); //store characters left of fixed char
            string rightSubstring = stacktop.word.substr(i+1); //store characters right of fixed char
            string combinedStr = leftSubstring + rightSubstring; //combine substrings together

            Pair to_push; //now, get new pair ready for recursive call
            to_push.word = combinedStr; //assign the combined string into 
            to_push.fixed_str = stacktop.fixed_str + fixed_character; //append fixed character to combined string 
            s.push(to_push); //to_push's pair should look like {combinedStr, fixed_str + fixed_character}
        }

    }
    return final_output;
} 

LinkedList stretch(string input_str, int k)
{
    LinkedList final_output; //generate empty list
    stack <class Pair> s; // create empty stack that performs the recursion
    Pair initial, stacktop; //create pairs to help intialize the stack
    initial.word = ""; //initial string is empty
    initial.k = 0; //initial k value
    s.push(initial); //push this pair into the stack

    while(!s.empty())
    {
        stacktop = s.top(); //get the top of stack and store into stacktop
        s.pop(); //remove stacktop from the top of stack

        if (stacktop.k >= input_str.length()) //Base Case: once we reach the end of input_str
            final_output.insert(stacktop.word);

        else
        {
            Pair to_push; //get new pair ready for recursive call
            to_push.word = stacktop.word; //store string of top into to_push
            for (int i = 1; i <= k; i++) //itierate for number of duplication
            {
                to_push.word += input_str[stacktop.k]; //append extra character to string
                to_push.k = stacktop.k + 1; //increment k
                s.push(to_push); //push onto the stack
            }
        }
    }
    return final_output;
}

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
    initial.word = ""; //start with the empty string
    initial.k = 0; //start with repetitions = 0
    s.push(initial); // push "initial" pair onto the stack

    while(!s.empty())
    {
        stacktop = s.top(); //get pair on top

        if (stacktop.k == 0){ //Base Case 1: if repetitions(k) reaches 0/ensures empty string is included
            final_output.insert(stacktop.word); //store strings into list
        }
        
        if (stacktop.k >= alpha.size() || stacktop.word.size() >= k){ //Base Case 2: when repetition limit is met
            s.pop(); //pop top from stack
        }

        //now, time for recursive process
        else
        {
            s.top().k++; //increment the repetition of element on top of stack
            Pair to_push; //get new pair ready for recursive call
            to_push.word = stacktop.word + alpha[stacktop.k]; //append next char in input_str to stacktop.word
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
    initial.word = input_str;
    initial.k = 0; //this will keep track of the index of input string
    s.push(initial); //push this onto the stack

    while(!s.empty())
    {
        stacktop = s.top(); //get top of stack and store in stacktop
        s.pop(); //remove it from the stack

        if (stacktop.k >= input_str.length() - 1) //Base Case: if index reaches end of string
        {
            final_output.insert(stacktop.word); //insert string into list
            continue;
        }

        Pair to_push; //get new pair ready for recursive call
        to_push.word = stacktop.word;
        to_push.k = stacktop.k + 1; //increment index by one
        s.push(to_push); //make recursive call without swap

        swap(stacktop.word[stacktop.k], stacktop.word[stacktop.k + 1]); //swap input string at index k and k+1;
        to_push.word = stacktop.word; //place swapped string into to_push
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
        
        //LinkedList myList = allSubSeqStack(word); // initializing the linked list
        //LinkedList myList = allAnagramsStack(word);
        LinkedList myList = stretch(word,2);
        //LinkedList myList = bubblingStack(word);
        //LinkedList myList = languange(word, 2);
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