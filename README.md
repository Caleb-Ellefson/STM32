# STM32 Bare Metal Driver Development

Welcome to the STM32 Lessons repository! This repository contains a collection of lessons and examples designed to help you learn and work with STM32 microcontrollers. Each lesson covers various aspects of STM32 programming, from basic concepts to more advanced features.

Note: Not all lessons may be included in this repository, so lesson numbers might jump around. The purpose of this repository is to serve as a reference for future projects and development.

Feel free to explore the lessons and use them as a resource for your STM32 development journey.

## Table of Contents

1. [Lesson 1: Understanding MCU Clock Tree](#lesson-1-understanding-mcu-clock-tree)
2. [Lesson 2: Understanding MCU Interrupt Concepts](#lesson-2-understanding-mcu-interrupt-concepts)

---

## Lesson 1: Understanding MCU Clock Tree

### Description:
This lesson introduces you to STM32 microcontrollers clock types, covering their architecture, features, and how to set up a development using different types of clocks for STM32 programming. It provides a foundation for understanding the hardware and tools you will use in subsequent lessons.

<div align="center">
    <img src='Assets/005-HSI-Measurement.JPG' width='400' height='500'/>
</div>

### Files:
- `004-PeriClockEnable.cpp`
- `005-HSI-Measurement.cpp`

## Lesson 2: Understanding MCU Interrupt Concepts

### Description:
In this lesson, I dive into the world of interrupts in STM32 microcontrollers. Interrupts are crucial for creating responsive systems, allowing the microcontroller to handle events as they occur in real-time.

In this example, I configure a button to trigger an interrupt, which then activates an LED connected to another GPIO pin. This setup demonstrates how interrupts can control GPIO outputs based on external events. Although some of the GPIO configuration details are provided, my focus here is on understanding and implementing interrupts.

<div align="center">
    <img src='Assets/006-MCU-Interrupt-Design.JPG' width='400' height='500'/>
</div>
