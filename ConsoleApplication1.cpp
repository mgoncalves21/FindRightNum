#include <iostream>;
using namespace std;


const int BORNE_MIN(0);
const int BORNE_MAX(10'000);
const int BORNE_MAX_FACILE(1'000);

enum class choixMenu {
	JOUER = 'a',
	JOUER_FACILE = 'b',
	JOUER_TROIS_PARTIES = 'c',
	QUITTER = 'q',
	INCORRECT
};

choixMenu demanderChoixMenu() {
	char saisieChoix;
	cin >> saisieChoix;


	if (saisieChoix == static_cast<char> (choixMenu::JOUER) || saisieChoix == static_cast<char> (choixMenu::JOUER_FACILE)
		|| saisieChoix == static_cast<char> (choixMenu::JOUER_TROIS_PARTIES) || saisieChoix == static_cast<char> (choixMenu::QUITTER))
	{
		return  static_cast<choixMenu>(saisieChoix);
	}
	else {
		return  choixMenu::INCORRECT;

	}
}
void jouerPartie(int leJustePrix, int max, int min) {

	auto proposition(0);
	auto nombreTentative(0);


	do
	{

		cin >> proposition;
		if (proposition >= min && proposition < max)
		{
			nombreTentative++;
		}
		if (proposition == leJustePrix)
		{
			cout << "Bravo, vous avez le juste prix" << endl;

		}

		else if (proposition > leJustePrix)
		{
			cout << "Faux, Plus bas !" << endl;
			if (proposition > 10'000)
			{
				cout << "(beaucoup plus bas)" << endl;
			}
		}
		else
		{
			cout << "Plus haut" << endl;
		}


	} while (proposition != leJustePrix && proposition >= BORNE_MIN);


	cout << "Partie terminer " << " en " << nombreTentative << " tentatives " << endl;

	if (proposition == 2017 && leJustePrix == 2017)
	{
		cout << "Bravo, tu te souviens de la plus belle des dates <3 " << endl;
	}


}
void jouerTroisParties()
{
	cout << "C'est partit ! " << endl;
	for (auto aDeviner : { 21, 04, 2017 })
		jouerPartie(aDeviner, BORNE_MAX, BORNE_MIN);

}
void afficherMenu() {

	cout << "Bienvenue au juste prix" << endl;
	cout << "Tentez votre chance pour trouver le bon chiffre :" << endl;
	cout << static_cast <char> (choixMenu::JOUER) << " : jouer " << endl;
	cout << static_cast <char> (choixMenu::JOUER_FACILE) << " : jouer (facile) " << endl;
	cout << static_cast <char> (choixMenu::JOUER_TROIS_PARTIES) << " : jouer (3 parties � la suite !)" << endl;
	cout << static_cast <char> (choixMenu::QUITTER) << " : quitter " << endl;

}

int main()
{

	bool continuer{ true };

	while (continuer)

	{
		afficherMenu();
		auto choix = demanderChoixMenu();


		switch (choix)
		{
		case choixMenu::JOUER:
			jouerPartie(3000, BORNE_MIN, BORNE_MAX);
			break;



		case choixMenu::JOUER_FACILE:
			jouerPartie(250, BORNE_MIN, BORNE_MAX_FACILE);
			break;

		case choixMenu::JOUER_TROIS_PARTIES:
			jouerTroisParties();
			break;

		case choixMenu::INCORRECT:


		default:

			return EXIT_FAILURE;

		}
	}
	return EXIT_SUCCESS;

}