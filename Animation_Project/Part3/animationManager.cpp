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
* File Name: animationManager.cpp
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
Function name  :EditAnimation
Purpose        :Allows the user to edit animations
				(edit/delete/insert frames)	
				in the animation manager
In parameters  :None
Out Parameters :None
************************************************/
void AnimationManager::EditAnimation() {
	
	cout << "\nSelected option: 3" << endl;
	//Checks if the vector is empty
	if (AnimationManager::animations.empty() == 1) {
		cout << "There are no animations in the manager" << endl;
	}
	else {
		int index = 0;
		int count = 0;
		cout << "Which animation do you wish to edit? Please provide the index (from 0 to " << this->animations.size()-1 << " ):" << endl;
		//Input validation for index
		while (!(cin >> index) || index < 0 || index > this->animations.size()) {
			cout << "Invalid index!";
			cin.clear();
			cin.ignore(123, '\n');
		}
		cout << "Editing Animation # " << index << endl;
		bool loopCheck = true;
		char choice = 0;
		do {
			cout << "\nMENU\n 1. Insert a Frame\n 2. Delete a Frame\n 3. Edit a Frame\n 4. Quit" << endl;
			cin >> choice;
			//Switch case used to prompt the frame edit options menu
				switch (choice)
				{
				//Case 1 - insert a frame to the selected animation
				case '1':cin >> animations.at(index); break;
				//Case 2 - delete a frame in the selected animation
				case '2':animations.at(index).DeleteFrame(); break;
				//Case 3 - edit a frame in the selected animation
				case '3':animations.at(index).EditFrame(); break;
				//Case 4 - quit
				case '4':loopCheck = false; break;
				//Default - input validation
				default:cout << "Please enter a valid option" << endl;
				}
		} while (loopCheck == true);
		cout << "Animation #" << index << " edit is complete\n" << endl;
	}
}

/***********************************************
Function name  :DeleteAnimation
Purpose        :Delete an animation from the 
				animation manager
In parameters  :None
Out Parameters :None
************************************************/
void AnimationManager::DeleteAnimation() {
	cout << "\nSelected option: 2 \n" << endl;
	//Checks if the vector is empty
	if (animations.empty() == 1) {
		cout << "There are no animations in the manager" << endl;
	}
	else {
		int index;
		cout << "Delete an animation from the animation manager \nWhich animation do you wish to delete? Please provide the index (from 0 to " << animations.size()-1 << " ):" << endl;
		//Input validation for index
		while (!(cin >> index) || index < 0 || index > animations.size()) {
			cout << "Invalid index!";
			cin.clear();
			cin.ignore(123, '\n');
		}
		animations.erase(animations.begin()+index);
		cout << "Animation #" << index << " deleted" << endl;
	}
}

/***********************************************
Overload name  : >>
Purpose        :Overload assignment operator (>>) - 
				Adds an animation to the end of the
				animation manager
In parameters  :in - input stream object
				animate - Animation object reference
Out Parameters :istream reference
************************************************/
istream& operator>>(istream& in, AnimationManager& animate) {
	cout << "\nSelected option:1 \nAdd an animation to the animation manager \nPlease enter the animation name: " << endl;
	string animateName;
	cin.ignore(123, '\n');
	getline(cin, animateName);
	Animation animation1 = Animation(animateName);
	animate.animations.push_back(animation1);
	cout << "Animation " << animateName << " added at the back of animations\n" << endl;
	return in;

}

/***********************************************
Overload name  : <<
Purpose        :Overload assignment operator (<<) - 
				Animation manager output to console
In parameters  :out - output stream object
				animate - Animation object reference
Out Parameters :ostream reference
************************************************/
ostream& operator<<(ostream& out, AnimationManager& animate) {
	out << "\nSelected option: 4 \nAnimation Manager: " << animate.managerName << endl;
	for (int x = 0; x < animate.animations.size(); x++) {
		out << "Animation: " << x << endl;
		out << animate.animations.at(x);
	}
	cout << endl;
	return out;
}