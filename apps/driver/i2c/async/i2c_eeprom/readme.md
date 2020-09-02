---
parent: Harmony 3 driver and system service application examples for PIC32CM LE/LS family
title: I2C driver asynchronous - I2C EEPROM 
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# I2C driver asynchronous - I2C EEPROM

This example application shows how to use the I2C driver in asynchronous mode to perform operations on the EEPROM.

## Description

This example uses the I2C driver in asynchronous mode to communicate with the EEPROM to perform write and read operations in Bare-Metal environment. This application uses I2C driver to read and write data from an AT24CM02 EEPROM device.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/core_apps_pic32cm_le00_ls00) and then click Clone button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/driver/i2c/async/i2c_eeprom/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32cm_le00_curiosity_pro.X | MPLABX project for [PIC32CM LE00 Curiosity Pro Evaluation Kit]() |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32cm_le00_curiosity_pro.X | [PIC32CM LE00 Curiosity Pro Evaluation Kit]() |
|||

### Setting up [PIC32CM LE00 Curiosity Pro Evaluation Kit]()

- To run the demo, the following additional hardware are required:
  - One [EEPROM 3 Click](https://www.mikroe.com/eeprom-3-click) board
  - One [mikroBUS Xplained Pro](https://www.microchip.com/developmenttools/ProductDetails/ATMBUSADAPTER-XPRO) boards

- Connect [mikroBUS Xplained Pro board](https://www.microchip.com/developmenttools/ProductDetails/ATMBUSADAPTER-XPRO) to EXT1 header
- Plug the [EEPROM 3 click Board](https://www.mikroe.com/eeprom-3-click) into the MikroBus socket of the [mikroBUS Xplained Pro board](https://www.microchip.com/developmenttools/ProductDetails/ATMBUSADAPTER-XPRO)
- Connect the Debug USB port on the board to the computer using a micro USB cable

## Running the Application

1. Build and program the application using its IDE
2. LED indicates success or failure:
    - The LED is turned ON when the value read from the EEPROM matched with the written value

Refer to the following table for LED name:

| Board | LED Name |
| ----- | -------- |
|  [PIC32CM LE00 Curiosity Pro Evaluation Kit]() | LED1 |
|||
