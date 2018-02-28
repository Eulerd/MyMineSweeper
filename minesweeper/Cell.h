#pragma once
#include <Siv3D.hpp>
#include "CellState.h"

class Cell
{
public:
	/// <summary>
	/// �Z������mine����ŏ�����
	/// </summary>
	Cell();

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="is_mine">���̃Z����mine�������Ă��邩</param>
	/// <param name="count">�Z���̎���ɂ���mine�̐�</param>
	Cell(bool is_mine, int count);
	~Cell();

	/// <summary>
	/// �Z����`�悵�܂�
	/// </summary>
	void Draw() const;

	/// <summary>
	/// �Z�����J��mine�����邩�m�F���܂�
	/// </summary>
	/// <returns>mine�����������ǂ���</returns>
	bool Open();

	/// <summary>
	/// �Z�������̏�ԂɕύX����
	/// None -> Flag -> Question -> None�̏��ŕύX�����
	/// </summary>
	void ChangeNextState();

	/// <summary>
	/// �Z���̏ꏊ��ύX���܂�
	/// </summary>
	/// <param name="pos">�ړ���̏ꏊ</param>
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
	/// ���ɉ������F���擾����
	/// </summary>
	/// <returns>�����mine�̐��ɉ������F��Ԃ�</returns>
	Color count_color() const;
		
};

