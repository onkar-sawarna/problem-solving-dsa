#include <iostream>
#include <vector>

using namespace std;

void divisors(){
    vector<int> divisors[100001];
    for(int i=1;i<=100000;i++){
        for(int j=i;j<=100000;j+=i){
            divisors[j].push_back(i);
        }
    }
    for(int i=0;i<=10;i++){
         for(auto v:divisors[i]){
             cout<<v<<" ";
         }
         cout<<"\n";
    }
   
}
void seiveOfEratosthenes(){
    vector<int> primes;
    int is_prime[100001];
    for(int i=1;i<=100001;i++)is_prime[i]=1; //assume all are primes
    is_prime[1] = 0; // 1 is neither prime nor composite
    
    for(int i=2;i<=100000;i++){
        if(is_prime[i]){
            primes.push_back(i);
        for(int j=2*i;j<=100000;j+=i){
            is_prime[j]=0;
        }
    }
    }
    for(int i=0;i<=100;i++){
             cout<<primes[i]<<" ";
    }
   
}

int spf(int x){
    // vector<int> primes;
    // int is_prime[100001];
    int spf[100001];
    for(int i=1;i<=100001;i++){
        spf[i] = i; //assuming all smallest prime factor are the number itself 
       // is_prime[i]=1;
    }
    //is_prime[1] = 0;
    spf[1] = 1;
    
    for(int i=2;i<=100000;i++){
        if(spf[i] == i){
        for(int j=2*i;j<=100000;j+=i){
            if(spf[j] == j)spf[j] = i;
        }
    }
    }
             
             //cout<<x<<":"<<spf[x]<<"\n";
    return spf[x];

    
}
void primeFactorization(int x){
    while(x!=1){
        cout<<spf(x);
        if(x!=spf(x))cout<<"*";
        x=x/spf(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin>>x;
    primeFactorization(x);
    return 0;
}
