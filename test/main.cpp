#include <signal.h>
#include <functional>

std::function<void(int)> callback_wrapper;
void callback_function(int value)
{
  callback_wrapper(value);
}

class Foo {
public:
  void catch_signal(int) {}
};

int main(int argc, char** argv)
{
    Foo foo;

    // deprecated since C++-11
    callback_wrapper = std::bind1st(std::mem_fun(&Foo::catch_signal),
                                    &foo);
    // or
    callback_wrapper = std::bind(&Foo::catch_signal,
                                 &foo,
                                 std::placeholders::_1);

    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = callback_function;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGTERM, &sigIntHandler, NULL);
}
