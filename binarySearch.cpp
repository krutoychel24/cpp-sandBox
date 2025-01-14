#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int arr[10];
    int key;

    cout << "Введите 10 чисел для заполнения массива: "<< endl;
    
    for(int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + 10);

    cout << endl << "Insert key: ";

    cin >> key;

    bool flag = false;
    int l = 0;
    int r = 9;

    int mid;

    while ((l <= r) && (flag != true))
    {
        mid = (l + r) / 2;

        if (arr[mid] == key) flag = true;
        if (arr[mid] > key) r = mid - 1;
        else l = mid + 1;
    }

    if(flag) cout << "Индекс елемента " << key << " в масиве равен: "<< mid << endl;
    else cout << "Извините, такого елемента нет в массиве" << endl;

    system("pause");
    return 0;
    

}



