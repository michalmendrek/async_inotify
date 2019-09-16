#ifndef NOTIFICATION
#define NOTIFICATION
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <functional>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

class notify {
 private:
  std::vector<std::tuple<std::string, std::function<void()>>> File;

  int inotifyFD;
  int inotifyWD;
  struct sigaction sig_a;
  std::function<void(int)> callback;
  char buff[BUF_LEN];
  char *p;
  struct inotify_event *event;
  ssize_t numRead;
  void handler(int sig);

 public:
  notify(std::string LogDir);
  ~notify();
  void AddFileName(std::string FileName, std::function<void()> func=nullptr);
};

#endif
