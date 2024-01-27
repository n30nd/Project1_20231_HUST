//Problem: Week 7 - Bank Transaction
//Description
//The data about bank transactions consists of a sequence of transactions: the information of each transaction has the following format:
//                                                                    <from_account>   <to_account>   <money>   <time_point>   <atm>
//In which:
//•	<from_account>: the account from which money is transferred (which is a string of length from 6 to 20 )
//•	<to_account>: the account which receives money in the transaction (which is a string of length from 6 to 20)
//•	<money>: amount of money transferred in the transaction (which is an integer from 1 to 10000)
//•	<time_point>: the time point at which the transaction is performed, it is a string under the format HH:MM:SS  (hour: minute: second)
//•	<atm>: the code of the ATM where the transaction is taken (a string of length from 3 to 10)
//Example: T00112233445 T001234002 2000 08:36:25 BIDV (at the ATM BIDV, account T00112233445 transfers 2000$ to account T001234002 at time point 08:36:25 (08 hour, 36 minutes, 25 seconds)
//A transaction cycle of length k starting from account a1 is defined to be a sequence of distinct account a1, a2, …, ak  in which there are transactions from account a1 to a2, from a2 to a3, …, from ak to a1->
//Write a program that process the following queries:
//?number_transactions: compute the total number of transactions of the data
//?total_money_transaction: compute the total amount of money of transactions
//?list_sorted_accounts: compute the sequence of bank accounts (including sending and receiving accounts) appearing in the transaction (sorted in an increasing (alphabetical) order)
//?total_money_transaction_from <account>: compute the total amount of money transferred from the account <account>
//?inspect_cycle <account> k : return 1 if there is a transaction cycle of length k, starting from <account>, and return 0, otherwise
//Input (stdin)
//The input consists of 2 blocks of information: the data block and the query block
//•	The data block consists of lines:
//o	Each line contains the information about a transaction described above
//o	The data is terminated by a line containing #
//•	The query block consists of lines:
//o	Each line is a query described above
//o	The query block is terminated by a line containing #
//
//Output (stdout)
//•	Print to stdout (in each line) the result of each query described above
//
//Example
//Input
//T000010010 T000010020 1000 10:20:30 ATM1
//T000010010 T000010030 2000 10:02:30 ATM2
//T000010010 T000010040 1500 09:23:30 ATM1
//T000010020 T000010030 3000 08:20:31 ATM1
//T000010030 T000010010 4000 12:40:00 ATM2
//T000010040 T000010010 2000 10:30:00 ATM1
//T000010020 T000010040 3000 08:20:31 ATM1
//T000010040 T000010030 2000 11:30:00 ATM1
//T000010040 T000010030 1000 18:30:00 ATM1
//#
//?number_transactions
//?total_money_transaction
//?list_sorted_accounts
//?total_money_transaction_from T000010010
//?inspect_cycle T000010010 3
//#
//Output
//9
//19500
//T000010010 T000010020 T000010030 T000010040
//4500
//1

#include "bits/stdc++.h"
using namespace std;


int MaptoNum(string& s){
return (s[8]-'0')*10+s[9]-'0';
}
vector<int> adj[99];
bool vistited[99];
vector<int> x;// Lưu vị trí các bước đi qua
int dist;
bool TRY(int u, int k){

    if(k==1) {
        for(auto v : adj[u]){
            if(v==dist) {
                x.push_back(v);
                return true;
            }
        }
    }
    else {
        for(auto v : adj[u]){
            // if(v!=u && v!=dist && TRY(v,k-1)) {
            //     x.push_back(v);
            //     return true;
            // }

            if(!vistited[v] && v!=dist){
                vistited[v] = true;
                if(TRY(v,k-1)) return true;
                vistited[v] = false;
            }
        }
    }
    return false;
}
int main(){

    map<string,int> checksdt;
    map<string,int> tienGDtu;
    int soGD=0, tongtiengd=0;
    string s;
    string fa, ta, tmp;
    int money;


    while(cin >> s){
        if(s == "#") break;
        fa = s;
        cin >> ta >>money>>tmp>>tmp;

        if(checksdt[fa] == 0) {
                checksdt[fa]=1;
                }

        if(checksdt[ta] == 0) {
                checksdt[ta]=1;
        }

        adj[MaptoNum(fa)].push_back(MaptoNum(ta));


        tienGDtu[fa]+=money;
        soGD++;
        tongtiengd += money;

    }

    while(cin >> s){
        if(s == "#") break;
        if(s == "?number_transactions") {
            cout << soGD <<endl;
            continue;
        }
        if(s == "?total_money_transaction"){
            cout << tongtiengd <<endl;
            continue;
        }
        if(s == "?list_sorted_accounts"){
            vector<string> v;
            for(auto p : checksdt){
                v.push_back(p.first);
            }
            sort(v.begin(),v.end(), [](const string& a, const string& b){
                 return a.compare(b)<0;
                 });
            for(string str : v){
                cout << str << " ";
            }
            cout << endl;

            continue;
        }
        if(s == "?total_money_transaction_from"){
            cin >> tmp;
            cout << tienGDtu[tmp] <<endl;
            continue;
        }
        if(s == "?inspect_cycle"){
            int k;
            cin >> fa >> k;
            dist = MaptoNum(fa);

            for(int i=0;i<99;i++) vistited[i] = false;
            cout << TRY(dist,k) <<endl;

            // if(TRY(dist,k)) {
            //     reverse(x.begin(), x.end());
            //     for(auto v : x) {
            //         cout << v <<"->";
            //     }
            //     cout << endl;
            // }
            continue;
        }

    }

    return 0;
    }
