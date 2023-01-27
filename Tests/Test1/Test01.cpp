using namespace std;
#include <fstream>
#include <iostream>
#include "../../LigneLog.h"
#include "../../AnalyseurLogs.h"

int main() {
    ifstream fichier("test.log");
    AnalyseurLogs anal(fichier);
    anal.LireFichier();
    auto logs = anal.GetLogs();
    for (auto const &log : logs)
    {
        cout << log << endl;
    }
}