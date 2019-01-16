
class MPU9250Multi {
public:
  MPU9250Multi(unsigned char i2cbus = 0, unsigned char multiplexer_addr = 0x70, unsigned char mpu_addr = 0x68);

  // set range of IMU's by bitmask
  void setRange(char mask);

  // set range of IMU's via count
  void setRange(unsigned char ct, unsigned char offset = 0);

  int selectMask(char mask);
  int selectId(unsigned char id);

  void enableAccel();
  void enableGyro();

private:
  // writes to MPUs, whatever was selected last
  int writeI2C(void* buffer, int length);

  unsigned char i2cbus;
  unsigned char multiplexer_addr;
  unsigned char mpu_addr;

  int fd;
};
