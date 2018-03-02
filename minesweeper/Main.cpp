
# include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "Field.h"

struct CommonData
{
	Point origin{ 0,0 };
	Field field{ Size(16, 16), 10, origin };
};

using MyApp = SceneManager<String, CommonData>;

class Game : public MyApp::Scene
{
public:

	void update() override
	{
		// マウスがクリックしたセルの座標
		Point pos = Point(Mouse::Pos() - m_data->origin) / Field::CellSize;

		if (Input::MouseL.clicked)
		{
			if (m_data->field.IsMineCell(pos))
			{
				Println(L"GameOver");
				// Game Over
			}
			else
			{
				m_data->field.AutoOpenCells(pos);
			}
		}

		if (Input::MouseR.clicked)
		{
			m_data->field.ChangeCellState(pos);
		}
	}

	void draw() const override
	{
		m_data->field.Draw();
	}
};

class Result : public MyApp::Scene
{
public:
	void update() override
	{

	}

	void draw() const override
	{

	}
};

void Main()
{
	int c_size = Field::CellSize;

	// フォント登録
	FontAsset::Register(L"cell", Field::CellSize / 3);

	// 画像登録
	TextureAsset::Register(L"flag", L"Images/flag.png");
	TextureAsset::Register(L"mine", L"Images/mine.png");
	TextureAsset::Register(L"question", L"Images/question.png");
	TextureAsset(L"flag").resize(Size(c_size - 1, c_size - 1));
	TextureAsset(L"mine").resize(Size(c_size - 1, c_size - 1));
	TextureAsset(L"question").resize(Size(c_size - 1, c_size - 1));

	// シーン登録
	MyApp manager;
	manager.add<Game>(L"Game");
	manager.add<Result>(L"Result");

	while (System::Update())
	{
		manager.updateAndDraw();
	}
}
