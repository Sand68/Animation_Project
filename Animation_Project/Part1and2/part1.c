/*
* Final Project - Animation Project (Part 1)
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
* File Name: part1.cpp
*
*/

// part1.c

//@author: Surbhi Bahri


#define _CRT_SECURE_NO_WARNINGS

#define _CRTDBG_MAP_ALLOC // need this to get the line identification



//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations


//NB must be in debug build


#include <crtdbg.h>


#include <stdio.h>


#include <string.h>


typedef enum { FALSE = 0, TRUE } BOOL;


struct Frame {


	char* frameName;


	struct Frame* pNext;


};


typedef struct {

	char* animationName;

	struct Frame* frames;


}Animation;


// Forward declarations

void InitAnimation(Animation*);


void InsertFrame(Animation*);


void DeleteFrame(Animation*);

void EditFrame(Animation*);


void ReportAnimation(Animation*);


void CleanUp(Animation*);


int main(void)


{

	char response;


	BOOL RUNNING = TRUE;

	Animation RG;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	InitAnimation(&RG);


	while (RUNNING)


	{


		printf("MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit\n"); scanf("%c", &response);


		switch (response)

		{

		case '1':InsertFrame(&RG); break;

		case '2':DeleteFrame(&RG); break;


		case '3':EditFrame(&RG); break;


		case '4':ReportAnimation(&RG); break;

		case '5':RUNNING = FALSE; CleanUp(&RG); break;


		default:printf("Please enter a valid option\n");


		}

	}

	return 0;

}

/***********************************************
Function name  :InitAnimation
Purpose        :This method allocate memory and askes for the name of animation.
In parameters  : a - Animation Pointer
Out Parameters :None
************************************************/

void InitAnimation(Animation* a) {
	char str[20];

	//allocating memory for animation object
	Animation* temp = (Animation*)malloc(sizeof(Animation));
	if (temp == NULL) {
		printf("\nfailed to dynamically allocate memory");
		return;
	}

	temp->frames = NULL;

	printf("Enter the animation name\n");
	scanf("%[^\n],", str);

	//allocating memory for char animation  name
	temp->animationName = (char*)malloc(strlen(str) + 1);
	//if memory allocating fails, return
	if (temp->animationName == NULL) {
		printf("\nfailed to dynamically allocate memory\n");
		return;
	}
	strcpy(temp->animationName, str);

	*a = *temp;
	//free temp object
	free(temp->animationName);
	free(temp);
	while ((getchar()) != '\n');

}

/***********************************************
Function name  :InsertFrame
Purpose        :This method insert an frame to the head of the linked list
In parameters  : a - Animation Pointer
Out Parameters :None
************************************************/

void InsertFrame(Animation* a) {
	while ((getchar()) != '\n');
	char name[256];
	struct Frame* frame;

	//allocate memory for frame object
	frame = (struct Frame*)malloc(sizeof(struct Frame));
	if (frame == NULL) {
		printf("\nfailed to dynamically allocate memory\n");
		return;
	}

	int size = strlen(name) + 1;
	//allocate memory for frame name
	frame->frameName = (char*)malloc(size);

	if (frame->frameName == NULL) {
		printf("\nfailed to dynamically allocate memory\n");
		return;
	}

	printf("Selected Option: 1\n");
	printf("Insert a frame in the animation\n");
	printf("Please enter the frame name: ");
	scanf("%[^\n],", name);
	strcpy(frame->frameName, name);

	struct Frame* current;

	//empty linked list case; add to head
	if (a->frames == NULL) {
		frame->pNext = NULL;
		a->frames = frame;
	}
	//list not empty, add to head of list; keep track of old head in current
	else {
		current = a->frames;
		frame->pNext = current;
		a->frames = frame;
	}
	//clear input
	while ((getchar()) != '\n');

}

