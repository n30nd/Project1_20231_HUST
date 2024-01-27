//Problem: Hash Over Strings
//Description
//Given a string s[1…k] which is a sequence of characters taken from {‘a’, . . ., ‘z’}. Given a positive integer m, the hash code of s is defined by the formula:
//H(s) =  (s[1]*256
//k-1
// + s[2]*256
//k-2
// + . . . + s[k]*256
//0
//) mod m  (the contant integer m is a parameter)
//Given a sequence of strings k1, k2, …, kn, compute the corresponding hash codes
//Input
//Line 1: n and m (1 <= n,m <= 100000)
//Line i+1 (i = 1,2,…,n): contains the string ki (the length of each string is less than or equal to 200)
//Output
//Each line contains the corresponding hash code of n given strings
//Example
//Input
//4 1000
//a
//ab
//abc
//abcd
//Output
//97
//930
//179
//924

//#include <bits/stdc++.h>
//
//using namespace std;
//int n,m;
//int pow256[201];
//
//inline int  H(string s){
//    int len = s.length();
//    int f = 0;
//   /* for(int i =1;i<=len;i++){
//        f = (f*256 +s[i-1]) % m;
//    }*/
//
//    for(int i=1;i<=len;i++){
//        f = (f + s[i-1]*pow256[len-i])%m;
//    }
//    return f;
//}
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//
//    cin >> n>>m;
//    pow256[0] = 1;
//    for(int i=1;i<=200;i++){
//        pow256[i] = (pow256[i-1]*256) % m;
//    }
//
//
//    string s;
//    for(int i=0;i<n;i++){
//        cin >> s;
//
//        int len = s.length();
//    int f = 0;
//    for(int i=1;i<=len;i++){
//        f = f + s[i-1]*pow256[len-i]%m;
//    }
//
//        cout << f%m <<endl;
//    }
//        return 0;
//}


#include "bits/stdc++.h"
using namespace std;
string s;
int n,m,len;
int f(int i){
    if(i==0) return 0;
    int t = 256*f(i-1)%m+s[i-1];
    return t%m;
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s;
        len = s.length();
        cout << f(len) <<endl;
    }

    return 0;
}
