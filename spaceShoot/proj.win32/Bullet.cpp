#include "Bullet.h"



Bullet::Bullet(Scene * scene)
{
	m_sprite = Sprite::create("./Sprites/Bullet/bullet.png");
	scene->addChild(m_sprite);
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
}

void Bullet::Update(float deltaTime)
{
}
