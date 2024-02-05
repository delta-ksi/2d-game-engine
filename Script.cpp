#include "Script.h"
#include "Body.h"

////////////////////////////////////////////////////////////
bool ScriptVM::interpret(unsigned char* _bytecode, size_t _size, MechanicObject& _this)
{

	// ������ ������ �� �����
	for (int i = 0; i < _size; i++)
	{
		char inst = _bytecode[i];
		switch (inst)
		{
			// Basic arithmetic and logic instructions
		case INST_LITERAL:
		{
			int value = _bytecode[++i];
			push(value);
			break;
		}

		case INST_DELETE:
			pop();
			break;

		case INST_COMBINE:
		{
			int b = pop();
			int a = pop();
			push(a * 256 + b);
			break;
		}

		case INST_ADD:
		{
			int b = pop();
			int a = pop();
			push(a + b);
			break;
		}

		case INST_SUBTRACT:
		{
			int b = pop();
			int a = pop();
			push(a - b);
			break;
		}

		case INST_MULTIPLY:
		{
			int b = pop();
			int a = pop();
			push(a * b);
			break;
		}

		case INST_DIVIDE:
		{
			int b = pop();
			int a = pop();
			push((float)a / b);
			break;
		}

		case INST_LOG_EQUAL:
		{
			int b = pop();
			int a = pop();
			push(a == b);
			break;
		}

		case INTS_LOG_NOT_EQUAL:
		{
			int b = pop();
			int a = pop();
			push(a != b);
			break;
		}

		case INST_LOG_LESS:
		{
			int b = pop();
			int a = pop();
			push(a < b);
			break;
		}

		case INST_LOG_MORE:
		{
			int b = pop();
			int a = pop();
			push(a > b);
			break;
		}

		case INST_LOG_LESS_EQUAL:
		{
			int b = pop();
			int a = pop();
			push(a <= b);
			break;
		}

		case INST_LOG_MORE_EQUAL:
		{
			int b = pop();
			int a = pop();
			push(a >= b);
			break;
		}

		case INST_IF:
		{
			bool flag = pop();
			int else_i = _bytecode[++i];
			int endif_i = _bytecode[++i];

			if (!flag)  i += else_i;
			else	i += endif_i;
			break;
		}

		case INST_GOTO:
		{
			int goto_i = _bytecode[++i];

			i = goto_i;
			break;
		}

		case GET_THIS_POSITION_X:
		{
			push(_this.getPosition().x);
			break;
		}

		case GET_THIS_POSITION_Y:
		{
			push(_this.getPosition().y);
			break;
		}

		case GET_HERO_POSITION_X:
		{
			push(hero_.getPosition().x);
			break;
		}

		case GET_HERO_POSITION_Y:
		{
			push(hero_.getPosition().y);
			break;
		}

		case GET_HERO_HEALTH:
		{
			push(hero_.m_health);
			break;
		}

		case MOVE_THIS:
		{
			float dy = pop();
			float dx = pop();
			_this.propel(dx, dy);
			break;
		}

		case SET_HERO_POSITION:
		{
			float y = pop();
			float x = pop();
			hero_.setPosition(x, y);
			break;
		}

		case DAMAGE_HERO:
		{
			int d = pop();
			hero_.takeDamage(d);
			break;
		}

		default:
			return false;
			break;
		}

		//for (int i = 0; i < m_size; i++)
		//{
		//	std::cout << '[' << m_stack[i] << ']';
		//}
		//std::cout << '\n';
	}
}


////////////////////////////////////////////////////////////
bool ScriptVM::interpret(unsigned char* _bytecode, size_t _size, GameObject& _this)
{

	// ������ ������ �� �����
	for (int i = 0; i < _size; i++)
	{
		char inst = _bytecode[i];
		switch (inst)
		{
			// Basic arithmetic and logic instructions
		case INST_LITERAL:
		{
			int value = _bytecode[++i];
			push(value);
			break;
		}

		case INST_DELETE:
			pop();
			break;

		case INST_COMBINE:
		{
			int b = pop();
			int a = pop();
			push(a * 256 + b);
			break;
		}

		case INST_ADD:
		{
			int b = pop();
			int a = pop();
			push(a + b);
			break;
		}

		case INST_SUBTRACT:
		{
			int b = pop();
			int a = pop();
			push(a - b);
			break;
		}

		case INST_MULTIPLY:
		{
			int b = pop();
			int a = pop();
			push(a * b);
			break;
		}

		case INST_DIVIDE:
		{
			int b = pop();
			int a = pop();
			push((float)a / b);
			break;
		}

		case INST_LOG_EQUAL:
		{
			int b = pop();
			int a = pop();
			push(a == b);
			break;
		}

		case INTS_LOG_NOT_EQUAL:
		{
			int b = pop();
			int a = pop();
			push(a != b);
			break;
		}

		case INST_LOG_LESS:
		{
			int b = pop();
			int a = pop();
			push(a < b);
			break;
		}

		case INST_LOG_MORE:
		{
			int b = pop();
			int a = pop();
			push(a > b);
			break;
		}

		case INST_LOG_LESS_EQUAL:
		{
			int b = pop();
			int a = pop();
			push(a <= b);
			break;
		}

		case INST_LOG_MORE_EQUAL:
		{
			int b = pop();
			int a = pop();
			push(a >= b);
			break;
		}

		case INST_IF:
		{
			bool flag = pop();
			int else_i = _bytecode[++i];
			int endif_i = _bytecode[++i];

			if (!flag)  i += else_i;
			else	i += endif_i;
			break;
		}

		case INST_GOTO:
		{
			int goto_i = _bytecode[++i];

			i = goto_i;
			break;
		}

		case GET_THIS_POSITION_X:
		{
			push(_this.getPosition().x);
			break;
		}

		case GET_THIS_POSITION_Y:
		{
			push(_this.getPosition().y);
			break;
		}

		case GET_HERO_POSITION_X:
		{
			push(hero_.getPosition().x);
			break;
		}

		case GET_HERO_POSITION_Y:
		{
			push(hero_.getPosition().y);
			break;
		}

		case GET_HERO_HEALTH:
		{
			push(hero_.m_health);
			break;
		}

		case MOVE_THIS:
		{
			float dy = pop();
			float dx = pop();
			_this.propel(dx, dy);
			break;
		}

		case DAMAGE_HERO:
		{
			int h = pop();
			hero_.m_health = h;
			break;
		}

		default:
			return false;
			break;
		}

		//for (int i = 0; i < m_size; i++)
		//{
		//	std::cout << '[' << m_stack[i] << ']';
		//}
		//std::cout << '\n';
	}
}