#include <bits/stdc++.h>
using namespace std;
void calculate(int n, int activity[], int start[], int finish[])
{
    int ans[n], end = -1;
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        if (start[i] >= end)
        {
            end = finish[i];
            ans[size] = activity[i];
            size++;
        }
    }
    cout << "Result : ";
    for (int i = 0; i < size; i++)
        cout << ans[i] << " ";
}
int main()
{
    int n;
    cout << "Enter the size : ";
    cin >> n;
    int start[n], finish[n], activity[n];
    cout << "Enter the Activities array : ";
    for (int i = 0; i < n; i++)
        cin >> activity[i];
    cout << "Enter the start time for activities : ";
    for (int i = 0; i < n; i++)
        cin >> start[i];
    cout << "Enter the finish time for activities : ";
    for (int i = 0; i < n; i++)
        cin >> finish[i];
    calculate(n, activity, start, finish);
    return 0;
}