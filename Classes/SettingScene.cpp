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

#include "SettingScene.h"
#include "SimpleAudioEngine.h"
//#include "MainMenuScene.h"
USING_NS_CC;

Scene* Setting::createScene()
{
    return Setting::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Setting::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    /*auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 16);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
	
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }*/	
	auto sprite = Sprite::create("./Sprites/background.png");
	sprite->setAnchorPoint(Vec2(0, 0));
	sprite->setPosition(Vec2(0, 0));
	addChild(sprite);

	auto logo = Sprite::create("./Sprites/Logo/logo__.png");
	logo->setAnchorPoint(Vec2(0, 0));
	logo->setPosition(Vec2(50, 550));
	addChild(logo);

	auto itemSound = MenuItemFont::create("Sound", CC_CALLBACK_1(Setting::onClickItemSound, this));
	auto itemAbout = MenuItemFont::create("About", CC_CALLBACK_1(Setting::onClickItemAbout, this));
	auto itemBack = MenuItemImage::create("./Buttons/resume_normal.png", "./Buttons/resume_pressed.png" ,CC_CALLBACK_1(Setting::menuCloseCallback, this));
	itemSound->setPosition(Vec2(10, 200));
	itemAbout->setPosition(Vec2(10, 100));
	//itemBack->setAnchorPoint(Vec2(1,1));
	//itemBack->setPosition(Vec2(10 , 150));
	// Create Menu from array of menuItem
	Vector<MenuItem*> menuItems;
	menuItems.pushBack(itemSound);
	menuItems.pushBack(itemAbout);
	//menuItems.pushBack(itemBack);
	auto menu = Menu::createWithArray(menuItems);
	menu->setAnchorPoint(Vec2(0,0));
	menu->setPosition(Vec2(100, 100));
	addChild(menu);
	
	static auto textField = ui::TextField::create("Hello Cocos2d-x", "Arial", 24);
	textField->setMaxLengthEnabled(true);
	textField->setMaxLength(10);
	//textField->setPasswordEnabled(true);
	textField->setPosition(Vec2(220, 500));
	textField->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		log("editing a TextField");
	});
	addChild(textField);

	


    return true;
}


void Setting::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();
	//auto main = MainMenuScene::create();
	//Director::getInstance()->replaceScene(main);

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void Setting::onClickItemSound(cocos2d::Ref * pSender)
{
	
	static auto slider = ui::Slider::create();
	slider->loadBarTexture("./Sprites/slider_bar_bg.png");
	slider->loadSlidBallTextures("./Sprites/slider_ball_normal.png", "./Sprites/slider_ball_pressed.png", "./Sprites/slider_ball_disable.png");
	slider->loadProgressBarTexture("./Sprites/slider_bar_pressed.png");
	slider->setPercent(10);
	slider->setPosition(Vec2(200, 250));
	slider->addClickEventListener([](Ref* event) 
	{
		log("Slider: %d", slider->getPercent());
	});
	addChild(slider);

	auto visibleSize1 = Director::getInstance()->getVisibleSize();
	auto checkbox = ui::CheckBox::create("./Sprites/checkbox_normal.png",
		"./Sprites/checkbox_pressed.png",
		"./Sprites/checkbox_checked.png",
		"./Sprites/checkbox_normal_disable.png",
		"./Sprites/checkbox_checked_disable.png");

	checkbox->setPosition(Vec2(350, 250));
	checkbox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			log("checkbox 1 clicked");
			break;
		default:
			break;
		}
	});

	this->addChild(checkbox);
	
	
}

void Setting::onClickItemAbout(cocos2d::Ref * pSender)
{
	auto label = Label::createWithSystemFont("Game Fight Fly ", "Arial", 20);
	label->setPosition(Vec2(100,50));
	addChild(label);




}
