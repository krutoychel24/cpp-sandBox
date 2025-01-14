#include <iostream>
#include <vector>
#include <algorithm>

int iterations;

std::vector<int> generateData(int size)
{
    std::vector<int> result;
    for (int i = 0; i < size; i++) {
        result.push_back(i);
    }

    return result;
}

bool isInArray(std::vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        iterations++; // debug info

        if (nums[i] == target)
        {
            return true;
        }
    }
    
    return false;
}

bool isInArrayBinary(std::vector<int>& nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) // O(log(n)) = 
    {
        iterations++; // debug info

        int mid = (l + r) / 2;

        if (nums[mid] == target)
        {
            return true;
        }

        if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else 
        {
            l = mid + 1;
        }
    }
    
    return false;
}

// Rewrited for binary search
bool twoSum(std::vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());

    int size = nums.size();

    for (int i = 0; i < size; ++i) {
        int complement = target - nums[i];

        int low = i + 1, high = size - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == complement) {
                return true;
            }
            else if (nums[mid] < complement) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return false;
}


bool isEven(int number)
{
    return number % 2 == 0;
}

int main()
{
    for (int inputSize = 0; inputSize < 10000; inputSize += 100) {
        std::vector<int> data = generateData(inputSize);
        twoSum(data, -1);

        std::cout << inputSize << " " << iterations << std::endl;
        iterations = 0;
    }

    return 0;
}