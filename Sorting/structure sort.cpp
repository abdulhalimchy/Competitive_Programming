/*:::::::::::::::::::::::::::::::::Structure Sort:::::::::::::::::::::::::::::*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int age, income, spendings, savings;
};

bool cmp(Node a, Node b)
{
    if(a.age!=b.age)
        return a.age>b.age; // if ages are not same, then sort in descending order based on age
    if(a.income!=b.income)
        return a.income<b.income;  // if ages are same, then sort in ascending order based on income
    if(a.spendings!=b.spendings)
        return a.spendings>b.spendings; // if ages and incomes same, then sort in descending order based on spendings
    return a.savings<b.savings; // if ages, incomes and spendings are same, then sort in ascending order based on savings
}

int main()
{
    int n;
    Node data[100];
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> data[i].age >> data[i].income >> data[i].spendings >> data[i].savings;
    sort(data, data+n, cmp);

    cout << "\n";
    for(int i=0; i<n; i++)
        printf("%d    %d    %d    %d\n", data[i].age, data[i].income, data[i].spendings, data[i].savings);
    return 0;
}
/*
10
25 200 150 50
23 250 200 50
25 200 160 40
25 200 160 30
30 700 350 350
30 650 350 300
25 150 130 20
30 700 450 250
21 120 80 40
45 2000 700 1300
*/
