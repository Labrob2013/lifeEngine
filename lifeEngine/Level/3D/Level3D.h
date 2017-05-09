#ifndef LEVEL3D_H
#define LEVEL3D_H

#define COMPILING_LIBRARY
#include "../../DllGlobal.h"

//////////////////
// LIFEENGINE
/////////////////
#include "../../System/System.h"
#include "Brush.h"

namespace le
{
	//-------------------------------------------------------------------------//

	class DLL_API Level3D
	{
	public:
		/////////////////
		/// �����������
		////////////////
		Level3D( System& System );

		/////////////////
		/// ����������
		////////////////
		~Level3D();

		///////////////////////
		/// ��������� �������
		//////////////////////
		bool LoadLevel( string sRoute );

		///////////////////////
		/// �������� �������
		//////////////////////
		void ClearLevel();

		///////////////////////
		/// ����������� �������
		//////////////////////
		void RenderLevel();

	private:

		string				sNameMap;
		string				sDescriptionMap;
		string				sSkyBoxName;

		System*				System;

		vector<Brush*>		vBrushes;
	};

	//-------------------------------------------------------------------------//
}

#endif // LEVEL3D_H
