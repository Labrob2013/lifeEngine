#ifndef Console_H
#define Console_H

#define COMPILING_LIBRARY
#include "../DllGlobal.h"

//////////////
/// SFML
//////////////
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "system.h"

using namespace sf;

namespace le
{
	//-------------------------------------------------------------------------//

	class DLL_API Console
	{
	public:
		/*
		/////////////////////////////
		// ������� 
		/////////////////////////////
		Console(System& system);

		/////////////////////////////
		// ����������
		/////////////////////////////
		~Console();

		/////////////////////////////
		// ��������� ������� 
		/////////////////////////////
		void loadWidgets( tgui::Gui & gui );

		/////////////////////////////
		// ��������  
		/////////////////////////////
		void Update( tgui::Gui & gui );

		tgui::Gui* gui;
		*/
	};

	//-------------------------------------------------------------------------//
}
#endif // Console_H