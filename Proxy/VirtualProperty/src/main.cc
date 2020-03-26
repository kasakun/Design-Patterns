#include <iostream>
using namespace std;

struct Image
{
    virtual void draw() = 0;
};

//
// Supposing this struct is created and cannot be changed.
// That's why we need proxy to avoid load bitmap when create the object
struct Bitmap : Image
{
    Bitmap(const string& filename)
    {
        // Here
        cout << "Loading bitmap from" << filename << endl;
    }

    void draw() override
    {
        cout << "Drawing bitmap" << endl;
    }
};

struct LazyBitmap: Image
{
    LazyBitmap(const string& filename) : filename(filename) {}
    void draw() override
    {
        if (!bmp)
            bmp = new Bitmap(filename);
        bmp->draw();
    }
private:
    string filename;
    Bitmap *bmp{nullptr};
};

int main()
{
    //
    // The LazyBitmap will load the file only after draw() is called
    Bitmap bmp("nanako.png");
    LazyBitmap lbmp("lazynanako.png");

    cout << "After draw()" << endl;

    bmp.draw();
    lbmp.draw();

    return 0;
}
