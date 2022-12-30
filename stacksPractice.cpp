#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        throw std::invalid_argument("Usage: ./hello <INPUT.TXT> <OUTPUT.TXT>"); //throw an error
    }

    ifstream input;
    ofstream output;

    input.open(argv[1]);
    output.open(argv[2]);
}