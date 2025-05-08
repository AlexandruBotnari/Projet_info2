#include <stdio.h>
#include "combattant.h"
#include "equipe.h"
#include "technique.h"
#include "combat.h"
#include "environnement.h"
#include <time.h>

int main() {
	Equipe e1=creer_equipe();
	afficher_equipe(e1);
	Equipe e2=creer_equipe();
	afficher_equipe(e2);
	

	return 0;
}
	
