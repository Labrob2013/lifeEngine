﻿//////////////////////////////////////////////////////////////////////////
// 
//			*** lifeEngine (Двигатель Жизни) ***
//					Copyright (C) 2017
//
// Связь со мной:		https://vk.com/zombihello
// Репозиторий движка:  https://github.com/zombihello/lifeEngine
// 
//////////////////////////////////////////////////////////////////////////

#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H
#pragma warning( push )

#pragma warning( disable: 4251 ) 

#define COMPILING_LIBRARY
#include <DllGlobal.h>

//////////////
// OPENGL
//////////////
#include <glew\glew.h>
#include <glm\glm.hpp>

////////////////
// LIFEENGINE
///////////////
#include <Graphics\BaseLight.h>
#include <Graphics\LightCone.h>

namespace le
{
	//-------------------------------------------------------------------------//

	//////////////////////////////////////////////////////////////////////
	/// \brief Класс прожекторного света
	///
	/// Данный класс необходим для работы прожекторного света
	//////////////////////////////////////////////////////////////////////
	class DLL_API SpotLight : public BaseLight
	{
	public:
		//////////////////////////////////////////////////////////////////////
		/// \brief Конструктор
		//////////////////////////////////////////////////////////////////////
		SpotLight();

		//////////////////////////////////////////////////////////////////////
		/// \brief Конструктор копирования
		//////////////////////////////////////////////////////////////////////
		SpotLight( const SpotLight& Copy );

		//////////////////////////////////////////////////////////////////////
		/// \brief Конструктор
		///
		/// \param[in] Radius Радиус конуса у света
		/// \param[in] Height Высота конуса у света
		/// \param[in] Rotation Угол поворота света
		/// \param[in] Position Позиция света
		/// \param[in] Color Цвет света
		/// \param[in] Intensivity Интенсивность света
		/// \param[in] Specular Отражение света
		//////////////////////////////////////////////////////////////////////
		SpotLight( float Radius, float Height, const glm::vec3& Rotation, const glm::vec3& Position, const glm::vec4& Color, float Intensivity = 1.f, const glm::vec4& Specular = glm::vec4( 0.0f, 0.0f, 0.0f, 1.0f ) );

		//////////////////////////////////////////////////////////////////////
		/// \brief Деструктор
		//////////////////////////////////////////////////////////////////////
		~SpotLight();

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать радиус конуса у света
		///		
		/// \param[in] Radius Радиус конуса
		//////////////////////////////////////////////////////////////////////
		void SetRadius( float Radius );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать высоту конуса у света
		///		
		/// \param[in] Height Высота конуса
		//////////////////////////////////////////////////////////////////////
		void SetHeight( float Height );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать угол поворота света
		///		
		/// \param[in] Rotation Угол поворота
		//////////////////////////////////////////////////////////////////////
		void SetRotation( const glm::vec3& Rotation );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать угол поворота света
		///		
		/// \param[in] Rotation Угол поворота
		//////////////////////////////////////////////////////////////////////
		void SetRotation( const glm::quat& Rotation );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать позицию света
		///		
		/// \param[in] Position Позиция света
		//////////////////////////////////////////////////////////////////////
		void SetPosition( const glm::vec3& Position );

		le::SpotLight& operator=( const SpotLight& Copy );

		float				SpotCutoff; ///< Угол влиянияf
		float				Radius; ///< Радиус конуса у света
		float				Height; ///< Высота конуса у света

		glm::vec3			SpotDirection; ///< Направление света
		LightCone			LightCone; ///< Конус света
	};

	//-------------------------------------------------------------------------//
}

#pragma warning( pop )
#endif // SPOT_LIGHT_H
