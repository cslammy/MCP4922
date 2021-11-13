/*
 * MCP4922.h
 *
 * Created: 11/8/2021 6:02:52 AM
 *  Author: clamm
 */ 


#ifndef MCP4922_H_
#define MCP4922_H_

uint16_t output_4922(uint16_t data, uint8_t channel);

void buffer_4922(uint8_t buffered);

void gain_4922(uint8_t damnloud);

void enable_4922_output(uint8_t silence);

#endif /* MCP4922_H_ */