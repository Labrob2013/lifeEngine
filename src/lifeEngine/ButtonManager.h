#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

//////////////////
// LIFEENGINE
/////////////////
#include "System.h"
#include "Button.h"

namespace le
{
    class ButtonManager
    {
    public:
        /////////////////////////////////
        // CONSTRUCTOR | �����������
        ////////////////////////////////
        ButtonManager( System& System );

        ///////////////////////////////////////////////////
        // DESTRUCTOR DEFAULT | ���������� �� ���������
        ///////////////////////////////////////////////////
        ~ButtonManager();

        ///////////////////////////////////
        // CREATE BUTTON | ������� ������  
        //////////////////////////////////
        void CreateButton( const Text& Text );

        //////////////////////////////////////////
        // UPDATE BUTTONS | ��������� ��� ������  
        /////////////////////////////////////////
        void UpdateButtons();

        /////////////////////////////////////////////
        // DELETE ALL BUTTONS | ������� ��� ������  
        ////////////////////////////////////////////
        void DeleteAllButtons();

        ///////////////////////////////////////////////
        // DELETE BUTTON BY ID | ������� ������ �� ID  
        //////////////////////////////////////////////
        void DeleteButton( const int id );

        ///////////////////////////////////////////////////
        // GET TEMP ID BUTTON | �������� ������� ID ������ 
        // @return int
        //////////////////////////////////////////////////
        int GetTmpIdButton() const;
    private:
        int                     iIdButton;
        RenderWindow*           RenderWindow;
        Vector2i*               CursorPosition;
        System*                 System;
        vector<Button*>         vButton;
    };
}

#endif // BUTTON_MANAGER_H