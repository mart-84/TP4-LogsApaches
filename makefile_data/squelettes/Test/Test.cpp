using namespace std;
#include <iostream>

// --------------------------------------------------------------------------------
// Description
// --------------------------------------------------------------------------------


// Description : 
// Resultat attendu : 
void test1()
{
}

// Description : 
// Resultat attendu : 
void test2()
{
}

void betweenTest()
{
    cerr << endl
         << "------------------------------" << endl
         << endl;
    cout << endl
         << "------------------------------" << endl
         << endl;
}

int main()
{
    auto tests = {test1, test2};
    for (auto &test : tests)
    {
        test();
        betweenTest();
    }
}