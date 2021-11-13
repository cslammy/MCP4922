/*
 * MCP4922.c
 *
 * Created: 11/8/2021 6:02:23 AM
 *  Author: audiodiWHY
 */ 
#include <stdint.h>
#include "spi3.h"

uint16_t dac16bits = 0b0011000000000000; /* default chan A, unbuffered ref, gain 1, no shutdown */
uint8_t MSB = 0;
uint8_t LSB = 0;

void output_4922(uint16_t data, uint8_t channel)
	{
	// constrain data variable to 12 bits.
	 if ((data & 0b00001111111111111111) > 4095)
	   {
		   data = 4095;
	   }
	
	if (channel == 0)
		{
		dac16bits |= 1 << 15;
		}
	else
		{
		dac16bits &= ~(1 << 15);
		}
    /*form 2 8 bit words */
	dac16bits = (dac16bits & 0b1111000000000000) + data;
	
	/*hunka 8 bit chunkas */
	MSB = ((dac16bits >> 8) & 0xFF);
    LSB = (dac16bits & 0xFF);
	
	/* send that puppy */
	SPI_TransferTx16_SingleCS(MSB, LSB);
	}
	
void buffer_4922(uint8_t buff)
   {
    if (buff == 0)
	  {
	   	 dac16bits |= 1 << 14; 
	  }
	 else
	  {
		 dac16bits &= ~(1 << 14);  
	  } 

    }
	
void gain_4922(uint8_t damnloud)
    {
		    if (damnloud == 1) // 1 for gain = 1, anything else for gain = 2
		    {
			    dac16bits |= 1 << 13;
		    }
		    else
		    {
			    dac16bits &= ~(1 << 13);
		    }
	}

void enable_4922_output(uint8_t silence)
{
	if (silence == 0) // 0 is shutdown , anything else for no shutdown
	{
		dac16bits &= ~(1 << 12);
	}
	else
	{
		dac16bits |= (1 << 12);
	}
		
		
}	
