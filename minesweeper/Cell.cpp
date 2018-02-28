#include "Cell.h"
#include "Field.h"


Cell::Cell(bool is_mine, int count)
{
	_count = count;
	_state = CellState::None;
	_is_mine = is_mine;
	_is_open = false;
	_rect = Rect(Field::CellSize);
}


Cell::Cell()
	: Cell::Cell(true, -1) {}

Cell::~Cell()
{
}

bool Cell::Open()
{
	_is_open = true;

	return _is_mine;
}

void Cell::Draw() const
{
	// äJÇ¢ÇΩÇ«Ç§Ç©ÇÌÇ©ÇÈÇÊÇ§Ç…ÉZÉãÇï`âÊ
	_rect.draw(_is_open ? Palette::Gray : Palette::Darkgray);

	// ògê¸Çï`âÊ
	_rect.drawFrame(0.5, 0, Palette::Lightgrey);

	if (_is_open)
	{
		if (_is_mine)
		{
			TextureAsset(L"mine").drawAt(_rect.center);
		}
		else if(_count > 0)
		{
			// é¸ÇËÇ…Ç†ÇÈmineêîÇï`âÊ
			FontAsset(L"cell")(ToString(_count)).drawCenter(_rect.center, count_color());
		}
	}
	else
	{
		switch (_state)
		{
		case CellState::Flag:
			TextureAsset(L"flag").drawAt(_rect.center);
			break;
		case CellState::Question:
			TextureAsset(L"question").drawAt(_rect.center);
			break;
		}
	}
}

void Cell::ChangeNextState()
{
	switch (_state)
	{
	case CellState::None:
		_state = CellState::Flag;
		break;
	case CellState::Flag:
		_state = CellState::Question;
		break;
	case CellState::Question:
	default:
		_state = CellState::None;
		break;
	}
}

void Cell::SetPos(Point pos)
{
	_rect.setPos(pos);
}

bool Cell::GetIsMine()
{
	return _is_mine;
}

int Cell::GetCount()
{
	return _count;
}

Color Cell::count_color() const
{
	switch (_count)
	{
	case 1:
		return Palette::Blue;
	case 2:
		return Palette::Green;
	case 3:
		return Palette::Red;
	case 4:
		return Palette::Darkblue;
	case 5:
		return Palette::Brown;
	case 6:
		return Palette::Mediumseagreen;
	case 7:
		return Palette::Black;
	case 8:
		return Palette::Darkgray;
	default:
			return Palette::White;
	}
}
