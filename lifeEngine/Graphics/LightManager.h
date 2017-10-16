//////////////////////////////////////////////////////////////////////////
// 
//			*** lifeEngine (��������� �����) ***
//					Copyright (C) 2017
//
// ����� �� ����:		https://vk.com/zombihello
// ����������� ������:  https://github.com/zombihello/lifeEngine
// 
//////////////////////////////////////////////////////////////////////////

#ifndef LIGHT_MANAGER_H
#define LIGHT_MANAGER_H

#define COMPILING_LIBRARY
#include <DllGlobal.h>

///////////////////////////
// ��������� ����������
///////////////////////////
#include <vector>
using namespace std;

////////////////
// LIFEENGINE
///////////////
#include <Graphics\PointLight.h>

namespace le
{
	//-------------------------------------------------------------------------//

	class Scene;

	//-------------------------------------------------------------------------//

	//////////////////////////////////////////////////////////////////////
	/// \brief �����-�������� ��� ������ � ����������� �����
	//////////////////////////////////////////////////////////////////////
	class DLL_API LightManager
	{
	public:
		//////////////////////////////////////////////////////////////////////
		/// \brief �����������
		//////////////////////////////////////////////////////////////////////
		LightManager();

		//////////////////////////////////////////////////////////////////////
		/// \brief ����������
		//////////////////////////////////////////////////////////////////////
		~LightManager();

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� ��� ��������� ����� �� �����
		//////////////////////////////////////////////////////////////////////
		void AddLightsToScene( Scene& Scene );

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� �������� �������� ����� 
		/// \details ���� ����� ������� �������� �������� �� ����������
		/// ���������������. �� ��������� �������� ���������, �����
		/// ������� ��� ���������� ���� �������� ��� ������ � ���������
		/// � ������� ����� SetDinamicLight (� ���������� ����� �� �����������
		/// ����� �����)
		///
		/// \param[in] NameLight �������� �����
		/// \param[in] Radius ������ �����
		/// \param[in] Intensivity ������������� �����
		/// \param[in] Position ������� �����
		/// \param[in] Color ���� �����
		/// \param[in] Specular ��������� �����
		//////////////////////////////////////////////////////////////////////
		void AddPointLight( const string& NameLight, float Radius, float Intensivity, const glm::vec3& Position, const glm::vec4& Color, const glm::vec4& Specular = glm::vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );
		
		//////////////////////////////////////////////////////////////////////
		/// \brief �������� �������� �������� ����� 
		/// \details ���� ����� ������� ����� ��������� ����� � ���������
		/// �� � ��������
		///
		/// \param[in] NameLight �������� �����
		/// \param[in] PointLight �������� ����
		//////////////////////////////////////////////////////////////////////
		void AddPointLight( const string& NameLight, const PointLight& PointLight );

		//////////////////////////////////////////////////////////////////////
		/// \brief ���������� ������� �������� �����
		///
		/// \param[in] NameLight �������� �����
		//////////////////////////////////////////////////////////////////////
		void DestroyPointLight( const string& NameLight );

		//////////////////////////////////////////////////////////////////////
		/// \brief ���������� ��� ������� ��������� �����
		//////////////////////////////////////////////////////////////////////
		void DestroyAllPointLights();

		//////////////////////////////////////////////////////////////////////
		/// \brief ���������� ��� ��������� �����
		//////////////////////////////////////////////////////////////////////
		void DestroyAllLights();

		//////////////////////////////////////////////////////////////////////
		/// \brief ������� ����� (���������� ��� ����������� �� �����)
		///		
		/// \param[in] Scene �����
		//////////////////////////////////////////////////////////////////////
		void SetScene( Scene* Scene );

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� ������� �������� ����� � ������ ������
		///
		/// \param[in] NameLight �������� �����
		/// \return PointLight*, ���� ������ ����� ���� �� NULL
		//////////////////////////////////////////////////////////////////////
		PointLight* GetPointLight( const string& NameLight );

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� ������ ������� ���������� ����� � ������ ������
		///
		/// \param[in] NameLight �������� �����
		/// \return vector<PointLight*>&
		//////////////////////////////////////////////////////////////////////
		vector<PointLight*> GetPointLights( const string& NameLight );

		//////////////////////////////////////////////////////////////////////
		/// \brief �������� ���� ������ ������� ���������� �����
		///
		/// \return vector<PointLight>*
		//////////////////////////////////////////////////////////////////////
		vector<PointLight>* GetAllPointLights();

	private:

		Scene*						Scene; ///< ����� �� ������� ��������� ��������� �����

		vector<PointLight>			PointLights; ///< ������ �������� ���������� �����
	};

	//-------------------------------------------------------------------------//
}

#endif // LIGHT_MANAGER_H