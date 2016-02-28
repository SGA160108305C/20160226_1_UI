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
		BUTTON
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
		default:
			break;
		}

		return nullptr;
	}
};

