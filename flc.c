#include "flc.h"
#include <stdio.h>
#include "main.h"

//LightState frontLights = OFF;
//LightState interiorLights = OFF;
//LightState rearLights = OFF;
typedef enum {
  // OFF,
    LEFT_DIR_LIGHT_STATUS,
	RIGHT_DIR_LIGHT_STATUS
} DIRECTION_LIGHT_STATUS;

// Global variable to store the current direction light status

//DIRECTION_LIGHT_STATUS dir_light_status = NULL;

void DirIndSwitchInput(char *ptr)
{
	Indicator_Light_cmd *cmd_i = (Indicator_Light_cmd *) ptr;

	 // Check the status of left indicator
	  if (cmd_i->DIR_LIGHT == 0) {
		  //HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7, GPIO_PIN_RESET);
		  //HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8, GPIO_PIN_SET);
	    }
	  else if (cmd_i->DIR_LIGHT == 1)
	  {
			 // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET); //right direction indicator on
			 // HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
			 // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7, GPIO_PIN_RESET);

	  }
	  else if (cmd_i->DIR_LIGHT == 2)
	  {
				 // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET); //right direction indicator on
				 // HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
				 // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7, GPIO_PIN_SET);

	  }
	  else
	  {
					// If neither left nor right indicator is active, turn off direction lights
				   // dir_light_status = OFF;
				 // HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
				 // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
				  //HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8, GPIO_PIN_SET);

	    }
	}

	//uint8_t DIR_LIGHT = cmd_i->DIR_LIGHT;


void Ignition_Input(char *ptr)
{
	//ptr[]

}
void brake_Li_Inp(char *ptr)
{
	//ptr[]

}

void revers_Li_Inp(char *ptr)
{
	//ptr[]

}


void InteriorLightStatus (char *ptr)
{
	//ptr[]
	Interior_light_cmd *cmd_int = (Interior_light_cmd *)ptr;

	 if (cmd_int->INTERIOR_LIGHT==1)
	 {
		 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET);
	 }
	 else
	 {
		 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);
	 }
}
void ExtLiSwtSts(char *ptr)
{
	//ptr[]

	Headlight_cmd *cmd = (Headlight_cmd *)ptr;


		// Simulate receiving RX data and call Headlight_cmd function

		//char rx_data[sizeof(Headlight_cmd)]; // Simulated received data buffer
	   //Headlight_cmd(data); // Call the Headlight_cmd function with received data

	// Check if the position light is on
	if (cmd->POS_LIGHT== 1)
	{

		//Turn on Position Light
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);

		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
		if (cmd->LOW_BEAM == 1)
		{
			// Turn on Low beam Light
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
			if (cmd->HIGH_BEAM == 1)
			{
				// Turn on High beam Light
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
			}
			else
			{
				//Turn off High beam Light
				HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
				//HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
			}
		}
		else
		{
			//Turn off Low beam Light
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
		}
	}
	else
	{
		//Turn off Position Light
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9, GPIO_PIN_SET);
	}

}
void DRL_swtch_INP(char *ptr)
{
	//ptr[]
	DRL_light_cmd *cmd_d = (DRL_light_cmd *) ptr;

	 // Check the status of left indicator
	  if (cmd_d->DRL_LIGHT==1) {

		   HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
		  // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET);

		 // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
		//  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
	    }

	  else
	  {
		 // HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
		 // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);
	    }
	}

void Fog_Swi_Inp(char *ptr)
{
	//ptr[]
	Fog_light_cmd *cmd_f = (Fog_light_cmd *) ptr;

	 // Check the status of left indicator
	  if (cmd_f->FOG_LIGHT ==1) {

		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_RESET); //RELAY 4 IS NOT WORKING CHANGED PIN TO PE14- RELAY 5 IS USED
		  //HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_RESET);

		 // HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
		//  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
	    }

	  else
	  {
	        // If neither left nor right indicator is active, turn off direction lights
	       // dir_light_status = OFF;
		 // HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_14, GPIO_PIN_SET);  //RELAY 4 IS NOT WORKING CHANGED PIN TO PE14- RELAY 5 IS USED
		  //HAL_GPIO_WritePin(GPIOE, GPIO_PIN_13, GPIO_PIN_SET);
	    }
	}


//void updateLights()
//{
//    printf("frontLights: ");
//    switch (frontLights) {
//        case OFF:
//        		printf("Off\n");
//        		break;
//        case LOW_BEAM:
//        		printf("Low Beam\n");
//        		break;
//        case HIGH_BEAM:
//        		printf("High Beam\n");
//        		break;
//        case POSITION_LIGHTS:
//        		printf("Position Lights\n");
//        		break;
//        case DRL:
//        		printf("DRL\n");
//        		break;
//    }
//}
