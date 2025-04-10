#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x, y;
} Point;

Point p0;

int swap(Point* a, Point* b) {
    Point temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}

// To find orientation
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Distance square
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) +
           (p1.y - p2.y)*(p1.y - p2.y);
}

// Compare function for qsort
int compare(const void* vp1, const void* vp2) {
    Point* p1 = (Point*)vp1;
    Point* p2 = (Point*)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return distSq(p0, *p2) - distSq(p0, *p1);
    return (o == 2) ? -1 : 1;
}

// Next to top in stack
Point nextToTop(Point stack[], int* top) {
    return stack[*top - 1];
}

void convexHull(Point points[], int n) {
    // Step 1: Find the bottom-most point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) ||
            (points[i].y == ymin && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    swap(&points[0], &points[min]);
    p0 = points[0];

    // Step 2: Sort based on angle with p0
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Step 3: Build hull
    Point stack[100];
    int top = 0;
    stack[top++] = points[0];
    stack[top++] = points[1];
    stack[top++] = points[2];

    for (int i = 3; i < n; i++) {
        while (top >= 2 && orientation(nextToTop(stack, &top), stack[top - 1], points[i]) != 2)
            top--;
        stack[top++] = points[i];
    }

    // Print result
    printf("Points in Convex Hull:\n");
    for (int i = 0; i < top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
}

int main() {
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}

