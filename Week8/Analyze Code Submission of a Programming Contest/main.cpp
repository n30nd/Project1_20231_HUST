//Description
//Data about submission of a programming contest consists a sequence of lines, each line has the following information:
//                                                      <UserID> <ProblemID> <TimePoint> <Status> <Point>
//in which the user <UserID> submits his/her code to solve the problem <ProblemID> at time-point <TimePoint>, and gets status <Status> and point <Point>
//<UserID>: string of length from 3 to 10
//<ProblemID>: string under the format Pxy where x, y are digits 0,1,...,9 (for example P03, P10)
//<TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)
//<Status>: string with two cases (ERR, OK)
//<Point>: integer from {0, 1, 2, ..., 10}
//
//A user can submit the code for solving each problem several time. The point that the user gets for a problem is the maximal point among the submissions for that problem.
//
//Perform a sequence of queries of following types:
//?total_number_submissions: return the number of submissions of the contest
//?number_error_submision: return the number of submissions having status ERR
//?number_error_submision_of_user <UserID>: return the number of submission having status ERR of user <UserID>
//?total_point_of_user <UserID>: return the total point of user <UserID>
//?number_submission_period <from_time_point> <to_time_point>: return the number of submissions in the period from <from_time_point> to <to_time_point> (inclusive)
//
//Input
//The input consists of two blocks of data:
//The first block is the operational data, which is a sequence of lines (number of lines can be up to 100000), each line contains the information of a submission with above format .The first block is terminated with a line containing the character #
//The second block is the query block, which is a sequence of lines (number of lines can be up to 100000), each line is a query described above. The second block is terminated with a line containing the character #
//
//Output
//Write in each line, the result of the corresponding query
//
//Example
//Input
//U001 P01 10:30:20 ERR 0
//U001 P01 10:35:20 OK 10
//U001 P02 10:40:20 ERR 0
//U001 P02 10:55:20 OK 7
//U002 P01 10:40:20 ERR 0
//U001 P01 11:35:20 OK 8
//U002 P02 10:40:20 OK 10
//#
//?total_number_submissions
//?number_error_submision
//?number_error_submision_of_user U002
//?total_point_of_user U001
//?number_submission_period 10:00:00 11:30:45
//#
//
//
//Output
//7
//3
//1
//17
//6
#include"bits/stdc++.h"
using namespace std;
int timeToS(string &t){
    int h = 10*(t[0]-'0')+t[1]-'0';
    int m = 10*(t[3]-'0')+t[4]-'0';
    int s = 10*(t[6]-'0')+t[7]-'0';
    return h*3600+m*60+s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string userID, problemID, timePoint, status;
    int point;
    int total_number_submision = 0, number_error_submision =0;
    map<string, int> number_error_s_of_user;
    map<string, int> total_point_of_user;
    map<pair<string, string>, int> point_userID_pId;
    int number_sub_until_time[86400];
    for(int i=0;i<86400;i++) number_sub_until_time[i] = 0;

    while(cin >> userID){
        if(userID == "#") break;
        cin >> problemID >> timePoint >> status >> point;

        total_number_submision++;
        if(status == "ERR") {
            number_error_submision++;
            number_error_s_of_user[userID] ++;
        }
        if(point > point_userID_pId[{userID, problemID}]){
            total_point_of_user[userID] += point - point_userID_pId[{userID, problemID}];
            point_userID_pId[{userID, problemID}] = point;
        }
        number_sub_until_time[timeToS(timePoint)]++;
    }
    for(int i=1;i<86400;i++){
        number_sub_until_time[i] += number_sub_until_time[i-1];
    }
    string q;
    while(cin >> q){
        if(q == "?total_number_submissions"){
            cout << total_number_submision <<endl;
            continue;
        }
        if(q == "?number_error_submision"){
            cout << number_error_submision <<endl;
            continue;
        }
        if(q == "?number_error_submision_of_user"){
            cin >> userID;
            cout << number_error_s_of_user[userID]<<endl;
            continue;
        }
        if(q == "?total_point_of_user"){
            cin >> userID;
            cout << total_point_of_user[userID] <<endl;
            continue;
        }
        if(q == "?number_submission_period"){
            string t1, t2;
            cin >> t1 >> t2;
            cout << number_sub_until_time[timeToS(t2)] - number_sub_until_time[timeToS(t1)-1] <<endl;
            continue;
        }

    }
    return 0;
}
