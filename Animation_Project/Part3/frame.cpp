/*
* Final Project - Animation Project (Part 3)
* Professors: Surbhi Bahri, Kaci Taouch
* CST 8219 
* Lab Section: 303
* 
* Due Date: April 11th, 2022
* 
* Group Members: 
*	Isabelle Yeo (040998040)
*	Tyler Morris (040989042)
*	Naijo Palayoor Jose (041003360)
*	Keshav Sandhu (040994718)
* 
* File Name: frame.cpp
* 
*/

#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include "frame.h"
#include "animation.h"
#include "animationManager.h"
using namespace std;

/***********************************************
Function name  :Frame
Purpose        :2 parameter constructor which creates
				a Frame object
In parameters  :frameName - pointer to char
			    duration - double value for frame 
						   duration
Out Parameters :None
************************************************/
Frame::Frame(char* frameName, double duration) {
	this->frameName = new char[strlen(frameName) + 1];
	strcpy(this->frameName, frameName);

	this->duration = duration;
}

/***********************************************
Function name  :Frame
Purpose        :1 parameter constructor which creates
				a Frame object
In parameters  :frame - Frame object
Out Parameters :None
************************************************/
Frame::Frame(const Frame& frame) {
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(this->frameName, frame.frameName);

	this->duration = frame.duration;
}

/***********************************************
Function name  :~Frame
Purpose        :Deconstructor to destroy Frame object
In parameters  :None
Out Parameters :None
************************************************/
Frame::~Frame() {
	delete[] this->frameName;
}

/***********************************************
Overload name  : = 
Purpose        :Overload assignment operator (=)  
				Copies the frameName and duration 
				from the frame object parameter to
				the calling frame object
In parameters  :frame - Frame object
Out Parameters :Frame reference
************************************************/
Frame& Frame::operator=(const Frame& frame) {
	delete[] this->frameName;
	this->frameName = new char[strlen(frame.frameName) + 1];
	strcpy(this->frameName, frame.frameName);

	this->duration = frame.duration;

	return *this;
}

/***********************************************
Overload name  : <<
Purpose        :Overload assignment operator (<<) - 
				Frame output to console
In parameters  :output - output stream object
			    frame - Frame object reference
Out Parameters :ostream reference
************************************************/
ostream& operator<<(ostream& output, Frame& frame) {
	output << "Frame Name=" << frame.frameName << "; duration=" << frame.duration;
	return output;
}