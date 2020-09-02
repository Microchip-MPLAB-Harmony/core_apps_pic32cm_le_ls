---
parent: Harmony 3 driver and system service application examples for PIC32CM LE/LS family
title: TrustZone FreeRTOS basic 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# TrustZone FreeRTOS basic

This example application blinks an LED to show the FreeRTOS threads that are running in non-secure mode and to indicate status.

## Description

This demonstrates TrustZone feature and uses two projects viz., Secure and Non-Secure Project that work together on the same
MCU and offering security isolation between the Trusted and the Non-trusted resources in the device.

FreeRTOS and BSP are configured and run in Non-Secure mode.

This demonstration creates three tasks and a queue. Task1 sends message to Task2 and Task3 to unblock and toggle an LED. Task1 priority is low compared to Task2 and Task3 which shares same priority.

- **Task1**: This task sends the data (i.e. delay, the amount of time for which the task need blocked) to Task2 and Task3 using a queue, then Task1 blocks itself for 200ms to allow other tasks to schedule and run
- **Task2**: This task blocks until it receives the data from queue, if the Task2 receives the expected delay (i.e. 1000ms) from Task1 then toggles the LED and blocks itself for the amount of delay received
- **Task3**: This task blocks until it receives the data from queue, if the Task3 receives the expected delay (i.e. 100ms) from Task1 then toggles the LED and blocks itself for the amount of delay received

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_pic32cm_le00_ls00) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is as shown below:

| Type        | Path                         |
|:-----------:|:----------------------------:|
| Project group | apps/rtos/freertos/basic_freertos_trustZone |
|Secure Project|  apps/rtos/freertos/basic_freertos_trustZone/Secure/firmware |
|Non-Secure Project|  apps/rtos/freertos/basic_freertos_trustZone/NonSecure/firmware |
||||

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| :-----------------: | :----------------------------------------------: |
| pic32cm_ls00_cpro_Secure.X <br> pic32cm_ls00_cpro_NonSecure.X | Secure and Non-secure MPLABX project for [PIC32CM LS00 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_ls00_cpro_Secure.X <br> pic32cm_ls00_cpro_NonSecure.X | [PIC32CM LS00 Curiosity Pro Evaluation Kit]() |
|||

### Setting up [PIC32CM LS00 Curiosity Pro Evaluation Kit]()

- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and program the application using its IDE
2. The LED indicates the success or failure.
    - The LED toggles on success i.e. each time when the Task2 or Task3 receives a valid message

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [PIC32CM LS00 Curiosity Pro Evaluation Kit]() | LED1 |
|||
