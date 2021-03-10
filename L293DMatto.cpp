#include "L293DMatto.h"

L293DMatto::L293DMatto(int enable, int dirA, int dirB) {
  this->enable = enable;
  this->dirA = dirA;
  this->dirB = dirB;
  pinMode(enable, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  setDir(true);
  setVel(0);
}

void L293DMatto::setDir(bool dir) {
  this->dir = dir;
  digitalWrite(dirA, dir);
  digitalWrite(dirB, !dir);
}

void L293DMatto::setDir(int dir) {
  this->setDir(dir >= 0);
}

bool L293DMatto::getDir() {
  return this->dir;
}

void L293DMatto::setVel(int vel) {
  if (vel<=255 && vel>=0) {
    this->vel = vel;
    analogWrite(this->enable, vel);
  }
}

void L293DMatto::setVelPerc(int vel) {
  int newVel = map(vel, 0, 100, 0, 255);
  this->setVel(newVel);
}

int L293DMatto::getVel() {
  return this->vel;
}

