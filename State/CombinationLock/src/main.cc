#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationLock
{
    vector<int> combinations;
    int index;
    bool failed = false;
public:
    string status;

    CombinationLock(vector<int> combinations)
        : combinations(combinations)
    {
        reset();
    }

    void reset()
    {
        index = 0;
        failed = false;
        status = "LOCKED";
    }

    void enter_digit(int digit)
    {
        if (status == "LOCKED")
            status = "";

        status += to_string(digit);

        if (combinations[index] != digit)
            failed = true;

        ++index;

        if (combinations.size() == index)
            status = failed ? "ERROR":"OPEN";

    }

};

int main()
{
    CombinationLock lock{vector<int>{1,2,3}};

    lock.enter_digit(1);
    lock.enter_digit(2);
    lock.enter_digit(3);

    cout << lock.status << endl;
    return 0;
}
