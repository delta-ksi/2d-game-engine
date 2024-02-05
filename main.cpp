#include <SFML/Graphics.hpp>
#include <iostream>
#include "Controlling.h"
#include "Interface.h"
#include "Map.h"
#include "File.h"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(1280, 720), "OMIKRON ver: pre-alpha", Style::Close);
    window.setFramerateLimit(60);
    
    View interface_view;
    interface_view.setSize(Vector2f(640, 360));
    interface_view.setCenter(interface_view.getSize() / 2.f);

    View game_view;
    game_view.setSize(Vector2f(480, 270));
    game_view.setCenter(0, 0);

    Clock clock;

    KeyboardInput keyboard;
    keyboard.setW(new MoveUp());
    keyboard.setA(new MoveLeft());
    keyboard.setS(new MoveDown());
    keyboard.setD(new MoveRight());
    keyboard.setLShift(new Run());

    Interface interface;
    Map map;
    unsigned char bytecode[] = {0x23, 0x20, 0x04, 0x00, 0x0A, 0x06, 0x24, 0x21, 0x04, 0x00, 0x0A, 0x06, 0x32};
    unsigned char bytecode2[] = {0x00, 0xFF, 0x00, 0xFF, 0x33};
    
    if (!FileVM().loadMapFromFile("maps/test.map", map)) return -1;
    map.m_fieldHandler.add(new Trigger(32, 32, 100, 100, bytecode2, 5));
    

    Body body2;
    FileVM().loadBodyFromFile("environment/bodies/test.b", body2);
    body2.setPosition(100, 100);
    body2.m_velocity = 0.1f;

   RectangleShape rec;
   rec.setFillColor(Color(255,255,255));
   rec.setPosition(Vector2f(0,0));
   rec.setSize(Vector2f(10,10));

    while (window.isOpen())
    {

        float frametime = clock.getElapsedTime().asMicroseconds();
        frametime = frametime / 1e6;
        clock.restart();

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (window.hasFocus())
        {
            keyboard.input(hero_);
            map.m_fieldHandler.check();
            interface.update(hero_);
            map.update(frametime);
            hero_.update(frametime);
            body2.update(frametime);
            ScriptVM().interpret(bytecode, 13, body2);

            game_view.setCenter(hero_.getPosition());

            window.clear();

            // ��������� �������� �����
            window.setView(game_view);
            window.draw(map);
            window.draw(body2);
            window.draw(hero_);
            window.draw(map.m_fieldHandler);

            // ��������� ����������
            window.setView(interface_view);
            window.draw(interface);

            window.display();
        }
    }

    return 0;
}