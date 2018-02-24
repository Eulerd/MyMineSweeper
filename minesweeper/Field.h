#pragma once
#include <Siv3D.hpp>
#include "Cell.h"

class Field
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="size">フィールドの大きさ</param>
	/// <param name="count">フィールド内のmineの数</param>
	/// <param name="origin">フィールドを描画する基準</param>
	Field(Size size, int count, Point origin);
	~Field();

	/// <summary>
	/// フィールド情報を描画する
	/// </summary>
	void Draw() const;

	/// <summary>
	/// セルの状態を変更する
	/// </summary>
	/// <param name="pos">セルの座標</param>
	void ChangeCellState(Point pos);

	/// <summary>
	/// セルを開ける
	/// </summary>
	/// <param name="pos">セルの座標</param>
	/// <returns>セル内にmineがあったか</returns>
	bool OpenCell(Point pos);

public:
	/// <summary>
	/// セルの大きさ
	/// </summary>
	static const int CellSize = 32;

private:
	/// <summary>
	/// セルの周りにあるmineの数を返す
	/// </summary>
	/// <param name="mines">mineがあるかどうかの配列</param>
	/// <param name="pos">調べるセル</param>
	/// <returns>周囲8マスのmineの数</returns>
	int to_count(Grid<bool> mines, Point pos);

private:
	Grid<Cell> cells;
};

