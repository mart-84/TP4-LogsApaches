#include <list>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

#include "AnalyseurLogs.h"


int main(int argc, char** argv)
{
    //utypedef list<pair<string, list<pair<string &, int>>>> Graph;

    ifstream fichier("test.log");
    AnalyseurLogs anal(fichier);
    anal.LireFichier();
    auto logs = anal.GetLogs();
    for (auto const &log : logs)
    {
        cout << log << endl;
    }
}