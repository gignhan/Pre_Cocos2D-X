#include "Bullet.h"
#include"ResourceManager.h"


Bullet::Bullet(Scene * scene)
{
	ResourceManager * resource = new ResourceManager();
	resource->Init("Data.bin");
	m_sprite = resource->getSpriteById(2);
	m_sprite->setPosition(Vec2(100,130));
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
	auto moveBy = MoveTo::create(4.0f, Vec2(0, 700));
	auto sequence = Sequence::create(moveBy->reverse(), nullptr);
	this->getM_sprite()->runAction(sequence);
}
