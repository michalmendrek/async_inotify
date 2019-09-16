#include <notification.h>
#include <limits.h>
#include <sys/inotify.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <functional>


std::function<void(int)> callback_wrapper;
void callback_function(int sig)
{
  callback_wrapper(sig);
}




notify::notify(std::string LogDir)
{
  std::string File=LogDir;
  inotifyFD=inotify_init();
  if(inotifyFD == -1) {}
  inotifyWD = inotify_add_watch(inotifyFD,File.c_str(),IN_CLOSE_WRITE);
  if(inotifyWD == -1) {}
  callback_wrapper = std::bind1st(std::mem_fun(&notify::handler), this);
  sig_a.sa_handler=callback_function;
  sigemptyset(&sig_a.sa_mask);
  sig_a.sa_flags=0;
  sigaction(SIGIO, &sig_a, NULL);
  fcntl(inotifyFD,F_SETFL,O_ASYNC);
  fcntl(inotifyFD,F_SETOWN,getpid());


}


notify::~notify()
{

}


void notify::handler(int sig)
{

  numRead = read(inotifyFD, buff, BUF_LEN);
  if(numRead > 0){

  for(p = buff; p < buff + numRead;)
  {
   event = (struct inotify_event *) p;
   if(event->len >0){
   for(auto it:File)
   {
    if(event->name  == std::get<0>(it))
    {
      //auto ptr = 
      std::get<1>(it)();
      //ptr();
     std::cout << event->name << std::endl;
    }
   }
   }
   p+= sizeof(struct inotify_event) + event->len;
  }
  }


}


void notify::AddFileName(std::string FileName, std::function<void()> func)
{
 File.push_back(std::make_tuple(FileName,func));
}
