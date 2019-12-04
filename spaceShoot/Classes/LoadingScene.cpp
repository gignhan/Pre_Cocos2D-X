﻿/****************************************************************************
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

	auto background = Sprite::create("./Sprites/background.png");
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(Vec2(0,0));
	background->setScale(0.7f);
	addChild(background);
    
	//Tạo hình ảnh nền
	auto loadingBarGB = Sprite::create("./Sprites/Loading/loadingbar_bg.png");
	loadingBarGB->setPosition(Vec2(250, 350));
	addChild(loadingBarGB);

	//Tạo 1 LoadingBar từ hình ảnh loadingbar.png
	static auto loadingbar = ui::LoadingBar::create("./Sprites/Loading/loadingbar.png");
	loadingbar->setPosition(loadingBarGB->getPosition());

	//đặt mức độ hoàn thành lúc mới bắt đầu là 0/100
	loadingbar->setPercent(0);
	//Thiết lập hướng của tiến trình, ở đây là từ trái sang phải
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);

	addChild(loadingbar);
	//hàm lambda để cập nhật tiến trình
	auto updateLoadingBar = CallFunc::create([]() {
		if (loadingbar->getPercent() < 100)
		{
			loadingbar->setPercent(loadingbar->getPercent() + 1);
		}
	});

	auto sequenceRunUpdateLoadingBar = Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeat = Repeat::create(sequenceRunUpdateLoadingBar, 100);
	loadingbar->runAction(repeat);
	
    return true;
}

void LoadingScene::Update(float deltaTime)
{
	auto mainmenu = MainMenuScene::createScene();
	auto s = Director::getInstance();
	s->replaceScene(mainmenu);
}



