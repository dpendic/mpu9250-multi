#include "MPU9250Multi.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

MPU9250Multi::MPU9250Multi(unsigned char _i2cbus, unsigned char _multiplexer_addr, unsigned char _mpu_addr) 
  : i2cbus(_i2cbus),
    multiplexer_addr(_multiplexer_addr),
    mpu_addr(_mpu_addr),
    fd(-1) {

  // open file descriptor to i2c
  char filename[] = "/dev/i2c-000";
  const char* num = std::to_string(i2cbus).c_str();

  assert(strnlen(num, 4) < 4);

  strncpy(filename + 9, num, 3);

  fd = open(filename, O_RDWR);

  if(fd < 0) {
    std::cerr << "Failed to open i2c bus" << std::endl;
    exit(EXIT_FAILURE);
  }

  // acquire bus access

  if(ioctl(fd, I2C_SLAVE, multiplexer_addr) < 0) {
    std::cerr << "Failed to acquire bus access to multiplexer" << std::endl;
    exit(EXIT_FAILURE);
  }
}

void MPU9250Multi::setRange(char mask) {

}

void MPU9250Multi::setRange(unsigned char ct, unsigned char offset) {

}

int MPU9250Multi::selectMask(char mask) {
  assert(fd >= 0);

  return write(fd, &mask, 1);
}

int MPU9250Multi::selectId(unsigned char id) {

}


int MPU9250Multi::writeI2C(void* buffer, int length) {

}
