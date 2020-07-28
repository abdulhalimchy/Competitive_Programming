#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    vector<double> value_per_weight;
    for(int i=0; i<values.size(); i++){
        value_per_weight.push_back((double)values[i]/(double)weights[i]);
    }

    //sorting weight based on the maximum value_per_weight. Using Bubble sort algorithm
    for(int i=0; i<value_per_weight.size(); i++){
        for(int j=0; j<value_per_weight.size()-i-1; j++){
            if(value_per_weight[j+1]>value_per_weight[j]){
                swap(value_per_weight[j+1],value_per_weight[j]);
                swap(weights[j+1], weights[j]);
                swap(values[j+1], values[j]);
            }
        }
    }

    for(int i=0; i<weights.size(); i++){
        if(capacity==0)
            break;
        if(weights[i]<=capacity){
            value+=values[i];
            capacity-=weights[i];
        }
        else{
            value+=(double)capacity*value_per_weight[i];
            break;
        }
    }
    return value;
}

int main()
{
    int n;
    int capacity;
    cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}

/*input1:
3 50
120 30
60 10
100 20
*/
