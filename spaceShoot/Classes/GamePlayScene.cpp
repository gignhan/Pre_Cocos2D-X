#include "GamePlayScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "Bullet.h"
USING_NS_CC;

Scene* GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GamePlayScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	scheduleUpdate();
	s = new SpaceShooter(this);
	s->m_sprite->setAnchorPoint(Vec2(0.5, 0.5));
	CreateRock();
	//MoveRock();
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	return true;
}
void GamePlayScene::CreateRock()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = 0; i < 30; i++)
	{
		auto randomX = RandomHelper::random_int(0, 480);
		Object_spaceshooter* rock = new Rock(this);
		r.push_back(rock);
		rock->m_sprite->setPosition(Vec2(randomX, 700));


	}
}
void GamePlayScene::MoveRock(float dt)
{
	auto randomX1 = RandomHelper::random_int(0, 480);
	auto moveBy = MoveTo::create(1.5f, Vec2(randomX1, -30));
	auto sequence = Sequence::create(moveBy, nullptr);
	for (int i = 0; i < 30; i++)
	{
		auto bullet = this->r[i]->getM_sprite();
		if (!bullet->isVisible()) {
			bullet->setVisible(true);
			bullet->setPosition(randomX1, 700);
			bullet->runAction(sequence->clone());
			dt = 0;
			break;
		}
		if (bullet->getPosition().y <=0)
		{
			bullet->stopAllActions();
			bullet->setVisible(false);
			bullet->setPosition(randomX1, 700);
		}
	}
}
float dt = 0;
void GamePlayScene::update(float deltaTime)
{

	dt += deltaTime;

	if (dt >= 0.5f)
	{
		dt = 0;
		s->Update(0.1f);
		MoveRock(0.1f);
	}




}

bool GamePlayScene::onTouchBegan(Touch * touch, Event * urused_event)
{
	Vec2 touchLocation = touch->getLocation();// toa do cham tren man hinh

	auto moveTo = MoveTo::create(0.1f, Vec2(touchLocation.x, touchLocation.y));
	s->m_sprite->runAction(moveTo);
	return true;
}

void GamePlayScene::onTouchMoved(Touch * touch, Event * urused_event)
{
	Vec2 touchLocation = touch->getLocation();
	s->m_sprite->setPosition(touchLocation);
}

void GamePlayScene::onTouchEnded(Touch * touch, Event * urused_event)
{
	Vec2 touchLocation = touch->getLocation();
	s->m_sprite->setPosition(touchLocation);
}
