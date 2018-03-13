#version 330 core

//------------------------------------------

struct SpotLight
{
	mat4 LightMatrix;
	vec4 Position;
	vec4 Color;
	vec3 SpotDirection;
	
	float Height;
	float SpotCutoff;
	float Intensivity;
};

//-------------------------------------------

out vec4 Color;

//-------------------------------------------

uniform vec2 ScreenSize;
uniform vec4 AmbientLight;
uniform SpotLight light;

// Textures
uniform sampler2D ColorMap;
uniform sampler2D PositionMap;
uniform sampler2D NormalMap;
uniform sampler2D ShadowMap;

//------------------------------------------

vec2 CalcTexCoord()
{
	return gl_FragCoord.xy / ScreenSize;
}

//------------------------------------------

float ShadowCalculation( vec2 TexCoords, float CurrentDepth, float Bias )
{		
    float ClosestDepth = texture( ShadowMap, TexCoords.xy ).r; 	
    float Shadow = CurrentDepth - Bias > ClosestDepth ? 1.0f : 0.0f;        
        
    return Shadow;
}

//------------------------------------------

float ShadowCalculationLiner( vec2 TexCoords, vec2 TexelSize, float CurrentDepth, float Bias )
{
	vec2 PixelPos = TexCoords / TexelSize + 0.5f;
	vec2 FractPart = fract( PixelPos );
	vec2 StartTexel = ( PixelPos - FractPart ) * TexelSize;
	
	float blTexel = ShadowCalculation( StartTexel, CurrentDepth, Bias );
	float brTexel = ShadowCalculation( StartTexel + vec2( TexelSize.x, 0.0f ), CurrentDepth, Bias );
	float tlTexel = ShadowCalculation( StartTexel + vec2( 0.0f, TexelSize.y ), CurrentDepth, Bias );
	float trTexel = ShadowCalculation( StartTexel + TexelSize, CurrentDepth, Bias );
	
	float MixA = mix( blTexel, tlTexel, FractPart.y );
	float MixB = mix( brTexel, trTexel, FractPart.y );
	
	return mix( MixA, MixB, FractPart.x );
}

//------------------------------------------

float ShadowCalculationPCF( vec4 PosFragInLightSpace, float NdotL )
{
    vec3 ProjCoords = PosFragInLightSpace.xyz / PosFragInLightSpace.w;
	ProjCoords = ProjCoords * 0.5f + 0.5f;
	
	vec2 TexelSize = 1.0f / textureSize( ShadowMap, 0 );
	
	float Bias = max( 0.0015f * ( 1.0f - NdotL ), 0.00005f );
	float CurrentDepth = ProjCoords.z;
	float Shadow = 0.0f;
	
	for ( int x = -1; x <= 1; ++x )
		for ( int y = -1; y <= 1; ++y )
			Shadow += ShadowCalculationLiner( ProjCoords.xy + vec2( x, y ) * TexelSize, TexelSize, CurrentDepth, Bias );
	           
    return Shadow / 9.0f;
}

//------------------------------------------

void main()
{
	vec2 texCoord = CalcTexCoord();
	vec3 Normal = normalize( texture( NormalMap, texCoord ).xyz );	
	vec4 PositionFragment = texture( PositionMap, texCoord );
	vec4 PosFragInLightSpace = light.LightMatrix * vec4(PositionFragment.xyz,1);
	
	vec3 lightDirection = ( light.Position - PositionFragment ).xyz;
	float Distance = length( lightDirection );
	lightDirection = normalize( lightDirection );
	
	float NdotL = dot( Normal, lightDirection );
	float DiffuseFactor = max( NdotL, 0.0f );
	float SpotFactor = dot( light.SpotDirection, -lightDirection );
	SpotFactor = clamp( ( SpotFactor - light.SpotCutoff ) / ( 1.0f - light.SpotCutoff ), 0.0f, 1.0f );
	float Attenuation = max( 1.0f - pow( Distance / light.Height, 2 ), 0.f );
	float Shadow = ShadowCalculationPCF( PosFragInLightSpace, NdotL );
	
	Color = ( 1.0f - Shadow ) * ( light.Color * DiffuseFactor * light.Intensivity * SpotFactor ) * Attenuation * texture( ColorMap, texCoord );
}