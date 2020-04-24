/*
 * @brief FreeRTOS Blinky example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */




/*Note: Single On-board push button is used to accomplish the project
 * 		LEDs glow at a rate of 500ms only
 * 		The project uses vTaskDelayUntil
 * 		The project is implemented using only one single task function
 */



#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

/*Led on/off states*/

bool LedOff = true;
bool LedOn = false;

/*Assign LEDs */

int Red = 0;
int Green = 1;
int Blue = 2;

static void pvrSetupHardware(void)
{
	SystemCoreClockUpdate();

	/*Initiate Board Configurations.*/

	Board_Init();

/*Set LEDs off*/

	Board_LED_Set(0, LedOff);
	Board_LED_Set(1, LedOff);
	Board_LED_Set(2, LedOff);

}

/*Led Task Function*/

static void TaskFunction(void *pvParameters)
{
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();		/*Initialize the xLastWakeTime variable with the current time.*/

	const portTickType xFrequencyOn = 1000;		/*Led on frequency of 1/seconds */
	const portTickType xFrequencyOff = 500;		/*Led off frequency of 1/0.5 seconds */

    while (1)
    {
    	int l = Buttons_GetStatus();			/*Take the status of the button press (P2.10) On board button*/

    	while(l) {
    			if(l==1) {						/*If the button is pressed. > 0x01*/
/*Red Led*/
    				vTaskDelayUntil(&xLastWakeTime, xFrequencyOff);
		    		Board_LED_Set(Red, LedOn);							/*Sets the Red Led on*/
		    		vTaskDelayUntil(&xLastWakeTime, xFrequencyOn );
		    		Board_LED_Set(Red, LedOff);							/*Sets the Red Led off*/

/*Green Led*/
		    		Board_LED_Set(Green, LedOff);						/*Sets the Green Led off*/
		    		vTaskDelayUntil(&xLastWakeTime, xFrequencyOff );
		    		Board_LED_Set(Green, LedOn);						/*Sets the Green Led on*/
		    		vTaskDelayUntil(&xLastWakeTime, xFrequencyOn );
		    		Board_LED_Set(Green, LedOff);						/*Sets the Green Led off*/

/*Blue Led*/
		    		Board_LED_Set(Blue, LedOff);						/*Sets the Blue Led off*/
		    		vTaskDelayUntil(&xLastWakeTime, xFrequencyOff );
		    		Board_LED_Set(Blue, LedOn);							/*Sets the Blue Led on*/
		    		vTaskDelayUntil(&xLastWakeTime, xFrequencyOn );
		    		Board_LED_Set(Blue, LedOff);						/*Sets the Blue Led off*/

    		} 															/*If ends here*/

    	}																/*While ends here*/

    }																	/*While ends here*/

 } 																		/*Task Function ends here.*/

int main(void)
{
	/* initialize hardware */
	pvrSetupHardware();

    /* create toggle thread */
    xTaskCreate(TaskFunction, (signed char *) "TaskFunction", configMINIMAL_STACK_SIZE, NULL, (1),
                    (xTaskHandle *) NULL);

    /* Start the scheduler */
    vTaskStartScheduler();

    /* Should never arrive here */
    return 1;
}
