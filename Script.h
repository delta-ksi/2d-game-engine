#pragma once

#ifndef _SCRIPT_
#define _SCRIPT_

#include <assert.h>
#include "Object.h"

class ScriptVM
{
public:

	ScriptVM() : m_size(0) {}

	enum Instruction
	{
		// Basic arithmetic and logic instructions
		INST_LITERAL		= 0x00,
		INST_DELETE			= 0x01,
		INST_COMBINE		= 0x02,
		INST_ADD			= 0x03,
		INST_SUBTRACT		= 0x04,
		INST_MULTIPLY		= 0x05,
		INST_DIVIDE			= 0x06,
		INST_LOG_EQUAL		= 0x07,
		INTS_LOG_NOT_EQUAL	= 0x08,
		INST_LOG_LESS		= 0x09,
		INST_LOG_MORE		= 0x0A,
		INST_LOG_LESS_EQUAL = 0x0B,
		INST_LOG_MORE_EQUAL = 0x0C,

		INST_IF				= 0x12,
		INST_GOTO			= 0x13,

		// Instructions for getting info about game situation
		GET_THIS_POSITION_X	= 0x20,
		GET_THIS_POSITION_Y = 0x21,
		GET_THIS_HEALTH		= 0x22,
		GET_HERO_POSITION_X	= 0x23,
		GET_HERO_POSITION_Y = 0x24,
		GET_HERO_HEALTH		= 0x25,

		// Instructions for setting info
		SET_THIS_POSITION	= 0x30,
		SET_THIS_HEALTH		= 0x31,
		MOVE_THIS			= 0x32,
		SET_HERO_POSITION	= 0x33,
		DAMAGE_HERO			= 0x34,
		MOVE_HERO			= 0x35

	};

	//@// ����� ������ ������������ ���� ���������� ��������������
	bool interpret(unsigned char* _bytecode, size_t _size, GameObject& _this);
	bool interpret(unsigned char* _bytecode, size_t _size, MechanicObject& _this);

private:

	void push(int _value)
	{
		assert(m_size < MAX_STACK);
		m_stack[m_size++] = _value;
	}

	int pop()
	{
		assert(m_size > 0);
		return m_stack[--m_size];
	}

	static const size_t MAX_STACK = 128;
	size_t	m_size;
	float	m_stack[MAX_STACK];
};

#endif // !_SCRIPT_