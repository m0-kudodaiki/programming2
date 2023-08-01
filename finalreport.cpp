#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <numeric>
#include <fstream>

using namespace std;
using namespace std::chrono;

int x;
int y;
int A;
int grade;
int z;
int z1;
int s1;
int s2;
int decide;

double Time;

string inName;

vector<int> level;

//�Ǝ��̃N���X:�v���C���[�̃f�[�^(���O�A�擾��)���Ǘ�����N���X
//�v���C���[�̃N���X�̒�`
class Player {
	public:
	string name;
	int grade;
	void setName(string newName); 
	void setGrade(int newGrade); 
	void show();
};


//�v���C���[�N���X�̃����o�֐��̒�`
void Player::setName(string newName) {
	name = newName;
}
void Player::setGrade(int newGrade) {
	grade = newGrade;
}
void Player::show() {
	cout << "���O�F" << name << "\t�擾���F" << grade << endl;
}


//�Ǝ��̊֐�����1:�ݒ肵����Փx�ɉ����������Z�𐶐�����֐�
void LEVEL() {
	random_device engine;
	uniform_int_distribution<unsigned> dist1(1, s1);
	uniform_int_distribution<unsigned> dist2(1, s2);
	 x = dist1(engine);
     y = dist2(engine);

	string strx = to_string(x);
	string stry = to_string(y);
	cout << " " << strx << " + " << stry << " \n";
	cout << "��������͂��Ă�������\n";
}


//�Ǝ��̊֐�����2:�������ƃ^�C���ɉ����Ď擾���𔻒肷��֐�
void Result() {
	cout << "�^�C����[s]�P�ʂœ��͂��Ă�������(��:10.016)\n" << endl;
	cin >> Time;
	if (85 <= z1-Time && z1-Time <= 100) {
		grade = 1;
		printf("\x1b[31m");
		cout << "����:" << to_string(grade) << " ��\n" << endl;
		cout << "���߂łƂ�!�@����ŌN�������Z�}�X�^�[��!\n" << endl;
	}

	if (65 <= z1-Time && z1-Time <= 85) {
		grade = 2;
		printf("\x1b[34m");
		cout << "����:" << to_string(grade) << " ��\n" << endl;
		cout << "���ƈ��!�@1���߂����Ċ撣��!\n" << endl;
	}

	if (45 <= z1-Time && z1-Time <= 65) {
		grade = 3;
		printf("\x1b[35m");
		cout << "����:" << to_string(grade) << " ��\n" << endl;
		cout << "���̒��q!�@����ɍ��݂�ڎw����!\n" << endl;
	}

	if (25 <= z1-Time && z1-Time <= 45) {
		grade = 4;
		printf("\x1b[43m");
		cout << "����:" << to_string(grade) << " ��\n" << endl;
		cout << "�������炳��Ɋ撣�낤!\n" << endl;
	}

	if (z1-Time <= 25) {
		grade = 5;
		printf("\x1b[42m");
		cout << "����:" << to_string(grade) << " ��\n" << endl;
		cout << "�܂��͂�������!\n" << endl;
	}
}

template <typename T>
int total(T first, T last) {
	int sum = 0;
	for (T p = first; p != last; ++p) sum += *p;
	return sum;
}



