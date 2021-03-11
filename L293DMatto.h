#ifndef L293DMatto_h
#define L293DMatto_h

#include "Arduino.h"

class L293DMatto {
  public:
    L293DMatto(int enable, int dirA, int dirB);
    L293DMatto(int enable, int pin); //Motore unidirezionale, consente di controllare fino a 4 motori con un solo driver. dirB sarà settato a 0
    void setMin(int min); //Setta velocità minima
    void setVel(int vel); //Setta la velocità tenendo conto del minimo in una funzione map
    void setDir(bool dir);
    void setVelPerc(int vel); //Setta la velocità in percentuale
    void setVelRaw(int vel); //Setta la velocità senza tenere conto del minimo
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
