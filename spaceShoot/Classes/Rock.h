#pragma once
#include"Object_spaceshooter.h"
#include"ResourceManager.h"
class Rock:public Object_spaceshooter
{
public:
	Rock();
	Rock(Scene* scene);
	~Rock();
	void Init();
	void Update(float deltaTime);
};

