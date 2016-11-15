#include <stdio.h>
#include <math.h>
#include "gfx4.h" 


void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3) {

   if (abs(x2-x1) < 5) {
      return;
   }

   drawtriangle(x1, y1, x2, y2, x3, y3);

   sierpinski(x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2);
   sierpinski((x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2);
   sierpinski((x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3);

}

void shrinkingsquares(int length, int cx, int cy) {

   int len;

   if (length<5) {
      return;
   }

   len=length/2;
   drawsquare(length, cx, cy);

   shrinkingsquares(length/2.1, cx-len, cy-len);
   shrinkingsquares(length/2.1, cx+len, cy-len);
   shrinkingsquares(length/2.1, cx-len, cy+len);
   shrinkingsquares(length/2.1, cx+len, cy+len);

}

void spiralsquares(int length, int wd, int ht, float angle) {

   float xpos, ypos;

   if (length<1) {
      return;
   }

   xpos=pow(1.2,angle)*cos(angle)+(wd/2);
   ypos=pow(1.2,angle)*sin(angle)+(ht/2);

   drawsquare(length, xpos, ypos);

   spiralsquares(length*0.9, wd, ht, angle-(M_PI/4.5));
}

void circularlace(int x, int y, float r, int numcir, int centerx, int centery) {

   float xc, yc, anglechange, angle=0;
   int i;

   if (r<1) {
      return;
   }

   gfx_circle(x, y, r);

   anglechange=2*M_PI/numcir;

   for (i=0; i<numcir; i++) {
      xc=r*cos(angle)+x;
      yc=r*sin(angle)+y;
      circularlace(xc, yc, r*0.34, numcir, centerx, centery);
      angle=angle+anglechange;
   }

}


void snowflake(int startx, int starty, float r, int numlines) {

   float endx, endy, anglechange, angle=0;
   int i;

   if (r<1) {
      return;
   }

   anglechange=2*M_PI/numlines;

   for (i=0; i<=numlines; i++) {
      endx=r*cos(angle)+startx;
      endy=r*sin(angle)+starty;
      gfx_line(startx, starty, endx, endy);
      angle=angle+anglechange;
      snowflake(endx, endy, r*0.34, numlines);
   }

}


void tree(int startx, int starty, float r, float startangle, float anglechange)
{

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


void fern(int startx, int starty, float r, float startangle, float anglechange,
int numbranch) {

   float endx, endy;
   int i;

   if (r<2) {
      return;
   }

   endx=r*cos(startangle)+startx;
   endy=r*sin(startangle)+starty;
   gfx_line(startx, starty, endx, endy);

   for (i=0; i<numbranch; i++) {
      fern(endx-(((r*cos(startangle))/4)*i), endy-(((r*sin(startangle))/4)*i), r*0.3, startangle+anglechange, anglechange, numbranch);
      fern(endx-(((r*cos(startangle))/4)*i), endy-(((r*sin(startangle))/4)*i), r*0.3, startangle-anglechange, anglechange, numbranch);
   }

}


void drawsquare(int length, int cx, int cy) {

   int half;

   half=length/2;
   XPoint points[]={{cx-half, cy-half}, {cx+half, cy-half}, {cx+half, cy+half}, {cx-half, cy+half}, {cx-half, cy-half}};
   gfx_polygon(points, 5);

}

void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3) {

   XPoint points[]={{x1, y1}, {x2, y2}, {x3, y3}, {x1, y1}};
   gfx_polygon(points, 4);

}

