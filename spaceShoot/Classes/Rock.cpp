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
	if (m_sprite->getPosition().y < -100)
	{
		m_sprite->setVisible(false);
		m_sprite->stopAllActions();
		m_sprite->setPosition(m_sprite->getPosition().x, visibleSize.height + 300);
	}
}
