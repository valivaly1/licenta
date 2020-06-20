

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
char DEVICE_EUI[]  = "0004A30B00E987BB;
char DEVICE_ADDR[] = "2601166B";
char NWK_SESSION_KEY[] = "BA514F64BC8381FB3BDC2D7CB29721EF";
char APP_SESSION_KEY[] = "EA8F7B91318B4F507D8C7DA1276C7922";

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
	auto val = redis.get("v");
	if(val){
	std::cout << *val << std::endl;
	}
	else{
		std::cout<<"Nu exista"<< std::endl;
	}
	 error = LoRaWAN.ON(sock);

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
  // 2. Set Device EUI
  //////////////////////////////////////////////

  error = LoRaWAN.setDeviceEUI(DEVICE_EUI);

  // Check status
  if( error == 0 ) 
  {
    printf("2. Device EUI set OK\n");     
  }
  else 
  {
    printf("2. Device EUI set error = %d\n", error); 
  }


  //////////////////////////////////////////////
  // 3. Set Device Address
  //////////////////////////////////////////////

  error = LoRaWAN.setDeviceAddr(DEVICE_ADDR);

  // Check status
  if( error == 0 ) 
  {
    printf("3. Device address set OK\n");     
  }
  else 
  {
    printf("3. Device address set error = %d\n", error); 
  }


  //////////////////////////////////////////////
  // 4. Set Network Session Key
  //////////////////////////////////////////////
 
  error = LoRaWAN.setNwkSessionKey(NWK_SESSION_KEY);

  // Check status
  if( error == 0 ) 
  {
    printf("4. Network Session Key set OK\n");     
  }
  else 
  {
    printf("4. Network Session Key set error = %d\n",error); 
  }


  //////////////////////////////////////////////
  // 5. Set Application Session Key
  //////////////////////////////////////////////

  error = LoRaWAN.setAppSessionKey(APP_SESSION_KEY);

  // Check status
  if( error == 0 ) 
  {
    printf("5. Application Session Key set OK\n");     
  }
  else 
  {
    printf("5. Application Session Key set error = %d\n", error); 
  }


  //////////////////////////////////////////////
  // 6. Save configuration
  //////////////////////////////////////////////
  
  error = LoRaWAN.saveConfig();

  // Check status
  if( error == 0 ) 
  {
    printf("6. Save configuration OK\n");     
  }
  else 
  {
    printf("6. Save configuration error = %d\n", error);
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

  error = LoRaWAN.joinABP();

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
  delay(5000);
}

int main (){
	setup();
	while(1){
		loop();
	}
	return (0);
}

//////////////////////////////////////////////
