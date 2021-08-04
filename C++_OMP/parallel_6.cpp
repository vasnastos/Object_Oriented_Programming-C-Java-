#include <iostream>
#include <omp.h>
#include <thread>

void sum(int k)
{
    size_t s=0;
    for(int i=0;i<k;i++)
    {
        s+=k;
    }
    std::cout<<"S-TH"<<std::this_thread::get_id()<<":"<<s<<std::endl;
}

int main()
{
    #pragma omp parallel for
    for(int i=9000;i<10000;i++)
    {
         size_t s=0;
        for(int j=0;j<i;j++)
        {
            s+=j;
        }
        std::cout<<"S-TH"<<std::this_thread::get_id()<<":"<<s<<std::endl;
    }
}
