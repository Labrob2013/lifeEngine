#include "..\..\3D\Level3D.h"

//-------------------------------------------------------------------------//

le::Level3D::Level3D( le::System& System )
{
	this->System = &System;
}

//-------------------------------------------------------------------------//

le::Level3D::~Level3D()
{
	ClearLevel();
}

//-------------------------------------------------------------------------//

bool le::Level3D::LoadLevel( string sRoute )
{
	map<string, GLuint> mTextures;
	TiXmlDocument LMAP;

	if ( !LMAP.LoadFile( sRoute.c_str() ) )
		return false;

	// �������� � ����������� Map
	TiXmlElement *Map;
	Map = LMAP.FirstChildElement( "Map" );

	// -----MAP SETTINGS----- //

	// �������� � ����������� Settings
	TiXmlElement *Settings;
	Settings = Map->FirstChildElement( "Settings" );

	// �������� � ����������� NameMap
	TiXmlElement *NameMap;
	NameMap = Settings->FirstChildElement( "NameMap" );

	if ( NameMap->Attribute( "Value" ) != NULL )
		sNameMap = NameMap->Attribute( "Value" );

	// �������� � ����������� DescriptionMap
	TiXmlElement *DescriptionMap;
	DescriptionMap = Settings->FirstChildElement( "DescriptionMap" );

	if ( DescriptionMap->Attribute( "Value" ) != NULL )
		sDescriptionMap = DescriptionMap->Attribute( "Value" );

	// �������� � ����������� SkyBoxName
	TiXmlElement *SkyBoxName;
	SkyBoxName = Settings->FirstChildElement( "SkyBoxName" );

	if ( SkyBoxName->Attribute( "Value" ) != NULL )
		sSkyBoxName = SkyBoxName->Attribute( "Value" );

	// -----TEXTURES----- //

	// �������� � ����������� Textures
	TiXmlElement *Textures;
	TiXmlElement *Texture;
	Textures = Map->FirstChildElement( "Textures" );

	if ( Textures != NULL )
	{
		Texture = Textures->FirstChildElement( "Texture" );

		while ( Texture )
		{
			string name = Texture->Attribute( "Name" );
			string route = Texture->Attribute( "Route" );
			mTextures[name] = System->LoadGLTexture( route );

			Texture = Texture->NextSiblingElement();
		}
	}

	// -----BRUSHES----- //

	// �������� � ����������� Brushes
	TiXmlElement *Brushes;
	Brushes = Map->FirstChildElement( "Brushes" );

	// -----BRUSHES | SOLID----- //

	// �������� � ����������� Solid
	TiXmlElement *Solid;
	Solid = Brushes->FirstChildElement( "Solid" );

	if ( Solid != NULL )
	{
		// �������� � ����������� Brush
		TiXmlElement *Brush;
		Brush = Solid->FirstChildElement( "Brush" );

		while ( Brush )
		{
			string typeBrush;
			string textureName;

			vector<Vector3f> vertex;
			vector<Vector2f> texCoord;

			// �������� � ����������� Type
			TiXmlElement *Type;
			Type = Brush->FirstChildElement( "Type" );

			if ( Type->Attribute( "Value" ) != NULL )
				typeBrush = Type->Attribute( "Value" );

			// �������� � ����������� TextureName
			TiXmlElement *TextureName;
			TextureName = Brush->FirstChildElement( "TextureName" );

			if ( TextureName->Attribute( "Value" ) != NULL )
				textureName = TextureName->Attribute( "Value" );

			// �������� � ����������� PositionVertex
			TiXmlElement *PositionVertex;
			TiXmlElement *Vertex;			
			PositionVertex = Brush->FirstChildElement( "PositionVertex" );
			Vertex = PositionVertex->FirstChildElement( "Vertex" );

			while ( Vertex )
			{
				Vector3f tmpVertex;

				tmpVertex.x = atof( Vertex->Attribute( "X" ) );
				tmpVertex.y = atof( Vertex->Attribute( "Y" ) );
				tmpVertex.z = atof( Vertex->Attribute( "Z" ) );

				vertex.push_back( tmpVertex );
				Vertex = Vertex->NextSiblingElement( );
			}

			// �������� � ����������� TextureCoords
			TiXmlElement *TextureCoords;
			TiXmlElement *Point;
			TextureCoords = Brush->FirstChildElement( "TextureCoords" );
			Point = TextureCoords->FirstChildElement( "Point" );

			while ( Point )
			{
				Vector2f tmpPoint;

				tmpPoint.x = atof( Point->Attribute( "X" ) );
				tmpPoint.y = atof( Point->Attribute( "Y" ) );

				texCoord.push_back( tmpPoint );
				Point = Point->NextSiblingElement( );
			}

			le::Brush* tmpBrush = new le::Brush( *System );
			tmpBrush->InitBrush( Brush::PrimitivesType::Cube, mTextures[textureName], vertex, texCoord );
			vBrushes.push_back( tmpBrush );

			Brush = Brush->NextSiblingElement();
		}
	}

	return true;
}

//-------------------------------------------------------------------------//

void le::Level3D::ClearLevel()
{
	for ( int i = 0; i < vBrushes.size(); i++ )
		delete vBrushes[i];
}

//-------------------------------------------------------------------------//

void le::Level3D::RenderLevel()
{
	for ( int i = 0; i < vBrushes.size(); i++ )
		vBrushes[i]->RenderBrush();
}

//-------------------------------------------------------------------------//