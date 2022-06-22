// Animation.h
//@author: Surbhi Bahri
#pragma once

class Animation
{
	std::string AnimationName;
	std::forward_list<Frame> frames;
public:
	Animation(std::string name) :AnimationName(name) {  }
	~Animation() { }
	void EditFrame();
	void DeleteFrame();
	// Add a frame as in cin>>A;
	friend std::istream& operator>>(std::istream&, Animation&);
	// Output the frames as in cout<<A;
	friend std::ostream& operator<<(std::ostream&, Animation&);
};
