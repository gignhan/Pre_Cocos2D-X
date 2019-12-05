#pragma once
#include"Object_spaceshooter.h"
#include"Rock.h"
#include"Bullet.h"
class SpaceShooter :public Object_spaceshooter
{
protected :  
		vector<Object_spaceshooter*> m_bullet;
public:
	SpaceShooter();
	SpaceShooter(Scene * scene);
	~SpaceShooter();
	void Init();
	void Update(float deltaTime);
	void Shoot();
	//void Collision(Vector<Rock*> v);


};

