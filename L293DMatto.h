#ifndef L293DMatto_h
#define L293DMatto_h

#include "Arduino.h"

class L293DMatto {
  public:
    L293DMatto(int enable, int dirA, int dirB);
    L293DMatto(int enable, int pin);
    void setMin(int min);
    void setVel(int vel);
    void setDir(bool dir);
    void setVelPerc(int vel);
    void setVelRaw(int vel);
    int getVel();
    bool getDir();
  private:
    void init(int enable, int dirA, int dirB);
    int enable;
    int dirA;
    int dirB;
    int vel;
    bool dir;
    int min;
};

#endif
