#include <stdio.h>
#include <math.h>
#include "gfx4.h"

int main () {

   int wd=(gfx_screenwidth())*0.6, ht=(gfx_screenheight())*0.8, loop=1;
   int centerx=wd/2, centery=ht/2;
   int length;
   char c;

   gfx_open(wd, ht, "Fractals");

   while (loop) {

      c=gfx_wait();
      gfx_clear();
      switch (c) {
         case '1':
            gfx_color(255, 204, 204);   //pink
            length=ht*0.4;
            sierpinski(centerx-length, centery-length, centerx+length, centery-length, centerx, centery+length);
            break;

         case '2':
            length=ht*0.5;
            gfx_color(152, 152, 255);   //purple
            shrinkingsquares(length, centerx, centery);
            break;
         case '3':
            gfx_color(178, 255, 102);  //green
            spiralsquares(200, wd, ht, 11*(M_PI));
            break;
         case '4':
            gfx_color(0, 191, 255);  //blue
            circularlace(centerx, centery, ht*0.35, 6, centerx, centery);
            break;
         case '5':
            gfx_color(152, 255, 255);   //light blue
            snowflake(centerx, centery, ht*0.35, 5);
            break;
         case '6':
            gfx_color(255, 155, 0);   //orange
            tree(wd/2, ht, ht*0.3, -M_PI/2, M_PI/5);
            break;
         case '7':
            gfx_color(255, 69, 0);    //red
            fern(wd/2, ht, ht*0.7, -M_PI/2, M_PI/5, 4);
            break;
         case 'q':
            loop=0;
            break;
      }

      gfx_flush();

   }

}


