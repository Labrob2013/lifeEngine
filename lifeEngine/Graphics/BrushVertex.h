//////////////////////////////////////////////////////////////////////////
// 
//			*** lifeEngine (��������� �����) ***
//					Copyright (C) 2017
//
// ����� �� ����:		https://vk.com/zombihello
// ����������� ������:  https://github.com/zombihello/lifeEngine
// 
//////////////////////////////////////////////////////////////////////////

#ifndef BRUSH_VERTEX_H
#define BRUSH_VERTEX_H
#pragma warning( push )

#pragma warning( disable: 4251 )

#define COMPILING_LIBRARY
#include <DllGlobal.h>

//////////////
// OPENGL
//////////////
#include <glew\glew.h>
#include <glm\glm.hpp>

namespace le
{
	//-------------------------------------------------------------------------//

	//////////////////////////////////////////////////////////////////////
	/// \brief ��������� ������ ���������� ������� (�������,
	/// ������� � �.� ) ��� �����
	//////////////////////////////////////////////////////////////////////
	struct DLL_API BrushVertex
	{
		glm::vec3		Position; ///< ������� �������
		glm::vec3		Normal; ///< ������� �������
		glm::vec2		TextureCoord_DiffuseMap; ///< ���������� ���������� ��� �������� ��������
		glm::vec2		TextureCoord_LightMap; ///< ���������� ���������� ��� ����� ���������

		bool operator==( BrushVertex& BrushVertex );
	};

	//-------------------------------------------------------------------------//
}

#pragma warning( pop )
#endif // BRUSH_VERTEX_H

