//Problem:
//Description
//Data about sales in an e-commerce company (the e-commerce company has several shops) consists a sequence of lines, each line (represents an order) has the following information:
//            <CustomerID> <ProductID> <Price> <ShopID> <TimePoint>
//in which the customer <CustomerID> buys a product <ProductID> with price <Price> at the shop <ShopID> at the time-point <TimePoint>
//<CustomerID>: string of length from 3 to 10
//<ProductID>: string of length from 3 to 10
//<Price>: a positive integer from 1 to 1000
//<ShopID>: string of length from 3 to 10
//<TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)
//
//
//Perform a sequence of queries of following types:
//?total_number_orders: return the total number of orders
//?total_revenue: return the total revenue the e-commerce company gets
//?revenue_of_shop <ShopID>: return the total revenue the shop <ShopID> gets
//?total_consume_of_customer_shop <CustomerID> <ShopID>: return the total revenue the shop <ShopID> sells products to customer <CustomerID>
//?total_revenue_in_period <from_time> <to_time>: return the total revenue the e-commerce gets of the period from <from_time> to <to_time> (inclusive)
//
//Input
//The input consists of two blocks of data:
//The first block is the operational data, which is a sequence of lines (number of lines can be upto 100000), each line contains the information of a submission with above format
//The first block is terminated with a line containing the character #
//The second block is the query block, which is a sequence of lines (number of lines can be upto 100000), each line is a query described above
//The second block is terminated with a line containing the character #
//
//Output
//Write in each line, the result of the corresponding query
//
//Example
//Input
//C001 P001 10 SHOP001 10:30:10
//C001 P002 30 SHOP001 12:30:10
//C003 P001 40 SHOP002 10:15:20
//C001 P001 80 SHOP002 08:40:10
//C002 P001 130 SHOP001 10:30:10
//C002 P001 160 SHOP003 11:30:20
//#
//?total_number_orders
//?total_revenue
//?revenue_of_shop SHOP001
//?total_consume_of_customer_shop C001 SHOP001
//?total_revenue_in_period 10:00:00 18:40:45
//#
//
//
//Output
//6
//450
//170
//40
//370

#include"bits/stdc++.h"
using namespace std;
int timeToSecond(string& s){
    int h = 10*(s[0]-'0')+s[1]-'0';
    int m = 10*(s[3]-'0')+s[4]-'0';
    int second = 10*(s[6]-'0')+s[7]-'0';
    return h*3600+m*60+second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string customerID, productID, shopID, timeStr;
    int price;
    int totalNumberOrders = 0, totalRevenue = 0;
    map<string, int> revenue_of_shop;
    map<pair<string,string>, int> total_consume_of_customer_shop;
//    map<int, int> revenue_at_time;
    int timeAr[86400];

        for(int i=0;i<86400;i++){
        timeAr[i] = 0;;
    }

    string s;
    while(cin>>customerID){
        if(customerID == "#") break;
        cin >> productID >> price >> shopID >> timeStr;

        totalNumberOrders++;
        totalRevenue += price;
        revenue_of_shop[shopID] += price;
        total_consume_of_customer_shop[{customerID, shopID}] += price;
//        revenue_at_time[timeToSecond(timeStr)] += price;
        timeAr[timeToSecond(timeStr)] += price;
    }

    for(int i=1;i<86400;i++){
        timeAr[i] += timeAr[i-1];
    }

    while(cin >> s){
        if(s == "#") break;
        if(s == "?total_number_orders"){
            cout << totalNumberOrders <<endl;
            continue;
        }
        if(s == "?total_revenue"){
            cout << totalRevenue << endl;
            continue;
        }
        if(s == "?revenue_of_shop"){
            cin >> shopID;
            cout << revenue_of_shop[shopID] <<endl;
            continue;
        }
        if(s == "?total_consume_of_customer_shop"){
            cin >> customerID >> shopID;
            int t = total_consume_of_customer_shop[{customerID, shopID}];
            cout << t <<endl;
            continue;
        }
        if(s == "?total_revenue_in_period"){
            string time1, time2;
            cin >> time1 >>time2;
            int t1 = timeToSecond(time1);
            int t2 = timeToSecond(time2);

            cout << timeAr[t2] - timeAr[t1-1] <<endl;
            continue;
        }
    }
    return 0;

    }
