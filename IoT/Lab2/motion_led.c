/*
	MPU6050 Interfacing with Raspberry Pi
	http://www.electronicwings.com
*/

#include <wiringPiI2C.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <wiringPi.h>

#define Device_Address 0x68	/*Device Address/Identifier for MPU6050*/

#define PWR_MGMT_1   0x6B
#define SMPLRT_DIV   0x19
#define CONFIG       0x1A
#define GYRO_CONFIG  0x1B
#define INT_ENABLE   0x38
#define ACCEL_XOUT_H 0x3B
#define ACCEL_YOUT_H 0x3D
#define ACCEL_ZOUT_H 0x3F
#define GYRO_XOUT_H  0x43
#define GYRO_YOUT_H  0x45
#define GYRO_ZOUT_H  0x47

int fd;

int LED = 0;
int BUTTON = 2;
bool lastLedState = LOW;
int count = 0;
int Delay;

void MPU6050_Init(){
	
	wiringPiI2CWriteReg8 (fd, SMPLRT_DIV, 0x07);	/* Write to sample rate register */
	wiringPiI2CWriteReg8 (fd, PWR_MGMT_1, 0x01);	/* Write to power management register */
	wiringPiI2CWriteReg8 (fd, CONFIG, 0);		/* Write to Configuration register */
	wiringPiI2CWriteReg8 (fd, GYRO_CONFIG, 24);	/* Write to Gyro Configuration register */
	wiringPiI2CWriteReg8 (fd, INT_ENABLE, 0x01);	/*Write to interrupt enable register */

	} 
short read_raw_data(int addr){
	short high_byte,low_byte,value;
	high_byte = wiringPiI2CReadReg8(fd, addr);
	low_byte = wiringPiI2CReadReg8(fd, addr+1);
	value = (high_byte << 8) | low_byte;
	return value;
}

void ms_delay(int val){
	int i,j;
	for(i=0;i<=val;i++)
		for(j=0;j<1200;j++);
}

void blink() {
    
}

int main(){
	
	float Acc_x,Acc_y,Acc_z;
	float Gyro_x,Gyro_y,Gyro_z;
	float Ax=0, Ay=0, Az=0;
	float Gx=0, Gy=0, Gz=0;
	fd = wiringPiI2CSetup(Device_Address);   /*Initializes I2C with device Address*/
	MPU6050_Init();		                 /* Initializes MPU6050 */

    wiringPiSetup();
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT);
    while (1) {
        Delay = 1000;
        Acc_x = read_raw_data(ACCEL_XOUT_H);
        Acc_y = read_raw_data(ACCEL_YOUT_H);
        Acc_z = read_raw_data(ACCEL_ZOUT_H);
        
        Gyro_x = read_raw_data(GYRO_XOUT_H);
        Gyro_y = read_raw_data(GYRO_YOUT_H);
        Gyro_z = read_raw_data(GYRO_ZOUT_H);
        
        /* Divide raw value by sensitivity scale factor */
        Ax = Acc_x/16384.0;
        Ay = Acc_y/16384.0;
        Az = Acc_z/16384.0;
        
        Gx = Gyro_x/131;
        Gy = Gyro_y/131;
        Gz = Gyro_z/131;
        printf("\n Gx=%.3f °/s\tGy=%.3f °/s\tGz=%.3f °/s\tAx=%.3f g\tAy=%.3f g\tAz=%.3f g\n",Gx,Gy,Gz,Ax,Ay,Az);
        if(Ax > 1.0 || Ay > 1.0 || Az > 1.0 || Gx > 1.0 || Gy > 1.0 || Gz > 1.0 || Ax < -1.0 || Ay < -1.0 || Az < -1.0 || Gx < -1.0 || Gy < -1.0 || Gz < -1.0) {
            count = count+1;
            printf("Shaking Seconds Count: %d\n", count);
            if (count >= 5) {
                printf("Blinking\n");
                int blinkInterval = 100;
                int elapsed = 0;
                while (elapsed < 2000) {
                    digitalWrite(LED, HIGH);
                    delay(blinkInterval);
                    digitalWrite(LED, LOW);
                    delay(blinkInterval);
                    elapsed += 2 * blinkInterval;
                }
                count = 0;
            } else {
                printf("Not yet\n");
            }
        }else{
            count = 0;
        }
        digitalWrite(LED, LOW);
        delay(1000);
        
    }
	return 0;
}

