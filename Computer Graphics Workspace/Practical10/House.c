#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  int gm, x, y, gd = DETECT, i;
  int stangle = 45, endangle = 50;
  int radius = 50;

  initgraph(&gd, &gm, "z:\\tc\\bgi");

  x = getmaxx(); // to get the co-ordinates i.e. x & y
  y = getmaxy();

  cleardevice();

  fflush(stdout); // this is the function in C to clean the screen

  // Drawing the hut
  line(200, 150, 350, 150);
  line(140, 200, 200, 150);
  line(140, 330, 140, 200);
  line(250, 200, 140, 200);
  line(200, 150, 250, 200);
  circle(196, 180, 15);
  setfillstyle(2, 14);
  floodfill(196, 180, 15);
  setfillstyle(1, 2);
  line(350, 150, 400, 200);
  floodfill(210, 180, 15);
  line(400, 200, 400, 330);
  line(140, 330, 400, 330);
  line(250, 200, 250, 330);
  line(250, 200, 400, 200); // Hut

  setfillstyle(5, 7);
  floodfill(260, 180, 15);

  // Door
  line(170, 260, 170, 330);
  line(170, 260, 210, 260);
  setfillstyle(10, 9);
  floodfill(180, 250, 15);
  line(210, 260, 210, 330);
  setfillstyle(9, 9);
  floodfill(210, 250, 15);

  // Chimney
  line(290, 110, 290, 150);
  line(310, 110, 310, 150);
  ellipse(300, 110, 0, 360, 10, 3);
  setfillstyle(6, 8);
  floodfill(300, 120, 15);

  // Window
  line(300, 250, 350, 250);
  line(300, 280, 350, 280);
  line(300, 250, 350, 280);
  line(300, 280, 300, 250);
  line(350, 280, 350, 250);
  setfillstyle(9, 9);
  floodfill(252, 300, 15);
  setfillstyle(8, 9);
  floodfill(342, 270, 15);

  setcolor(2);
  arc(30, 300, stangle, endangle, radius);
  setcolor(8);
  line(5, 330, 600, 330);

  // Animated text
  for (i = 0; i < 650; i = i + 10)
  {
    setcolor(4);
    settextstyle(7, 0, 5);
    outtextxy(0 + i, 390, "Home Sweet Home");
    delay(100);
    setcolor(0);
    settextstyle(7, 0, 5);
    outtextxy(0 + i, 390, "Home Sweet Home");
  }

  getch();
  closegraph();
  return 0;
}

// g++ House.c -o House.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32