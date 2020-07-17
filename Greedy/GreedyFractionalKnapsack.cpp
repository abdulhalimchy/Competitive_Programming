#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    string name[50];
    double price[50], weight[50], price_per_kg[50];

    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> name[i] >> price[i] >> weight[i];

        //calculate price per kg
        price_per_kg[i]=price[i]/weight[i];
    }


    //sort items with highest price per kg to lowest price per kg
    //Here using bubble sort technique
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(price_per_kg[j+1]>price_per_kg[j])
            {
                swap(name[j+1], name[j]);
                swap(weight[j+1], weight[j]);
                swap(price_per_kg[j+1],price_per_kg[j]);
            }
        }
    }


    //Taking items to the knapsack
    double total_price=0, currently_taken_weight=0;
    int lastItem=0;
    bool lastItem_taken_fully=true;

    for(int i=0; i<n; i++)
    {
        if(m-currently_taken_weight==0)     //If knapsack is full already, then break.
            break;
        else
        {
            lastItem=i;
            if(m-currently_taken_weight>=weight[i])     //If the full item can be taken into the knapsack
            {
                total_price+=(weight[i]*price_per_kg[i]);
                currently_taken_weight+=weight[i];
            }
            else    //If fully not possible, then take partially to the knapsack
            {
                total_price+=((m-currently_taken_weight)*price_per_kg[i]);
                lastItem_taken_fully=false;
                break;
            }
        }
    }

    printf("Total price achieved: %.3f\n", total_price);

    for(int i=0; i<lastItem; i++)
    {
        cout << name[i] << " taken with a fraction of 1\n";
    }

    if(lastItem_taken_fully==true)
        cout << name[lastItem] << " taken with a fraction of 1\n";
    else
        cout << name[lastItem] << " taken with a fraction of " << ((1.0/weight[lastItem])*(m-currently_taken_weight)) << "\n";

    return 0;
}

/*
Input 1:
3 50
rice 120 30
pulse 60 10
sugar 100 20


Input 2:
6 15
rice 40 5
pulse 10 4
sugar 24 3
wheat 36 6
oats 20 2
cumin 35 7


Input 3:
5 15
a 260 2
b 777 7
c 589 3
d 570 5
e 480 4

*/
