#include <iostream>
#include <random>
#include <chrono>
#include <thread>

std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    const int tablesize=120;
    int *board=new int[tablesize];
    auto initializer=std::uniform_int_distribution<int>(0,1000);

    auto start_timer=std::chrono::high_resolution_clock::now();
    #pragma omp parallel for
    for(int i=0;i<tablesize;i++)
    {
        board[i]=initializer(mt);
        std::cout<<"Thread "<<std::this_thread::get_id()<<" initializes board["<<i<<"]="<<board[i]<<std::endl;
    }
    auto end_timer=std::chrono::high_resolution_clock::now();
    std::cout<<"Lapsed Time:"<<std::chrono::duration_cast<std::chrono::milliseconds>(end_timer-start_timer).count()<<" \'ms"<<std::endl;
    return 0;
}