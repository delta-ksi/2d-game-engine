#pragma once

#ifndef _CONTROLLING_
#define _CONTROLLING_

#include <SFML/Graphics.hpp>
#include "Body.h"

#include "input.h"


////////////////////////////////////////////////////////////
class Button
{
public:
	virtual ~Button() {}
	virtual void press(Body& hero) {};
	virtual void release(Body& hero) {};
};


////////////////////////////////////////////////////////////
class MoveUp : public Button
{
public:
	virtual void press(Body& hero);
	virtual void release(Body& hero);
};


////////////////////////////////////////////////////////////
class MoveRight : public Button
{
public:
	virtual void press(Body& hero);
	virtual void release(Body& hero);
};


////////////////////////////////////////////////////////////
class MoveDown : public Button
{
public:
	virtual void press(Body& hero);
	virtual void release(Body& hero);
};


////////////////////////////////////////////////////////////
class MoveLeft : public Button
{
public:
	virtual void press(Body& hero);
	virtual void release(Body& hero);
};


////////////////////////////////////////////////////////////
class Run : public Button
{
public:
	virtual void press(Body& hero);
	virtual void release(Body& hero);
};


////////////////////////////////////////////////////////////
class KeyboardInput
{
public:

	void setA				(Button* command) { m_A = command; }
	void setB				(Button* command) { m_B = command; }
	void setC				(Button* command) { m_C = command; }
	void setD				(Button* command) { m_D = command; }
	void setE				(Button* command) { m_E = command; }
	void setF				(Button* command) { m_F = command; }
	void setG				(Button* command) { m_G = command; }
	void setH				(Button* command) { m_H = command; }
	void setI				(Button* command) { m_I = command; }
	void setJ				(Button* command) { m_J = command; }
	void setK				(Button* command) { m_K = command; }
	void setL				(Button* command) { m_L = command; }
	void setM				(Button* command) { m_M = command; }
	void setN				(Button* command) { m_N = command; }
	void setO				(Button* command) { m_O = command; }
	void setP				(Button* command) { m_P = command; }
	void setQ				(Button* command) { m_Q = command; }
	void setR				(Button* command) { m_R = command; }
	void setS				(Button* command) { m_S = command; }
	void setT				(Button* command) { m_T = command; }
	void setU				(Button* command) { m_U = command; }
	void setV				(Button* command) { m_V = command; }
	void setW				(Button* command) { m_W = command; }
	void setX				(Button* command) { m_X = command; }
	void setY				(Button* command) { m_Y = command; }
	void setZ				(Button* command) { m_Z = command; }
	void setNum0			(Button* command) { m_Num0 = command; }
	void setNum1			(Button* command) { m_Num1 = command; }
	void setNum2			(Button* command) { m_Num2 = command; }
	void setNum3			(Button* command) { m_Num3 = command; }
	void setNum4			(Button* command) { m_Num4 = command; }
	void setNum5			(Button* command) { m_Num5 = command; }
	void setNum6			(Button* command) { m_Num6 = command; }
	void setNum7			(Button* command) { m_Num7 = command; }
	void setNum8			(Button* command) { m_Num8 = command; }
	void setNum9			(Button* command) { m_Num9 = command; }
	void setEscape			(Button* command) { m_Escape = command; }
	void setLControl		(Button* command) { m_LControl = command; }
	void setLShift			(Button* command) { m_LShift = command; }
	void setLAlt			(Button* command) { m_LAlt = command; }
	void setLSystem			(Button* command) { m_LSystem = command; }
	void setRControl		(Button* command) { m_RControl = command; }
	void setRShift			(Button* command) { m_RShift = command; }
	void setRAlt			(Button* command) { m_RAlt = command; }
	void setRSystem			(Button* command) { m_RSystem = command; }
	void setMenu			(Button* command) { m_Menu = command; }
	void setLBracket		(Button* command) { m_LBracket = command; }
	void setRBracket		(Button* command) { m_RBracket = command; }
	void setSemicolon		(Button* command) { m_Semicolon = command; }
	void setComma			(Button* command) { m_Comma = command; }
	void setPeriod			(Button* command) { m_Period = command; }
	void setQuote			(Button* command) { m_Quote = command; }
	void setSlash			(Button* command) { m_Slash = command; }
	void setBackslash		(Button* command) { m_Backslash = command; }
	void setTilde			(Button* command) { m_Tilde = command; }
	void setEqual			(Button* command) { m_Equal = command; }
	void setHyphen			(Button* command) { m_Hyphen = command; }
	void setSpace			(Button* command) { m_Space = command; }
	void setEnter			(Button* command) { m_Enter = command; }
	void setBackspace		(Button* command) { m_Backspace = command; }
	void setTab				(Button* command) { m_Tab = command; }
	void setPageUp			(Button* command) { m_PageUp = command; }
	void setPageDown		(Button* command) { m_PageDown = command; }
	void setEnd				(Button* command) { m_End = command; }
	void setHome			(Button* command) { m_Home = command; }
	void setInsert			(Button* command) { m_Insert = command; }
	void setDelete			(Button* command) { m_Delete = command; }
	void setAdd				(Button* command) { m_Add = command; }
	void setSubtract		(Button* command) { m_Subtract = command; }
	void setMultiply		(Button* command) { m_Multiply = command; }
	void setDivide			(Button* command) { m_Divide = command; }
	void setLeft			(Button* command) { m_Left = command; }
	void setRight			(Button* command) { m_Right = command; }
	void setUp				(Button* command) { m_Up = command; }
	void setDown			(Button* command) { m_Down = command; }
	void setNumpad0			(Button* command) { m_Numpad0 = command; }
	void setNumpad1			(Button* command) { m_Numpad1 = command; }
	void setNumpad2			(Button* command) { m_Numpad2 = command; }
	void setNumpad3			(Button* command) { m_Numpad3 = command; }
	void setNumpad4			(Button* command) { m_Numpad4 = command; }
	void setNumpad5			(Button* command) { m_Numpad5 = command; }
	void setNumpad6			(Button* command) { m_Numpad6 = command; }
	void setNumpad7			(Button* command) { m_Numpad7 = command; }
	void setNumpad8			(Button* command) { m_Numpad8 = command; }
	void setNumpad9			(Button* command) { m_Numpad9 = command; }
	void setF1				(Button* command) { m_F1 = command; }
	void setF2				(Button* command) { m_F2 = command; }
	void setF3				(Button* command) { m_F3 = command; }
	void setF4				(Button* command) { m_F4 = command; }
	void setF5				(Button* command) { m_F5 = command; }
	void setF6				(Button* command) { m_F6 = command; }
	void setF7				(Button* command) { m_F7 = command; }
	void setF8				(Button* command) { m_F8 = command; }
	void setF9				(Button* command) { m_F9 = command; }
	void setF10				(Button* command) { m_F10 = command; }
	void setF11				(Button* command) { m_F11 = command; }
	void setF12				(Button* command) { m_F12 = command; }
	void setF13				(Button* command) { m_F13 = command; }
	void setF14				(Button* command) { m_F14 = command; }
	void setF15				(Button* command) { m_F15 = command; }
	void setPause			(Button* command) { m_Pause = command; }

