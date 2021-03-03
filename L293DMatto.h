#ifndef L293DMatto_h
#define L293DMatto_h

#include "Arduino.h"

class L293DMatto {
  public:
    L293DMatto(int enable, int dirA, int dirB);
    void setVel(int vel);
    void setDir(bool dir);
    int setDir(int dir);
    int getVel();
    bool getDir();
  private:
    int enable;
    int dirA;
    int dirB;
    int vel;
    bool dir;
};

#endif
