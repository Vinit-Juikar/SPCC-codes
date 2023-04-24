#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Quadruple {
 string op;
 string arg1;
 string arg2;
 string result;
};
int main()
{
 vector<Quadruple> quadruples = {
 {"+", "a", "b", "t1"},
 {"*", "t1", "c", "t2"},
 {"-", "t2", "d", "e"},
 {"/", "e", "f", "g"}
 };
 // display the quadruples
 cout << "Quadruples in Three Address Code:" << endl;
 for (int i = 0; i < quadruples.size(); i++) {
 cout << i << ": " << quadruples[i].op << " ";
 if (quadruples[i].arg1 != "") {
 cout << quadruples[i].arg1 << " ";
 }
 if (quadruples[i].arg2 != "") {
 cout << quadruples[i].arg2 << " ";
 }
 cout << quadruples[i].result << endl;
 }
 return 0;
}
