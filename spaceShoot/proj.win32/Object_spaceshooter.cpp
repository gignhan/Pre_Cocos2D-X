#include "Object_spaceshooter.h"



Object_spaceshooter::Object_spaceshooter()
{
}


Object_spaceshooter::~Object_spaceshooter()
{
}

Sprite * Object_spaceshooter::getM_sprite()
{
	return m_sprite;
}

void Object_spaceshooter::setM_sprite(Sprite * s)
{
	m_sprite = s;
}
