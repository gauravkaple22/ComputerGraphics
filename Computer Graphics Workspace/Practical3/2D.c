#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void translate(int *x, int *y, int tx, int ty)
{
    *x += tx;
    *y += ty;
}

void rotate(int *x, int *y, float angle)
{
    float rad = angle * (PI / 180);
    int newX = *x * cos(rad) - *y * sin(rad);
    int newY = *x * sin(rad) + *y * cos(rad);
    *x = newX;
    *y = newY;
}

void scale(int *x, int *y, float sx, float sy)
{
    *x *= sx;
    *y *= sy;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2, x3, y3;

    // Input the coordinates of the triangle
    printf("Enter the coordinates of the triangle (x1, y1), (x2, y2), (x3, y3):\n");
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);

    int choice;
    do
    {
        cleardevice(); // Clear the screen

        // Draw the original triangle
        setcolor(WHITE);
        drawTriangle(x1, y1, x2, y2, x3, y3);

        // Display options
        printf("\nChoose a transformation:\n");
        printf("1. Translation\n");
        printf("2. Rotation\n");
        printf("3. Scaling\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        { // Translation
            int tx, ty;
            printf("Enter translation vector (tx, ty): ");
            scanf("%d %d", &tx, &ty);
            translate(&x1, &y1, tx, ty);
            translate(&x2, &y2, tx, ty);
            translate(&x3, &y3, tx, ty);
            break;
        }
        case 2:
        { // Rotation
            float angle;
            printf("Enter rotation angle (in degrees): ");
            scanf("%f", &angle);
            rotate(&x1, &y1, angle);
            rotate(&x2, &y2, angle);
            rotate(&x3, &y3, angle);
            break;
        }
        case 3:
        { // Scaling
            float sx, sy;
            printf("Enter scaling factors (sx, sy): ");
            scanf("%f %f", &sx, &sy);
            scale(&x1, &y1, sx, sy);
            scale(&x2, &y2, sx, sy);
            scale(&x3, &y3, sx, sy);
            break;
        }
        case 4: // Exit
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }

        delay(1000); // Wait for 1 second
    } while (choice != 4); // Loop until user chooses to exit

    // Close the graphics window
    closegraph();
    return 0;
}

// g++ 3D.c -o 3D.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
//  input: 50 20
//         100 20
//         75 40