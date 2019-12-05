#pragma once
#include"Object_spaceshooter.h"
#include"ResourceManager.h"
class Bullet :public Object_spaceshooter
{
public:
	Bullet(Scene* scene);
	~Bullet();
	void Init();
	void Update(float deltaTime);
};