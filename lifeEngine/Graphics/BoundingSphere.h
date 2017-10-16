//////////////////////////////////////////////////////////////////////////
// 
//			*** lifeEngine (��������� �����) ***
//					Copyright (C) 2017
//
// ����� �� ����:		https://vk.com/zombihello
// ����������� ������:  https://github.com/zombihello/lifeEngine
// 
//////////////////////////////////////////////////////////////////////////

#ifndef BOUNDING_SPHERE_H
#define BOUNDING_SPHERE_H

#define COMPILING_LIBRARY
#include <DllGlobal.h>

///////////////////////////
// ��������� ����������
///////////////////////////
#include <vector>
using namespace std;

//////////////
// OPENGL
//////////////
#include <glew\glew.h>
#include <glm\glm.hpp>
#include <glm/gtx/transform.hpp>

////////////////
// LIFEENGINE
///////////////
#include <Graphics\Frustum.h>
#include <System\Query.h>

namespace le
{
	//-------------------------------------------------------------------------//

	//////////////////////////////////////////////////////////////////////
	/// \brief ����� ��������������� ���� (�����)
	///
	/// ������ ����� ������������� ��� ������������ (��������) ���������
	/// ��������� ��������� � �������� ������� �����
	//////////////////////////////////////////////////////////////////////
	class DLL_API BoundingSphere
	{
	public:
		//////////////////////////////////////////////////////////////////////
		/// \brief �����������
		//////////////////////////////////////////////////////////////////////
		BoundingSphere();

		//////////////////////////////////////////////////////////////////////
		/// \brief ����������� �����������
		//////////////////////////////////////////////////////////////////////
		BoundingSphere( BoundingSphere& Copy );

		//////////////////////////////////////////////////////////////////////
		/// \brief ����������
		//////////////////////////////////////////////////////////////////////
		~BoundingSphere();

		//////////////////////////////////////////////////////////////////////
		/// \brief ���������������� �������������� ����
		///		
		/// \param[in] Radius ������ �����
		//////////////////////////////////////////////////////////////////////
		void InitSphere( const float& Radius );

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� ���� �� ��������� �������
		//////////////////////////////////////////////////////////////////////
		void QueryTest();

		//////////////////////////////////////////////////////////////////////
		/// \brief ����������� ������
		//////////////////////////////////////////////////////////////////////
		void RenderSphere();

		//////////////////////////////////////////////////////////////////////
		/// \brief ������ ������� �����
		///		
		/// \param[in] Position ������� �����
		//////////////////////////////////////////////////////////////////////
		void SetPosition( const glm::vec3& Position );

		//////////////////////////////////////////////////////////////////////
		/// \brief ������ ������ �����
		///		
		/// \param[in] Radius ������ �����
		//////////////////////////////////////////////////////////////////////
		void SetRadius( const float& Radius );

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� ������ ����
		///		
		/// \return  float. ������ �����
		//////////////////////////////////////////////////////////////////////
		float GetRadius();

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� ������� �������������
		///		
		/// \return  glm::mat4&
		//////////////////////////////////////////////////////////////////////
		glm::mat4& GetTransformation();

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� �������
		///		
		/// \return  glm::vec3&
		//////////////////////////////////////////////////////////////////////
		glm::vec3& GetPosition();

		BoundingSphere& operator=( const BoundingSphere& Copy );

		Query				Query; ///< ������ ��� �������� ����������

	private:
		//////////////////////////////////////////////////////////////////////
		/// \brief ������� �����
		///		
		/// \param[in] Radius ������ �����
		/// \return  vector<glm::vec3>&
		//////////////////////////////////////////////////////////////////////
		vector<glm::vec3>	CreateSphere( const float& Radius );

		float				Radius; ///< ������ �����

		GLuint				ArrayBuffer; ///< VAO ������
		GLuint				VertexBuffer; ///< �������� ������
		GLuint				IndexBuffer; ///< ��������� ������

		glm::vec3			Position; ///< ������� �����
		glm::mat4			Transformation; ///< ������� �������������
	};

	//-------------------------------------------------------------------------//
}

#endif // BOUNDING_SPHERE_H

