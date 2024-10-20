#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265
#define MAX_POINTS 8

typedef struct
{
    float x, y, z;
} Point3D;

Point3D cube[MAX_POINTS] = {
    {-50, -50, -50},
    {50, -50, -50},
    {50, 50, -50},
    {-50, 50, -50},
    {-50, -50, 50},
    {50, -50, 50},
    {50, 50, 50},
    {-50, 50, 50}};

int projX(float x, float z)
{
    return (int)(x * 200 / (z + 200)); // Simple perspective projection
}

int projY(float y, float z)
{
    return (int)(y * 200 / (z + 200));
}

void drawCube()
{
    for (int i = 0; i < 4; i++)
    {
        line(projX(cube[i].x, cube[i].z) + 300, projY(cube[i].y, cube[i].z) + 300,
             projX(cube[(i + 1) % 4].x, cube[(i + 1) % 4].z) + 300,
             projY(cube[(i + 1) % 4].y, cube[(i + 1) % 4].z) + 300);

        line(projX(cube[i + 4].x, cube[i + 4].z) + 300, projY(cube[i + 4].y, cube[i + 4].z) + 300,
             projX(cube[(i + 1) % 4 + 4].x, cube[(i + 1) % 4 + 4].z) + 300,
             projY(cube[(i + 1) % 4 + 4].y, cube[(i + 1) % 4 + 4].z) + 300);

        line(projX(cube[i].x, cube[i].z) + 300, projY(cube[i].y, cube[i].z) + 300,
             projX(cube[i + 4].x, cube[i + 4].z) + 300,
             projY(cube[i + 4].y, cube[i + 4].z) + 300);
    }
}

void translate(Point3D *p, float tx, float ty, float tz)
{
    p->x += tx;
    p->y += ty;
    p->z += tz;
}

void rotateX(Point3D *p, float angle)
{
    float rad = angle * (PI / 180);
    float y = p->y * cos(rad) - p->z * sin(rad);
    float z = p->y * sin(rad) + p->z * cos(rad);
    p->y = y;
    p->z = z;
}

void rotateY(Point3D *p, float angle)
{
    float rad = angle * (PI / 180);
    float x = p->x * cos(rad) + p->z * sin(rad);
    float z = -p->x * sin(rad) + p->z * cos(rad);
    p->x = x;
    p->z = z;
}

void rotateZ(Point3D *p, float angle)
{
    float rad = angle * (PI / 180);
    float x = p->x * cos(rad) - p->y * sin(rad);
    float y = p->x * sin(rad) + p->y * cos(rad);
    p->x = x;
    p->y = y;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int choice;
    do
    {
        cleardevice(); // Clear the screen

        // Draw the cube
        setcolor(WHITE);
        drawCube();

        // Display options
        printf("\nChoose a transformation:\n");
        printf("1. Translation\n");
        printf("2. Rotation (X-axis)\n");
        printf("3. Rotation (Y-axis)\n");
        printf("4. Rotation (Z-axis)\n");
        printf("5. Scaling\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        { // Translation
            float tx, ty, tz;
            printf("Enter translation vector (tx, ty, tz): ");
            scanf("%f %f %f", &tx, &ty, &tz);
            for (int i = 0; i < MAX_POINTS; i++)
            {
                translate(&cube[i], tx, ty, tz);
            }
            break;
        }
        case 2:
        { // Rotation around X-axis
            float angle;
            printf("Enter rotation angle (in degrees): ");
            scanf("%f", &angle);
            for (int i = 0; i < MAX_POINTS; i++)
            {
                rotateX(&cube[i], angle);
            }
            break;
        }
        case 3:
        { // Rotation around Y-axis
            float angle;
            printf("Enter rotation angle (in degrees): ");
            scanf("%f", &angle);
            for (int i = 0; i < MAX_POINTS; i++)
            {
                rotateY(&cube[i], angle);
            }
            break;
        }
        case 4:
        { // Rotation around Z-axis
            float angle;
            printf("Enter rotation angle (in degrees): ");
            scanf("%f", &angle);
            for (int i = 0; i < MAX_POINTS; i++)
            {
                rotateZ(&cube[i], angle);
            }
            break;
        }
        case 5:
        { // Scaling
            float sx, sy, sz;
            printf("Enter scaling factors (sx, sy, sz): ");
            scanf("%f %f %f", &sx, &sy, &sz);
            for (int i = 0; i < MAX_POINTS; i++)
            {
                cube[i].x *= sx;
                cube[i].y *= sy;
                cube[i].z *= sz;
            }
            break;
        }
        case 6: // Exit
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }

        delay(1000); // Wait for 1 second
    } while (choice != 6); // Loop until user chooses to exit

    // Close the graphics window
    closegraph();
    return 0;
}

// g++ 3D.c -o 3D.exe -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32