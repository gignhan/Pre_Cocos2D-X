#include "Rock.h"



Rock::Rock()
{
}


Rock::Rock(Scene * scene)
{
	ResourceManager * resource = new ResourceManager();
	resource->Init("Data.bin");
	m_sprite = resource->getSpriteById(3);
	//m_sprite->setVisible(false);
	scene->addChild(m_sprite);
}

Rock::~Rock()
{
}

void Rock::Init()
{
}

void Rock::Update(float deltaTime)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rock = getM_sprite();
	if (rock->getPosition().y < -100)
	{
		rock->setVisible(false);
		rock->stopAllActions();
		rock->setPosition(rock->getPosition().x, visibleSize.height + 300);
	}
}
