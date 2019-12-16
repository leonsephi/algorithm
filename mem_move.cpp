#include <iostream>

using namespace std;

int _mem_move( char* dst, char* src, size_t len )
{
    int ret_len = 0;

    if ( !dst || !src ) { return len; }

    if ( src + len < dst )
    {
        ret_len = len;
        for( int i=0; i<len; ++i )
        {
            *(dst+i) = *(src+i);
        }
    }
    else
    {
        ret_len = (dst>src)?(dst-src):(src-dst);
        for( int i=0; i<ret_len; ++i )
        {
            *(dst+i) = *(src+i);
        }
    }

    return ret_len;
}

int main()
{
    char test1[21] = "1234567890abcdefghij";
    char test2[21] = "1234567890abcdefghij";
    cout << test1 << endl;
    cout << "memmove: " << _mem_move( test1+10, test1, 5 ) << " :" << test1 << endl;
    cout << test2 << endl;
    cout << "memmove: " << _mem_move( test2, test2+2, 5 ) << " :" << test2 << endl;
    return 0;
}
