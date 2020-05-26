/*
 *  LoRaWAN module
 *
 *  Copyright (C) Libelium Comunicaciones Distribuidas S.L.
 *  http://www.libelium.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see http://www.gnu.org/licenses/.
 *
 *  Version:           0.4
 *  Design:            David Gascón
 *  Implementation:    Yuri Carmona & Ruben Martin
 */

#include "arduPiLoRaWAN.h"
#include <sw/redis++/redis++.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/*================================================================
==============device EUI: 0004A30B00E987BB========================
==================================================================*/

using namespace sw::redis;

uint8_t sock = SOCKET0;
uint8_t error;
/*********************************************************
 *  IF YOUR ARDUINO CODE HAS OTHER FUNCTIONS APART FROM  *
 *  setup() AND loop() YOU MUST DECLARE THEM HERE        *
 * *******************************************************/

/**************************
 * YOUR ARDUINO CODE HERE *
 * ************************/

void setup()
{
	
	auto redis = Redis("tcp://127.0.0.1:6378");
	auto val = redis.get(v);
	if(val)
	std::cout << *val << std::endl;
	}
	else{
		std::cout<<"Nu exista"<< std::endl;
	}
	 error = LoRaWAN.ON(sock);

  // Check status
  if( error == 0 ) 
  {
    printf("1. Switch ON OK\n");
  }
  else 
  {
    printf("1. Switch ON error = %d\n", error);
  }
  
  
	error = LoRaWAN.getDeviceEUI();

  // Check status
  if( error == 0 ) 
  {
    printf("3.2. Get Device EUI OK. ");
    printf("Device EUI: %s\n",LoRaWAN._devEUI);
  }
  else 
  {
    printf("3.2. Get Device EUI error = %d\n", error);
  }
  
  
	
}

void loop(void)
{
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}

//////////////////////////////////////////////
