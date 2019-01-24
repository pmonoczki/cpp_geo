#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#define M 100

class proci {
  private:
   int mfrek; //mukodesi frekvencia
   int ara; //ara
   int lszam; //labak szama
  public:
  proci( void ){ mfrek = 0; ara = 0; lszam = 0; } //konstruktor
  void set_lszam( int a ){ lszam = a; }
  void set_ara( int a ){ ara = a; }
  void set_mfrek( int a ){ mfrek = a; }
  int get_lszam( void ){ return lszam; }
  int get_ara( void ){ return ara; }
  int get_mfrek( void ){ return mfrek; }
};

class risc : public proci{
  private:
    int vsz; //vektormuveletek szama
  public:
  risc( void ) : proci(){ vsz = 0; }
  void set_vsz( int a ){ vsz = a; }
  int get_vsz( void ){ return vsz; }
};

class cisc : public proci{
  private:
   int hmv; //3D van - e
   int stsz;//stringmuveletek
  public:
  cisc( void ) : proci() { hmv = 0; stsz=0; }
  void set_hmv( int a ){ hmv = a; }
  void set_stsz( int a ){ stsz = a; }
  int get_hmv( void ){ return hmv; }
  int get_stsz( void ){ return stsz; }
};

void main( void )
{
 risc rt[ M ];
 cisc ct[ M ];
 int i;
 //feltoltes
 randomize();
 for( i = 0; i < M; i++ )
    {
     rt[i].set_lszam( rand() % 200 + 50 );
     rt[i].set_ara( rand() % 20000 + 5000 );
     rt[i].set_mfrek( rand() % 2800 + 400 );
     rt[i].set_vsz( rand() % 200 + 50 );

     ct[i].set_lszam( rand() % 200 + 50 );
     ct[i].set_ara( rand() % 20000 + 5000 );
     ct[i].set_mfrek( rand() % 2800 + 400 );
     ct[i].set_hmv( rand() % 2 );
     ct[i].set_stsz( rand() % 50 + 5 );
    }
 //3D-s legalabb 12 stringmuveletes cisc-ek
 for( i=0; i < M; i++ )
 {
  clrscr();
  if (( ct[i].get_hmv() == 1 ) && ( ct[i].get_stsz() >= 12 ))
     {
      cout << "\n\t3D muveletes legalabb 12 stringmuveletes CISC procik: \n";
      cout << "\n\t\t3D : van" ;
      cout << "\n\t\tStringmuveletek szama : " << ct[i].get_stsz();
      cout << "\n\t\tLabak szama: " << ct[i].get_lszam();
      cout << "\n\t\tAra: " << ct[i].get_ara();
      cout << "\n\t\tMukodesi frekvenciaja: " << ct[i].get_mfrek();
      cout << "\n\n\t\tTovabb: space";
      getch();
    }
 }
 long int sum=0;
 for( i=0; i<M; i++ )
    sum+=(long int)(ct[i].get_ara() + rt[i].get_ara()) ;

 clrscr();
 cout << "\n\tA CISC es RISC processzorok osszerteke: " << sum;
 cout << "\n\n\t\tKilepes: SPACE";
 getch();
}

