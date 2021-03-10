#include "L293DMatto.h"

L293DMatto::L293DMatto(int enable, int dirA, int dirB) {
  this->enable = enable;
  this->dirA = dirA;
  this->dirB = dirB;
  this->min = 0;
  pinMode(enable, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  setDir(true);
  setVel(0);
}

L293DMatto::L293DMatto(int enable, int dirA, int dirB, int min) {
  this->enable = enable;
  this->dirA = dirA;
  this->dirB = dirB;
  this->min = min;
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

bool L293DMatto::getDir() {
  return this->dir;
}

void L293DMatto::setVelRaw(int vel) {
  if (vel<=255 && vel>=0) {
    this->vel = vel;
    analogWrite(this->enable, vel);
  }
}

void L293DMatto::setVel(int vel) {
  vel = map(vel, 0, 255, this->min, 255);
  this->setVelRaw(vel);
}

void L293DMatto::setVelPerc(int vel) {
  vel = map(vel, 0, 100, this->min, 255);
  this->setVelRaw(vel);
}

int L293DMatto::getVel() {
  return this->vel;
}

