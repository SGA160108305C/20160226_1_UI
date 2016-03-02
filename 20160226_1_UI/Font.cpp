#include "stdafx.h"
#include "Font.h"


Font::Font()
{
}


Font::~Font()
{
}

void Font::Initialize()
{
	D3DXFONT_DESC font_desc_heading;
	ZeroMemory(&font_desc_heading, sizeof(D3DXFONT_DESC));
	font_desc_heading.Height = 40;
	font_desc_heading.Width = 15;
	font_desc_heading.Weight = FW_NORMAL;
	font_desc_heading.MipLevels = D3DX_DEFAULT;
	font_desc_heading.Italic = false;
	font_desc_heading.CharSet = DEFAULT_CHARSET;
	font_desc_heading.OutputPrecision = OUT_DEFAULT_PRECIS;
	font_desc_heading.Quality = DEFAULT_QUALITY;
	font_desc_heading.PitchAndFamily = FF_DONTCARE;
	wcscpy_s(font_desc_heading.FaceName, L"Arial");	//글꼴 스타일
	//AddFontResource(L"./Data/Font/umberto.ttf");
	//wcscpy_s(font_desc.FaceName, L"umberto");

	D3DXFONT_DESC font_desc_button;
	ZeroMemory(&font_desc_button, sizeof(D3DXFONT_DESC));
	font_desc_button.Height = 25;
	font_desc_button.Width = 10;
	font_desc_button.Weight = FW_NORMAL;
	font_desc_button.MipLevels = D3DX_DEFAULT;
	font_desc_button.Italic = false;
	font_desc_button.CharSet = DEFAULT_CHARSET;
	font_desc_button.OutputPrecision = OUT_DEFAULT_PRECIS;
	font_desc_button.Quality = DEFAULT_QUALITY;
	font_desc_button.PitchAndFamily = FF_DONTCARE;
	wcscpy_s(font_desc_button.FaceName, L"Arial");	//글꼴 스타일

	D3DXFONT_DESC font_desc_body;
	ZeroMemory(&font_desc_body, sizeof(D3DXFONT_DESC));
	font_desc_body.Height = 20;
	font_desc_body.Width = 9;
	font_desc_body.Weight = FW_NORMAL;
	font_desc_body.MipLevels = D3DX_DEFAULT;
	font_desc_body.Italic = false;
	font_desc_body.CharSet = DEFAULT_CHARSET;
	font_desc_body.OutputPrecision = OUT_DEFAULT_PRECIS;
	font_desc_body.Quality = DEFAULT_QUALITY;
	font_desc_body.PitchAndFamily = FF_DONTCARE;
	wcscpy_s(font_desc_body.FaceName, L"Arial");	//글꼴 스타일

	D3DXCreateFontIndirect(
		GameManager::GetDevice(),
		&font_desc_heading,
		&fontHeading);

	D3DXCreateFontIndirect(
		GameManager::GetDevice(),
		&font_desc_button,
		&fontButton);

	D3DXCreateFontIndirect(
		GameManager::GetDevice(),
		&font_desc_body,
		&fontBody);
}

void Font::Destroy()
{
	SAFE_RELEASE(fontBody);
	SAFE_RELEASE(fontButton);
	SAFE_RELEASE(fontHeading);
}