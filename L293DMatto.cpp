#include "L293DMatto.h"

L293DMatto::L293DMatto(int enable, int dirA, int dirB) {
  this->init(enable, dirA, dirB);
}


L293DMatto::L293DMatto(int enable, int pin) {
  this->init(enable, pin, -1);
}


void L293DMatto::init(int enable, int dirA, int dirB) {
  this->enable = enable;
  this->dirA = dirA;
  this->dirB = dirB;
  this->min = 0;
  pinMode(enable, OUTPUT);
  pinMode(dirA, OUTPUT);
  
  if (dirB != -1) {
    pinMode(dirB, OUTPUT);
  }
  
  setDir(true);
  setVel(0);
}

void L293DMatto::setMin(int min) {
  this->min = min
}

void L293DMatto::setDir(bool dir) {
  if (dirB != -1) {
    this->dir = dir;
    digitalWrite(dirA, dir);
    digitalWrite(dirB, !dir);
  }
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
  if (vel == 0) {
    this->setVelRaw(0);
    return;
  }
  vel = map(vel, 0, 255, this->min, 255);
  this->setVelRaw(vel);
}

void L293DMatto::setVelPerc(int vel) {
  vel = map(vel, 0, 100, 0, 255);
  this->setVel(vel);
}

int L293DMatto::getVel() {
  return this->vel;
}

