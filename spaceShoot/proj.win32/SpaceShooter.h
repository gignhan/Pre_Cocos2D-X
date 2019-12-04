#pragma once
#include"Object_spaceshooter.h"
#include"Rock.h"
class SpaceShooter :public Object_spaceshooter
{
//public: Vector<Object_spaceshooter*> m_bullter;
public:
	SpaceShooter();
	SpaceShooter(Scene * scene);
	~SpaceShooter();
	void Init();
	void Update(float deltaTime);
	void Shoot();
	//void Collision(Vector<Rock*> v);


};