	void input(Body& hero)
	{
		if (m_A)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) m_A->press(hero);
			else m_A->release(hero);
		if (m_B)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) m_B->press(hero);
			else m_B->release(hero);
		if (m_C)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) m_C->press(hero);
			else m_C->release(hero);
		if (m_D)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) m_D->press(hero);
			else m_D->release(hero);
		if (m_E)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) m_E->press(hero);
			else m_E->release(hero);
		if (m_F)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) m_F->press(hero);
			else m_F->release(hero);
		if (m_G)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) m_G->press(hero);
			else m_G->release(hero);
		if (m_H)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) m_H->press(hero);
			else m_H->release(hero);
		if (m_I)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) m_I->press(hero);
			else m_I->release(hero);
		if (m_J)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) m_J->press(hero);
			else m_J->release(hero);
		if (m_K)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) m_K->press(hero);
			else m_K->release(hero);
		if (m_L)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) m_L->press(hero);
			else m_L->release(hero);
		if (m_M)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) m_M->press(hero);
			else m_M->release(hero);
		if (m_N)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) m_N->press(hero);
			else m_N->release(hero);
		if (m_O)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) m_O->press(hero);
			else m_O->release(hero);
		if (m_P)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) m_P->press(hero);
			else m_P->release(hero);
		if (m_Q)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) m_Q->press(hero);
			else m_Q->release(hero);
		if (m_R)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) m_R->press(hero);
			else m_R->release(hero);
		if (m_S)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) m_S->press(hero);
			else m_S->release(hero);
		if (m_T)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) m_T->press(hero);
			else m_T->release(hero);
		if (m_U)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) m_U->press(hero);
			else m_U->release(hero);
		if (m_V)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) m_V->press(hero);
			else m_V->release(hero);
		if (m_W)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) m_W->press(hero);
			else m_W->release(hero);
		if (m_X)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) m_X->press(hero);
			else m_X->release(hero);
		if (m_Y)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) m_Y->press(hero);
			else m_Y->release(hero);
		if (m_Z)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) m_Z->press(hero);
			else m_Z->release(hero);
		if (m_Num0)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) m_Num0->press(hero);
			else m_Num0->release(hero);
		if (m_Num1)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) m_Num1->press(hero);
			else m_Num1->release(hero);
		if (m_Num2)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) m_Num2->press(hero);
			else m_Num2->release(hero);
		if (m_Num3)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) m_Num3->press(hero);
			else m_Num3->release(hero);
		if (m_Num4)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) m_Num4->press(hero);
			else m_Num4->release(hero);
		if (m_Num5)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) m_Num5->press(hero);
			else m_Num5->release(hero);
		if (m_Num6)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) m_Num6->press(hero);
			else m_Num6->release(hero);
		if (m_Num7)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) m_Num7->press(hero);
			else m_Num7->release(hero);
		if (m_Num8)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) m_Num8->press(hero);
			else m_Num8->release(hero);
		if (m_Num9)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) m_Num9->press(hero);
			else m_Num9->release(hero);
		if (m_Escape)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) m_Escape->press(hero);
			else m_Escape->release(hero);
		if (m_LControl)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) m_LControl->press(hero);
			else m_LControl->release(hero);
		if (m_LShift)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) m_LShift->press(hero);
			else m_LShift->release(hero);
		if (m_LAlt)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) m_LAlt->press(hero);
			else m_LAlt->release(hero);
		if (m_LSystem)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem)) m_LSystem->press(hero);
			else m_LSystem->release(hero);
		if (m_RControl)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) m_RControl->press(hero);
			else m_RControl->release(hero);
		if (m_RShift)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) m_RShift->press(hero);
			else m_RShift->release(hero);
		if (m_RAlt)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) m_RAlt->press(hero);
			else m_RAlt->release(hero);
		if (m_RSystem)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem)) m_RSystem->press(hero);
			else m_RSystem->release(hero);
		if (m_Menu)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Menu)) m_Menu->press(hero);
			else m_Menu->release(hero);
		if (m_LBracket)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) m_LBracket->press(hero);
			else m_LBracket->release(hero);
		if (m_RBracket)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) m_RBracket->press(hero);
			else m_RBracket->release(hero);
		if (m_Semicolon)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Semicolon)) m_Semicolon->press(hero);
			else m_Semicolon->release(hero);
		if (m_Comma)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) m_Comma->press(hero);
			else m_Comma->release(hero);
		if (m_Period)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) m_Period->press(hero);
			else m_Period->release(hero);
		if (m_Quote)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) m_Quote->press(hero);
			else m_Quote->release(hero);
		if (m_Slash)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash)) m_Slash->press(hero);
			else m_Slash->release(hero);
		if (m_Backslash)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backslash)) m_Backslash->press(hero);
			else m_Backslash->release(hero);
		if (m_Tilde)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde)) m_Tilde->press(hero);
			else m_Tilde->release(hero);
		if (m_Equal)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) m_Equal->press(hero);
			else m_Equal->release(hero);
		if (m_Hyphen)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen)) m_Hyphen->press(hero);
			else m_Hyphen->release(hero);
		if (m_Space)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) m_Space->press(hero);
			else m_Space->release(hero);
		if (m_Enter)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) m_Enter->press(hero);
			else m_Enter->release(hero);
		if (m_Backspace)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) m_Backspace->press(hero);
			else m_Backspace->release(hero);
		if (m_Tab)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) m_Tab->press(hero);
			else m_Tab->release(hero);
		if (m_PageUp)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) m_PageUp->press(hero);
			else m_PageUp->release(hero);
		if (m_PageDown)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) m_PageDown->press(hero);
			else m_PageDown->release(hero);
		if (m_End)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) m_End->press(hero);
			else m_End->release(hero);
		if (m_Home)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Home)) m_Home->press(hero);
			else m_Home->release(hero);
		if (m_Insert)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Insert)) m_Insert->press(hero);
			else m_Insert->release(hero);
		if (m_Delete)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) m_Delete->press(hero);
			else m_Delete->release(hero);
		if (m_Add)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) m_Add->press(hero);
			else m_Add->release(hero);
		if (m_Subtract)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) m_Subtract->press(hero);
			else m_Subtract->release(hero);
		if (m_Multiply)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Multiply)) m_Multiply->press(hero);
			else m_Multiply->release(hero);
		if (m_Divide)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Divide)) m_Divide->press(hero);
			else m_Divide->release(hero);
		if (m_Left)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) m_Left->press(hero);
			else m_Left->release(hero);
		if (m_Right)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) m_Right->press(hero);
			else m_Right->release(hero);
		if (m_Up)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) m_Up->press(hero);
			else m_Up->release(hero);
		if (m_Down)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) m_Down->press(hero);
			else m_Down->release(hero);
		if (m_Numpad0)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) m_Numpad0->press(hero);
			else m_Numpad0->release(hero);
		if (m_Numpad1)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) m_Numpad1->press(hero);
			else m_Numpad1->release(hero);
		if (m_Numpad2)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) m_Numpad2->press(hero);
			else m_Numpad2->release(hero);
		if (m_Numpad3)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) m_Numpad3->press(hero);
			else m_Numpad3->release(hero);
		if (m_Numpad4)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) m_Numpad4->press(hero);
			else m_Numpad4->release(hero);
		if (m_Numpad5)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)) m_Numpad5->press(hero);
			else m_Numpad5->release(hero);
		if (m_Numpad6)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) m_Numpad6->press(hero);
			else m_Numpad6->release(hero);
		if (m_Numpad7)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) m_Numpad7->press(hero);
			else m_Numpad7->release(hero);
		if (m_Numpad8)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) m_Numpad8->press(hero);
			else m_Numpad8->release(hero);
		if (m_Numpad9)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) m_Numpad9->press(hero);
			else m_Numpad9->release(hero);
		if (m_F1)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) m_F1->press(hero);
			else m_F1->release(hero);
		if (m_F2)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) m_F2->press(hero);
			else m_F2->release(hero);
		if (m_F3)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) m_F3->press(hero);
			else m_F3->release(hero);
		if (m_F4)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) m_F4->press(hero);
			else m_F4->release(hero);
		if (m_F5)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5)) m_F5->press(hero);
			else m_F5->release(hero);
		if (m_F6)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F6)) m_F6->press(hero);
			else m_F6->release(hero);
		if (m_F7)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F7)) m_F7->press(hero);
			else m_F7->release(hero);
		if (m_F8)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F8)) m_F8->press(hero);
			else m_F8->release(hero);
		if (m_F9)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F9)) m_F9->press(hero);
			else m_F9->release(hero);
		if (m_F10)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F10)) m_F10->press(hero);
			else m_F10->release(hero);
		if (m_F11)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) m_F11->press(hero);
			else m_F11->release(hero);
		if (m_F12)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12)) m_F12->press(hero);
			else m_F12->release(hero);
		if (m_F13)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F13)) m_F13->press(hero);
			else m_F13->release(hero);
		if (m_F14)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F14)) m_F14->press(hero);
			else m_F14->release(hero);
		if (m_F15)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::F15)) m_F15->press(hero);
			else m_F15->release(hero);
		if (m_Pause)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Pause)) m_Pause->press(hero);
			else m_Pause->release(hero);
	}

	~KeyboardInput()
	{
		if (m_A)			delete m_A;
		if (m_B)			delete m_B;
		if (m_C)			delete m_C;
		if (m_D)			delete m_D;
		if (m_E)			delete m_E;
		if (m_F)			delete m_F;
		if (m_G)			delete m_G;
		if (m_H)			delete m_H;
		if (m_I)			delete m_I;
		if (m_J)			delete m_J;
		if (m_K)			delete m_K;
		if (m_L)			delete m_L;
		if (m_M)			delete m_M;
		if (m_N)			delete m_N;
		if (m_O)			delete m_O;
		if (m_P)			delete m_P;
		if (m_Q)			delete m_Q;
		if (m_R)			delete m_R;
		if (m_S)			delete m_S;
		if (m_T)			delete m_T;
		if (m_U)			delete m_U;
		if (m_V)			delete m_V;
		if (m_W)			delete m_W;
		if (m_X)			delete m_X;
		if (m_Y)			delete m_Y;
		if (m_Z)			delete m_Z;
		if (m_Num0)			delete m_Num0;
		if (m_Num1)			delete m_Num1;
		if (m_Num2)			delete m_Num2;
		if (m_Num3)			delete m_Num3;
		if (m_Num4)			delete m_Num4;
		if (m_Num5)			delete m_Num5;
		if (m_Num6)			delete m_Num6;
		if (m_Num7)			delete m_Num7;
		if (m_Num8)			delete m_Num8;
		if (m_Num9)			delete m_Num9;
		if (m_Escape)		delete m_Escape;
		if (m_LControl)		delete m_LControl;
		if (m_LShift)		delete m_LShift;
		if (m_LAlt)			delete m_LAlt;
		if (m_LSystem)		delete m_LSystem;
		if (m_RControl)		delete m_RControl;
		if (m_RShift)		delete m_RShift;
		if (m_RAlt)			delete m_RAlt;
		if (m_RSystem)		delete m_RSystem;
		if (m_Menu)			delete m_Menu;
		if (m_LBracket)		delete m_LBracket;
		if (m_RBracket)		delete m_RBracket;
		if (m_Semicolon)	delete m_Semicolon;
		if (m_Comma)		delete m_Comma;
		if (m_Period)		delete m_Period;
		if (m_Quote)		delete m_Quote;
		if (m_Slash)		delete m_Slash;
		if (m_Backslash)	delete m_Backslash;
		if (m_Tilde)		delete m_Tilde;
		if (m_Equal)		delete m_Equal;
		if (m_Hyphen)		delete m_Hyphen;
		if (m_Space)		delete m_Space;
		if (m_Enter)		delete m_Enter;
		if (m_Backspace)	delete m_Backspace;
		if (m_Tab)			delete m_Tab;
		if (m_PageUp)		delete m_PageUp;
		if (m_PageDown)		delete m_PageDown;
		if (m_End)			delete m_End;
		if (m_Home)			delete m_Home;
		if (m_Insert)		delete m_Insert;
		if (m_Delete)		delete m_Delete;
		if (m_Add)			delete m_Add;
		if (m_Subtract)		delete m_Subtract;
		if (m_Multiply)		delete m_Multiply;
		if (m_Divide)		delete m_Divide;
		if (m_Left)			delete m_Left;
		if (m_Right)		delete m_Right;
		if (m_Up)			delete m_Up;
		if (m_Down)			delete m_Down;
		if (m_Numpad0)		delete m_Numpad0;
		if (m_Numpad1)		delete m_Numpad1;
		if (m_Numpad2)		delete m_Numpad2;
		if (m_Numpad3)		delete m_Numpad3;
		if (m_Numpad4)		delete m_Numpad4;
		if (m_Numpad5)		delete m_Numpad5;
		if (m_Numpad6)		delete m_Numpad6;
		if (m_Numpad7)		delete m_Numpad7;
		if (m_Numpad8)		delete m_Numpad8;
		if (m_Numpad9)		delete m_Numpad9;
		if (m_F1)			delete m_F1;
		if (m_F2)			delete m_F2;
		if (m_F3)			delete m_F3;
		if (m_F4)			delete m_F4;
		if (m_F5)			delete m_F5;
		if (m_F6)			delete m_F6;
		if (m_F7)			delete m_F7;
		if (m_F8)			delete m_F8;
		if (m_F9)			delete m_F9;
		if (m_F10)			delete m_F10;
		if (m_F11)			delete m_F11;
		if (m_F12)			delete m_F12;
		if (m_F13)			delete m_F13;
		if (m_F14)			delete m_F14;
		if (m_F15)			delete m_F15;
		if (m_Pause)		delete m_Pause;
	}

