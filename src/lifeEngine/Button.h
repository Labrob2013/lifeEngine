#ifndef BUTTON_H
#define BUTTON_H

/////////////////
// LIFEENGINE
/////////////////
#include "System.h"

namespace le
{
    class Button
    {
    public:
        ///////////////////////////////////////////////////
        // CONSTRUCTOR DEFAULT | �����������
        ///////////////////////////////////////////////////
        Button( System& System );

        ///////////////////////////////////////////////////
        // DESTRUCTOR DEFAULT | ���������� �� ���������
        ///////////////////////////////////////////////////
        ~Button();

        //////////////////////////////////////
        // UPDATE BUTTON  | ��������� ������  
        /////////////////////////////////////
        void UpdateButton();

        //////////////////////////////////////
        // CREATE BUTTON  | ������� ������  
        /////////////////////////////////////
        void CreateButton( const Text& Text );

        ///////////////////////////////////////////////
        // SET ID FOR BUTTON  | ������ ����� ������
        //////////////////////////////////////////////
        void SetId( const int id );

        ///////////////////////////////////////////////
        // GET TEXT BUTTON  | �������� ����� ������
        // @return Text
        //////////////////////////////////////////////
        Text GetText() const;

        ///////////////////////////////////////////////
        // GET COLOR BUTTON  | �������� ���� ������
        // @return �olor
        //////////////////////////////////////////////
        Color GetColor() const;

        //////////////////////////////////////////////////////
        // GET RECT BUTTON  | �������� ������������� ������
        // @return FloatRect
        //////////////////////////////////////////////////////
        FloatRect GetRectButton() const;

        //////////////////////////////////////////////////////
        // GET ID BUTTON  | �������� ���������� ����� ������
        // @return int
        //////////////////////////////////////////////////////
        int GetIdButton() const;
    private:
        int                 iId;
        Text                Text;
        Color               Color;
        FloatRect           RectButton;
        RenderWindow*       RenderWindow;
        MouseCursor*        MouseCursor;
    };
}

#endif // BUTTON_H