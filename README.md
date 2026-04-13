# Automatic Street Light using LDR, NeoPixel and OLED

## Project Overview

This project implements an automatic street light system using STM32.
The system detects ambient light using an LDR sensor and automatically controls NeoPixel LEDs to simulate street lights. OLED display shows current street light status.

## Components Used

* STM32 Nucleo Board
* LDR Sensor
* NeoPixel LED Ring (WS2812)
* OLED Display (SSD1306 I2C)

## Pin Configuration

* LDR → PA0 (ADC Input)
* NeoPixel → PB4 (TIM3 CH1 PWM Output)
* OLED SDA → PB9
* OLED SCL → PB8

## Working Principle

* During daytime, LDR senses high light intensity.

* NeoPixel LEDs remain OFF.

* OLED displays: STREET LIGHT OFF

* During nighttime, LDR senses low light intensity.

* NeoPixel LEDs turn ON in white color.

* OLED displays: STREET LIGHT ON

## Software Configuration

* ADC enabled for PA0
* TIM3 PWM configured for PB4
* I2C1 configured for OLED communication

## Output

* Automatic light switching based on environmental light.
* OLED indicates ON/OFF status.

## Real Life Application

Used in smart city street lighting systems for automatic power saving.

## Files Included

* main.c
* ssd1306.c
* ssd1306.h
