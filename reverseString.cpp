#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {

        int Left = 0;
        int Right = s.size() - 1;

        while (Left < Right)
        {
            swap(s[Left], s[Right]);

            Left++;
            Right--;
        }
        int i = 0;
        // while (i < sSize)
        //{
        //   cout << i;
        //  i++;
        //}
    }
};

int main()
{
    Solution s;

    vector<char> input = {'h', 'e', 'l', 'l', 'o'};

    s.reverseString(input);

    for (char &c : input)
    {
        cout << c;
    }

    return 0;
}