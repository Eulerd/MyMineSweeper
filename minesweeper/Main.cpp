
# include <Siv3D.hpp>
#include "Field.h"

void Main()
{
	int c_size = Field::CellSize;
	FontAsset::Register(L"cell", Field::CellSize / 3);
	TextureAsset::Register(L"flag", L"Images/flag.png");
	TextureAsset::Register(L"mine", L"Images/mine.png");
	TextureAsset::Register(L"question", L"Images/question.png");
	TextureAsset(L"flag").resize(Size(c_size - 1, c_size - 1));
	TextureAsset(L"mine").resize(Size(c_size - 1, c_size - 1));
	TextureAsset(L"question").resize(Size(c_size - 1, c_size - 1));


	Point origin{ 0,0 };
	Field field{ Size(16, 16), 10, origin };

	while (System::Update())
	{
		// マウスがクリックしたセルの座標
		Point pos = Point(Mouse::Pos() - origin) / Field::CellSize;

		if (Input::MouseL.clicked)
		{			
			field.OpenCell(pos);
		}

		if (Input::MouseR.clicked)
		{
			field.ChangeCellState(pos);
		}

		field.Draw();
	}
}
