#include <vector>
#include <iostream>
#define GREEN "\033[32m"
#define BLUE "\033[34m"

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {

        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            swap(s[left], s[right]);

            left++;
            right--;
        }
        int i = 0;
    }
};

int main()
{
    Solution s;

    vector<char> input = {'h', 'e', 'l', 'l', 'o'};

    s.reverseString(input);

    for (char &c : input)
    {
        cout << BLUE << c;
    }

    return 0;
}