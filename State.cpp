#include "State.h"
#include "Body.h"
#include "Controlling.h"
#include "math.h"

////////////////////////////////////////////////////////////
BodyState* StandingState::changeState(Body& _body, Input _input)
{
	if (_input == Input::PRESS_DUCK) return new DuckingState();
	if (_input == Input::PRESS_JUMP) return new JumpingState();
	if (_input == Input::PRESS_RUN) return new RunningState();
	return NULL;
}


////////////////////////////////////////////////////////////
BodyState* DuckingState::changeState(Body& _body, Input _input)
{
	if (_input == Input::RELEASE_DUCK) return new StandingState();
	return NULL;
}


////////////////////////////////////////////////////////////
BodyState* JumpingState::changeState(Body& _body, Input _input)
{
	if (_input == Input::STOP) return new StandingState();
	return NULL;
}


////////////////////////////////////////////////////////////
BodyState* RunningState::changeState(Body& _body, Input _input)
{
	if (_input == Input::RELEASE_RUN) return new StandingState();
	if (_input == Input::PRESS_JUMP)  return new JumpingState();
	if (_input == Input::STOP)  return new StandingState();
	return NULL;
}


////////////////////////////////////////////////////////////
void StandingState::handleInput(Body& _body, Input _input)
{
	float v = _body.m_velocity;
	float vd = v / sqrt(2);

	//@// �������? �� ������ switch-case. ��� ������� State �� ������ ������� �� ������� � �������� ��� ����������!!! (������ switch-case ���������� ������)
	switch (_input)
	{
	case NONE:					switch (_body.m_anim)
								{
								case WALK_UP:			_body.setGraphics(Anim::STAND_UP);		break;
								case WALK_UP_RIGHT:		_body.setGraphics(Anim::STAND_RIGHT);	break;
								case WALK_RIGHT:		_body.setGraphics(Anim::STAND_RIGHT);	break;
								case WALK_DOWN_RIGHT:	_body.setGraphics(Anim::STAND_RIGHT);	break;
								case WALK_DOWN:			_body.setGraphics(Anim::STAND_DOWN);	break;
								case WALK_DOWN_LEFT:	_body.setGraphics(Anim::STAND_LEFT);	break;
								case WALK_LEFT:			_body.setGraphics(Anim::STAND_LEFT);	break;
								case WALK_UP_LEFT:		_body.setGraphics(Anim::STAND_LEFT);	break;
								case RUN_UP:			_body.setGraphics(Anim::STAND_UP);		break;
								case RUN_UP_RIGHT:		_body.setGraphics(Anim::STAND_RIGHT);	break;
								case RUN_RIGHT:			_body.setGraphics(Anim::STAND_RIGHT);	break;
								case RUN_DOWN_RIGHT:	_body.setGraphics(Anim::STAND_RIGHT);	break;
								case RUN_DOWN:			_body.setGraphics(Anim::STAND_DOWN);	break;
								case RUN_DOWN_LEFT:		_body.setGraphics(Anim::STAND_LEFT);	break;
								case RUN_LEFT:			_body.setGraphics(Anim::STAND_LEFT);	break;
								case RUN_UP_LEFT:		_body.setGraphics(Anim::STAND_LEFT);	break;
								}
								break;
	case PRESS_UP:				_body.move(sf::Vector2f(0, -v));
								_body.setGraphics(Anim::WALK_UP);
								break;
	case PRESS_UP_RIGHT:		_body.move(sf::Vector2f(vd, -vd));
								_body.setGraphics(Anim::WALK_UP_RIGHT);
								break;
	case PRESS_RIGHT:			_body.move(sf::Vector2f(v, 0));
								_body.setGraphics(Anim::WALK_RIGHT);
								break;
	case PRESS_DOWN_RIGHT:		_body.move(sf::Vector2f(vd, vd));
								_body.setGraphics(Anim::WALK_DOWN_RIGHT);
								break;
	case PRESS_DOWN:			_body.move(sf::Vector2f(0, v));
								_body.setGraphics(Anim::WALK_DOWN);
								break;
	case PRESS_DOWN_LEFT:		_body.move(sf::Vector2f(-vd, vd));
								_body.setGraphics(Anim::WALK_DOWN_LEFT);
								break;
	case PRESS_LEFT:			_body.move(sf::Vector2f(-v, 0));
								_body.setGraphics(Anim::WALK_LEFT);
								break;
	case PRESS_UP_LEFT:			_body.move(sf::Vector2f(-vd, -vd));
								_body.setGraphics(Anim::WALK_UP_LEFT);
								break;
	}
}


