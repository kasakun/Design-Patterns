#include <vector>
#include "Singleton.h"
using namespace std;

int main()
{
    vector<string> list = {"Tokyo", "Osaka"}; 
    for (auto city: list) 
        cout << city << " "
        << SingletonDatabase::get().get_population(city) << endl;
    return 0;
}