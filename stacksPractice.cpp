#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "linkedlist.h"
using namespace std;

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
        output << word << endl;
    }

}