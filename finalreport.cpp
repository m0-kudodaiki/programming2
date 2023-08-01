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

//独自のクラス:プレイヤーのデータ(名前、取得級)を管理するクラス
//プレイヤーのクラスの定義
class Player {
	public:
	string name;
	int grade;
	void setName(string newName); 
	void setGrade(int newGrade); 
	void show();
};


//プレイヤークラスのメンバ関数の定義
void Player::setName(string newName) {
	name = newName;
}
void Player::setGrade(int newGrade) {
	grade = newGrade;
}
void Player::show() {
	cout << "名前：" << name << "\t取得級：" << grade << endl;
}


//独自の関数その1:設定した難易度に応じた足し算を生成する関数
void LEVEL() {
	random_device engine;
	uniform_int_distribution<unsigned> dist1(1, s1);
	uniform_int_distribution<unsigned> dist2(1, s2);
	 x = dist1(engine);
     y = dist2(engine);

	string strx = to_string(x);
	string stry = to_string(y);
	cout << " " << strx << " + " << stry << " \n";
	cout << "答えを入力してください\n";
}


//独自の関数その2:正答率とタイムに応じて取得級を判定する関数
void Result() {
	cout << "タイムを[s]単位で入力してください(例:10.016)\n" << endl;
	cin >> Time;
	if (85 <= z1-Time && z1-Time <= 100) {
		grade = 1;
		printf("\x1b[31m");
		cout << "結果:" << to_string(grade) << " 級\n" << endl;
		cout << "おめでとう!　これで君も足し算マスターだ!\n" << endl;
	}

	if (65 <= z1-Time && z1-Time <= 85) {
		grade = 2;
		printf("\x1b[34m");
		cout << "結果:" << to_string(grade) << " 級\n" << endl;
		cout << "あと一歩!　1級めざして頑張れ!\n" << endl;
	}

	if (45 <= z1-Time && z1-Time <= 65) {
		grade = 3;
		printf("\x1b[35m");
		cout << "結果:" << to_string(grade) << " 級\n" << endl;
		cout << "その調子!　さらに高みを目指そう!\n" << endl;
	}

	if (25 <= z1-Time && z1-Time <= 45) {
		grade = 4;
		printf("\x1b[43m");
		cout << "結果:" << to_string(grade) << " 級\n" << endl;
		cout << "ここからさらに頑張ろう!\n" << endl;
	}

	if (z1-Time <= 25) {
		grade = 5;
		printf("\x1b[42m");
		cout << "結果:" << to_string(grade) << " 級\n" << endl;
		cout << "まずはここから!\n" << endl;
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
	cout << "--トレーニングモードは「1」キーを、検定モードは「2」キーを押してね!--\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "<トレーニングモード>\n難易度と出題数を選んで足し算トレーニングができます。\n検定結果は表示されません。\n";
	cout << "　\n";
	cout << "<検定モード>\n10問足し算を出題し、正答率とタイムをもとに級を判定します。\n出題範囲は1から100の自然数同士の足し算です。\n目指せ足し算マスター!\n";
	cout << "　\n";
	cin >> select;

	if (select == 1) {
		std::system("cls");
		int number;
		do {
			std::system("cls");
			cout << "--トレーニングモードへようこそ!--\n";
			cout << "出題数を4～20の中から選んでね!\n";
			cin >> number;
		} while (number < 4 || 21 < number);
		A = number;
		cout << "難易度を1～100の中から2回入力してね!(入力した数字までの範囲から問題が作成されます)\n";
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
				cout << "正解!\n";
				cout << "1P GET\n";
				cout << " \n";
				Score.push_back(1);
			}
			else {
				cout << "不正解...\n";
				cout << " \n";
				Score.push_back(0);
			}
		}
		auto t1 = high_resolution_clock::now();

		//イテレータを用いてベクター要素の和を求める。
		z = total(Score.begin(), Score.end());
		string strz = to_string(z);

		z1 = (100 * z / A);
		string strz1 = to_string(z1);

		std::system("cls");

		cout << "--成績発表--\n" << endl;
		cout << duration_cast<milliseconds>(t1 - t0).count() / 1000. << " s.\n";
		cout << "合計　" << strz << " P 獲得!\n" << endl;
		cout << "正答率　" << strz1 << " %\n" << endl;
		cout << "Thank you for playing!\n" << endl;
	}

	if (select == 2) {
		do {
			std::system("cls");
			cout << "--検定モードへようこそ!--\n";
			cout << "--遊ぶ前に名前を2字以上のローマ字か数字で入力してね!--\n";
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
					cout << "正解!\n";
					cout << "1P GET\n";
					cout << " \n";
					Score.push_back(1);
				}
				else {
					cout << "不正解...\n";
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

				cout << "--成績発表--\n" << endl;
				cout << duration_cast<milliseconds>(t1 - t0).count() / 1000. << " s.\n";
				cout << "合計　" << strz << " P 獲得!\n" << endl;
				cout << "正答率　" << strz1 << " %\n" << endl;

				Result();

				printf("\x1b[0m");
				cout << "「1」キーをどうぞ\n" << endl;
				cin >> one;
			} while (one != 1);


			ofstream outfile("Result.txt", ios_base::app);
			outfile << inName << " " << grade << endl;

			cout << "終了して歴代プレイヤー表を表示するには「1」、\nもう1度チャレンジするにはその他の数字キーを押してね\n" << endl;
			cin >> decide;

		} while (decide != 1);

		std::system("cls");
		cout << "--Thank you for playing!--\n" << endl;
		cout << "歴代プレイヤーたち\n" << endl;

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
		cout << "--無効な数字が入力されました。最初からやり直してください--\n";
	}
}