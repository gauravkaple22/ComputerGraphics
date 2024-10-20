#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

// Function to move the drawing cursor
void move(int j, int h, int &x, int &y)
{
  if (j == 1)
    y -= h;
  else if (j == 2)
    x += h;
  else if (j == 3)
    y += h;
  else if (j == 4)
    x -= h;
  lineto(x, y); // Move to new position and draw a line
}

// Hilbert curve drawing function
void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y)
{
  if (i > 0)
  {
    i--;
    hilbert(d, r, u, l, i, h, x, y);
    move(r, h, x, y);
    delay(100); // Delay to visualize the drawing process
    hilbert(r, d, l, u, i, h, x, y);
    move(d, h, x, y);
    delay(100);
    hilbert(r, d, l, u, i, h, x, y);
    move(l, h, x, y);
    delay(100);
    hilbert(u, l, d, r, i, h, x, y);
  }
}

int main()
{
  int n, x1, y1;
  int x0 = 50, y0 = 150, x, y, h = 10;
  int r = 2, d = 3, l = 4, u = 1;

  system("cls"); // Clear the console (for Windows)

  std::cout << "\nGive the value of n: ";
  std::cin >> n;

  x = x0;
  y = y0;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

  moveto(x, y);
  hilbert(r, d, l, u, n, h, x, y);

  delay(100);
  std::cin.get(); // Wait for user input before closing
  closegraph();   // Close the graphics window

  return 0;
}

// g++ Hibert.c -o Hibert.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32