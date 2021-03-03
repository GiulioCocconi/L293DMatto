#include "L293DMatto.h"

L293DMatto::L293DMatto(int enable, int dirA, int dirB) {
  this->enable = enable;
  this->dirA = dirA;
  this->dirB = dirB;
  pinMode(enable, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  setDir(true);
  setVel(127); //Metà della velocità massima
}

void L293DMatto::setDir(bool dir) {
  this->dir = dir;
  digitalWrite(dirA, dir);
  digitalWrite(dirB, !dir);
}

void L293DMatto::setDir(int dir) {
  this->dir = (dir >= 0);
  digitalWrite(dirA, this->dir);
  digitalWrite(dirB, !(this->dir));
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

void L293DMatto::setAll(int velDir) {
  this->setVel(abs(velDir));
  this->setDir(veldir >= 0);
}
