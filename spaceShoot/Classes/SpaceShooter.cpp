#include "SpaceShooter.h"



SpaceShooter::SpaceShooter()
{
}

SpaceShooter::SpaceShooter(Scene * scene)
{
	ResourceManager * resource = new ResourceManager();
	resource->Init("Data.bin");
	m_sprite = resource->getSpriteById(4);
	auto background = resource->getBackGround();
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(0,0);
	background->setScale(0.7f);
	scene->addChild(background);
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("./Sprites/SpaceShip/ship.plist", "./Sprites/SpaceShip/ship.png");

	const int numberSprite = 5;

	m_sprite = Sprite::createWithSpriteFrameName("1.png");
	m_sprite->setAnchorPoint(Vec2(0, 0));
	m_sprite->setPosition(200, 100);
	scene->addChild(m_sprite);

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(numberSprite);

	animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("2.png"));
	animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("3.png"));
	animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("4.png"));
	animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("5.png"));
	animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("6.png"));
	animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("7.png"));
	animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName("8.png"));

	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);

	m_sprite->runAction(RepeatForever::create(animate));

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
