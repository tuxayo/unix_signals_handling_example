#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

void fonctionTraitementSignaux(int numeroSignal) {
	cout << "Signal " << numeroSignal << " reçu" << endl;
	sleep(5); // let some time to test SIGUSR1's sending.
	cout << "Traitement signal fini" << endl;
}

int main(int argc, char * argv[]) {
	// We create the sigaction which will store the action's information to do when receving a signal.
	// We create too an OldAction if we want to store the previous sigaction linked to a signal.
	struct sigaction ActionEnCasDeSignal/*, OldAction */;

	// SIGQUIT:
	ActionEnCasDeSignal.sa_handler = SIG_IGN; // ignore the signal
	// Link our action with SIGQUIT signal
	sigaction(SIGQUIT, &ActionEnCasDeSignal, NULL/* &OldAction */);

	// SIGTERM : If we carelessy take the same sigaction (ActionEnCasDeSignal), there will be problems
	// with the previous parameters. This time, we link a function to the signal reception.
	ActionEnCasDeSignal.sa_handler = fonctionTraitementSignaux;
	// Clears the blocked signals list during the SIGTERM signal processing (there are some by default that
	// we don't want).
	sigemptyset(&ActionEnCasDeSignal.sa_mask);
	// Add SIGUSR1 to the blocked signals list to have only it.
	sigaddset(&ActionEnCasDeSignal.sa_mask, SIGUSR1);
	// Link our action with SIGTERM
	sigaction(SIGTERM, &ActionEnCasDeSignal, NULL/* &OldAction */);

	while (true) {
	} // Active (thus bad, wrong and as horrible as a while(42)) signal waiting.

	return 0;
}  //  main()
