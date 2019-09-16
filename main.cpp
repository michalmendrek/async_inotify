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


int main()
{

notify plik("./");
plik.AddFileName("plik.log");
plik.AddFileName("plik1.log");

while(1)
{


}

}

