#include "SpaceShooter.h"



SpaceShooter::SpaceShooter()
{
}

SpaceShooter::SpaceShooter(Scene * scene)
{
	m_sprite = Sprite::create("./Sprites/SpaceShipspaceship.png");
	scene->addChild(m_sprite);
}


SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{
}

void SpaceShooter::Update(float deltaTime)
{
}

void SpaceShooter::Shoot()
{
}

//void SpaceShooter::Collision(Vector<Rock*> v)
//{
//}
