// Name:    MotorController.cpp
// Created: 09/10/2018 13:00
// Edited:  08/11/2018 17:21
// Author:  Mads
// Purpose: Interface implementation for the motor controller.
// Made by Gruppe 5: Mads Bluhme, Frederik Schultz & Mads Beyer Mogensen



#include "MotorController.h"


MotorController::MotorController(const uint8_t motorAControl1Pin, const uint8_t motorAControl2Pin, const uint8_t motorBControl1Pin, const uint8_t motorBControl2Pin)
	: _motorAControl1Pin(motorAControl1Pin), _motorAControl2Pin(motorAControl2Pin), _motorBControl1Pin(motorBControl1Pin), _motorBControl2Pin(motorBControl2Pin)
{ }

void MotorController::Begin() const
{
	pinMode(_motorAControl1Pin, OUTPUT);
	pinMode(_motorAControl2Pin, OUTPUT);
	pinMode(_motorBControl1Pin, OUTPUT);
	pinMode(_motorBControl2Pin, OUTPUT);

	Brake();
}

void MotorController::Start() const
{
	Forward();
	delay(250);
	Brake();
	delay(175);
	Rotate(180);
	Brake();
}

void MotorController::Freewheel() const
{
	digitalWrite(_motorAControl1Pin, LOW);
	digitalWrite(_motorAControl2Pin, LOW);
	digitalWrite(_motorBControl1Pin, LOW);
	digitalWrite(_motorBControl2Pin, LOW);
}

void MotorController::Brake() const
{
	digitalWrite(_motorAControl1Pin, HIGH);
	digitalWrite(_motorAControl2Pin, HIGH);
	digitalWrite(_motorBControl1Pin, HIGH);
	digitalWrite(_motorBControl2Pin, HIGH);
}

void MotorController::Forward() const
{
	digitalWrite(_motorAControl1Pin, HIGH);
	digitalWrite(_motorAControl2Pin, LOW);
	digitalWrite(_motorBControl1Pin, HIGH);
	digitalWrite(_motorBControl2Pin, LOW);
}

void MotorController::TurnLeft() const
{
	digitalWrite(_motorAControl1Pin, HIGH);
	digitalWrite(_motorAControl2Pin, LOW);
	digitalWrite(_motorBControl1Pin, HIGH);
	digitalWrite(_motorBControl2Pin, HIGH);
}

void MotorController::TurnRight() const
{
	digitalWrite(_motorAControl1Pin, HIGH);
	digitalWrite(_motorAControl2Pin, HIGH);
	digitalWrite(_motorBControl1Pin, HIGH);
	digitalWrite(_motorBControl2Pin, LOW);
}

void MotorController::Backwards() const
{
	digitalWrite(_motorAControl1Pin, LOW);
	digitalWrite(_motorAControl2Pin, HIGH);
	digitalWrite(_motorBControl1Pin, LOW);
	digitalWrite(_motorBControl2Pin, HIGH);
}

void MotorController::Rotate(const int16_t angle) const
{
	if (angle > 0)
	{
		digitalWrite(_motorAControl1Pin, LOW);
		digitalWrite(_motorAControl2Pin, HIGH);
		digitalWrite(_motorBControl1Pin, HIGH);
		digitalWrite(_motorBControl2Pin, LOW);
		delay(17.123 * pow(angle, 0.6494));
		Brake();
	}
	else
	{
		digitalWrite(_motorAControl1Pin, HIGH);
		digitalWrite(_motorAControl2Pin, LOW);
		digitalWrite(_motorBControl1Pin, LOW);
		digitalWrite(_motorBControl2Pin, HIGH);
		delay(17.123 * pow(abs(angle), 0.6494));
		Brake();
	}
}
