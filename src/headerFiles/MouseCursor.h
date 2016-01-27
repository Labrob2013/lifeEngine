#ifndef MOUSE_CURSOR_H
#define MOUSE_CURSOR_H

//////////////////
// SYSTEM
/////////////////
#include <string>
using namespace std;

///////////////////
// SFML
//////////////////
#include <SFML\Graphics.hpp>
using namespace sf;

namespace le
{
    class MouseCursor
    {
    public:
        ///////////////////////////////////////////////////
        // CONSTRUCTOR DEFAULT | ����������� �� ���������
        ///////////////////////////////////////////////////
        MouseCursor();

        ///////////////////////////////////////////////////
        // DESTRUCTOR DEFAULT | ���������� �� ���������
        ///////////////////////////////////////////////////
        ~MouseCursor();

        //////////////////////////////////////////////////////////////
        // LOAD TEXTURE FOR CURSOR  | ��������� �������� ��� �������
        //////////////////////////////////////////////////////////////
        void LoadTexture( const string sRoute );

        //////////////////////////////////////////////////////
        // UPDATE MOUSE POSITION  | ���������� ������� ����
        /////////////////////////////////////////////////////
        void MousePosition( RenderWindow& RenderWindow );

        /////////////////////////////////////
        // DRAW CURSOR  | ���������� ������
        ////////////////////////////////////
        void DrawCursor( RenderWindow& RenderWindow );

        /////////////////////////////////////////////////////
        // GET RECT CURSOR  | �������� ������������� �������  
        // @return RectCursor
        /////////////////////////////////////////////////////
        FloatRect GetRectCursor() const;

        /////////////////////////////////////////////////////
        // GET VECTOR CURSOR  | �������� ������ �������  
        // @return Vector2i
        /////////////////////////////////////////////////////
        Vector2i GetVectorCursor() const;
    private:
        FloatRect       RectCursor;
        Texture         Texture;
        Sprite          Sprite;
    };
}

#endif // MOUSE_CURSOR_H