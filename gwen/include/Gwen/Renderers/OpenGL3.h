/*
	GWEN
	Copyright (c) 2011 Facepunch Studios
	See license in Gwen.h
*/

#ifndef GWEN_RENDERERS_OPENGL3_H
#define GWEN_RENDERERS_OPENGL3_H

#include "Gwen/Gwen.h"
#include "Gwen/BaseRender.h"

#include "GL\glew.h"

namespace Gwen
{
	namespace Renderer
	{

		class OpenGL3 : public Gwen::Renderer::Base
		{
			public:

				struct Vertex
				{
					float x, y, z;
					float u, v;
					float r, g, b, a;
				};

				OpenGL3();
				~OpenGL3();

				virtual void Init(int _windowWidth, int _windowHeight);

				virtual void Begin();
				virtual void End();

				virtual void SetDrawColor( Gwen::Color color );
				virtual void DrawFilledRect( Gwen::Rect rect );

				void StartClip();
				void EndClip();

				void DrawTexturedRect( Gwen::Texture* pTexture, Gwen::Rect pTargetRect, float u1 = 0.0f, float v1 = 0.0f, float u2 = 1.0f, float v2 = 1.0f );
				void LoadTexture( Gwen::Texture* pTexture );
				void FreeTexture( Gwen::Texture* pTexture );
				Gwen::Color PixelColour( Gwen::Texture* pTexture, unsigned int x, unsigned int y, const Gwen::Color & col_default );

			protected:

				static const int	MaxVerts = 1024;

				//Opengl3 rendering stuff
				std::vector<GLfloat> vertexBufferData;
				GLuint VAO;
				GLuint VBO;
				GLuint Program;
				GLuint ProgramViewportLocation;
				GLuint ProgramTextureLocation;
				GLuint ProgramTextureEnabledLocation;

				int windowWidth;
				int windowHeight;

				void Flush();
				void AddVert( int x, int y, float u = 0.0f , float v = 0.0f );

				Gwen::Color			m_Color;
				int					m_iVertNum;
				Vertex				m_Vertices[ MaxVerts ];

				bool   m_textureEnabled;
				GLuint m_currentTexture;

			public:

				//
				// Self Initialization
				//

				virtual bool InitializeContext( Gwen::WindowProvider* pWindow );
				virtual bool ShutdownContext( Gwen::WindowProvider* pWindow );
				virtual bool PresentContext( Gwen::WindowProvider* pWindow );
				virtual bool ResizedContext( Gwen::WindowProvider* pWindow, int w, int h );
				virtual bool BeginContext( Gwen::WindowProvider* pWindow );
				virtual bool EndContext( Gwen::WindowProvider* pWindow );

				void*	m_pContext;
		};

	}
}
#endif
