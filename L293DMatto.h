#ifndef L293DMatto_h
#define L293DMatto_h

#include "Arduino.h"

class L293DMatto {
  public:
    L293DMatto(int enable, int positivo, int negativo);
    void setVel(int vel);
    void setDir(bool dir);
    int getVel();
    bool getDir();
  private:
    int enable;
    int positivo;
    int negativo;
    int vel;
    int dir
};

#endif
