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

#define GPIO_INTERRUPT_BUTTON   BUTTONS_BUTTON1_GPIO_BIT_NUM	/*OnBoard Button Pin (10)*/
#define GPIO_INTERRUPT_PORT    BUTTONS_BUTTON1_GPIO_PORT_NUM	/*OnBoard Button Port (P2)*/

#define GPIO_IRQ_HANDLER		EINT3_IRQHandler	/* GPIO interrupt IRQ function name */
#define GPIO_INTERRUPT_NVIC_NAME    	EINT3_IRQn		/* GPIO interrupt NVIC interrupt name */



/*Led on/off states*/

bool LedOff = true;
bool LedOn = false;

/*Assign LEDs */

struct Leds {
int Red = 0;							/* OnBoard LED 0 mapped to Red color */
int Green = 1;							/* OnBoard LED 1 mapped to Green color */
int Blue = 2;							/* OnBoard LED 2 mapped to Blue color */
}


void GPIO_IRQ_HANDLER(void)
{
	Chip_GPIOINT_ClearIntStatus(LPC_GPIOINT, GPIO_INTERRUPT_PORT, (1 << GPIO_INTERRUPT_BUTTON));

	// check the button states
		int l = Buttons_GetStatus();			/*Take the status of the button press (P2.10) On board button*/
}



static void pvrSetupHardware(void)
{
	SystemCoreClockUpdate();

	/*Initiate Board Configurations.*/

	Board_Init();

/*Set LEDs off*/

	Board_LED_Set(0, LedOff);
	Board_LED_Set(1, LedOff);
	Board_LED_Set(2, LedOff);
	
	Chip_GPIOINT_SetIntFalling(LPC_GPIOINT, GPIO_INTERRUPT_PORT, 
				(1 << GPIO_INTERRUPT_BUTTON));		/* Configure the GPIO interrupt */

	/* Enable interrupt in the NVIC */
	NVIC_ClearPendingIRQ(GPIO_INTERRUPT_NVIC_NAME);
	NVIC_EnableIRQ(GPIO_INTERRUPT_NVIC_NAME);

}

/*Led Task Function*/

static void TaskFunction(void *pvParameters)
{
	LEDs LED = *((LEDs*) pvParameters);		/*Passing the Red, Green, Blue Parameters*/
	
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();		/*Initialize the xLastWakeTime variable with the current time.*/

	const portTickType xFrequencyOn = 1000;		/*Led on frequency of 1 seconds */
	const portTickType xFrequencyOff = 500;		/*Led off frequency of 0.5 seconds */

    while (l)
    {

    	if(l==1) {							/*If the button is pressed. > 0x01*/

		Board_LED_Set(LED, LedOn);				/*Sets the LED Led on*/
    		vTaskDelayUntil(&xLastWakeTime, xFrequencyOn );
		    		
		Board_LED_Set(LED, LedOff);				/*Sets the LED Led off*/
		vTaskDelayUntil(&xLastWakeTime, xFrequencyOff);	

    		} 							/*If ends here*/

    }									/*While ends here*/

 } 									/*Task Function ends here.*/

int main(void)
{
	/* initialize hardware */
	pvrSetupHardware();

    /* create toggle thread */
	xTaskCreate(TaskFunction, (signed char *) "TaskFunction", configMINIMAL_STACK_SIZE, Red, (3),
                    (xTaskHandle *) NULL);
	
	xTaskCreate(TaskFunction, (signed char *) "TaskFunction", configMINIMAL_STACK_SIZE, Green, (2),
                    (xTaskHandle *) NULL);
	
	xTaskCreate(TaskFunction, (signed char *) "TaskFunction", configMINIMAL_STACK_SIZE, Blue, (1),
                    (xTaskHandle *) NULL);


    /* Start the scheduler */
    vTaskStartScheduler();

    /* Should never arrive here */
    return 1;
}

