#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FormattedText
{
    string plain;
    bool* caps;
public:
    explicit FormattedText(const string& plain)
        :plain(plain)
    {
        caps = new bool[plain.length()];
    }

    ~FormattedText()
    {
        delete[] caps;
    }

    void capitalize(int start, int end)
    {
        for (int i = start; i <= end; ++i)
        {
            caps[i] = true;
        }
    }

    friend ostream& operator<<(ostream& os, const FormattedText& obj)
    {
        string s;
        for (int i = 0; i < obj.plain.size(); ++i)
        {
            char c = obj.plain[i];
            s += (obj.caps[i] ? toupper(c) : c);
        }
        return os << s;
    }
};

class BetterFormattedText
{
public:
    struct TextRange
    {
        int start, end;
        bool cap, bold, italic;

        bool covers(int position) const
        {
            return position >= start && position <= end;
        }
    };

    TextRange& getRange(int start, int end)
    {
        formatting.emplace_back(TextRange{start, end});
        return *formatting.rbegin();
    }

    explicit BetterFormattedText(const string& plain)
        : plain(plain)
    {
    }

    friend ostream& operator<<(ostream& os, BetterFormattedText& obj)
    {
        string s;
        for (int i = 0; i < obj.plain.size(); ++i)
        {
            auto c = obj.plain[i];
            for (const auto& range: obj.formatting)
            {
                if (range.covers(i) && range.cap)
                    c = toupper(c);
                s += c;
            }
        }
        return os << s;
    }
private:
    string plain;
    vector<TextRange> formatting;
};

int main()
{
    FormattedText ft("This is a brave new world");
    ft.capitalize(10, 15);
    cout << ft << endl;

    BetterFormattedText bft("This is a brave new world");
    bft.getRange(10, 15).cap = true;
    cout << bft << endl;
    return 0;
}
