#ifndef __GAMEPLAY_SCENE_H__
#define __GAMEPLAY_SCENE_H__

#include "cocos2d.h"
#include "SpaceShooter.h"
class GamePlayScene : public cocos2d::Scene
{
private:

	Object_spaceshooter* s;
	vector<Object_spaceshooter*> r;
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void CreateRock();
	void MoveRock(float dt);
	// a selector callback
	void update(float deltaTime);
	// on Touch 
	bool onTouchBegan(Touch *touch, Event *urused_event);
	void onTouchMoved(Touch *touch, Event *urused_event);
	void onTouchEnded(Touch *touch, Event *urused_event);

	// implement the "static create()" method manually
	CREATE_FUNC(GamePlayScene);
};

#endif // __GAMEPLAY_SCENE_H__