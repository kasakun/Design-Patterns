#include <string>
#include <iostream>

using namespace std;


class Point {
    int x{0}, y{0};
public:
    Point(){}
    Point(const int x, const int y):x(x), y(y){}

    friend class Line;
    friend ostream& operator<< (ostream& os, Point& point)
    {
        return os
            << "x:" << point.x << " y:" << point.y << " ";
    }
};

class Line {
    Point *start, *end;
public:
    Line(Point* const start, Point* const end)
        :start(start), end(end)
    {
    };

    ~Line()
    {
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        return Line {
            new Point(start->x, start->y),
            new Point(end->x, end->y)
        };
    }


    friend ostream& operator<< (ostream& os, Line& line)
    {
        return os
            << "Start point: " << *line.start
            << "End point: " << *line.end;
    }
};

int main()
{
    Line line1{
        new Point(2,10),
        new Point(3,4)
    };

    // line1 is a prototype
    auto line2 = line1.deep_copy();

    cout << "Line 1 " << line1 << endl;
    cout << "Line 2 " << line2 << endl;
}
