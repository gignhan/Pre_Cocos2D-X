/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

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
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	scheduleUpdate();
	s = new SpaceShooter(this);
	s->m_sprite->setAnchorPoint(Vec2(0.5,0.5));
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
	for (int i = 0; i < 20; i++)
	{
		Object_spaceshooter* rock = new Rock(this);
		r.push_back(rock);
		rock->m_sprite->setPosition(Vec2(rock->m_sprite->getPosition().x +30, 750));

		
	}
}
void GamePlayScene::MoveRock()
{
	auto moveBy = MoveBy::create(3, Vec2(100, -900));
	for (int i = 0; i < 20; i++)
	{
		auto rock = this->r[i]->m_sprite;
		rock->setPosition(Vec2(100, 750));
		rock->runAction(moveBy);
		if (rock->getPosition().y < 0)
		{
			rock->stopAllActions();
			rock->setVisible(false);
			rock->setPosition(Vec2(i + 10,700));
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
		s->Update(0.3f);	
		
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

