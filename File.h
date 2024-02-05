#pragma once

#ifndef _FILE_
#define _FILE_

#include "Map.h"

class FileVM
{
public:

	FileVM() : m_size(0) {}

	enum Instruction
	{
		// Basic (arithmetic) and logic instructions
		LITERAL						= 0x00,
		DELETE						= 0x01,
		COMBINE						= 0x02,

		// Tilemap instructions //
		TILEMAP_SET_POSITION		= 0xC0,
		TILEMAP_SET_TILE_SIZE		= 0xC1,
		TILEMAP_RESIZE_VERTEX		= 0xC2,
		TILEMAP_VECTOR_PUSH			= 0xC3,
		TILEMAP_PUSH_TILE			= 0xC4,
		TILEMAP_LOAD_TEXTURE		= 0xC5,

		// Field instructions //
		FIELD_SET					= 0xD0,

		// Entity instructions //
		ENTITY_SET_POSITION			= 0xE0,
		ENTITY_SET_FREQUENCY		= 0xE1,
		ENTITY_PUSH_NEW_BLOCK		= 0xE2,
		ENTITY_PUSH_NEW_CADR		= 0xE3,
		ENTITY_VECTOR_PUSH			= 0xE4,
		ENTITY_LOAD_TEXTURE			= 0xE5,
		ENTITY_LOAD_FROM_FILE		= 0xE6,

		// Body instructions //
		BODY_SET_POSITION			= 0xF0,
		BODY_SET_FREQUENCY			= 0xF1,
		BODY_PUSH_NEW_BLOCK			= 0xF2,
		BODY_PUSH_NEW_CADR			= 0xF3,
		BODY_VECTOR_PUSH			= 0xF4,
		BODY_LOAD_TEXTURE			= 0xF5,
		BODY_LOAD_FROM_FILE			= 0xF6,

		END_OF_FILE					= 0xFF
	};

	bool loadMapFromFile(std::string _file_address, Map& _map);
	bool loadBodyFromFile(std::string _file_address, Body& _body);

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
	int		m_stack[MAX_STACK];
};

#endif // !_FILE_
