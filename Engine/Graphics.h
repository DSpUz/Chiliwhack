/******************************************************************************************
*	Chili DirectX Framework Version 16.07.20											  *
*	Graphics.h																			  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once
#include <d3d11.h>
#include <wrl.h>
#include <math.h>
#include "ChiliException.h"
#include "Colors.h"
#include "Surface.h"
#include "RectI.h"


class Graphics
{
public:
	class Exception : public ChiliException
	{
	public:
		Exception( HRESULT hr,const std::wstring& note,const wchar_t* file,unsigned int line );
		std::wstring GetErrorName() const;
		std::wstring GetErrorDescription() const;
		virtual std::wstring GetFullMessage() const override;
		virtual std::wstring GetExceptionType() const override;
	private:
		HRESULT hr;
	};
private:
	// vertex format for the framebuffer fullscreen textured quad
	struct FSQVertex
	{
		float x,y,z;		// position
		float u,v;			// texcoords
	};
public:
	Graphics( class HWNDKey& key );
	Graphics( const Graphics& ) = delete;
	Graphics& operator=( const Graphics& ) = delete;
	void EndFrame();
	void BeginFrame();
	/*--------------------------------------------
	--------------MY FUNCTIONS---------------------*/
	void DrawLine(int x1, int y1, int x2, int y2, int r, int g, int bl);//see video - old series beginner Lesson 10
	void DrawRectangle(int cx, int cy, int height, int width, int angle, int r, int g, int b);//for drawing hammer
	/*------------ALPHABET, NUMBERS, and SPECIAL CHARACTERS - THANKS to Nny http://www.planetchili.net/forum/viewtopic.php?f=3&t=3703-----------------------------*/
	void Block(int x, int y, int r, int g, int b);
	void chA(int x, int y, int r, int g, int b);

	void chC(int x, int y, int r, int g, int b);

	void chE(int x, int y, int r, int g, int b);

	void chG(int x, int y, int r, int g, int b);
	void chH(int x, int y, int r, int g, int b);
	void chI(int x, int y, int r, int g, int b);

	void chK(int x, int y, int r, int g, int b);
	void chL(int x, int y, int r, int g, int b);
	void chM(int x, int y, int r, int g, int b);
	void chN(int x, int y, int r, int g, int b);
	void chO(int x, int y, int r, int g, int b);
	void chP(int x, int y, int r, int g, int b);

	void chR(int x, int y, int r, int g, int b);
	void chS(int x, int y, int r, int g, int b);
	void chT(int x, int y, int r, int g, int b);
	void chU(int x, int y, int r, int g, int b);

	void chW(int x, int y, int r, int g, int b);

	void chY(int x, int y, int r, int g, int b);


	void ch0(int x, int y, int r, int g, int b);
	void ch1(int x, int y, int r, int g, int b);
	void ch2(int x, int y, int r, int g, int b);
	void ch3(int x, int y, int r, int g, int b);
	void ch4(int x, int y, int r, int g, int b);
	void ch5(int x, int y, int r, int g, int b);
	void ch6(int x, int y, int r, int g, int b);
	void ch7(int x, int y, int r, int g, int b);
	void ch8(int x, int y, int r, int g, int b);
	void ch9(int x, int y, int r, int g, int b);

	void chPoint(int x, int y, int r, int g, int b);
	void chApostrophe(int x, int y, int r, int g, int b);
	void chExMark(int x, int y, int r, int g, int b);
	/*---------------------------------------------------------*/
	void PutPixel( int x,int y,int r,int g,int b )
	{
		PutPixel( x,y,{ unsigned char( r ),unsigned char( g ),unsigned char( b ) } );
	}
	void PutPixel( int x,int y,Color c );
	~Graphics();
	void DrawSpriteNonChroma(int x, int y, const Surface& s);
	void DrawSpriteNonChroma(int x, int y, const RectI& srcRect, const Surface& s);
	void DrawSpriteNonChroma(int x, int y, RectI srcRect, const RectI& clipRect, const Surface& s);
	void DrawSprite(int x, int y, const Surface& s, Color colorkey);
	void DrawSprite(int x, int y, const RectI& srcRect, const Surface& s, Color colorkey);
	void DrawSprite(int x, int y, RectI srcRect, const RectI& clipRect, const Surface& s, Color colorkey);
	RectI GetScreenRect() const;
private:
	Microsoft::WRL::ComPtr<IDXGISwapChain>				pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device>				pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			pImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		pRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				pSysBufferTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	pSysBufferTextureView;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>			pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>			pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>				pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>			pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			pSamplerState;
	D3D11_MAPPED_SUBRESOURCE							mappedSysBufferTexture;
	Color*                                              pSysBuffer = nullptr;
public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};