private:

    Button* m_A = nullptr;
    Button* m_B = nullptr;
    Button* m_C = nullptr;
    Button* m_D = nullptr;
    Button* m_E = nullptr;
    Button* m_F = nullptr;
    Button* m_G = nullptr;
    Button* m_H = nullptr;
    Button* m_I = nullptr;
    Button* m_J = nullptr;
    Button* m_K = nullptr;
    Button* m_L = nullptr;
    Button* m_M = nullptr;
    Button* m_N = nullptr;
    Button* m_O = nullptr;
	Button* m_P = nullptr;
	Button* m_Q = nullptr;
	Button* m_R = nullptr;
	Button* m_S = nullptr;
	Button* m_T = nullptr;
	Button* m_U = nullptr;
	Button* m_V = nullptr;
	Button* m_W = nullptr;
	Button* m_X = nullptr;
	Button* m_Y = nullptr;
	Button* m_Z = nullptr;
	Button* m_Num0 = nullptr;
	Button* m_Num1 = nullptr;
	Button* m_Num2 = nullptr;
	Button* m_Num3 = nullptr;
	Button* m_Num4 = nullptr;
	Button* m_Num5 = nullptr;
	Button* m_Num6 = nullptr;
	Button* m_Num7 = nullptr;
	Button* m_Num8 = nullptr;
	Button* m_Num9 = nullptr;
	Button* m_Escape = nullptr;
	Button* m_LControl = nullptr;
	Button* m_LShift = nullptr;
	Button* m_LAlt = nullptr;
	Button* m_LSystem = nullptr;
	Button* m_RControl = nullptr;
	Button* m_RShift = nullptr;
	Button* m_RAlt = nullptr;
	Button* m_RSystem = nullptr;
	Button* m_Menu = nullptr;
	Button* m_LBracket = nullptr;
	Button* m_RBracket = nullptr;
	Button* m_Semicolon = nullptr;
	Button* m_Comma = nullptr;
	Button* m_Period = nullptr;
	Button* m_Quote = nullptr;
	Button* m_Slash = nullptr;
	Button* m_Backslash = nullptr;
	Button* m_Tilde = nullptr;
	Button* m_Equal = nullptr;
	Button* m_Hyphen = nullptr;
	Button* m_Space = nullptr;
	Button* m_Enter = nullptr;
	Button* m_Backspace = nullptr;
	Button* m_Tab = nullptr;
	Button* m_PageUp = nullptr;
	Button* m_PageDown = nullptr;
	Button* m_End = nullptr;
	Button* m_Home = nullptr;
	Button* m_Insert = nullptr;
	Button* m_Delete = nullptr;
	Button* m_Add = nullptr;
	Button* m_Subtract = nullptr;
	Button* m_Multiply = nullptr;
	Button* m_Divide = nullptr;
	Button* m_Left = nullptr;
	Button* m_Right = nullptr;
	Button* m_Up = nullptr;
	Button* m_Down = nullptr;
	Button* m_Numpad0 = nullptr;
	Button* m_Numpad1 = nullptr;
	Button* m_Numpad2 = nullptr;
	Button* m_Numpad3 = nullptr;
	Button* m_Numpad4 = nullptr;
	Button* m_Numpad5 = nullptr;
	Button* m_Numpad6 = nullptr;
	Button* m_Numpad7 = nullptr;
	Button* m_Numpad8 = nullptr;
	Button* m_Numpad9 = nullptr;
	Button* m_F1 = nullptr;
	Button* m_F2 = nullptr;
	Button* m_F3 = nullptr;
	Button* m_F4 = nullptr;
	Button* m_F5 = nullptr;
	Button* m_F6 = nullptr;
	Button* m_F7 = nullptr;
	Button* m_F8 = nullptr;
	Button* m_F9 = nullptr;
	Button* m_F10 = nullptr;
	Button* m_F11 = nullptr;
	Button* m_F12 = nullptr;
	Button* m_F13 = nullptr;
	Button* m_F14 = nullptr;
	Button* m_F15 = nullptr;
	Button* m_Pause = nullptr;
};

#endif // _CONTROLLING_