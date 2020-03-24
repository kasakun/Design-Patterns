#include <iostream>
#include <vector>
#include <memory>

struct GraphicObject
{
    virtual void draw() = 0;
};

struct Circle: public GraphicObject
{
    void draw() override
    {
        std::cout << "Circle" << std::endl;
    }
};

struct Group: public GraphicObject
{
    std::string name;

    explicit Group(const std::string& name)
        :name(name)
    {
    }

    void draw() override
    {
        std::cout << "Group " << name.c_str() << " contains:" << std::endl;

        for (auto&& o : objects)
            o->draw();
    }
    std::vector<GraphicObject*> objects;
};

int main()
{
    Group root("root");
    Group sub("root/sub");
    Circle c1, c2;
    root.objects.emplace_back(&c1);
    sub.objects.emplace_back(&c2);

    root.objects.emplace_back(&sub);

    root.draw();
}