#include "L293DMatto.h"

L293DMatto::L293DMatto(int enable, int dirA, int dirB) {
  this->enable = enable;
  this->dirA = dirA;
  this->dirB = dirB;
  pinMode(enable, OUTPUT);
  pinMode(positivo, OUTPUT);
  pinMode(negativo, OUTPUT);
  setDir(true);
  setVel(127); //Metà della velocità massima
}

void L293DMatto::setDir(bool dir) {
  this->dir = dir;
  digitalWrite(dirA, dir);
  digitalWrite(dirB, !dir);
}

bool L293DMatto::getDir() {
  return this->dir;
}

void L293DMatto::setVel(int vel) {
  this->vel = vel
  analogWrite(this->enable, vel);
}

int L293DMatto::getVel() {
  return this->vel;
}
