#pragma once

#ifndef _STATE_
#define _STATE_

////////////////////////////////////////////////////////////
// ���������
////////////////////////////////////////////////////////////
class	Body;
// enum	Anim;
#include "input.h"


////////////////////////////////////////////////////////////
class BodyState
{
public:
	virtual				~BodyState() {}
	virtual BodyState*	changeState(Body& _body, Input _input) { return nullptr; }
	virtual void		handleInput(Body& _body, Input _input) {};
	virtual void		update(Body& _body) {};
};


////////////////////////////////////////////////////////////
class StandingState : public BodyState
{
public:
	virtual BodyState*	changeState(Body& _body, Input _input);
	virtual void		handleInput(Body& _body, Input _input);
	virtual void		update(Body& _body);
};


////////////////////////////////////////////////////////////
class DuckingState : public BodyState
{
public:
	virtual BodyState*	changeState(Body& _body, Input _input);
};


////////////////////////////////////////////////////////////
class JumpingState : public BodyState
{
public:
	virtual BodyState*	changeState(Body& _body, Input _input);
};


////////////////////////////////////////////////////////////
class RunningState : public BodyState
{
public:
	virtual BodyState*	changeState(Body& _body, Input _input);
	virtual void		handleInput(Body& _body, Input _input);
	virtual void		update(Body& _body);

	float acceleration;
};

#endif // !_STATE_
