#include <signal.h>
#include <iostream>
#include <string>



using namespace std;

class notify
{

private:

public:
 std::string name;
 notify(std::string name){
  name=name;
  struct sigaction sig_a;
  sigemptyset(&sig_a.sa_mask);
  //sig_a.sa_handler=handler;
  sig_a.sa_flags=0;
  sigaction(SIGIO, &sig_a, NULL);
  signal(SIGIO,notify::handler);       }
~notify();

 void handler(int sig)
{
  std::cout << "Signal S" << this->name <<std::endl;
}


};



int main()
{
notify eg("aa"), bp("bb");

while(1);


}
