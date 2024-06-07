#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Je fais des tests pour apprendre le C++ !" << endl;
	int cestpasinteressant(16);
	double pi(3.1415);
	bool lee(true);
	char letter('c');
	string jadorelesaucisson("bonsoir"), vivelecamembert("c'est non");

	string& oui(jadorelesaucisson);
	cout << "J'aime pas le CPP" << endl;
	cout << cestpasinteressant << endl << pi << endl << lee << endl;
	cout << letter << endl;
	cout << jadorelesaucisson << vivelecamembert << endl;
	cout << oui << endl;
	return 0;
}