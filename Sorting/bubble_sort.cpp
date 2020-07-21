/*:::::::::::::::::::::::::::::::Bubble Sort:::::::::::::::::::::::::::::::::::
                            Time Complexity: o(n^2)
----------------------------------------------------------------------------------*/

#include<iostream>  // for cin/cout
#include<algorithm> // for swap

using namespace std;

void bubble_sort(int ara[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(ara[j]>ara[j+1])
                swap(ara[j],ara[j+1]);
        }
    }
}

//Fuction for printing array elements
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
    bubble_sort(ara, n);
    print(ara,n);
}
