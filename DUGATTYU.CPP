#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <stdio.h>

double pi=3.14159265;

void main()
{
double i=0,pi30=pi/30,r;
double x2,y2,x20,deltax,deltay;
int gd,gm,d,xc,yc;

detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\Borlandc\\BGI");
xc=getmaxx()/2;
yc=getmaxy()/2;
r=(xc+yc)/4;
d=(xc+yc)/58;
x20=xc+(r-20*d)*cos((-1)*pi30);
do
{
 i=i-1;
 x2=xc+(r-20*d)*cos(i*pi30);
 y2=yc+(r-20*d)*sin(i*pi30);
 deltax=abs(x2-x20);
 deltay=sqrt(10000-(deltax*deltax));
 line(xc,y2-deltay,x2,y2);
 rectangle(xc+30,y2-deltay,xc-30,y2-deltay-60);
 circle(xc,yc,40);
// line(xc,yc,x2,y2);

 delay(100);
 clrscr();
}while(!kbhit());
getch();
closegraph();
}
