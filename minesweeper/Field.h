#pragma once
#include <Siv3D.hpp>
#include "Cell.h"

class Field
{
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="size">�t�B�[���h�̑傫��</param>
	/// <param name="count">�t�B�[���h����mine�̐�</param>
	/// <param name="origin">�t�B�[���h��`�悷��</param>
	Field(Size size, int count, Point origin);
	~Field();

	/// <summary>
	/// �t�B�[���h����`�悷��
	/// </summary>
	void Draw() const;

	/// <summary>
	/// �Z���̏�Ԃ�ύX����
	/// </summary>
	/// <param name="pos">�Z���̍��W</param>
	void ChangeCellState(Point pos);

	/// <summary>
	/// �Z�����J����
	/// </summary>
	/// <param name="pos">�Z���̍��W</param>
	/// <returns>�Z������mine����������</returns>
	bool OpenCell(Point pos);

	/// <summary>
	/// ���̃Z����mine�����邩���ׂ�
	/// </summary>
	/// <param name="pos">�Z���̍��W</param>
	/// <returns>�Z����mine�����邩</returns>
	bool IsMineCell(Point pos);

	/// <summary>
	/// �J����Z���������ŊJ����
	/// </summary>
	/// <param name="pos">�Z�����J�����̍��W</param>
	void AutoOpenCells(Point pos);

public:
	/// <summary>
	/// �Z���̑傫��
	/// </summary>
	static const int CellSize = 24;

private:
	/// <summary>
	/// �Z���̎���ɂ���mine�̐���Ԃ�
	/// </summary>
	/// <param name="mines">mine�����邩�ǂ����̔z��</param>
	/// <param name="pos">���ׂ�Z��</param>
	/// <returns>����8�}�X��mine�̐�</returns>
	int to_count(Grid<bool> mines, Point pos);

private:
	Grid<Cell> _cells;
	Grid<bool> _cells_table;
	Size _size;
};

