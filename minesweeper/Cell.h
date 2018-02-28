#pragma once
#include <Siv3D.hpp>
#include "CellState.h"

class Cell
{
public:
	/// <summary>
	/// セル内にmineありで初期化
	/// </summary>
	Cell();

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="is_mine">このセルがmineを持っているか</param>
	/// <param name="count">セルの周りにあるmineの数</param>
	Cell(bool is_mine, int count);
	~Cell();

	/// <summary>
	/// セルを描画します
	/// </summary>
	void Draw() const;

	/// <summary>
	/// セルを開けmineがあるか確認します
	/// </summary>
	/// <returns>mineがあったかどうか</returns>
	bool Open();

	/// <summary>
	/// セルを次の状態に変更する
	/// None -> Flag -> Question -> Noneの順で変更される
	/// </summary>
	void ChangeNextState();

	/// <summary>
	/// セルの場所を変更します
	/// </summary>
	/// <param name="pos">移動先の場所</param>
	void SetPos(Point pos);

	bool GetIsMine();

private:
	bool _is_mine;
	bool _is_open;
	CellState _state;
	int _count;
	Rect _rect;

private:
	/// <summary>
	/// 数に応じた色を取得する
	/// </summary>
	/// <returns>周りのmineの数に応じた色を返す</returns>
	Color count_color() const;
		
};

