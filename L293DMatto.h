#ifndef L293DMatto_h
#define L293DMatto_h

#include "Arduino.h"

class L293DMatto {
  public:
    L293DMatto(int enable, int dirA, int dirB);
    void setVel(int vel);
    void setDir(bool dir);
    void setDir(int dir);
    void setAll(int veldir);
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
