#include <omp.h>
#include <iostream>

int main()
{
    std::cout<<omp_get_max_threads()<<std::endl;
    std::cout<<omp_get_num_threads()<<std::endl;
    bool parallelism=true;
    int j=0;
    #pragma omp parallel for if(parallelism)
    for(int i=0;i<10;i++)
    {
        j+=i;
        std::cout<<i<<" ";
    }
    std::cout<<std::endl<<"Summary:"<<j<<std::endl;
    return EXIT_SUCCESS;
}