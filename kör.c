
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <time.h>
#include <dos.h>
#define Pi 3.14
#define T 1.0
#define SZAM 3

struct golyo{
  int r; /*sugar*/
  int x,y; /*a golyo kezdeti koordinatai*/
  double v; /*a golyo kezdeti sebessege*/
  int szog; /*a golyo kezdeti iranya fokban*/
  double alfa; /*a golyo kezdeti iranya, radianban*/
  int xr,yr; /*a golyo aktualis koordinatai*/
  int xk,yk; /*munkavaltozok*/
  int vx,vy; /*elmozdulas*/
  int szin; /*a golyo szine*/
};

void main( void )
{
 int Gd,Gm; /*graf. vezerlok*/
 struct golyo golyok[4];
 int segedx=0,segedy=0,c=0,NY,NX,segedszog,n,xm,ym,j,i;
 double seged=0.0,k,A,B,C,segedalfa,ujalfa,beta;
 double u,vni,vti,vnj,vtj,xi,yi,xj,yj;
 NY=240;
 NX=320;
 Gd=DETECT;
 randomize();
 /*init blokk*/
 golyok[0].r=10;
 golyok[1].r=20;
 golyok[2].r=30;
 golyok[3].r=NY;
 golyok[3].x=NX;
 golyok[3].y=NY;
 golyok[3].xr=golyok[3].x;
 golyok[3].yr=golyok[3].y;
 golyok[3].szin=WHITE;
 for( i=0; i<SZAM; i++ )
    {
     c=0;
     while( c==0 )
	  {
	   segedx=0; segedy=0; seged=0.0;
	   segedx=(rand() % ( NX+NY-golyok[i].r )) + 1;
	   segedy=(rand() % ( NY-golyok[i].r )) + 1;
	   /*ellenorzes, hogy a generalt pontok megfeleloek-e*/
	   k=pow((double)(segedx-NX),2.0) + pow((double)(segedy-NY),2.0);
	   seged = sqrt( k );
	   if (( seged < (NY-golyok[i].r)) && ( seged > 0 ))
	      {
	       golyok[i].x=segedx;
	       golyok[i].y=segedy;
	       c=1;
	      }
	   /*egymasra ne generalja a koroket*/
	   for(j=i; j>0; j--)
	      {
	       n=j-1;
	       seged=pow( (double)(golyok[j].x-golyok[n].x), 2.0 ) + pow( (double)(golyok[j].y-golyok[n].y), 2.0 );
	       k=sqrt( seged );
	       if ( k <= (double)(golyok[j].r+golyok[n].r))
		  c=0;
	      }
	  }
     golyok[i].v=(rand() % 10) + 6;
     golyok[i].szog=rand() % 360 + 1;
     golyok[i].alfa=Pi/180.0 * ( double )golyok[i].szog;
     golyok[i].xr=golyok[i].x;
     golyok[i].yr=golyok[i].y;
     golyok[i].xk=golyok[i].xr;
     golyok[i].yk=golyok[i].yr;
     golyok[i].vx=golyok[i].v*cos(golyok[i].alfa);
     golyok[i].vy=golyok[i].v*sin(golyok[i].alfa);
     golyok[i].szin=(rand() % 14) + 1;
    }
 initgraph( &Gd,&Gm,"" ); /*graf mod inditasa*/
 cleardevice(); /*graf kepernyo torlese*/
 while( !kbhit() )
    {
     /*kirajzolas*/
     for(i=0; i<4; i++)
	{
	 setcolor( golyok[i].szin );
	 circle( golyok[i].xr, golyok[i].yr, golyok[i].r );
	}
     /*mozgas*/
     for(i=0; i<SZAM; i++)
	{
	 golyok[i].xk=golyok[i].xr;
	 golyok[i].yk=golyok[i].yr;
	 golyok[i].xr+=golyok[i].vx*T;
	 golyok[i].yr-=golyok[i].vy*T;
	}
     /*utkozes a fallal*/
     for( i=0; i<SZAM; i++)
       {
	 A=0.0; B=0.0; C=0.0; segedszog=0; segedalfa=0.0; ujalfa=0.0;
	 C=pow( (double)(golyok[i].xr-NX), 2.0 ) + pow( (double)(golyok[i].yr-NY), 2.0 );
	 k=( pow( (double)(NY-golyok[i].r), 2.0 ) );
	 if ( C >= k )
	    {
	     B=pow( (double)(golyok[i].x-NX),2.0) + pow( (double)(golyok[i].y-NY), 2.0);
	     A=pow( (double)(golyok[i].xr-golyok[i].x), 2.0 ) + pow( (double)(golyok[i].yr-golyok[i].y), 2.0 );
	     k=sqrt(A)*sqrt(C);
	     segedalfa=(B-A-C)/(-2*k);
	     beta=acos(segedalfa);
	     ujalfa=golyok[i].alfa-2*beta+180.0;
	     if ( ujalfa==0 )
		ujalfa=90;
	     golyok[i].alfa=ujalfa;
	     segedszog=ujalfa*180.0/Pi;
	     golyok[i].szog=segedszog;
	     golyok[i].x=golyok[i].xr;
	     golyok[i].y=golyok[i].yr;
	     golyok[i].vx=golyok[i].v*cos(golyok[i].alfa);
	     golyok[i].vy=golyok[i].v*sin(golyok[i].alfa);
	    }
	}
     /*utkozes egymassal*/
     for(i=0; i<3; i++)
	{
	 if ( i!=2 )
	    j=i+1;
	 else j=0;
	 k=pow( (double)(golyok[i].xr-golyok[j].xr), 2.0 ) + pow( (double)(golyok[i].yr-golyok[j].yr), 2.0 );
	 seged=sqrt(k);
	 if ( seged <= (double)(golyok[i].r+golyok[j].r) )
	    {
	     /*utkozes kozbeni sebesseg osszetevok*/
	     vni=(golyok[i].vx*(golyok[j].xr-golyok[i].xr)+golyok[i].vy*(golyok[i].yr-golyok[j].yr))/(golyok[i].r+golyok[j].r);
	     vti=(-golyok[i].vx*(golyok[i].yr-golyok[j].yr)+golyok[i].vy*(golyok[j].xr-golyok[i].xr))/(golyok[i].r+golyok[j].r);
	     vnj=(golyok[j].vx*(golyok[j].xr-golyok[i].xr)+golyok[j].vy*(golyok[i].yr-golyok[j].yr))/(golyok[i].r+golyok[j].r);
	     vti=(-golyok[j].vx*(golyok[i].yr-golyok[j].yr)+golyok[j].vy*(golyok[j].xr-golyok[i].xr))/(golyok[i].r+golyok[j].r);
	     /*a sebessegek meroleges komp. valtozasa*/
	     u=vnj; vnj=vni; vni=u;
	     /*a norm es a tang osszetevok utk. utan*/
	     golyok[i].vx=(vni*(golyok[j].xr-golyok[i].xr)-vti*(golyok[i].yr-golyok[j].yr))/(golyok[i].r+golyok[j].r);
	     golyok[i].vy=(vni*(golyok[i].yr-golyok[j].yr)+vti*(golyok[j].xr-golyok[i].xr))/(golyok[i].r+golyok[j].r);
	     golyok[j].vx=(vnj*(golyok[j].xr-golyok[i].xr)-vtj*(golyok[i].yr-golyok[j].yr))/(golyok[i].r+golyok[j].r);
	     golyok[j].vy=(vnj*(golyok[i].yr-golyok[j].yr)+vtj*(golyok[j].xr-golyok[i].xr))/(golyok[i].r+golyok[j].r);

	     if ( golyok[i].vx<=0 )
		golyok[i].vx=8;
	     if ( golyok[j].vy<=0 )
		golyok[j].vy=6;
	    }

	}
     delay(10);
     /*gyorsitas miatt, hogy ne villogjon*/
     for(i=0; i<SZAM; i++)
	{
	 setcolor( BLACK );
	 setfillstyle(EMPTY_FILL,BLACK);
	 fillellipse( golyok[i].xk, golyok[i].yk, 1.8*golyok[i].r, 1.8*golyok[i].r );
	}
    }

 getch();
 closegraph(); /*graf mod bezarasa*/
}