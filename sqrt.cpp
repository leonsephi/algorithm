/*
求sqrt(2)的值,可以输出不同精度的结果
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

ull bit_list[10] = 
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

ull _plevel( ull value, ull precision )
{
	for( int i=1; i<=precision; ++i )
	{
		value *= 10;
	}
	return value;
}

/* only can reach to 9 digit precision */
ull _sqrt_try( ull value, ull precision )
{
    if ( precision>=9 )
    {
        precision=9;
    }
    ull _p = _plevel(1,precision);

    ull add = 1 * _p;
    ull end = add;
    int calc=0;
    for(int i=precision-1;i>=0;i--)
    {
        ull start = end;
        for( int attemp = 0; attemp<=9; ++attemp )
        {
            ++calc;
            add = start + attemp*bit_list[i];
            if( add*add>value*_p*_p )
            {
                break;
            }
            end = add;
        }
    }
    cout << "calc times(_sqrt_try): " << calc << endl;
    
    return end;
}

/* only can reach to 9 digit precision */
ull _sqrt( ull value, ull precision )
{
    if ( precision>=9 )
    {
        precision=9;
    }
	ull target = _plevel( _plevel(value,precision),precision );
	ull result_s = _plevel(1,precision);
	ull result_e = _plevel(value,precision);
	ull temp = result_s;
	ull result = result_s; // init
    int i = 0;
	for( ;; )
	{
        ++i;
		temp = (result_s+result_e)/2;
        ull _result = temp*temp;
		if ( _result > target )
		{
			result_e = temp;
		}
		if ( _result <= target )
		{
			result_s = temp;
            result = temp;
		}
		
        if ( result_e-result_s<=1 )
        {
            break;
        }
		

	}
    cout << "calc times(_sqrt): " << i << endl;
	
	return result;
}

/* reach to 15 digit precision */
double _sqrt_double( ull value, ull precision )
{
    if ( precision>=15 )
    {
        precision=15;
    }
	double target = value;
	double result_s = 1.0;
	double result_e = target;
	double temp = result_s;
	double result = result_s; // init
    int i = 0;
	for( ;; )
	{
        ++i;
		temp = (result_s+result_e)/2;
        double _result = temp*temp;
		if ( _result > target )
		{
			result_e = temp;
		}
		if ( _result <= target )
		{
			result_s = temp;
            result = temp;
		}
		
        // cout << setprecision(precision) << "e:" << result_e*_plevel(1,precision) << ", s:" << result_s*_plevel(1,precision)<<endl;
        /* calc more 1 digit to make sure precision */
        if ( result_e*_plevel(1,precision+1)-result_s*_plevel(1,precision+1)<=1 )
        {
            break;
        }
		

	}
    cout << "calc times(_sqrt): " << i << endl;
	
	return result;
}

int main(int argc, char** argv)
{
    if ( argc<3 )
    {
        cout << "usage: ./sqrt value precision" << endl;
        cout << "for example: ./sqrt 2 10" << endl;
        return 0;
    }
    ull sqrt_value = atoi(argv[1]);
    ull precision = atoi(argv[2]);
    cout << "==>> try to get sqrt(" << sqrt_value << "), precision: " << precision << " nums. <<==" << endl;
    
    cout << "result, " << precision << " nums of sqrt(" << sqrt_value << "):" << _sqrt(sqrt_value,precision) << endl;
    cout << "result, " << precision << " nums of sqrt_for(" << sqrt_value << "):" << _sqrt_try(sqrt_value,precision) << endl;
    cout << "result, " << precision << " nums of sqrt_double(" << sqrt_value << "):" << setprecision(precision>=15?15:precision+2) << _sqrt_double(sqrt_value,precision) << endl;

    return 0;
}
