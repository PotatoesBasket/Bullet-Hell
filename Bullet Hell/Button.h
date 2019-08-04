#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Text.h"
#include "ButtonData.h"
#include <Renderer2D.h>

/*

Button
- intended to be children of a canvas-like gameobject
- uses text and sprite components to make a button, can be either or both
- 3 states (standard, hover, press)
- all components initialised as OFF, set active in parent
- make sure text is added to gameobject components last to render on top of sprite

*/

class Button : public GameObject
{
public:
	Button(TextButton button, const char* text); //text only button
	Button(SpriteButton button); //image only button
	Button(TextButton textStates, SpriteButton spriteStates, const char* text); //both, currently unused, probably ugly
	~Button() {}

	enum State
	{
		standard,
		hover,
		press
	};

	//Adds text components to button
	void initText(TextButton button, const char* text);
	//Adds sprite components to button
	void initSprite(SpriteButton button);

	//Sets active/inactive correct components based on button state
	void setState(State state);

private:
	State m_state = standard;
	bool m_textOn = false;
	bool m_spriteOn = false;

	//Text button
	std::shared_ptr<Text> m_txtStandard = nullptr;
	std::shared_ptr<Text> m_txtHover = nullptr;
	std::shared_ptr<Text> m_txtPress = nullptr;
	
	//Sprite button
	std::shared_ptr<Sprite> m_sprStandard = nullptr;
	std::shared_ptr<Sprite> m_sprHover = nullptr;
	std::shared_ptr<Sprite> m_sprPress = nullptr;
};