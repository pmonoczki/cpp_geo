#include <graphics.h>
#include <conio.h>

void main( void )
{
 int i, sugar, csucsx[3], csucsy[3], szog[3], vszog[3], kpx, kpy,Gd,Gm;
 struct arccoordstype iv;
 for(i=0; i<3; i++)
    szog[i]=0;
 kpx=320;
 kpy=240;
 sugar=100;
 Gd=DETECT;
 initgraph(&Gd,&Gm,"");
 cleardevice();
 setcolor(BLACK);
 szog[0]=90;
 szog[1]=210;
 szog[2]=300;
 for( i=0; i<3; i++)
    {
     arc(kpx,kpy,0,szog[i],sugar);
     getarccoords(&iv);
     csucsx[i]=iv.xend;
     csucsy[i]=iv.yend;
     vszog[i]=szog[i]+15;
    }
 while(!kbhit())
  {
   setcolor(RED);
   line(csucsx[0],csucsy[0],csucsx[1],csucsy[1]);
   line(csucsx[1],csucsy[1],csucsx[2],csucsy[2]);
   line(csucsx[2],csucsy[2],csucsx[0],csucsy[0]);
   putpixel(kpx,kpy,1);
   delay(100);
   setcolor(BLACK);
   setfillstyle(EMPTY_FILL,BLACK);
   bar(200,100,500,400);
   for(i=0; i<3; i++)
      {
       arc(kpx,kpy,szog[i],vszog[i],sugar);
       getarccoords(&iv);
       csucsx[i]=iv.xend;
       csucsy[i]=iv.yend;
       szog[i]+=15;
       vszog[i]+=15;
      }
   }

 getch();
 closegraph();



}