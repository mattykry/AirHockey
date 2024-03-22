/*MSG.h*/

#ifndef __MSG__
#define __MSG__

class MSG {
  
  public:

  MSG(int content);
  void sendMessage();
  int getMessage();

  private :
  
  int content;
};

#endif
