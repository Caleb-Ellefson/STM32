# STM32 Bare Metal Driver Development

Welcome to my STM32 repository! This collection showcases lessons from my STM32 Driver Development course. Each program is written entirely from scratch, with no reliance on external libraries. The goal of this repository is to deepen my understanding of low-level driver development while creating a reference for future projects.

Note: Not all lessons may be included in this repository, so lesson numbers might jump around. The purpose of this repository is to serve as a reference for future projects and development. This is not a complete course to do. 

Feel free to explore the lessons and use them as a resource for your STM32 development journey.

## Table of Contents

1. [Lesson 1: Understanding MCU Clock Tree](#lesson-1-understanding-mcu-clock-tree)
2. [Lesson 2: HSI Clock Measurement](#lesson-2-hsi-clock-measurement)
3. [Lesson 3: Understanding MCU Interrupt Concepts](#lesson-3-understanding-mcu-interrupt-concepts)

---

## Lesson 1: Understanding MCU Clock Tree

### Description:
This lesson provides an introduction to the STM32 peripheral clock system. It demonstrates the importance of enabling each peripheral's clock before usage, ensuring proper functionality and power management within the microcontroller.

### Files:
- `004-PeriClockEnable.cpp`

## Lesson 2: HSI Clock Measurement

### Description:
This lesson delves into the different clock sources available in STM32 microcontrollers, focusing on the High-Speed Internal (HSI) clock. You’ll learn how to configure and output the HSI clock signal through a GPIO pin for measurement using an oscilloscope. This practical approach helps visualize the clock signal and understand the microcontroller's timing mechanisms.

<div align="center">
    <img src='Assets/005-HSI-Measurement.JPG' width='400' height='500'/>
    <h4> HSI Clock Measurement on the analog oscilloscope </h4>
</div>

### Files:
- `004-PeriClockEnable.cpp`
- `005-HSI-Measurement.cpp`

## Lesson 3: Understanding MCU Interrupt Concepts

### Description:
This lesson explores the fundamentals of interrupts in STM32 microcontrollers, which are essential for creating responsive and efficient systems. The lesson walks through configuring a button to trigger an interrupt that activates an LED on a different GPIO pin. This example illustrates how interrupts can be used to handle external events and control GPIO outputs in real-time, emphasizing the practical application of interrupts.

<div align="center">
    <img src='Assets/006-MCU-Interrupt-Design.JPG' width='400' height='500'/>
       <h4> Bread board design for a interrupt triggerd by the button </h4>
</div>


### Files:
- `006-MCU-Interrupt-Design.cpp`
