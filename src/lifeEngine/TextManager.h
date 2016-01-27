#ifndef TEXT_MANAGER_H
#define TEXT_MANAGER_H

////////////////////
// LIFEENGINE
///////////////////
#include "System.h"
#include <ostream>

namespace le
{
    class TextManager
    {
    public:
        ///////////////////////////////////////////////////
        // CONSTRUCTOR | �����������
        ///////////////////////////////////////////////////
        TextManager( System& System );

        ///////////////////////////////////////////////////
        // DESTRUCTOR DEFAULT | ���������� �� ���������
        ///////////////////////////////////////////////////
        ~TextManager();

        ///////////////////////////////////
        // LOAD FONT | ��������� �����  
        //////////////////////////////////
        void LoadFont( const string sRoute );

        ///////////////////////////////////
        //  WRITE TEXT  | �������� �����     
        ///////////////////////////////////
        void WriteText( const string sText , const int iSize , Vector2f PositionText , Color ColorText );

        ///////////////////////////////////////////////////////
        //  WRITE TEXT WITH VALUE | �������� ����� � ���������    
        ///////////////////////////////////////////////////////
        template<typename T> void WriteText( const string sText , const int iSize , Vector2f PositionText , Color ColorText , T Value );

        ///////////////////////////////////////
        // UPDATE TEXTS  | ���������� �������   
        //////////////////////////////////////
        void UpdateText();

        //////////////////////////////////////////
        // DELETE ALL TEXT  | ������� ���� �����    
        /////////////////////////////////////////
        void DeleteAllText();

        //////////////////////////////////////////////
        // DELETE TEXT BY ID  | ������� ����� �� ��� ID      
        //////////////////////////////////////////////
        void DeleteText( int ID );

        //////////////////////////////////////////////
        // GET TEXT BY ID | �������� ����� �� ��� ID    
        // @return Text
        /////////////////////////////////////////////
        Text GetText( int ID );
    private:
        RenderWindow*       RenderWindow;
        Font                Font;
        vector<Text*>       vText;
    };


    template<typename T> void TextManager::WriteText( const string sText , const int iSize , Vector2f PositionText , Color ColorText , T Value )
    {
        vText.push_back( new Text );
        Text* Text = vText[ vText.size() - 1 ];

        ostringstream ostringstream;
        ostringstream << sText << " " << Value;

        Text->setFont( Font );
        Text->setString( ostringstream.str() );
        Text->setCharacterSize( iSize );
        Text->setColor( ColorText );
        Text->setPosition( PositionText );
    }
}

#endif // TEXT_MANAGER_H