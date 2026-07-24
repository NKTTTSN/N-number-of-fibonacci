#include <iostream>
#include <vector>
#include <cstdint>
#include "myvector.h"

using namespace std;

class LongInt
{

public:
    List<uint32_t> d;
    LongInt(uint32_t a) 
    {
        d.push_back(a);
    }
    

};

void print_res(LongInt&res) 
{

    for(int c = res.d.GetSize()-1; c >= 0; c--) 
    {
        cout << res.d[c];
    }
    cout << endl;
}

void add(LongInt&a, LongInt&b, LongInt&r)
{
    r.d.clearall();
    uint32_t tmp = 0;

    for(int i = 0; i < max(a.d.GetSize(), b.d.GetSize());i++)
    {


        uint32_t x = (i < a.d.GetSize()) ? a.d[i] : 0;
        uint32_t y = (i < b.d.GetSize()) ? b.d[i] : 0;
        
       
        uint32_t sum = x + y + tmp;
        
        
        
        r.d.push_back(sum % 10);
        tmp = sum / 10;

        //tmp = (sum < 10)? 0:1;


    }
     if (tmp > 0) 
    {
        r.d.push_back(tmp);
    }


}

void print_fib(int n)
{

    
    LongInt last{0};
    LongInt pre_last{1};
    
    LongInt result{0};
    for (int i = 2; i <= n; i++) 
    {
        add(last, pre_last,result);
        last = pre_last;
        pre_last = result;
    }
    print_res(result);
    
}

int main() {
    for(int i = 0; i < 101;i++) {
        print_fib(i);
        cout <<'\n';
    }
    return 0;

} 