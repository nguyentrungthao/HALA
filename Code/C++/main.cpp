#include <iostream>
#include <thread>

using namespace std;

void delay(int s) {
    for (size_t i = 0; i < 0xffff; i++)
    {
        for (size_t j = 0; j < 5 * s; j++)
        {
        }
    }

}

void funcA(int i, double j) {
    int count = 0;
    while (1)
    {
        count++;
        cout << "funcA: " << count << endl;
        delay(4000);
    }
}

void funcB() {
    int count = 0;
    while (1)
    {
        count++;
        cout << "funcB: " << count << endl;
        delay(1000);
    }
}


int main(int argc, char const* argv[])
{
    thread t1(funcA, 4, 6.5);

    thread t2(funcB);

    t1.join();
    t2.join();


    return 0;
}
