#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

void fonctionTraitementSignaux(int numeroSignal) {
	cout << "Signal " << numeroSignal << " reçu" << endl;
	sleep(5); // pour avoir le temps de tester d'envoyer SIGUSR1
	cout << "Traitement signal fini" << endl;
}

int main(int argc, char * argv[]) {
	//On créé la sigaction qui va contenir les infos sur quoi faire en cas de signal,
	//on fait aussi OldAction si on veux sauvegarder l'ancienne sigaction asociée à un signal
	struct sigaction ActionEnCasDeSignal/*, OldAction */;

	//SIGQUIT:
	ActionEnCasDeSignal.sa_handler = SIG_IGN; // ignore le signal
	// associe notre action avec le signal SIGQUIT
	sigaction(SIGQUIT, &ActionEnCasDeSignal, NULL/* &OldAction */);

	//SIGTERM: en gardant la même sigaction (c'est-à-dire ActionEnCasDeSignal) si on fait pas attention
	//il risque d'y avoir des problèmes à cause de paramètres restés pour les signaux précédents.
	// Cette fois on met une fonction à lancer à la reception du signal
	ActionEnCasDeSignal.sa_handler = fonctionTraitementSignaux;
	// vide la liste des signaux bloqués pendant le traitement de SIGTERM (par défaut il y en a, on en veux pas)
	sigemptyset(&ActionEnCasDeSignal.sa_mask);
	// ajout SIGUSR1 à la liste des signaux bloqués pour n'avoir que lui
	sigaddset(&ActionEnCasDeSignal.sa_mask, SIGUSR1);
	// associe notre action avec le signal SIGTERM
	sigaction(SIGTERM, &ActionEnCasDeSignal, NULL/* &OldAction */);

	while (true) {
	} // attente (active donc pas propre) de signaux

	return 0;
}  //  main()
