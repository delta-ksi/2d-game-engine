#include "Controlling.h"
#include "State.h"

bool PressUp	= false;
bool PressRight	= false;
bool PressDown	= false;
bool PressLeft	= false;

//@// двойные вызовы стейта из нажатия двух кнопок, из за этого
// при движение по диагонали увеличивается скорость востановления
// и расстраты стамины

////////////////////////////////////////////////////////////
void MoveUp::press(Body& hero)
{
	PressUp = true;
	if (PressLeft)			hero.handelInput(PRESS_UP_LEFT);
	else if (PressRight)	hero.handelInput(PRESS_UP_RIGHT);
	else					hero.handelInput(PRESS_UP);
}


////////////////////////////////////////////////////////////
void MoveRight::press(Body& hero)
{
	PressRight = true;
	if (PressUp)			hero.handelInput(PRESS_UP_RIGHT);
	else if (PressDown)		hero.handelInput(PRESS_DOWN_RIGHT);
	else					hero.handelInput(PRESS_RIGHT);
}


////////////////////////////////////////////////////////////
void MoveDown::press(Body& hero)
{
	PressDown = true;
	if (PressLeft)			hero.handelInput(PRESS_DOWN_LEFT);
	else if (PressRight)	hero.handelInput(PRESS_DOWN_RIGHT);
	else					hero.handelInput(PRESS_DOWN);
}


////////////////////////////////////////////////////////////
void MoveLeft::press(Body& hero)
{
	PressLeft = true;
	if (PressUp)			hero.handelInput(PRESS_UP_LEFT);
	else if (PressDown)		hero.handelInput(PRESS_DOWN_LEFT);
	else					hero.handelInput(PRESS_LEFT);
}


////////////////////////////////////////////////////////////
void MoveUp::release(Body& hero)
{
	PressUp = false;
	if (!PressRight && !PressDown && !PressLeft) hero.handelInput(NONE);
}


////////////////////////////////////////////////////////////
void MoveRight::release(Body& hero)
{
	PressRight = false;
	if (!PressUp && !PressDown && !PressLeft) hero.handelInput(NONE);
}


////////////////////////////////////////////////////////////
void MoveDown::release(Body& hero)
{
	PressDown = false;
	if (!PressUp && !PressRight && !PressLeft) hero.handelInput(NONE);
}


////////////////////////////////////////////////////////////
void MoveLeft::release(Body& hero)
{
	PressLeft = false;
	if (!PressUp && !PressRight && !PressDown) hero.handelInput(NONE);
}

//@// Реализовать доступ к Body только через метод handleInput (никаких changeState)

////////////////////////////////////////////////////////////
void Run::press(Body& hero)
{ hero.changeState(Input::PRESS_RUN); }


////////////////////////////////////////////////////////////
void Run::release(Body& hero)
{ hero.changeState(Input::RELEASE_RUN); }