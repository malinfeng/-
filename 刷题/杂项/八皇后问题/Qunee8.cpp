
#include "Qunee8.h"
#include <iostream>

Qunee8::Qunee8()
{
	_qcount = 0;
	Initchree();
}

Qunee8::~Qunee8()
{
}

void Qunee8::EinghtQunee(int row)
{
	if (row == Qneue_Num)//���һ�У���ӡ
	{
		_qcount++;
		Qprint();
		for (int i = 0; i <= Qneue_Num-1; ++i)
		{
			Cherr[Qneue_Num-1][i] = 0;//���һ������
		}
	}
	else
	{
		for (int line = 0; line <= Qneue_Num-1; ++line)
		{
			if (bool a = safe(row, line))
			{
				for (int i = 0 ; i <= Qneue_Num - 1; ++i)//����ȫ������
				{
					Cherr[row][i] = 0;
				}
				Cherr[row][line] = 1;
				EinghtQunee(row + 1);

			}
		}
		--row;//�����꣬���ָ���û�а�ȫλ��

		if (row >= 0)
		{
			for (int i = 0; i <= Qneue_Num - 1; ++i)
			{
				Cherr[row][i] = 0;
			}
		}
		return;
	}

}

void Qunee8::Qprint()
{
	std::cout << "��" << _qcount << "�ֽ�����£�" << std::endl;
	for (int i = 0; i <= Qneue_Num - 1; ++i)
	{
		for (int j = 0; j <= Qneue_Num - 1; ++j)
		{
			std::cout << Cherr[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool Qunee8::safe(int row, int line)
{
	bool flag_row = true, flag_line = true, flag1 = true, flag2 = true, flag3 = true, flag4 = true;

	for (int i = 0 ; i <= Qneue_Num - 1; ++i)//�а�ȫ
	{
		if (Cherr[row][i] == 1)
		{
			flag_row = false;
		}
	}

	for (int i = 0; i <= Qneue_Num - 1; ++i)//�а�ȫ
	{
		if (Cherr[i][line] == 1)
		{
			flag_line = false;
		}
	}

	for (int i = row , j = line ; i <= Qneue_Num - 1 && j <= Qneue_Num - 1 ; ++i , ++j)
	{
		if (Cherr[i][j] == 1)
		{
			flag1 = false;
		}
	}

	for (int i = row, j = line; i <= Qneue_Num - 1 && j >= 0; ++i, --j)
	{
		if (Cherr[i][j] == 1)
		{
			flag2 = false;
		}
	}

	for (int i = row, j = line; i >= 0 && j <= Qneue_Num - 1; --i, ++j)
	{
		if (Cherr[i][j] == 1)
		{
			flag3 = false;
		}
	}

	for (int i = row, j = line; i >= 0 && j >= 0; --i, --j)
	{
		if (Cherr[i][j] == 1)
		{
			flag4 = false;
		}
	}

	if (flag1 && flag2 && flag3 && flag4 && flag_line && flag_row)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Qunee8::Initchree()
{
	for (int i = 0 ; i <= Qneue_Num - 1;++i)
	{
		for (int j = 0 ; j <= Qneue_Num - 1;++j)
		{
			Cherr[i][j] = 0;
		}
	}
}
