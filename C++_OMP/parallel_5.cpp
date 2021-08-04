#include <iostream>

int main()
{
    int n=100;
    #pragma omp parallel for private(n)
    for(n=1;n<9;n++)
    {
        std::cout<<n<<std::endl;
    }
    std::cout<<"N:"<<n<<std::endl;
}