#include "Bullet.h"
#include"ResourceManager.h"


Bullet::Bullet(Scene * scene)
{
	auto bulletSpace = ResourceManager::getInstance()->getSpriteById(2);
	auto bullet = Sprite::createWithSpriteFrame(bulletSpace->getSpriteFrame());
	this->setM_sprite(bullet);
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
