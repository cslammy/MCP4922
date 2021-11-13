/*
 * MCP4922-test.c
 *
 * Created: 11/8/2021 6:01:48 AM
 * Author : clamm
 */ 

#include <avr/io.h>
#include "MCP4922.h"
#include <stdint.h>
#include "spi3.h"

int main(void)
{
init_spi_master();
spi_mode(0);

    while (1) 
    {
		//increases one output, then the other.
		for (uint16_t x = 0; x < 4095; x++)
			{
			output_4922 (x,0);	 
			}
		for (uint16_t y = 0; y < 4095; y++)
			{
			output_4922 (y,1);    
			}

        /* test for the chip--dances traces all over scope since MSB changes
	    but proves that the wiring etc. works.
	    for (uint8_t x = 0; x < 255; x++)
		{
		SPI_TransferTx16_SingleCS(x,0xFF);
		}
        */
     }  //end while


}
