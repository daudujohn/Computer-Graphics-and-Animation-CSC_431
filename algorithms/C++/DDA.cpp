#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>

using namespace std;
struct Point
{
    double x;
    double y;
};

Point get_next_point(double slope, Point p[])
{
    Point next_point;
    double new_x;
    double new_y;
    if (slope < 1)
    {
        new_x = 1 + p->x;
        new_y = slope + p->y;
    }
    else if (slope == 1)
    {
        new_x = 1 + p->x;
        new_y = 1 + p->y;
    }
    else
    {
        new_x = (1 / slope) + p->x;
        new_y = 1 + p->y;
    }

    next_point.x = new_x;
    next_point.y = new_y;

    return next_point;
}

/**
 * @brief calculates the points between a given start and end point
 * @param: start_point - co-ordinates of the start point
 * @param: end_point - co-ordinates of the end point
 *
 * @return a collection of points
 */
vector<Point> DDA(Point start_point, Point end_point)
{
    assert(((start_point.x != end_point.x) && (start_point.y != end_point.y)) && "both points have the same co-ordinates");

    int change_in_x = end_point.x - start_point.x;
    int change_in_y = end_point.y - start_point.y;
    double slope = change_in_y / change_in_x;
    vector<Point> points;

    int number_of_iterations = 0;
    if (abs(change_in_x) > abs(change_in_y))
    {
        number_of_iterations = abs(change_in_x);
    }
    else
    {
        number_of_iterations = abs(change_in_y);
    }

    points.push_back(start_point);
    for (int i = 0; i < number_of_iterations; i++)
    {
        Point next_point = get_next_point(slope, &start_point);
        start_point = next_point;
        points.push_back(start_point);
    }

    return points;
}

int main()
{
    Point start = {5, 6};
    Point end = {8, 12};

    vector<Point> points = DDA(start, end);
    for (int i = 0; i < points.size(); i++)
    {
        cout << "Point: (" << round(points[i].x) << ", " << round(points[i].y) << ")" << endl;
    }

    return 0;
}
