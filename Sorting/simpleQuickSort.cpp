/*::::::::::::::::::::::::::::::Simple QuickSort:::::::::::::::::::::::::::::::
                    Average case - time complexity : O(n logn)
                    Worst case - time complexity : O(n^2);
Note: worst case occurs when it is already sorted in ascending/descending order. The implementation below is not stable. There are better ways to implement QuickSort.
*/
#include<iostream>
#include<vector>
#include<algorithm> // for swap()
using namespace std;

void print(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int divide(vector<int> &v, int low, int high){
    int i=low-1;
    for(int j=low; j<high; j++){
        if(v[j]<v[high]){   // v[high] is our current pivot. It means, here last element is our pivot
            i++;
            swap(v[i],v[j]);
        }
    }
    i++;
    swap(v[i],v[high]);
    return i;
}

void quickSort(vector<int> &v, int low, int high){
    if(low<high){
        int pi=divide(v,low,high);  // partition index
        quickSort(v, low, pi-1); //Left partition of the pi
        quickSort(v,pi+1, high); //Right partition of the pi
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    quickSort(v, 0, n-1);
    print(v);
    return 0;
}
