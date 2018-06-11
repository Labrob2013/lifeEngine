//////////////////////////////////////////////////////////////////////////
// 
//			*** lifeEngine (��������� �����) ***
//					Copyright (C) 2017
//
// ����� �� ����:		https://vk.com/zombihello
// ����������� ������:  https://github.com/zombihello/lifeEngine
// 
//////////////////////////////////////////////////////////////////////////

#ifndef BRUSH_PLANE_H
#define BRUSH_PLANE_H
#pragma warning( push )

#pragma warning( disable: 4251 )

#define COMPILING_LIBRARY
#include <DllGlobal.h>

///////////////////////////
// ��������� ����������
///////////////////////////
#include <vector>
#include <map>
using namespace std;

//////////////
// OPENGL
//////////////
#include <glew\glew.h>
#include <glm\glm.hpp>

//////////////////
// LIFEENGINE
//////////////////
#include <Graphics\BrushVertex.h>

namespace le
{
	//-------------------------------------------------------------------------//

	class Brush;

	//-------------------------------------------------------------------------//

	//////////////////////////////////////////////////////////////////////
	/// \brief ��������� ������ ���������� ��������� ����� (LightMap,
	/// �������� � �.�)
	//////////////////////////////////////////////////////////////////////
	struct DLL_API BrushPlane
	{
		int						CountIndexs; ///< ���������� �������� ������
		Brush*					Brush; ///< ��������� �� ����

		GLuint					LightMap; ///< ����� ��������� ��������� �����
		GLuint					ArrayBuffer; ///< VAO
		GLuint					IndexBuffer; ///< ��������� ������

		vector<BrushVertex>		Vertexes; ///< ������ ������
	};

	//-------------------------------------------------------------------------//
}

#pragma warning( pop )
#endif // BRUSH_PLANE_H