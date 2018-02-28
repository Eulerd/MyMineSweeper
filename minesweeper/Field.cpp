#include "Field.h"



Field::Field(Size size, int count, Point origin)
{
	_size = size;
	Grid<bool> mines{ _size };
	_cells = Grid<Cell>(_size);
	_cells_table = Grid<bool>(_size, false);

	// mineをランダムにcount個生成する
	for (int i = 0; i < count; i++)
	{
		bool & mine = mines[Random(0, _size.y)][Random(0, _size.x)];

		if (mine)
		{
			i--;
		}
		else
		{
			mine = true;
		}
	}

	// フィールドのセルを生成しそれぞれoriginを基準とした描画場所を設定する
	for (int i = 0; i < mines.width; i++)
	{
		for (int j = 0; j < mines.height; j++)
		{
			_cells[j][i] = Cell(mines[j][i], to_count(mines, Point(i, j)));
			_cells[j][i].SetPos(origin + Point(i, j) * CellSize);
		}
	}
}

Field::~Field()
{
}

void Field::Draw() const
{
	for (auto cell : _cells)
	{
		cell.Draw();
	}
}

void Field::ChangeCellState(Point pos)
{
	_cells[pos.y][pos.x].ChangeNextState();
}

bool Field::OpenCell(Point pos)
{
	return _cells[pos.y][pos.x].Open();
}

bool Field::IsMineCell(Point pos)
{
	return _cells[pos.y][pos.x].GetIsMine();
}

void Field::AutoOpenCells(Point pos)
{
	// 探索済みにする
	_cells_table[pos.y][pos.x] = true;

	// そのセルか周囲にmineがあれば終了
	if (_cells[pos.y][pos.x].GetIsMine())
	{
		return;
	}

	_cells[pos.y][pos.x].Open();

	if (_cells[pos.y][pos.x].GetCount() > 0)
	{
		return;
	}

	// 枠外にはみ出さないように探索
	if (pos.x > 0 && ! _cells_table[pos.y][pos.x - 1])
	{
		AutoOpenCells(pos - Point(1, 0));
	}

	if (pos.x < _size.x - 1 && !_cells_table[pos.y][pos.x + 1])
	{
		AutoOpenCells(pos + Point(1, 0));
	}

	if (pos.y > 0 && !_cells_table[pos.y - 1][pos.x])
	{
		AutoOpenCells(pos - Point(0, 1));
	}

	if (pos.y < _size.y - 1 && !_cells_table[pos.y + 1][pos.x])
	{
		AutoOpenCells(pos + Point(0, 1));
	}
}

int Field::to_count(Grid<bool> mines, Point pos)
{
	int count = 0;

	for (int i = pos.x - 1; i <= pos.x + 1; i++)
	{
		// フィールド外はカウントせずに飛ばす
		if (i < 0 || i >= mines.width)
		{
			continue;
		}

		for (int j = pos.y - 1; j <= pos.y + 1; j++)
		{
			// フィールド外はカウントせずに飛ばす
			if (j < 0 || j >= mines.height)
			{
				continue;
			}

			if (mines[j][i])
			{
				count++;
			}
		}
	}

	return count;
}
