//Description
//CITIZEN
//Given a DataBase about citizen, perform queries over this DataBase.
//Input
//The input consists of two blocks: the first block is the DataBase and the second block is the list of queries. Two blocks are separated by a line containing a character *.
//1. The first block (DataBase about citizen) consists of lines (number of lines can be upto 100000), each line is the information about a person and is under the format:
//                                   <code>  <dat_of_birth>  <fathher_code>   <mother_code>  <is_alive>  <region_code>
//in which:
// <code>: the code of the person which is a string of length 7
// <date_of_birth>: the date of birth of the person and has the format YYYY-MM-DD (for example 1980-02-23), <date_of_birth> is before 3000-12-31
// <fathher_code> and <mother_code> is the code of father and mother: they are also strings of length 7. If the code is 0000000, then the current person does not has information about his father or mother
// <is_alive>: a character with two values: �Y� means that the person is still alive, and �N� means tat the current person is died.
// <region_code>: the code of the region where the person lives
//
//2. The second block is the list of queries (number of queries can be upto 100000) over the DataBase which consists of following commands:
// NUMBER_PEOPLE: return the number of people (number of lines of the DataBase)
// NUMBER_PEOPLE_BORN_AT <date>: return the number of people having date-of-birth is equal to <date>
// MOST_ALIVE_ANCESTOR <code>: find the most ancestor (farthest in term of generation distance) of the given person <code>. Return the generation distance between the ancestor found and the given person
// NUMBER_PEOPLE_BORN_BETWEEN <from_date> <to_date>: compute the number of people having date-of-birth between <from_date> and <to_date> (<from_date> and <to_date> are under the form YYYY-MM-DD, <to_date> is before 3000-12-31)
// MAX_UNRELATED_PEOPLE: find a subset of people in which two any people of the subset do not have father/mother-children and the size of the subset is maximal. Return the size of the subset found.
//The second block is terminated by a line containing ***.
//Output
// Each line presents the result of the corresponding query (described above).
//Example
//Input
//0000001 1920-08-10 0000000 0000000 Y 00002
//0000002 1920-11-03 0000000 0000000 Y 00003
//0000003 1948-02-13 0000001 0000002 Y 00005
//0000004 1946-01-16 0000001 0000002 Y 00005
//0000005 1920-11-27 0000000 0000000 Y 00005
//0000006 1920-02-29 0000000 0000000 Y 00004
//0000007 1948-07-18 0000005 0000006 Y 00005
//0000008 1948-07-18 0000005 0000006 Y 00002
//0000009 1920-03-09 0000000 0000000 Y 00005
//0000010 1920-10-16 0000000 0000000 Y 00005
//*
//NUMBER_PEOPLE
//NUMBER_PEOPLE_BORN_AT 1919-12-10
//NUMBER_PEOPLE_BORN_AT 1948-07-18
//MAX_UNRELATED_PEOPLE
//MOST_ALIVE_ANCESTOR 0000008
//MOST_ALIVE_ANCESTOR 0000001
//NUMBER_PEOPLE_BORN_BETWEEN 1900-12-19 1928-11-16
//NUMBER_PEOPLE_BORN_BETWEEN 1944-08-13 1977-12-15
//NUMBER_PEOPLE_BORN_BETWEEN 1987-01-24 1988-06-03
//***
//Output
//10
//0
//2
//6
//1
//0
//6
//4
//0
#include "bits/stdc++.h"
using namespace std;

    map<string, tuple<string, string, char>> code_to_father_mother_alive;
int dateToInt(string& s){
 int y = 1000*(s[0]-'0')+100*(s[1]-'0')+10*(s[2]-'0')+s[3]-'0';
 int m = 10*(s[5]-'0')+s[6]-'0';
 int d = 10*(s[8]-'0')+s[9]-'0';
 return  (y-1900)*365+m*31+d;
}

int findAliveAncestor(string code, int generationDistance){
    if(code=="0000000" || get<2>(code_to_father_mother_alive[code]) == 'N') return generationDistance-1;

    int t1 = findAliveAncestor(get<0>(code_to_father_mother_alive[code]), generationDistance+1);
    int t2 = findAliveAncestor(get<1>(code_to_father_mother_alive[code]), generationDistance+1);
    return max(t1,t2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string code, dat_of_birth, father_code, mother_code, region_code;
    char is_alive;

    int numberPeople = 0;
    map<string, int> number_people_born_at;
    int number_people_born_until[40000];


    for(int i=0;i<40000;i++) number_people_born_until[i] = 0;
    while(cin >> code ){
        if(code == "*") break;
        cin >> dat_of_birth >> father_code >> mother_code >> is_alive >> region_code;

        numberPeople++;
        number_people_born_at[dat_of_birth]++;
        number_people_born_until[dateToInt(dat_of_birth)] ++;
//        father_code_of[code] = father_code;
//        mother_code_of[code] = mother_code;
        code_to_father_mother_alive[code] = make_tuple(father_code, mother_code, is_alive);

    }
    for(int i=1;i<40000;i++){
        number_people_born_until[i] += number_people_born_until[i-1];
    }

    string q;
    while(cin >> q){
        if(q == "***") break;
        if(q == "NUMBER_PEOPLE"){
            cout << numberPeople <<endl;
            continue;
        }
        if(q=="NUMBER_PEOPLE_BORN_AT"){
            cin >> dat_of_birth;
            cout << number_people_born_at[dat_of_birth]<<endl;
            continue;
        }
        if(q=="MOST_ALIVE_ANCESTOR"){
            cin >> code;
            cout << findAliveAncestor(code, 0) <<endl;
            continue;
        }
        if(q=="NUMBER_PEOPLE_BORN_BETWEEN"){
            string from_date, to_date;
            cin >> from_date >>to_date;
            cout << number_people_born_until[dateToInt(to_date)] - number_people_born_until[dateToInt(from_date)-1] <<endl;
            continue;
        }
        if(q=="MAX_UNRELATED_PEOPLE"){


            continue;
        }
    }




    return 0;
}
