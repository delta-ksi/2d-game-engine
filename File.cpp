#include "File.h"

////////////////////////////////////////////////////////////
bool FileVM::loadMapFromFile(std::string _file_address, Map& _map)
	{
	// Открытие файла
	std::ifstream file(_file_address, std::ios::binary); // std::ios::in | 
	if (!file.is_open()) return false;

	unsigned char byte = 0;

	// Чтение данных из файла
	while (!file.eof())
	{
		file.read((char*)&byte, 1);

		switch (byte)
		{
		// Basic arithmetic and logic instructions
		case LITERAL:
			file.read((char*)&byte, 1);
			push(byte);
			break;

		case DELETE:
			pop();
			break;

		case COMBINE:
		{
			int b = pop();
			int a = pop();
			push(a * 256 + b);
			break;
		}

		// Tilemap instructions //
		case TILEMAP_SET_POSITION:
		{
			int y = pop();
			int x = pop();
			_map.m_tilemaps.back().setPosition(x, y);
			break;
		}

		case TILEMAP_SET_TILE_SIZE:
		{
			int h = pop();
			int w = pop();
			_map.m_tilemaps.back().setTilemapParam(w, h);
			break;
		}

		case TILEMAP_RESIZE_VERTEX:
		{
			int n_y = pop();
			int n_x = pop();
			_map.m_tilemaps.back().resizeVertexArray(n_x, n_y);
			break;
		}

		case TILEMAP_VECTOR_PUSH:
			_map.m_tilemaps.push_back(Tilemap());
			break;

		case TILEMAP_PUSH_TILE:
		{
			int id = pop();
			_map.m_tilemaps.back().pushNewTile(id);
			break;
		}

		case TILEMAP_LOAD_TEXTURE:
		{
			std::string str;
			int s = pop();
			for (int i = 0; i < s; i++)
				str += (char)pop();

			if (!_map.m_tilemaps_texture.loadFromFile(str)) return false;
			break;
		}

		// Field instructions //
		case FIELD_SET:
		{
			int p = pop();
			int h = pop();
			int w = pop();
			int t = pop();
			int l = pop();

			_map.m_fieldHandler.add(new LineBorder(l, t, w, h, (Direction)p));
			break;
		}

		// Entity instructions //
		case ENTITY_SET_POSITION:
		{
			int y = pop();
			int x = pop();
			_map.m_entities.back().setPosition(x, y);
			break;
		}

		case ENTITY_SET_FREQUENCY:
		{
			int f = pop();
			_map.m_entities.back().m_cadrs.setFrequency(f);
			break;
		}

		case ENTITY_PUSH_NEW_BLOCK:
		{
			int n = pop();
			_map.m_entities.back().m_cadrs.pushBlock(n);
			break;
		}

		case ENTITY_PUSH_NEW_CADR:
		{
			int h = pop();
			int w = pop();
			int t = pop();
			int l = pop();
			_map.m_entities.back().m_cadrs.push(l, t, w, h);
			break;
		}

		case ENTITY_LOAD_TEXTURE:
		{
			std::string str;
			int s = pop();
			for (int i = 0; i < s; i++)
				str += (char)pop();

			if (!_map.m_entities_texture.loadFromFile(str)) return false;
			break;
		}

		case ENTITY_VECTOR_PUSH:
			_map.m_entities.push_back(Entity());
			break;

		// Body instructions //
		case BODY_SET_POSITION:
		{
			int y = pop();
			int x = pop();

			hero_.setPosition(x, y);
			break;
		}

		case BODY_VECTOR_PUSH:
			//Something...
			break;

		case BODY_LOAD_FROM_FILE:
		{
			std::string str;
			int s = pop();
			for (int i = 0; i < s; i++)
				str += (char)pop();

			if (!FileVM().loadBodyFromFile(str, hero_))
				return false;
			break;
		}

		case END_OF_FILE:
		{
			return true;
			break;
		}

		default:
			return false;
			break;
		}
	}
}

////////////////////////////////////////////////////////////
bool FileVM::loadBodyFromFile(std::string _file_address, Body& _body)
{
	// Открытие файла
	std::ifstream file(_file_address, std::ios::binary); // std::ios::in | 
	if (!file.is_open()) return false;

	unsigned char byte = 0;

	// Чтение данных из файла
	while (!file.eof())
	{
		file.read((char*)&byte, 1);

		switch (byte)
		{
			// Basic arithmetic and logic instructions
		case LITERAL:
			file.read((char*)&byte, 1);
			push(byte);
			break;

		case DELETE:
			pop();
			break;

		case COMBINE:
		{
			int b = pop();
			int a = pop();
			push(a * 256 + b);
			break;
		}

		case BODY_SET_POSITION:
		{
			int y = pop();
			int x = pop();
			_body.setPosition(x, y);
			break;
		}

		case BODY_SET_FREQUENCY:
		{
			int f = pop();
			_body.m_cadrs.setFrequency(f);
			break;
		}

		case BODY_PUSH_NEW_BLOCK:
		{
			int n = pop();
			_body.m_cadrs.pushBlock(n);
			break;
		}

		case BODY_PUSH_NEW_CADR:
		{
			int h = pop();
			int w = pop();
			int t = pop();
			int l = pop();
			_body.m_cadrs.push(l, t, w, h);
			break;
		}

		case BODY_LOAD_TEXTURE:
		{
			std::string str;
			int s = pop();
			for (int i = 0; i < s; i++)
				str += (char)pop();

			if (!_body.m_texture.loadFromFile(str)) return false;
			break;
		}

		case END_OF_FILE:
		{
			return true;
			break;
		}

		default:
			return false;
			break;
		}
	}
}