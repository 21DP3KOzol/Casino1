#include<iostream>
#include<conio.h>1
#include <windows.h>
#include <time.h>
// Vienkārša kazino spēle azarta mīlētājiem
// Veidoja Kristiāns Ozoliņš DP2-3
using namespace std;

void noteikumi() {
    system("cls");
    cout << endl << endl;
    cout << " ============================================================================" << endl;
    cout << "                        Kazino spēles noteikumi" << endl;
    cout << " ============================================================================" << endl;
    cout << " 1. Izvēlaties ciparu no 1 līdz 9" << endl;
    cout << " 2. Ja uzminēsiet jūs varat trīskāršot savu naudu ;)" << endl;
    cout << " 3. Ja uzliksiet uz nepareizo ciparu pazaudēsiet savu naudas likmi " << endl;
    cout << " ============================================================================" << endl;
    cout << "Nospiediet jebkādu pogu , lai sāktu";
    getch();
}

void spelet() {
    system("cls");
    noteikumi();
    system("cls");

    string vards;
    int visanauda;
    int likme;
    int minejums;
    int kaulins;
    char option;

    srand(time(0));

    cout << " =====================================" << endl;
    cout << "|       Las Vegasas kazino spēle     |" << endl;
    cout << " =====================================" << endl << endl;

    cout << "Ievadiet savu vārdu : ";
    getline(cin, vards);

    cout << endl << endl;
    cout << "Kāds būs jūsu naudas depozīts? : $";
    cin >> visanauda;

    do {
        system("cls");

	    cout << " =====================================" << endl;
	    cout << "|        Las Vegasas kazino spēle    |" << endl;
	    cout << " =====================================" << endl << endl<<endl;

		cout << "\nPašreizējais atlikums ir $ " << visanauda << endl;

        do {
            cout << vards << ", Ievadiet summu uz kuru spēlējat : $";
            cin >> likme;
            if (likme > visanauda)
                cout << "Summa kuru liekat pārsniedz pašreizējo atlikumu" << endl << "Ievadiet vēlreiz" << endl;



        } while (likme > visanauda);

        do {
            cout << "Miniet ciparu no 1 līdz 9 :";
            cin >> minejums;
            if (minejums < 1 || minejums > 9)
                cout << "Ciparam jābut no 1 līdz 9!" << endl << "Ievadiet vēlreiz " << endl;

        } while (minejums < 1 || minejums > 9);

        kaulins = rand() % 9 + 1;

        if (kaulins != minejums) {
            visanauda -= likme;
            cout << endl << endl << "Jūs zaudējāt $ " << likme << endl;
        } else {
            visanauda += (likme * 3);
            cout << endl << endl << "Apsveicam!! Jūs uzvarējāt ." << likme * 3;
        }

        cout << "\nLaimīgais cipars bija : " << kaulins << endl;
        cout << "\n" << vards << ", Jums ir $ " << visanauda << endl;
        if (visanauda == 0) {
            cout << "Jums nav naudas ar ko spēlēt ";
            break;
        }
        cout << endl << endl << " Gribat spēlēt vēlreiz? (y/n)? ";
        cin >> option;
    } while (option == 'Y' || option == 'y');

    cout << " ----------------------------------------------------------------------------" << endl;
    cout << " Paldies par spēli. Jūsu pašreizējā naudas summa ir $ " << visanauda << endl;
    cout << " ----------------------------------------------------------------------------" << endl;
    getch();
}

int main() {
    srand((unsigned) time(NULL));

    do {
        system("cls");
        cout << " =====================================" << endl;
    	cout << "|       Las Vegasas kazino spēle     |" << endl;
    	cout << " =====================================" << endl << endl;
        cout << "1. Sākt spēli" << endl;
        cout << "2. Noteikumi" << endl;
        cout << "3. Iziet" << endl;
        cout << "Izvēlaties opciju: ";
        char op = getche();

        if (op == '1') spelet();
        else if (op == '2') noteikumi();
        else if (op == '3') exit(0);

    } while (1);

    return 0;
}
