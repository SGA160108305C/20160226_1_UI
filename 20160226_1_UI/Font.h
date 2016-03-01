#pragma once
class Font
{
private:
	Font();
	Font(const Font& other);
	~Font();

public :
	enum FontType
	{
		HEADING,
		BUTTON,
		BODY
	};

	static Font& Get()
	{
		static Font instance;
		return instance;
	}

	void Initialize();
	void Destroy();

	static inline LPD3DXFONT GetFont(FontType type){ return Font::Get().GetInstanceFont(type); }

protected:
	LPD3DXFONT fontHeading = nullptr;
	LPD3DXFONT fontButton = nullptr;
	LPD3DXFONT fontBody = nullptr;

	inline LPD3DXFONT GetInstanceFont(FontType type)
	{
		switch (type)
		{
		case Font::HEADING:
			return fontHeading;
			break;
		case Font::BUTTON:
			return fontButton;
			break;
		case Font::BODY:
			return fontBody;
			break;
		default:
			break;
		}

		return nullptr;
	}
};

