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
* File Name: animation.cpp
*
*/
#include "frame.h"
#include "animation.h"
#include <iostream>

using namespace std;

/***********************************************
Function name  :Animation
Purpose        :Constructor to create Animation object
In parameters  :None
Out Parameters :None
************************************************/
Animation::Animation() {
	char animationName[100];
	cout << "Enter the animation name\n" << endl;
	cin.getline(animationName, 100);
	//allocate memory for animation name
	this->animationName = (char*)new char[strlen(animationName) + 1];
	strcpy(this->animationName, animationName);
	this->frames = nullptr;
}
/***********************************************
Function name  :~Animation
Purpose        :Deconstructor to destroy Animation object
In parameters  :None
Out Parameters :None
Version        :1.0
************************************************/
Animation::~Animation() {
	delete this->animationName;
	Frame* current;

	//iterate through list to delete frames
	while (this->frames != nullptr) {
		current = this->frames;
		this->frames = current->GetpNext();
		delete current;
	}

}
/***********************************************
Function name  :InsertFrame
Purpose        :This method insert an frame to the head of the linked list.
In parameters  :None
Out Parameters :None
Version        :1.0
************************************************/
void Animation::InsertFrame() {
	Frame* frameToAdd = new Frame;
	char frameName[100];

	cout << "Selected Option: 1\nInsert a frame in the animation\nPlease enter the frame name: ";

	cin.ignore(123, '\n');
	cin.getline(frameName, 100);
	//allocate memory for frame name
	frameToAdd->GetFrameName() = (char*)new char[strlen(frameName) + 1];
	strcpy(frameToAdd->GetFrameName(), frameName);

	Frame* current;

	//if frame is empty, add first frame to animation, else add to head
	if (this->frames == nullptr) {
		this->frames = frameToAdd;
	}
	else {
		current = this->frames;
		frameToAdd->GetpNext() = current;
		this->frames = frameToAdd;
	}

}
/***********************************************
Function name  :EditFrame
Purpose        :This method replace a frame name for an particular index
In parameters  : None
Out Parameters :None
Version        :1.0
************************************************/
void Animation::EditFrame() {

	Frame* current = this->frames;

	char newFrameName[100];

	Frame* loopFrame = this->frames;
	//empty animation case
	if (current == NULL) {
		cout << "Animation is empty, no frames to update" << endl;
		return;
	}
	int index, count = 1;
	//count frames in animation
	while (loopFrame->GetpNext() != NULL) {
		count++;
		loopFrame = loopFrame->GetpNext();
	}

	cout << "Selected Option: 3\nEdit Frame in the animation\nThere are " << count << " frame(s) in the list. Please specify the index(<= " << count - 1 << ") to edit at : ";
	//input validation
	while (!(cin >> index) || (index > count) || (index < 0)) {
		cout << "Error! Enter a valid integer:";
		cin.clear();
		cin.ignore(123, '\n');
	}

	count = 0;
	Frame* temp = this->frames;

	while (temp != nullptr) {
		if (count == index) {
			cout << "The name of the frame is " << temp->GetFrameName() << ". What do you wish to replace it with?\n";
			cin.ignore(123, '\n');
			cin.getline(newFrameName, 100);
			delete temp->GetFrameName();
			//allocate memory for new frame name
			temp->GetFrameName() = (char*)new char[strlen(newFrameName) + 1];
			strcpy(temp->GetFrameName(), newFrameName);
			break;
		}
		temp = temp->GetpNext();
		count++;
	}


}
/***********************************************
Function name  :DeleteFrame
Purpose        :Deletes the frame in the particular index
In parameters  : None
Out Parameters :None
Version        :1.0
************************************************/
void Animation::DeleteFrame() {
	Frame* current = this->frames;

	/*begins by checking if there are any frames in the animation, returns to menu if there are not*/
	if (this->frames == nullptr) {
		cout << "Animation is empty, no frames to delete" << endl;
		return;
	}

	/*checks if theres only one frame, removes if true and returns to menu*/
	if (current->GetpNext() == nullptr) {
		this->frames = this->frames->GetpNext();
		delete current;
		return;
	}

	/*iterates through the animation until it reaches the second last frame, sets that frame's pNext = NULL, cutting off the last frame from the linked list*/
	while (current->GetpNext()->GetpNext() != nullptr) {
		current = current->GetpNext();
	}

	Frame* lastFrame = current->GetpNext();
	current->GetpNext() = nullptr;

	delete lastFrame;
	return;

}
/***********************************************
Function name  :ReportAnimation
Purpose        :Reports all the frames that we inserted to the list
In parameters  : None
Out Parameters :None
Version        :1.0
************************************************/
void Animation::ReportAnimation() {
	Frame* current = this->frames;
	int counter = 0;

	if (current == nullptr) {
		cout << "Animation is empty!" << endl;
	}

	//iterate through linked list to print frame details
	while (current != nullptr) {
		//will be printing with these details
		cout << "Image #" << counter << ", file name = " << current->GetFrameName() << endl;
		counter++;
		current = current->GetpNext();
	}


}
