#include <iostream>
#include <memory>

class Singleton
{
public:
    static Singleton geteInstance();
    void doSomething();
    ~Singleton() {}
private:
    Singleton() {}
};

Singleton Singleton::geteInstance()
{
    // Thread-safe, since it is guaranteed that this will be be executed
    // exactly once.
    static Singleton instance;
    return instance;
}

void Singleton::doSomething()
{
    std::cout << "I'm doing something..." << this << std::endl;
}

int main()
{
    auto s = Singleton::geteInstance();
    s.doSomething();
    s = Singleton::geteInstance();
    s.doSomething();

    return 0;
}
