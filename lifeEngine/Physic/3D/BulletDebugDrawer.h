#ifndef BULLET_DEBUG_DRAWER
#define BULLET_DEBUG_DRAWER

#define COMPILING_LIBRARY
#include "../../DllGlobal.h"

///////////////////////////
/// BULLET PHYSICS
///////////////////////////
#include <btBulletDynamicsCommon.h>

//////////////////
// LIFEENGINE
/////////////////
#include <System/System.h>

namespace le
{
	//-------------------------------------------------------------------------//

	class DLL_API BulletDebugDrawer : public btIDebugDraw
	{
	public:
		////////////////
		/// �����������
		////////////////
		BulletDebugDrawer();

		///////////////////////
		/// ���������� �����
		///////////////////////
		virtual void drawLine( const btVector3& from, const btVector3& to, const btVector3& color );

		//////////////////////////////////////
		/// ���������� ����� ���������������
		//////////////////////////////////////
		virtual void drawContactPoint( const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color );

		/////////////////////////////
		/// �������� ��� ������
		////////////////////////////
		virtual void reportErrorWarning( const char* warningString );

		/////////////////////////////
		/// ���������� 3D �����
		////////////////////////////
		virtual void draw3dText( const btVector3& location, const char* textString );

		/////////////////////////////
		/// ������ ����� �������
		////////////////////////////
		virtual void setDebugMode( int DebugMode );

		/////////////////////////////
		/// �������� ����� �������
		////////////////////////////
		virtual int getDebugMode() const;

	private:

		int				DebugMode;
	};

	//-------------------------------------------------------------------------//
}

#endif // BULLET_DEBUG_DRAWER