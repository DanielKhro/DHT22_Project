/**
* @file DHT_22.h
*
*	@brief Header file for the DHT_22 sensor driver.
*
*	This file contains the function definitions and any extra parameters such as constants
* used to develop the sensor data and read this data
*	
*
* @author Daniel Khrlobian
*/
#include <stdint.h>
void DHT22_Init(void);
void DHT22_Read(float *temp, float *hum);
void Execute_Selection(void);
