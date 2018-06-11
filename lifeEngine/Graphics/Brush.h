﻿//////////////////////////////////////////////////////////////////////////
// 
//			*** lifeEngine (Двигатель Жизни) ***
//					Copyright (C) 2017
//
// Связь со мной:		https://vk.com/zombihello
// Репозиторий движка:  https://github.com/zombihello/lifeEngine
// 
//////////////////////////////////////////////////////////////////////////

#ifndef BRUSH_H
#define BRUSH_H

#define COMPILING_LIBRARY
#include <DllGlobal.h>

///////////////////////////
// СИСТЕМНЫЕ БИБЛИОТЕКИ
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
#include <Graphics\BoundingBox.h>
#include <Graphics\Camera.h>
#include <Graphics\BrushPlane.h>

namespace le
{
	//-------------------------------------------------------------------------//

	//////////////////////////////////////////////////////////////////////
	/// \brief Класс для работы с брашем уровня
	//////////////////////////////////////////////////////////////////////
	class DLL_API Brush
	{
	public:

		//-------------------------------------------------------------------------//

		enum PrimitivesType
		{
			Cube,
			Sphere,
			Plane
		};

		//-------------------------------------------------------------------------//

		//////////////////////////////////////////////////////////////////////
		/// \brief Конструктор
		//////////////////////////////////////////////////////////////////////
		Brush();

		//////////////////////////////////////////////////////////////////////
		/// \brief Деструктор
		//////////////////////////////////////////////////////////////////////
		~Brush();

		//////////////////////////////////////////////////////////////////////
		/// \brief Создать браш
		///		
		/// \param[in] TypeBrush Тип браша
		/// \param[in] Position Позиция браша в мире
		/// \param[in] Texture Текстура
		/// \param[in] Vertex Вершины
		/// \param[in] Normals Нормали
		/// \param[in] TextureCoords Текстурные координаты
		//////////////////////////////////////////////////////////////////////
		void CreateBrush( const PrimitivesType& TypeBrush, const glm::vec3& Position, const GLuint& Texture, const vector<glm::vec3>& Vertex, const vector<glm::vec3>& Normals, const vector<glm::vec2>& TextureCoords, const vector<glm::vec2>& TextureCoords_LightMap, const vector<string>& NameLightmaps );

		//////////////////////////////////////////////////////////////////////
		/// \brief Попал ли браш в камеру
		///		
		/// \param[in] Frustum Пирамида отсечения камеры
		/// \return true - виден, иначе false
		//////////////////////////////////////////////////////////////////////
		bool IsVisible( Frustum& Frustum );

		//////////////////////////////////////////////////////////////////////
		/// \brief Попал ли браш в камеру
		///		
		/// \param[in] Camera Камера
		/// \return true - виден, иначе false
		//////////////////////////////////////////////////////////////////////
		bool IsVisible( Camera& Camera );

		//////////////////////////////////////////////////////////////////////
		/// \brief Не перекрывают ли браш другие объекты
		///		
		/// \return true - виден, иначе false
		//////////////////////////////////////////////////////////////////////
		bool IsVisible();

		//////////////////////////////////////////////////////////////////////
		/// \brief Провести тест на перекртие объекта
		//////////////////////////////////////////////////////////////////////
		void QueryTest();

		//////////////////////////////////////////////////////////////////////
		/// \brief Задать расстояние между брашем и камерой
		///		
		/// \param[in] Camera Камера
		//////////////////////////////////////////////////////////////////////
		void SetDistanceToCamera( Camera& Camera );

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить плоскости браша
		///		
		/// \return InfoBrush&
		//////////////////////////////////////////////////////////////////////
		map<GLuint, vector<BrushPlane> >& GetPlanes();

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить расстояние между брашем и камерой
		///		
		/// \return float
		//////////////////////////////////////////////////////////////////////
		float GetDistanceToCamera();

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить позицию браша в мире
		///		
		/// \return glm::vec3&
		//////////////////////////////////////////////////////////////////////
		glm::vec3& GetPosition();

		//////////////////////////////////////////////////////////////////////
		/// \brief Получить ограничивающее тело браша
		///		
		/// \return BoundingBox&
		//////////////////////////////////////////////////////////////////////
		BoundingBox& GetBoundingBox();

	private:

		float								DistanceToCamera; ///< Расстояние между брашем и камерой

		GLuint								VertexBuffer; ///< Вершиный буффер
		BoundingBox							BoundingBox; ///< Ограничивающее тело браша
		glm::vec3							Position; ///< Позиция браша в мире

		map<GLuint, vector<BrushPlane> >	Planes; ///< Массив плоскостей браша разбитый на текстуры
	};

	//-------------------------------------------------------------------------//
}

#endif // BRUSH_H