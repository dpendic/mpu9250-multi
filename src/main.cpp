#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include "MPU9250Multi.h"

int file_i2c;

#define MULTIPLEXER_ADDR 0x70

int main(int argc, char* argv[]) {
  MPU9250Multi* mpu_ctrl = new MPU9250Multi(1);
 
  unsigned int selector = 0;
  printf("argc: %d\n", argc);
  if(argc == 2) {
    selector = argv[1][0] - '0';
  }
  unsigned char mask = 1 << selector;
  
  mpu_ctrl->selectMask(mask);

  return 0;
}
