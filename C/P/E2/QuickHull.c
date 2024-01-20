#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
};

int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2; 
}

int dist(struct Point p, struct Point q) {
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

void quickHull(struct Point points[], int n, struct Point p1, struct Point p2, int side) {
    int index = -1;
    int max_dist = 0;

    for (int i = 0; i < n; i++) {
        int temp = dist(p1, p2) * dist(p2, points[i]);
        if (orientation(p1, p2, points[i]) == side && temp > max_dist) {
            index = i;
            max_dist = temp;
        }
    }

    if (index == -1) {
        printf("(%d, %d) ", p1.x, p1.y);
        return;
    }

    quickHull(points, n, points[index], p1, -orientation(points[index], p1, p2));
    quickHull(points, n, points[index], p2, -orientation(points[index], p2, p1));
}

void findConvexHull(struct Point points[], int n) {
    if (n < 3) {
        printf("Convex hull not possible\n");
        return;
    }

    int min_x = 0, max_x = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[min_x].x)
            min_x = i;
        if (points[i].x > points[max_x].x)
            max_x = i;
    }

    quickHull(points, n, points[min_x], points[max_x], 1);
    quickHull(points, n, points[min_x], points[max_x], -1);
}

int main() {
    struct Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    printf("Convex Hull points: ");
    findConvexHull(points, n);

    return 0;
}
