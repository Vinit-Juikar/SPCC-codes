//display tripes in 3 addr codes

#include <iostream>
#include <vector>
using namespace std;
struct Triple
{
    string op;
    string arg1;
    string arg2;
};
void display_tac(vector<Triple> triples)
{
    for (int i = 0; i < triples.size(); i++)
    {
        cout << i + 1 << ". ";
        cout << triples[i].op << " ";
        cout << triples[i].arg1 << " ";
        cout << triples[i].arg2 << endl;
    }
}
int main()
{
    vector<Triple> triples = {{"+", "a", "b"}, {"=", "c", "1"}, {"*", "d", "e"}};
    display_tac(triples);
    return 0;
}
