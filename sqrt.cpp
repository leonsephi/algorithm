/*
已知sqrt(2)约等于1.414，要求不用数学库，求sqrt(2)精确到小数点后10位
*/
#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long long bit_list[10] = 
{
1,
10,
100,
1000,
10000,
100000,
1000000,
10000000,
100000000,
1000000000,
};

int main()
{
    unsigned long long result = 2;
    unsigned long long precision = 10000000000;
    unsigned long long start = 1.414 * precision;

    unsigned long long add = start;
    unsigned long long end = add;
    for(int i=10-3-1;i>=0;i--)
    {
        unsigned long long _start = end;
        for( int attemp = 0; attemp<=9; attemp++ )
        {
            add = _start + attemp*bit_list[i];
            if( add*add>result*precision*precision )
            {
                break;
            }
            end = add;
        }
        
    }
    
    cout << "10 num precision of sqrt(2):" << end << endl;
    return 0;
}
