#include "Field.h"



Field::Field(Size size, int count, Point origin)
{
	Grid<bool> mines{ size };
	cells = Grid<Cell>(size);

	// mine�������_����count��������
	for (int i = 0; i < count; i++)
	{
		bool & mine = mines[Random(0, size.y)][Random(0, size.x)];

		if (mine)
		{
			i--;
		}
		else
		{
			mine = true;
		}
	}

	// �t�B�[���h�̃Z���𐶐������ꂼ��origin����Ƃ����`��ꏊ��ݒ肷��
	for (int i = 0; i < mines.width; i++)
	{
		for (int j = 0; j < mines.height; j++)
		{
			cells[j][i] = Cell(mines[j][i], to_count(mines, Point(i, j)));
			cells[j][i].SetPos(origin + Point(i, j) * CellSize);
		}
	}
}

Field::~Field()
{
}

void Field::Draw() const
{
	for (auto cell : cells)
	{
		cell.Draw();
	}
}

void Field::ChangeCellState(Point pos)
{
	cells[pos.y][pos.x].ChangeNextState();
}

bool Field::OpenCell(Point pos)
{
	return cells[pos.y][pos.x].Open();
}

bool Field::IsMineCell(Point pos)
{
	return cells[pos.y][pos.x].GetIsMine();
}

int Field::to_count(Grid<bool> mines, Point pos)
{
	int count = 0;

	for (int i = pos.x - 1; i <= pos.x + 1; i++)
	{
		// �t�B�[���h�O�̓J�E���g�����ɔ�΂�
		if (i < 0 || i >= mines.width)
		{
			continue;
		}

		for (int j = pos.y - 1; j <= pos.y + 1; j++)
		{
			// �t�B�[���h�O�̓J�E���g�����ɔ�΂�
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
