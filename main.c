#include <stdio.h>
#include "combattant.h"
#include "equipe.h"

int main() {
	Equipe e1=creer_equipe();
	afficher_equipe(e1);
	Equipe e2=creer_equipe();
	afficher_equipe(e2);
	

	return 0;
}
	
