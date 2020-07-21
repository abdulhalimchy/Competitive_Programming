/*:::::::::::::::::::::::::::::::Selection Sort:::::::::::::::::::::::::::::::::::
                            Time Complexity: o(n^2)
----------------------------------------------------------------------------------
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part
and putting it at the beginning. The algorithm maintains two subarrays in a given array.

See Ref: https://www.geeksforgeeks.org/selection-sort/
*/

#include<iostream>  // for cin/cout
#include<algorithm> // for swap

using namespace std;

void selection_sort(int ara[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        //Find the minimum element in unsorted array[i+1] to ara[n-1]
        int min_index=i;
        for(int j=i+1; j<n; j++)
        {
            if(ara[j]<ara[min_index])
                min_index=j;
        }

        //Swap mininum element to put it in in the sorted subarray
        swap(ara[i],ara[min_index]);
    }
}

//Fuction for printing array elements
void print(int ara[], int n){
    for(int i=0; i<n; i++)
        cout << ara[i] << " ";
    cout << endl;
}


//Another approach to implement selection sort algorithm
void selection_sort_2(int ara[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ara[i]>ara[j])
                swap(ara[i],ara[j]);
        }
    }
}


int main(){
    int n;
    cin >> n;
    int ara[n];
    for(int i=0; i<n; i++)
        cin >> ara[i];
    cout << "Ascending:\n";
    selection_sort_2(ara, n);
    print(ara,n);
}
