#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "gfx4.h"

void gallery(int wd, int ht, int l);
void tree(int startx, int starty, float r, float startangle, float anglechange); 

int main () {

   int wd=(gfx_screenwidth())*0.8, ht=(gfx_screenheight())*0.8, loop=1, l, n, i;
   int r, g, b, x;
   float angle;
   char c;
   time_t t;

   n=time(&t);
   srand(n);

   gfx_open(wd, ht, "Gallery");

   while (loop) {

      c=gfx_wait();
      gfx_clear();
      gfx_clear_color(204, 255, 255);

      switch (c) {
	 case 'q':
	    loop=0;
	    break;
	 default:     
	    for (i=1; i<17; i++) {
    	       //randomize colors
	       r=rand()%255 + 1;
	       g=rand()%255 + 1;
	       b=rand()%255 + 1;

	       //get random starting x and random angle
	       x=rand()%wd + 1;
	       angle=M_PI/(rand()%6 + 3);
	       l=i*(ht/64);
	       //draw tree
	       gfx_color(r, g ,b);
	       tree(x, ht, l, -M_PI/2, angle);
               //gallery(wd, ht, i*(ht/32));
	       gfx_flush();
	    }
	    break;
      }

   }

}



void gallery(int wd, int ht, int l) {

   int r, g, b, n, x;
   float angle;
   time_t t;

   //set seed to time
   n=time(&t);
   srand(n);

   //randomize colors
   r=rand()%255 + 1;
   g=rand()%255 + 1;
   b=rand()%255 + 1;

   //get random starting x and random angle
   x=rand()%wd + 1;
   angle=M_PI/(rand()%6 + 3);

   //draw tree
   gfx_color(r, g ,b);
   tree(x, ht, l, -M_PI/2, angle);

}

void tree(int startx, int starty, float r, float startangle, float anglechange) {

   float endx, endy;

   if (r<3) {
      return;
   }

   endx=r*cos(startangle)+startx;
   endy=r*sin(startangle)+starty;

   gfx_line(startx, starty, endx, endy);

   tree(endx, endy, r*0.7, startangle+anglechange, anglechange);
   tree(endx, endy, r*0.7, startangle-anglechange, anglechange);

}



