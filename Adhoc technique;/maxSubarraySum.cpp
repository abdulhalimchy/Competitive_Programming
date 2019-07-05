:::::::::::::::::::::::Maximum Sum of Subarray:::::::::::::::::::::
/*Given an array with n positive and negative numbers, find the subarray with one or more
consecutive numbers where the sum of the subarray is maximum.

Tutorial link: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/
#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;

    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is "
        << max_so_far << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
    return max_so_far;
}

int main()
{
    int a[] = {-2, -3, -1, -4, -6};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    return 0;
}
