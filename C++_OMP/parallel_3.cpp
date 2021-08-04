#include <iostream>
#include <random>
#include <chrono>

std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{ 
    auto init=std::uniform_int_distribution<int>(0,100);
    int s=0;
    #pragma omp parallel
    {
        for(int i=0;i<10;i++)
        {
            s+=init(mt);
        }    
    }
    printf("S=%d\n",s);
}