#pragma once
#include"cocos2d.h"
USING_NS_CC;

class Object_spaceshooter
{
public: Sprite* m_sprite;

public:
	Object_spaceshooter();
	~Object_spaceshooter();
	Sprite* getM_sprite();
	void setM_sprite(Sprite* );
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;

};

