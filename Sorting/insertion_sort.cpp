/*::::::::::::::::::::::::::Insertion Sort::::::::::::::::::::::::::::::::::::
                        Time Complexity: O(n^2)
------------------------------------------------------------------------------*/

#include<iostream>  //for cin and cout
using namespace std;

void sort_ascending(int ara[], int n){
    for(int i=1; i<n; i++)
    {
        int temp=ara[i], j=i-1;
        while(j>=0 && ara[j]>temp)
        {
            ara[j+1]=ara[j];
            j--;
        }
        ara[j+1]=temp;
    }
}

void sort_descending(int ara[], int n){
    for(int i=1; i<n; i++)
    {
        int temp=ara[i], j=i-1;
        while(j>=0 && ara[j]<temp)
        {
            ara[j+1]=ara[j];
            j--;
        }
        ara[j+1]=temp;
    }
}

void print(int ara[], int n){
    for(int i=0; i<n; i++)
        cout << ara[i] << " ";
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int ara[n];
    for(int i=0; i<n; i++)
        cin >> ara[i];
    cout << "Ascending:\n";
    sort_ascending(ara, n);
    print(ara,n);

    cout << "\n\nDescending:\n";
    sort_descending(ara,n);
    print(ara,n);
}
