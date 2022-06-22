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
* File Name: animation.cpp
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
Function name  :EditFrame
Purpose        :Allows the user to change the 
				frameName and duration of a frame
				in the animation
In parameters  :None
Out Parameters :None
************************************************/
void Animation::EditFrame()
{
	int count = 0; 
	int index = 0; 
	char newName[100];
	newName[0] = '\0';
	int newDuration = 0; 

	//Loop to count number of frames in the animation
	for (auto i = this->frames.begin(); i != this->frames.end(); ++i) {
		count++;
	}
	cout << "\nSelected Option: 3" << endl;
	if (count == 0) {
		cout << "There are no frames in the animation" << endl;
	}
	else {
		cout << "Edit a Frame in the Animation" << endl;
		if (count == 1) {
			cout << "There are " << count << " Frame(s) in the list. Please specify the index (<=0) to edit at:";
		}
		else {
			cout << "There are " << count << " Frame(s) in the list. Please specify the index (from 0 to " << count - 1 << ") to edit at:";
		}
		//Input validation for index
		while (!(cin >> index) || index < 0 || index > count) {
			cout << "Invalid index!";
			cin.clear();
			cin.ignore(123, '\n');
		}
		if (index <= count - 1 && index >= 0) {
			count = 0;
			for (Frame& frame : frames) { 
				if (count == index) {
					cout << "The name and duration of this frame is: "<< frame << ".\nWhat do you wish to replace them with?" << endl;
					cin.getline(newName, 100);
					cin.ignore(123, '\n');
					//Input validation for newDuration
					while (!(cin >> newDuration)) {
						cout << "Invalid duration!";
						cin.clear();
						cin.ignore(123, '\n');
					}
					Frame newFrame(newName, newDuration);
					frame = newFrame; 
					cout << "Frame #"<< index << " edit completed" << endl;
				}
				count++;
			}
		}
		else {
			cout << "The index selected is out of range" << endl; 
		}
	}
}

/***********************************************
Function name  :DeleteFrame
Purpose        :Deletes a frame from the front 
				of the forward list
In parameters  :None
Out Parameters :None
************************************************/
void Animation::DeleteFrame() {
	//Checks if the forward list is empty
	if (this->frames.empty()) {
		cout << "No frames to delete" << endl;
	}
	else {
		this->frames.pop_front(); 
		cout << "First frame deleted" << endl;
	}
}

/***********************************************
Overload name  : >>
Purpose        :Overload assignment operator (>>) -
				Adds a frame to the front of the
				animation
In parameters  :in - input stream object
				animation - Animation object reference
Out Parameters :istream reference
************************************************/
istream& operator>>(istream& in, Animation& animation) {
	char name[100];
	name[0] = '\0';
	int duration = 0; 
	cout << "\nSelected Option: 1" << endl;
	cout << "Insert a frame in the animation" << endl;
	cout << "Please enter the frame name: ";
	cin.ignore(123, '\n');
	cin.getline(name, 100);
	cout << "Please enter the frame duration: ";
	//Input validation for duration
	while (!(cin >> duration)) {
		cout << "Invalid duration!";
		cin.clear();
		cin.ignore(123, '\n');
	}
	animation.frames.push_front(Frame(name, duration)); 
	cout << "Frame " << name << " added to the front of the frames" << endl;	
	return in;
}

/***********************************************
Overload name  : <<
Purpose        :Overload assignment operator (<<) -
				Animation output to console
In parameters  :out - output stream object
				animation - Animation object reference
Out Parameters :ostream reference
************************************************/
ostream& operator<<(ostream& out, Animation& animation) {
	int counter = 0; 
	out << "	Animation Name is " << animation.AnimationName << endl;
	out << "	Report the Animation" << endl;
	if (animation.frames.empty()) {
		out << "	No frames in the Animation" << endl; 
	}
	else {
		for (Frame& frame : animation.frames) {
			out << "	Frame " << counter << ": " << frame << endl; 
			counter++;
		}
	}
	return out;
}


