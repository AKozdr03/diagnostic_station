# README

## Project Overview -- Building of multi-thread applications

This project was created as part of the **Building of multi-thread applications** course. Its goal is to build a **diagnostic station**
capable of measuring key physiological parameters of the user. The
system collects the following data:

-   **Heart rate (Pulse)**
-   **Galvanic Skin Response (GSR)**
-   **Body temperature**

## Project Description

The diagnostic station uses three sensors, each connected according to
the hardware requirements of the **myRIO** platform.

### Sensors Used and Their Connections:

1.  **Temperature sensor**
    -   Connected to **myRIO** through an **ESP** module
    -   Wired to **Connector A, PIN 10**
2.  **Pulse sensor**
    -   Connected **directly** to myRIO
    -   Wired to **Connector B, AI0**
3.  **GSR (Galvanic Skin Response) sensor**
    -   Connected **directly** to myRIO
    -   Wired to **Connector B, AI1**

## Project Goals

The objective of this project was to design and implement a multilayer
application capable of:

-   Acquiring data from multiple sensors
-   Processing and visualizing the collected measurements
-   Providing insights into the user's basic physiological parameters
-   Demonstrating the practical use of multilayer architecture and
    communication between embedded systems
