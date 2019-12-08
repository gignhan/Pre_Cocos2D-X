#include "SpaceShooter.h"


Sprite * DuplicateSprite(Sprite * sprite);
SpaceShooter::SpaceShooter()
{
}

SpaceShooter::SpaceShooter(Scene * scene)
{
	ResourceManager * resource = new ResourceManager();
	resource->Init("Data.bin");
	m_sprite = resource->getSpriteById(4); // Ship 
	auto background = Sprite::create("./Sprites/bg_for_game.png");
	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(0, 0);
	scene->addChild(background);



	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("./Sprites/SpaceShip/ship.plist", "./Sprites/SpaceShip/ship.png");

	const int numberSprite = 5;

	m_sprite = Sprite::createWithSpriteFrameName("1.png");
	m_sprite->setAnchorPoint(Vec2(0.5, 1));
	m_sprite->setPosition(200, 150);
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

	for (int i = 0; i < 20; i++)
	{
		Bullet* b = new Bullet(scene);
		m_bullet.push_back(b);
	}

}


SpaceShooter::~SpaceShooter()
{
}

void SpaceShooter::Init()
{

}

void SpaceShooter::Update(float deltaTime)
{
	Shoot();
}

void SpaceShooter::Shoot()
{
	/*auto move = MoveBy::create(1.5f, Vec2(0, 700));

	for (int i = 1; i < 20; i++)
	{
	m_bullet[i]->m_sprite->setPosition(this->m_sprite->getPosition().x, this->m_sprite->getPosition().y);
	m_bullet[i]->m_sprite->runAction(move);
	}*/
	auto moveBy = MoveBy::create(1.5f, Vec2(0, 700));
	auto sequence = Sequence::create(moveBy, nullptr);
	for (int i = 0; i < 20; i++)
	{
		auto bullet = this->m_bullet[i]->getM_sprite();
		if (!bullet->isVisible()) {
			bullet->setVisible(true);
			bullet->setPosition(this->getM_sprite()->getPosition().x, this->getM_sprite()->getPosition().y);
			bullet->runAction(sequence->clone());

			break;
		}
		if (bullet->getPosition().y > 700)
		{
			bullet->stopAllActions();
			bullet->setVisible(false);
			bullet->setPosition(this->getM_sprite()->getPosition().x, this->getM_sprite()->getPosition().y);
		}
	}
}

void SpaceShooter::Collision(vector<Rock*> v)
{

}
Sprite * DuplicateSprite(Sprite * sprite)
{
	Sprite* pRet = Sprite::createWithTexture(sprite->getTexture());
	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite* spriteChild = (Sprite*)sprite->getChildren().at(child);
			Sprite* clone = DuplicateSprite((Sprite*)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}