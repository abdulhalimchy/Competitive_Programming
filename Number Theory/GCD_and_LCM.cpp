/*::::::::::::::::::::::GCD and LCM:::::::::::::::::::::::*/
#include<iostream>

//Applying Euclidean algorithm technique to find gcd
int gcd(int a, int b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a,b) << std::endl;
    std::cout << lcm(a,b) << std::endl;
}
