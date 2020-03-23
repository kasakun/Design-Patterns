#include <iostream>

struct Square
{
    int side = 0;
    explicit Square(const int side)
        : side(side)
    {
    }
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    const Square& square;

    SquareToRectangleAdapter(const Square& square)
        : square(square)
    {}

    int width() const override
    {
        return square.side;
    }

    int height() const override
    {
        return square.side;
    }
};

int main()
{
    Square sq{11};

    SquareToRectangleAdapter adapter {sq};

    std::cout << "The area is "
        << adapter.area() << std::endl;
}