int main() {
	int select;
	cout << "---------------------------------------------------------------------\n";
	cout << "--�g���[�j���O���[�h�́u1�v�L�[���A���胂�[�h�́u2�v�L�[�������Ă�!--\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "<�g���[�j���O���[�h>\n��Փx�Əo�萔��I��ő����Z�g���[�j���O���ł��܂��B\n���茋�ʂ͕\������܂���B\n";
	cout << "�@\n";
	cout << "<���胂�[�h>\n10�⑫���Z���o�肵�A�������ƃ^�C�������Ƃɋ��𔻒肵�܂��B\n�o��͈͂�1����100�̎��R�����m�̑����Z�ł��B\n�ڎw�������Z�}�X�^�[!\n";
	cout << "�@\n";
	cin >> select;

	if (select == 1) {
		std::system("cls");
		int number;
		do {
			std::system("cls");
			cout << "--�g���[�j���O���[�h�ւ悤����!--\n";
			cout << "�o�萔��4�`20�̒�����I��ł�!\n";
			cin >> number;
		} while (number < 4 || 21 < number);
		A = number;
		cout << "��Փx��1�`100�̒�����2����͂��Ă�!(���͂��������܂ł͈̔͂����肪�쐬����܂�)\n";
		cin >> s1;
		cin >> s2;

		std::system("cls");

		vector <int> Score;
		auto t0 = high_resolution_clock::now();
		for (int i = 0; i < A; ++i) {

			LEVEL();

			int answer;
			cin >> answer;

			if (answer == x + y) {
				cout << "����!\n";
				cout << "1P GET\n";
				cout << " \n";
				Score.push_back(1);
			}
			else {
				cout << "�s����...\n";
				cout << " \n";
				Score.push_back(0);
			}
		}
		auto t1 = high_resolution_clock::now();

		//�C�e���[�^��p���ăx�N�^�[�v�f�̘a�����߂�B
		z = total(Score.begin(), Score.end());
		string strz = to_string(z);

		z1 = (100 * z / A);
		string strz1 = to_string(z1);

		std::system("cls");

		cout << "--���є��\--\n" << endl;
		cout << duration_cast<milliseconds>(t1 - t0).count() / 1000. << " s.\n";
		cout << "���v�@" << strz << " P �l��!\n" << endl;
		cout << "�������@" << strz1 << " %\n" << endl;
		cout << "Thank you for playing!\n" << endl;
	}

	if (select == 2) {
		do {
			std::system("cls");
			cout << "--���胂�[�h�ւ悤����!--\n";
			cout << "--�V�ԑO�ɖ��O��2���ȏ�̃��[�}���������œ��͂��Ă�!--\n";
			cin >> inName;

			A = 10;
			s1 = 100;
			s2 = 100;

			std::system("cls");
			vector <int> Score;
			auto t0 = high_resolution_clock::now();
			for (int i = 0; i < A; ++i) {

				LEVEL();

				int answer;
				cin >> answer;

				if (answer == x + y) {
					cout << "����!\n";
					cout << "1P GET\n";
					cout << " \n";
					Score.push_back(1);
				}
				else {
					cout << "�s����...\n";
					cout << " \n";
					Score.push_back(0);
				}
			}
			auto t1 = high_resolution_clock::now();

			z = total(Score.begin(), Score.end());
			string strz = to_string(z);

			z1 = (100 * total(Score.begin(), Score.end()) / A);
			string strz1 = to_string(z1);

			int one;

			do {
				std::system("cls");

				cout << "--���є��\--\n" << endl;
				cout << duration_cast<milliseconds>(t1 - t0).count() / 1000. << " s.\n";
				cout << "���v�@" << strz << " P �l��!\n" << endl;
				cout << "�������@" << strz1 << " %\n" << endl;

				Result();

				printf("\x1b[0m");
				cout << "�u1�v�L�[���ǂ���\n" << endl;
				cin >> one;
			} while (one != 1);


			ofstream outfile("Result.txt", ios_base::app);
			outfile << inName << " " << grade << endl;

			cout << "�I�����ė��v���C���[�\��\������ɂ́u1�v�A\n����1�x�`�������W����ɂ͂��̑��̐����L�[�������Ă�\n" << endl;
			cin >> decide;

		} while (decide != 1);

		std::system("cls");
		cout << "--Thank you for playing!--\n" << endl;
		cout << "���v���C���[����\n" << endl;

		vector<Player> seisekihyou;
		string name;

		ifstream infile("Result.txt");
		while (infile >> name >> grade) {
			seisekihyou.emplace_back();
			seisekihyou[seisekihyou.size() - 1].setName(name);
			seisekihyou[seisekihyou.size() - 1].setGrade(grade);
		}

		infile.close();

		for (int i = 0;i < seisekihyou.size(); i++) seisekihyou[i].show();
	}

	if (select != 1 && select != 2) {
		std::system("cls");
		cout << "--�����Ȑ��������͂���܂����B�ŏ������蒼���Ă�������--\n";
	}
}