#ifndef NOTIFICATION
#define NOTIFICATION
#include <iostream>
#include <string>
#include <limits.h>
#include <signal.h>
#include <functional>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/inotify.h>
#include <vector>


#define BUF_LEN (10 * (sizeof (struct inotify_event) + NAME_MAX +1))

class notify
{

private:

  std::vector<std::string> File;

  int inotifyFD;
  int inotifyWD;
  struct sigaction sig_a;
  std::function<void(int)> callback;
  char buff[BUF_LEN];
  char *p;
  struct  inotify_event *event;
  ssize_t numRead;
  void handler(int sig);
public:
  notify(std::string LogDir);
 ~notify();
  void AddFileName(std::string FileName);


};


#endif