/***********************************************
Function name  :DeleteFrame
Purpose        :Deletes the frame in the particular index
In parameters  : a - Animation Pointer
Out Parameters :None
************************************************/
void DeleteFrame(Animation* a) {
	while ((getchar()) != '\n');
	struct Frame* current = a->frames;

	//empty animation
	if (current == NULL) {
		printf("The animation is empty, thus no frames to delete\n");
		return;
	}

	//only one frame in animation case (delete head)
	if (current->pNext == NULL) {
		free(current->frameName);
		free(current);
		a->frames = NULL;
		return;
	}

	//multiple frames in animation case
	while (current->pNext->pNext != NULL) {
		current = current->pNext;
	}
	//free frame to be deleted
	free(current->pNext->frameName);
	free(current->pNext);
	//set new tail to point to null
	current->pNext = NULL;
}

/***********************************************
Function name  :EditFrame
Purpose        :This method replace a frame for an particular index
In parameters  : a - Animation Pointer
Out Parameters :None
************************************************/
void EditFrame(Animation* a) {
	//clear input
	while ((getchar()) != '\n');

	int count = 1;
	int Index = 0;
	struct Frame* countOfFrame = a->frames;
	struct Frame* edit = a->frames;
	char replaceName[1000];
	char* temp;

	printf("Selected Option 3\n");

	//no frames in animation
	if (countOfFrame == NULL) {
		printf("There are no frames in the animation to edit\n");
		return;
	}

	//count frames in animation
	while (countOfFrame->pNext != NULL) {
		count++;
		countOfFrame = countOfFrame->pNext;
	}

	//Input validation
	while (1) {
		printf("Edit a Frame in the animation\n");
		printf("There are %d Frame(s) in the list. Please specify the index (<=%d) to edit at: \n", count, (count - 1));
		if ((scanf("%d", &Index) != 1) || Index < 0 || Index >= count) {
			printf("There is no frame at that index.\n");
			while ((getchar()) != '\n');
		}
		else {
			while ((getchar()) != '\n');
			break;
		}
	}

	//select frame to edit
	if (Index > 0) {
		for (int i = 0; i < Index; i++) {
			edit = edit->pNext;
		}
		printf("The name of this Frame is %s. What do you wish to replace it with? \n", edit->frameName);
	}
	else {
		printf("The name of this Frame is %s. \nWhat do you wish to replace it with? \n", edit->frameName);
	}

	scanf("%[^\n]", replaceName);
	//reallocate memory for new frame name
	temp = realloc(edit->frameName, strlen(replaceName) + 1);

	//check if realloc is successfull
	if (edit->frameName != temp) {
		edit->frameName = temp;
	}
	strcpy(edit->frameName, replaceName);
	while ((getchar()) != '\n');
}
/***********************************************
Function name  :ReportAnimation
Purpose        :Reports all the frames that we inserted to the list
In parameters  : a - Animation Pointer
Out Parameters :None
************************************************/
void ReportAnimation(Animation* a) {
	while ((getchar()) != '\n');
	struct Frame* current;
	int counter = 0;

	printf("Selected Option: 4\n");

	//animation not created
	if (a == NULL) {
		printf("Animation does not exist!\n");
		return;
	}

	printf("Report the animation\n");

	//set current to head of list
	current = a->frames;

	if (current == NULL) {
		printf("Animation is empty!\n");
	}

	//iterate through linked list to print frame details
	while (current != NULL) {
		printf("Image #%d, file name = %s\n", counter, current->frameName);
		counter++;
		current = current->pNext;
	}
}

/***********************************************
Function name  :CleanUp
Purpose        :This method free up all unwanted space
In parameters  : a - Animation Pointer
Out Parameters :None
************************************************/
void CleanUp(Animation* a) {
	struct Frame* toDelete = a->frames;
	struct Frame* next;

	//empty animation case
	if (a->frames == NULL)
	{
		return;
	};
	//loop through linked list and free frame name then frame object
	do {
		next = toDelete->pNext;
		free(toDelete->frameName);
		free(toDelete);
		toDelete = next;
	} while (toDelete != NULL);
	printf("Exiting...\n");

}