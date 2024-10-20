#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

// Function to draw clock hands
void drawHand(int length, int angle, int color)
{
  int x_center = getmaxx() / 2;
  int y_center = getmaxy() / 2;

  int x = x_center + length * cos(angle * PI / 180);
  int y = y_center - length * sin(angle * PI / 180);

  setcolor(color);
  line(x_center, y_center, x, y);
}

// Function to draw clock face
void drawClockFace()
{
  int x_center = getmaxx() / 2;
  int y_center = getmaxy() / 2;
  int radius = 200;

  setcolor(WHITE);
  circle(x_center, y_center, radius);

  // Draw hour markers
  for (int i = 0; i < 12; i++)
  {
    int angle = i * 30; // 360/12 = 30 degrees for each hour
    int x_inner = x_center + (radius - 20) * cos(angle * PI / 180);
    int y_inner = y_center - (radius - 20) * sin(angle * PI / 180);
    int x_outer = x_center + radius * cos(angle * PI / 180);
    int y_outer = y_center - radius * sin(angle * PI / 180);

    setcolor(WHITE);
    line(x_inner, y_inner, x_outer, y_outer);
  }
}

// Main function to update and draw the clock
int main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

  while (1)
  {
    // Get the current time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    int hours = current_time->tm_hour;
    int minutes = current_time->tm_min;
    int seconds = current_time->tm_sec;

    // Adjust the hour to 12-hour format
    if (hours >= 12)
    {
      hours -= 12;
    }

    // Clear the screen
    cleardevice();

    // Draw the clock face
    drawClockFace();

    // Draw hour, minute, and second hands
    drawHand(100, (hours * 30 + minutes / 2) - 90, BLUE); // Hour hand
    drawHand(150, (minutes * 6) - 90, GREEN);             // Minute hand
    drawHand(170, (seconds * 6) - 90, RED);               // Second hand

    delay(1000); // Update every second
  }

  closegraph();
  return 0;
}

//  g++ AnalogClock.c -o AnalogClock.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32