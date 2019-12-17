#include <iostream>
#include <stdlib.h>

using namespace std;

// @ret: 0-ok, !0-not symmetry num
int is_symmetry_num( unsigned int num )
{
    int str[11] = {0};
    int num_len = 0;
    int ret = 0;
    // itoa
    for( int i=0; i<11; ++i )
    {
        str[i] = num%10;
        num /= 10;
        num_len++;
        if ( num==0 ) break;
    }
    for( int i=0; i<num_len; ++i )
    {
        cout << str[i] << " ";
    }
    cout << endl;
    // check symmetry
    for( int i=0; i<num_len; ++i )
    {
        if ( i>num_len/2 ) break;
        if ( str[i] != str[num_len-i-1] )
        {
            ret = -1;
            break;
        }
    }
    return ret;
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    if ( argc <2 ) { cout << "usage: ./symmetry num" << endl; return -1;}
    // 此处atoi仅为方便测试用，跟算法本身的实现无关
    unsigned int num = atoi(argv[1]);
    cout << "check num: " << num << ", ret:" <<  is_symmetry_num(num) << endl;
    return 0; 
}
