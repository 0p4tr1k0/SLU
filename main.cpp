/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>
#include <string>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    char zn;
    cout << "dej znak: ";
    cin >> zn;
    
    cout << "        "<<zn << endl;
    cout << "       "<<zn<<" " << zn << endl;
    cout << "      "<<zn << " "<< zn << " "<< zn << endl;
    
    
    
    /*char zn;
    
    cout << "dej znak: ";
    cin >> zn;
    cout << zn << " " << dec << (int)zn << " " << hex << (int)zn;
    
    
    
    
    
    const float pi = 3.14159265358; // pozor , desetinna tecka , ne carka
    int mista;
    
    cout << pi << endl ;
    cout << setprecision (2) << pi << endl ; // mate nactenou knihovnu iomanip ?
    cout << setprecision (3) << pi << endl ; // pokud ne , bude zde chyba
    cout << setprecision (4) << pi << endl ;
    cout << setprecision (8) << pi << endl ;
    cout << "Kolik desetinnych mist ?" ;
    cin >> mista ;
    cout << setprecision ( mista ) << pi ;
    
    
	float cislo ;
	printf ( " Zadej racionalni cislo : " ) ;
	
	fflush ( NULL ) ;
	scanf ( " %f", & cislo ) ;
	
	int cele = cislo ; // odstranime desetinnou cast
	
	printf ("Cela cast :\t %02d, resp . %02d\n",(int) cislo, cele);
	printf ("Realna cast :\t %4.2f\n", cislo-cele );
	printf ("Zaokrouhleno :\t %4.2f", round(cislo));

	printf("Dopravni prostredek \tVlastnik \tVek\n");
	printf("auto Jeep \t\ttata \t\t4 \nauto Opel \t\tmama \t\t5 \nauto Citroen \t\tbabicka \t12 \nkolo \t\t\ttata \t\t7 \nkolo \t\t\tMartin \t\t7 \nkolo \t\t\tMartin \t\t7 \nkolo \t\t\tJana \t\t6 \nkolobezka \t\tJana \t\t8");

	printf ("Diagonala:\n             x o o \n             o x o \n             o o x ");
	char c;
	float n = 8.259035;

	printf("%f\n", n);
	printf("%2.4f\n", n);
	printf("%2.2f\n", n);

	printf("dej znak pls: ");
	char c;

	scanf("%c", &c);

	printf("znak %c je hodnota %d, a hexa %X" ,c,c,c);*/

	return 0;
}