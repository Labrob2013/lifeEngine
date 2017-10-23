﻿//////////////////////////////////////////////////////////////////////////
// 
//			*** lifeEngine (Двигатель Жизни) ***
//					Copyright (C) 2017
//
// Связь со мной:		https://vk.com/zombihello
// Репозиторий движка:  https://github.com/zombihello/lifeEngine
// 
//////////////////////////////////////////////////////////////////////////

#ifndef CAMERA_H
#define CAMERA_H

#define COMPILING_LIBRARY
#include <DllGlobal.h>

//////////////
// OPENGL
//////////////
#include <glm\glm.hpp>

//////////////////
// SFML
//////////////////
#include <SFML\Graphics.hpp>
using namespace sf;

//////////////////
// LIFEENGINE
//////////////////
#include <System\System.h>
#include <Graphics\Frustum.h>

namespace le
{
	//-------------------------------------------------------------------------//

	class BoundingBox;

	//-------------------------------------------------------------------------//

	//////////////////////////////////////////////////////////////////////
	/// \brief Класс для работы с камерой
	//////////////////////////////////////////////////////////////////////
	class DLL_API Camera
	{
	public:

		//-------------------------------------------------------------------------//

		enum TypeMove
		{
			Forward,
			Back,
			Left,
			Right
		};

		//-------------------------------------------------------------------------//

		//////////////////////////////////////////////////////////////////////
		/// \brief Конструктор
		//////////////////////////////////////////////////////////////////////
		Camera( System& System );

		//////////////////////////////////////////////////////////////////////
		/// \brief Деструктор
		//////////////////////////////////////////////////////////////////////
		~Camera();

		//////////////////////////////////////////////////////////////////////
		/// \brief Обновить камеру
		/// \details Данный метод обновляет видовую матрицу камеры
		//////////////////////////////////////////////////////////////////////
		void UpdateCamera();

		//////////////////////////////////////////////////////////////////////
		/// \brief Сместить камеру
		/// \details Данный метод перемещает камеру
		///
		/// \param[in] FactorMove Фактор смещение (на сколько сместить)
		//////////////////////////////////////////////////////////////////////
		void Move( const glm::vec3& FactorMove );

		//////////////////////////////////////////////////////////////////////
		/// \brief Сместить камеру
		/// \details Данный метод перемещает камеру с учетом ее поворота
		///
		/// \param[in] typeMove Тип движения (Влево, Вправо и т.д)
		/// \param[in] MoveSpeed Скорость перемещения
		//////////////////////////////////////////////////////////////////////
		void Move( TypeMove typeMove, float MoveSpeed );

		//////////////////////////////////////////////////////////////////////
		/// \brief Наклонить камеру по оси Z
		/// \details Данный метод наклоняет камеру по Z
		///
		/// \param[in] FactorTilt Фактор наклона
		//////////////////////////////////////////////////////////////////////
		void TiltCamera( float FactorTilt );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать чуствительность мыши
		///
		/// \param[in] sensitivityMouse Чуствительность мыши
		//////////////////////////////////////////////////////////////////////
		void SetSensitivityMouse( float sensitivityMouse );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать позицию мыши
		///
		/// \param[in] NewPosition Новая позиция
		//////////////////////////////////////////////////////////////////////
		void SetPosition( const glm::vec3& NewPosition );

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать наклонение камеры по Z
		///
		/// \param[in] InclinationCamera Наклон камеры
		//////////////////////////////////////////////////////////////////////
		void SetInclinationCamera( float InclinationCamera );

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить позицию камеры
		///
		/// \return const glm::vec3&
		//////////////////////////////////////////////////////////////////////
		glm::vec3& GetPosition();

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить наклон камеры по Z
		///
		/// \return float
		//////////////////////////////////////////////////////////////////////
		float GetInclinationCamera();

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить растояние до точки
		///
		/// \param[in] PositionObject Позиция точки
		/// \return float
		//////////////////////////////////////////////////////////////////////
		inline float GetDistance( const glm::vec3& PositionObject );

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить вектор смещения
		/// \details Возвращает смещение XYZ с учетом поворота камеры
		///
		/// \param[in] typeMove Тип движения (Влево, Вправо и т.д)
		/// \param[in] MoveSpeed Скорость перемещения
		/// \return glm::vec3&
		//////////////////////////////////////////////////////////////////////
		glm::vec3 GetVectorMove( TypeMove typeMove, float MoveSpeed );

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить видовую матрицу
		///
		/// \return const glm::mat4&
		//////////////////////////////////////////////////////////////////////
		glm::mat4& GetViewMatrix();

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить пирамиду усечения
		///
		/// \return Frustum&
		//////////////////////////////////////////////////////////////////////
		Frustum& GetFrustum();

	private:

		float			SensitivityMouse; ///< Чуствительность мыши
		float			InclinationCamera; ///< Наклон камеры
		glm::vec2		Angle; ///< Угол поворота камеры
		glm::vec3		Position; ///< Позиция камеры		
		glm::mat4		ViewMatrix; ///< Матрица вида
		glm::mat4*		ProjectionMatrix; ///< Матрица проекции
		glm::mat4		InclinationCameraMatrix; ///< Матрица наклона камеры
		Frustum			Frustum; ///< Пирамида усечения (для отсечения невидимой геометрии)

		RenderWindow*	RenderWindow; ///< Игровое окно
		glm::vec2		CenterWindow; ///< Центр окна
		Vector2i		MousePosition; ///< Позиция мыши
		Vector2u		SizeWindow; ///< Размер окна
	};

	//-------------------------------------------------------------------------//
}

#endif //CAMERA_H