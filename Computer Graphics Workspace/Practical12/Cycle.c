#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <unistd.h> // For delay

// Driver code
int main()
{
  int gd = DETECT, gm, i;

  // Initialize graphics mode
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // Ensure the correct path to your BGI files is set here

  // Move the cycle
  for (i = 0; i < 600; i++)
  {
    // Upper body of cycle
    line(50 + i, 405, 100 + i, 405);
    line(75 + i, 375, 125 + i, 375);
    line(50 + i, 405, 75 + i, 375);
    line(100 + i, 405, 100 + i, 345);
    line(150 + i, 405, 100 + i, 345);
    line(75 + i, 345, 75 + i, 370);
    line(70 + i, 370, 80 + i, 370);
    line(80 + i, 345, 100 + i, 345);

    // Wheels
    circle(150 + i, 405, 30);
    circle(50 + i, 405, 30);

    // Road
    line(0, 436, getmaxx(), 436);

    // Stone
    rectangle(getmaxx() - i, 436, 650 - i, 431);

    // Delay the screen for a short period
    delay(10); // Or use usleep(10000); on Unix-like systems

    // Clear the screen
    cleardevice();
  }

  getch();

  // Close the graph
  closegraph();
  return 0;
}

// g++ Cycle.c -o Cycle.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32