#pragma once
#include"Object_spaceshooter.h"
#include"Rock.h"
#include"Bullet.h"
class SpaceShooter :public Object_spaceshooter
{
protected :  
	float dt = 0;
	std::vector<Object_spaceshooter*> m_bullet;
	//vector<Sprite*> m_bullet;

public:
	SpaceShooter();
	SpaceShooter(Scene * scene);
	~SpaceShooter();
	void Init();
	void Update(float deltaTime);
	void Shoot();
	void Collision(vector<Rock*> v);


};

