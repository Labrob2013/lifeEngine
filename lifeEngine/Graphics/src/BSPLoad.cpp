#include "..\BSPLoad.h"

//-------------------------------------------------------------------------//

bool le::BSPLoad::LoadBSP( const string& Route )
{
	ifstream FileBSP( Route, ios::binary );

	if ( !FileBSP.is_open() )
	{
		Logger::Log( Logger::Error, "BSP File [" + Route + "] Not Found" );
		return false;
	}

	BSPHeader		Header = { 0 };
	BSPLump			Lumps[ MaxLumps ] = { 0 };

	// *************************************
	// ��������� ��������� � ����� �����

	FileBSP.read( ( char* ) &Header, sizeof( BSPHeader ) );
	FileBSP.read( ( char* ) &Lumps, MaxLumps * sizeof( BSPLump ) );

	// �������� ������ ��� ������
	NumOfVerts = Lumps[ Vertices ].Length / sizeof( BSPVertex );
	PointVerts = new BSPVertex[ NumOfVerts ];

	// �������� ������ ��� ������
	NumOfFaces = Lumps[ Faces ].Length / sizeof( BSPFace );
	PointFaces = new BSPFace[ NumOfFaces ];

	// �������� ������ ��� ��������
	NumOfIndices = Lumps[ Indices ].Length / sizeof( unsigned int );
	PointIndices = new unsigned int[ NumOfIndices ];

	// �������� ������ ��� ���������� ����������
	NumOfTextures = Lumps[ Textures ].Length / sizeof( BSPTexture );
	BSPTexture* PointTextures = new BSPTexture[ NumOfTextures ];

	// ��������� �� ������� � �����, � ������� �������� ���������� � ��������
	FileBSP.seekg( Lumps[ Vertices ].Offset, ios::beg );

	// ��������� ��� ������� � �����
	for ( int i = 0; i < NumOfVerts; i++ )
	{
		// ��������� ������� �������
		FileBSP.read( ( char* ) &PointVerts[ i ], sizeof( BSPVertex ) );

		// ������ �������� Y � Z, � �������� ����� Z, ����� Y ��� �����.
		float Temp = PointVerts[ i ].Position.y;
		PointVerts[ i ].Position.y = PointVerts[ i ].Position.z;
		PointVerts[ i ].Position.z = -Temp;

		Temp = PointVerts[ i ].Normal.y;
		PointVerts[ i ].Normal.y = PointVerts[ i ].Normal.z;
		PointVerts[ i ].Normal.z = -Temp;
	}

	// ��������� �� ������� � �����, � ������� �������� ���������� � ��������
	FileBSP.seekg( Lumps[ Indices ].Offset, ios::beg );
	FileBSP.read( ( char* ) &PointIndices[0], NumOfIndices * sizeof( unsigned int ) );

	// ��������� �� ������� � �����, � ������� �������� ���������� � ������
	FileBSP.seekg( Lumps[ Faces ].Offset, ios::beg );
	FileBSP.read( ( char* ) &PointFaces[ 0 ], NumOfFaces * sizeof( BSPFace ) );

	// ��������� �� ������� � �����, � ������� �������� ���������� � ���������
	FileBSP.seekg( Lumps[ Textures ].Offset, ios::beg );
	FileBSP.read( ( char* ) &PointTextures[ 0 ], NumOfTextures * sizeof( BSPTexture ) );

	// ��������� ��� ��������
	for ( int i = 0; i < NumOfTextures; i++ )
	{
		ResourcesManager::LoadGlTexture( PointTextures[ i ].StrName, "../" + string( PointTextures[ i ].StrName ) + ".jpg" );
		TexturesID[ i ] = ResourcesManager::GetGlTexture( PointTextures[ i ].StrName );
	}

	// ������� ���������� � ���������
	delete[] PointTextures;

	FileBSP.close();
	return true;
}

//-------------------------------------------------------------------------//

int le::BSPLoad::GetNumberVertexs()
{
	return NumOfVerts;
}

//-------------------------------------------------------------------------//

int le::BSPLoad::GetNumberFaces()
{
	return NumOfFaces;
}

//-------------------------------------------------------------------------//

int le::BSPLoad::GetNumberIndices()
{
	return NumOfIndices;
}

//-------------------------------------------------------------------------//

int le::BSPLoad::GetNumberTextures()
{
	return NumOfTextures;
}

//-------------------------------------------------------------------------//

unsigned int* le::BSPLoad::GetPtrIndeces()
{
	return PointIndices;
}

//-------------------------------------------------------------------------//

le::BSPVertex* le::BSPLoad::GetPtrVertexs()
{
	return PointVerts;
}

//-------------------------------------------------------------------------//

le::BSPFace* le::BSPLoad::GetPtrFaces()
{
	return PointFaces;
}

//-------------------------------------------------------------------------//

GLuint* le::BSPLoad::GetPtrTextures()
{
	return &TexturesID[ 0 ];
}

//-------------------------------------------------------------------------//