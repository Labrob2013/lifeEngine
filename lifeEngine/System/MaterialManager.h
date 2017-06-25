#ifndef MATERIAL_MANAGER_H
#define MATERIAL_MANAGER_H

#define COMPILING_LIBRARY
#include "../../DllGlobal.h"

////////////////
/// LIFEENGINE
///////////////
#include "System.h"
#include "3D/ModelMesh.h"

namespace le
{
	//-------------------------------------------------------------------------//

	class DLL_API MaterialManager
	{
	public:
		///////////////////////////////
		/// ��������� OPENGL ��������
		//////////////////////////////
		static bool LoadGLTexture( string key, string route );

		//////////////////////////
		/// ��������� ��� ������
		//////////////////////////
		static bool LoadModelMesh( string key, string route );

		//////////////////////////////
		/// �������� OPENGL ��������
		//////////////////////////////
		static const GLuint GetGLTexture( string key );

		//////////////////////////
		/// �������� ��� ������
		//////////////////////////
		static const ModelMesh GetModelMesh( string key );

		//////////////////////////
		/// ������� ��� ���������
		//////////////////////////
		static void DeleteAllMaterials( );

		////////////////////////
		/// ������� ��� ������
		////////////////////////
		static void DeleteModelMesh( string key );

		/////////////////////////////
		/// ������� OPENGL ��������
		/////////////////////////////
		static void DeleteGlTexture( string key );

	private:
		static map<string, GLuint>				mGlTexture;
		static map<string, ModelMesh>			mModelMesh;
	};

	//-------------------------------------------------------------------------//
}

#endif // MATERIAL_MANAGER_H