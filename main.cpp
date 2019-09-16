#include <iostream>
#include <sys/inotify.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <notification.h>

using namespace std;


void funkcja1()
{
  std::cout <<"Funkcja jeden" << std::endl;
}

void funkcja2()
{
  std::cout <<"Funkcja dwa" << std::endl;
}


int main()
{

notify plik("./");
plik.AddFileName("plik.log",funkcja1);
plik.AddFileName("plik1.log");

while(1)
{


}

}

