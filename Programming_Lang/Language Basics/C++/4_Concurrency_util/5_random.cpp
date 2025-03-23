#include <random>
    //default_random_engine
    //uniform_int_distribution
#include <functional>
    //bind()
using namespace std;
/*
A random no generator consists of 2 parts
1. An engine (that generates random number)
2. A distribution (that maps those values into a mathematical distribution in a range)
*/

class Rand_int
{
    private:
        default_random_engine re;
        uniform_int_distribution<> dist;
    public:
        Rand_int(int low,int high): dist{low,high} {}
        int operator()(){return dist(re);}      //same as bind(dist,re)
};

int main()
{
    using my_engine = default_random_engine;
    using my_distribution = uniform_int_distribution<>;
    my_engine re{};
    my_distribution one_six {1,6};
    auto die = bind(one_six,re);

    int x = die();

    auto die2 = bind(normal_distribution<>{1,10},default_random_engine{});

    Rand_int rnd{1,10};
    int y = rnd();
    return x;
}