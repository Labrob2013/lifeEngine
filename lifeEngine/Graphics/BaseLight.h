﻿//////////////////////////////////////////////////////////////////////////
// 
//			*** lifeEngine (Двигатель Жизни) ***
//					Copyright (C) 2017
//
// Связь со мной:		https://vk.com/zombihello
// Репозиторий движка:  https://github.com/zombihello/lifeEngine
// 
//////////////////////////////////////////////////////////////////////////

#ifndef BASE_LIGHT_H
#define BASE_LIGHT_H
#pragma warning( push )

#pragma warning( disable: 4251 ) 

#define COMPILING_LIBRARY
#define SHADOWMAP_SIZE 1024
#include <DllGlobal.h>

///////////////////////////
// СИСТЕМНЫЕ БИБЛИОТЕКИ
///////////////////////////
#include <string>
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
#include <System\Logger.h>
#include <Graphics\Frustum.h>

namespace le
{
	//-------------------------------------------------------------------------//

	//////////////////////////////////////////////////////////////////////
	/// \brief Базовый класс света
	///
	/// Данный класс является базой для любого типа света
	//////////////////////////////////////////////////////////////////////
	class DLL_API BaseLight
	{
	public:
		//////////////////////////////////////////////////////////////////////
		/// \brief Конструктор
		//////////////////////////////////////////////////////////////////////
		BaseLight();

		//////////////////////////////////////////////////////////////////////
		/// \brief Деструктор
		//////////////////////////////////////////////////////////////////////
		~BaseLight();

		//////////////////////////////////////////////////////////////////////
		/// \brief Инициализировать карту теней
		///
		/// \param[in] IsCubeMap Создать ли кубическую карту теней
		/// \return true - иниц. карта, false - нет
		//////////////////////////////////////////////////////////////////////
		bool InitShadowMap( bool IsCubeMap = false );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать позицию света
		///		
		/// \param[in] Position Позиция света
		//////////////////////////////////////////////////////////////////////
		virtual void SetPosition( const glm::vec3& Position ) = 0;

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать название света
		///		
		/// \param[in] NameLight Название света
		//////////////////////////////////////////////////////////////////////
		void SetName( const string& NameLight );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать отражение света
		///		
		/// \param[in] Specular Отражение света
		//////////////////////////////////////////////////////////////////////
		void SetSpecular( const glm::vec4& Specular );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать цвет света
		///		
		/// \param[in] Color Цвет света
		//////////////////////////////////////////////////////////////////////
		void SetColor( const glm::vec4& Color );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать интенсивность света
		///		
		/// \param[in] Intensivity Интенсивность
		//////////////////////////////////////////////////////////////////////
		void SetIntensivity( float Intensivity );

		bool					IsInitShadowMap; ///< Инициализирована ли карта теней
		bool					IsVisible; ///< Виден ли источник света

		float					Intensivity; ///< Интенсивность света

		GLuint					ShadowMap; ///< карта теней
		GLuint					ShadowMap_FBO; ///< FBO для карты теней
		string					NameLight; ///< Название света

		glm::vec4				Position; ///< Позиция света 
		glm::vec4				Specular; ///< Отражение света
		glm::vec4				Color; ///< Цвет света
		glm::mat4				LightProjection; ///< Матрица проекции для карт теней

		vector<Frustum>			Frustums; ///< Массив усеченых пирамид для отсечения геометрии
		vector<glm::mat4>		LightViews; ///< Массив видовых матриц
		vector<glm::mat4>		LightTransforms; ///< Массив матриц трансформаций

	protected:
		//////////////////////////////////////////////////////////////////////
		/// \brief Скопировать базовые параметры света
		//////////////////////////////////////////////////////////////////////
		void CopyBaseLight( const BaseLight& Copy );
	};

	//-------------------------------------------------------------------------//
}

#pragma warning( pop )
#endif // BASE_LIGHT_H
