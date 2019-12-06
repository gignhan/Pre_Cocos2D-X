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

#include "LoadingScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "Bullet.h"
USING_NS_CC;

Scene* LoadingScene::createScene()
{
    return LoadingScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool LoadingScene::init()
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
	CreateRock();

    return true;
}
void LoadingScene::CreateRock()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	for (int i = 0; i < 20; i++)
	{
		auto rock = new Rock(this);
		r.push_back(rock);
		//addChild(rock->getM_sprite());
		rock->getM_sprite()->setPosition(i * visibleSize.width / 20, visibleSize.height + 300);
		
	}
}

float dt = 0;
void LoadingScene::update(float deltaTime)
{
	
	dt += deltaTime;
	if (dt >= 0.5f)
	{
		dt = 0; 
		s->Update(0.1f);
	}

	// make the rock move
	int randomNumber = rand() % r.size() + 1;
	auto moveBy = MoveBy::create(8.0f, Vec2(700, -100));
	if (dt >= 0.5f)
	{
		for (int i = randomNumber; i < r.size(); i++)
		{
			auto rock = this->r[i]->getM_sprite();
			if (!rock->isVisible())
			{
				rock->runAction(moveBy->clone());
				rock->setVisible(true);
				i = r.size() + 10;
				dt = 0;
			}
		}
	}
	for (int i = 0; i < r.size(); i++)
	{
		this->r[i]->Update(deltaTime);
	}
}



