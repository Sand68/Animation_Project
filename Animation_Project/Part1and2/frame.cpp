/*
* Final Project - Animation Project (Part 2)
* Professors: Surbhi Bahri, Kaci Taouch
* CST 8219
* Lab Section: 303
*
* Due Date: April 11th, 2022
*
* Group Members:
*    Isabelle Yeo (040998040)
*    Tyler Morris (040989042)
*    Naijo Palayoor Jose (041003360)
*    Keshav Sandhu (040994718)
*
* File Name: frame.cpp
*
*/
#include "frame.h"
#include "animation.h"

using namespace std;

/***********************************************
Function name  :Frame
Purpose        :Constructor to create Frame object
In parameters  :None
Out Parameters :None
************************************************/
Frame::Frame() {
	frameName = nullptr;
	pNext = nullptr;
}

/***********************************************
Function name  :~Frame
Purpose        :Deconstructor to destroy Frame object
In parameters  :None
Out Parameters :None
************************************************/
Frame::~Frame() {
	delete[] this->frameName;
	this->pNext = nullptr;
}
