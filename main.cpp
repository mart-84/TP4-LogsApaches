#include <iostream>
#include <fstream>
using namespace std;

#include "VerificateurCommande.h"
#include "Controleur.h"

int main(int argc, const char **argv)
{
    VerificateurCommande commande(argc, argv);
    if (commande)
    {
        Controleur controleur(commande);
        controleur.Demarrer();
        return 0;
    }
    return 1;
}
