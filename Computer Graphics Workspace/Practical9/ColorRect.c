#include <graphics.h>
#include <conio.h>
int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\turboc3\\bgi");

  // Implementing SOLID_FILL Pattern
  setfillstyle(SOLID_FILL, GREEN);

  // Rectangle Area
  rectangle(250, 100, 650, 280);

  // Flood Fill Function
  floodfill(252, 158, 15);

  getch();
  closegraph();
  return 0;
}

// g++ ColorRect.c -o ColorRect.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32