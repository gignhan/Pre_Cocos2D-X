#include "Object_spaceshooter.h"



Object_spaceshooter::Object_spaceshooter()
{
	m_sprite = new Sprite();
}


Object_spaceshooter::~Object_spaceshooter()
{
	delete m_sprite;
}

Sprite * Object_spaceshooter::getM_sprite()
{
	return m_sprite;
}

void Object_spaceshooter::setM_sprite(Sprite * s)
{
	m_sprite = s;
}