////////////////////////////////////////////////////////////
void RunningState::handleInput(Body& _body, Input _input)
{
	float a = _body.m_acceleration;
	float v = _body.m_velocity;
	float vd = v / sqrt(2);

	//@// �������? �� ������ switch-case. ��� ������� State �� ������ ������� �� ������� � �������� ��� ����������!!! (������ switch-case ���������� ������)
	switch (_input)
	{
	case NONE:					switch (_body.m_anim)
								{
								case WALK_UP:			_body.setGraphics(Anim::STAND_UP);		break;
								case WALK_UP_RIGHT:		_body.setGraphics(Anim::STAND_RIGHT);	break;
								case WALK_RIGHT:		_body.setGraphics(Anim::STAND_RIGHT);	break;
								case WALK_DOWN_RIGHT:	_body.setGraphics(Anim::STAND_RIGHT);	break;
								case WALK_DOWN:			_body.setGraphics(Anim::STAND_DOWN);	break;
								case WALK_DOWN_LEFT:	_body.setGraphics(Anim::STAND_LEFT);	break;
								case WALK_LEFT:			_body.setGraphics(Anim::STAND_LEFT);	break;
								case WALK_UP_LEFT:		_body.setGraphics(Anim::STAND_LEFT);	break;
								case RUN_UP:			_body.setGraphics(Anim::STAND_UP);		break;
								case RUN_UP_RIGHT:		_body.setGraphics(Anim::STAND_RIGHT);	break;
								case RUN_RIGHT:			_body.setGraphics(Anim::STAND_RIGHT);	break;
								case RUN_DOWN_RIGHT:	_body.setGraphics(Anim::STAND_RIGHT);	break;
								case RUN_DOWN:			_body.setGraphics(Anim::STAND_DOWN);	break;
								case RUN_DOWN_LEFT:		_body.setGraphics(Anim::STAND_LEFT);	break;
								case RUN_LEFT:			_body.setGraphics(Anim::STAND_LEFT);	break;
								case RUN_UP_LEFT:		_body.setGraphics(Anim::STAND_LEFT);	break;
								}
								break;
	case PRESS_UP:				_body.move(sf::Vector2f(0, -a*v));
								_body.setGraphics(Anim::RUN_UP);
								break;
	case PRESS_UP_RIGHT:		_body.move(sf::Vector2f(a*vd, -a *vd));
								_body.setGraphics(Anim::RUN_UP_RIGHT);
								break;
	case PRESS_RIGHT:			_body.move(sf::Vector2f(a*v, 0));
								_body.setGraphics(Anim::RUN_RIGHT);
								break;
	case PRESS_DOWN_RIGHT:		_body.move(sf::Vector2f(a*vd, a *vd));
								_body.setGraphics(Anim::RUN_DOWN_RIGHT);
								break;
	case PRESS_DOWN:			_body.move(sf::Vector2f(0, a*v));
								_body.setGraphics(Anim::RUN_DOWN);
								break;
	case PRESS_DOWN_LEFT:		_body.move(sf::Vector2f(-a*vd, a *vd));
								_body.setGraphics(Anim::RUN_DOWN_LEFT);
								break;
	case PRESS_LEFT:			_body.move(sf::Vector2f(-a*v, 0));
								_body.setGraphics(Anim::RUN_LEFT);
								break;
	case PRESS_UP_LEFT:			_body.move(sf::Vector2f(-a*vd, -a *vd));
								_body.setGraphics(Anim::RUN_UP_LEFT);
								break;
	}
}


void StandingState::update(Body& _body)
{
	if (_body.m_stamina < _body.m_max_stamina)
		_body.m_stamina += 0.2;
}



void RunningState::update(Body& _body)
{
	if (_body.m_stamina > 0)
	{
		acceleration = 2;
		_body.m_stamina -= 0.5;
	}
	else
	{
		acceleration = 1;
		_body.changeState(Input::STOP);
	}
}