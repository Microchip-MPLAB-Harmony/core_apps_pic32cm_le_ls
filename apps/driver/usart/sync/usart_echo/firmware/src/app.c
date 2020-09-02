/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "user.h"
#include <string.h>

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

static const char startMessage[] = "*** USART Driver Echo Demo Application ***\r\n"
"*** Type a character and observe it echo back ***\r\n"
"*** LED toggles on each time the character is echoed ***\r\n";
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_USART_ECHO_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app_usart_echo.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_USART_ECHO_STATE_INIT;
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    switch(appData.state)
    {
        case APP_USART_ECHO_STATE_INIT:

            /* Open USART Driver Instance 0 (USART 1)*/
            appData.usartHandle = DRV_USART_Open(DRV_USART_INDEX_0, DRV_IO_INTENT_READWRITE);
            if (appData.usartHandle != DRV_HANDLE_INVALID)
            {
                appData.state = APP_USART_ECHO_STATE_SEND_MESSGE;
            }
            else
            {
                appData.state = APP_USART_ECHO_STATE_ERROR;
            }
            break;

        case APP_USART_ECHO_STATE_SEND_MESSGE:

            if (DRV_USART_WriteBuffer( appData.usartHandle, (void*)startMessage, strlen(startMessage)) == true)
            {
                LED_TOGGLE();
                appData.state = APP_USART_ECHO_STATE_RECEIVE_BUFFER;
            }
            else
            {
                appData.state = APP_USART_ECHO_STATE_ERROR;
            }
            break;

        case APP_USART_ECHO_STATE_RECEIVE_BUFFER:

            /* Submit a read request and block until read completes */
            if (DRV_USART_ReadBuffer( appData.usartHandle, appData.receiveBuffer, APP_USART_ECHO_LOOPBACK_DATA_SIZE) == true)
            {
                appData.state = APP_USART_ECHO_STATE_SEND_BUFFER;
            }
            else
            {
                appData.state = APP_USART_ECHO_STATE_ERROR;
            }
            break;

        case APP_USART_ECHO_STATE_SEND_BUFFER:

            /* Echo the received character back */
            if (DRV_USART_WriteBuffer( appData.usartHandle, appData.receiveBuffer, APP_USART_ECHO_LOOPBACK_DATA_SIZE) == true)
            {
                LED_TOGGLE();
                appData.state = APP_USART_ECHO_STATE_RECEIVE_BUFFER;
            }
            else
            {
                appData.state = APP_USART_ECHO_STATE_ERROR;
            }
            break;

        case APP_USART_ECHO_STATE_ERROR:
        default:
            break;
    }
}


/*******************************************************************************
 End of File
 */
