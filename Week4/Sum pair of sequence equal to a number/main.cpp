//Problem: Sum pair of sequence equal to a number
//Description
//Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.
//
//Dữ liệu
//Dòng 1: ghi n và M (1 <= n, M <= 1000000)
//Dòng 2: ghi a1, a2, ..., an
//Kết quả
//Ghi ra giá trị Q
//Ví dụ
//Dữ liệu
//5 6
//5 2 1 4 3
//Kết quả
//2

#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<int,int> mp;
    int n,m,tmp;
    cin >> n >> m;
    int cnt = 0;
    while(n--){
       cin >> tmp;

       if(mp[tmp]>0) {
            cnt++;
       }
       else {
            mp[m-tmp] = 1;

       }
    }

    cout << cnt;
}
