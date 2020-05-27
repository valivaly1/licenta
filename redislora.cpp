

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
uint8_t PORT = 3;

char data[] = "0102030405060708090A0B0C0D0E0F";
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
  
    error = LoRaWAN.setAppEUI(APP_EUI);

  // Check status
  if( error == 0 ) 
  {
    printf("3. Application EUI set OK\n");     
  }
  else 
  {
    printf("3. Application EUI set error = %d\n", error); 
  }


  //////////////////////////////////////////////
  // 4. Set Application Session Key
  //////////////////////////////////////////////

  error = LoRaWAN.setAppKey(APP_KEY);

  // Check status
  if( error == 0 ) 
  {
    printf("4. Application Key set OK\n");     
  }
  else 
  {
    printf("4. Application Key set error = %d\n",error); 
  }


  //////////////////////////////////////////////
  // 5. Save configuration
  //////////////////////////////////////////////
  
  error = LoRaWAN.saveConfig();

  // Check status
  if( error == 0 ) 
  {
    printf("5. Save configuration OK\n");     
  }
  else 
  {
    printf("5. Save configuration error = %d\n", error);
  }


  printf("\n------------------------------------\n");
  printf("Module configured\n");
  printf("------------------------------------\n\n");
  
  LoRaWAN.getDeviceEUI();
  printf("Device EUI: %s\n", LoRaWAN._devEUI);
  
  LoRaWAN.getDeviceAddr();
  printf("Device Address: %s\n\n", LoRaWAN._devAddr);
  
	
}

void loop(void)
{
	 //////////////////////////////////////////////
  // 1. Switch on
  //////////////////////////////////////////////

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
  
  
  //////////////////////////////////////////////
  // 2. Join network
  //////////////////////////////////////////////

  error = LoRaWAN.joinOTAA();

  // Check status
  if( error == 0 ) 
  {
    printf("2. Join network OK\n");     

    //////////////////////////////////////////////
    // 3. Send unconfirmed packet 
    //////////////////////////////////////////////
  
    error = LoRaWAN.sendUnconfirmed(PORT, data);
  
    // Error messages:
    /*
     * '6' : Module hasn't joined a network
     * '5' : Sending error
     * '4' : Error with data length	  
     * '2' : Module didn't response
     * '1' : Module communication error   
     */
    // Check status
    if( error == 0 ) 
    {
      printf("3. Send Unconfirmed packet OK\n");     
      if (LoRaWAN._dataReceived == true)
      { 
        printf("   There's data on port number %d.\r\n", LoRaWAN._port);
        printf("   Data: %s\n", LoRaWAN._data);
      }
    }
    else 
    {
      printf("3. Send Unconfirmed packet error = %d\n", error); 
    }
  }
  else 
  {
    printf("2. Join network error = %d\n",error);
  }

  
  //////////////////////////////////////////////
  // 4. Clean channels
  //////////////////////////////////////////////
  error = LoRaWAN.reset();

  // Reset channels
  if( error == 0 ) 
  {
    printf("4. Clean channels OK\n");     
  }
  else 
  {
    printf("4. Clean channels error = %d\n", error); 
  }

  //////////////////////////////////////////////
  // 5. Switch off
  //////////////////////////////////////////////
  error = LoRaWAN.OFF(sock);

  // Check status
  if( error == 0 ) 
  {
    printf("5. Switch OFF OK\n");     
  }
  else 
  {
    printf("5. Switch OFF error = %d\n",error); 
  }
  
  
  printf("\n");
  delay(10000);
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}

//////////////////////////////////////////////
