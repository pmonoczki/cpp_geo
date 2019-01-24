#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define M 100

class evoeszkozok {
  private:
   int anyaga; //anyaga
   int ara; //ara
   double suly;
  public:
  evoeszkozok( void ){ anyaga = 0; ara = 0; suly = 0.0; } //konstruktor
  void set_suly( double a ){ suly = a; }
  void set_ara( int a ){ ara = a; }
  void set_anyaga( int a ){ anyaga = a; }
  double get_suly( void ){ return suly; }
  int get_ara( void ){ return ara; }
  int get_anyaga( void ){ return anyaga; }
};

class kanal : public evoeszkozok{
  private:
    int meret; //meret
  public:
  kanal( void ) : evoeszkozok(){ meret = 0; }
  void set_meret( int a ){ meret = a; }
  int get_meret( void ){ return meret; }
};

class kes : public evoeszkozok{
  private:
   int re; //recezett elu e
   int ocs;//osszecsukhato
  public:
  kes( void ) : evoeszkozok() { re = 0; ocs=0; }
  void set_re( int a ){ re = a; }
  void set_ocs( int a ){ ocs = a; }
  int get_ocs( void ){ return ocs; }
  int get_re( void ){ return re; }
};

void main( void )
{
 kanal kat[ M ];
 kes ket[ M ];
 int i,szam;
 //feltoltes
 randomize();
 for( i = 0; i < M; i++ )
    {
     kat[i].set_suly( (double)( (rand() % 10) / 10.0  ) + 0.5 );
     kat[i].set_ara( rand() % 1000 + 100 );
     //1: szenacel 2: kromacel 3: ezust 4:arany
     kat[i].set_anyaga( rand() % 4 +1 );
     // 1:kaves 2:mokkas 3:evo 4:mero
     kat[i].set_meret( rand() % 4 + 1 );

     ket[i].set_suly( (double)( (rand() % 10) / 10.0 ) + 0.5 );
     ket[i].set_ara( rand() % 1000 + 100 );
     ket[i].set_anyaga( ( rand() % 4) + 1 );
     ket[i].set_re( rand() % 2 );
     ket[i].set_ocs( rand() % 2 );
    }
 //osszecsukhato kromacel kesek adatai
 for( i=0; i < M; i++ )
 {
  clrscr();
  if (( ket[i].get_ocs() == 1 ) && ( ket[i].get_anyaga() == 2 ))
     {
      cout << "\n\tOsszecsukhato, kromacel kesek adatai: \n";
      cout << "\n\t\tAnyaga : kromacel" ;
      cout << "\n\t\tOsszecsukhato : igen";
      cout << "\n\t\tSulya: " << ket[i].get_suly();
      cout << "\n\t\tAra: " << ket[i].get_ara();
      cout << "\n\t\tRecezett elu: " ;
      if ( ket[i].get_re() == 1 )
	 cout << "igen";
      else cout << "nem";
      cout << "\n\n\t\tTovabb: space";
      getch();
    }
 }
 double sum=0.0;
 szam = 0;
 for( i=0; i<M; i++ )
    if ( kat[i].get_meret() == 1 )
       {
	sum+=kat[i].get_suly() ;
	szam++;
       }
 clrscr();
 cout << "\n\tA a kesek atlagos sulya: " << sum/szam;
 cout << "\n\n\t\tKilepes: SPACE";
 getch();
}

