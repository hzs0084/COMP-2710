/*
 * @author -Hemant Sherawat (hzs0084)
 * @version - 09/17/2020
 *
 * project2_hzs0084.cpp
 *
 * Consulted project document and handout for generating random values and test methods.
 */
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<ctime>
using namespace std;

const int TOTAL_RUNS = 10000;
const int aaronsChances = 33;
const int bobsChances = 50;

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	if (A_alive && B_alive && C_alive) {
		return true;
	}
	else if (B_alive && C_alive) {
		return true;
	}
	else if (A_alive && C_alive) {
		return true;
	}
	else if (A_alive && B_alive){
		return true;
	}
	else {
		return false;
	}
}

//Testing previous function
bool test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";
	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed ...\n";
	cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";
	cout << "\tCase 8: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";
}

void Aaron_shoots1(bool& B_alive, bool& C_alive) {
	int shoot_target_result = rand() % 100;

	/*int random_shot = rand() % 1;

	if (B_alive && C_alive) {
		if (shoot_target_result <= 33) {
			if (random_shot == 0)
				B_alive = false;
			else
				C_alive = false;
		}
		else {
			B_alive = true;
			C_alive = true;
		}
	}*/
	assert(B_alive || C_alive);
	if (C_alive) {
		if (shoot_target_result <= aaronsChances) {
			C_alive = false;
		}
		//else {
		//	C_alive = true;
		//}
	}
	else if (B_alive) {
		if (shoot_target_result <= aaronsChances) {
			B_alive = false;
		}
		//else {
		//	B_alive = true;
		//}
	}
}

//Testing previous function
void test_Aaron_shoots1(void) {
	cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

	bool bob_a = true;
	bool charlie_a = true;
	cout << "\tCase 1: Bob alive, Charlie alive\n"
		 << "\t\tAaron is shooting at Charlie\n";
	Aaron_shoots1(bob_a, charlie_a);

	bob_a = false;
	charlie_a = true;
	cout << "\tCase 2: Bob dead, Charlie alive\n"
		 << "\t\tAaron is shooting at Charlie\n";
	Aaron_shoots1(bob_a, charlie_a);

	bob_a = true;
	charlie_a = false;
	cout << "\tCase 3: Bob alive, Charlie dead\n"
		 << "\t\tAaron is shooting at Charlie\n";
	Aaron_shoots1(bob_a, charlie_a);
}


void Bob_shoots(bool& A_alive, bool& C_alive) {
	int shoot_target_result = rand() % 100;

	assert(A_alive || C_alive);
	if (C_alive) {
		if (shoot_target_result <= bobsChances)	{
			C_alive = false;
		}
		//else {
		//	C_alive = true;
		//}
	}
	else if (A_alive) {
		if (shoot_target_result <= bobsChances) {
			A_alive = false;
		}
		//else {
		//	A_alive = true;
		//}
	}
}

//Testing previous function
void test_Bob_shoots(void) {
	cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

	bool aaron_a = true;
	bool charlie_a = true;
	cout << "\tCase 1: Aaron alive, Charlie alive\n"
		 << "\t\tBob is shooting at Charlie\n";
	Bob_shoots(aaron_a, charlie_a);

	aaron_a = false;
	charlie_a = true;
	cout << "\tCase 2: Aaron dead, Charlie alive\n"
		 << "\t\tBob is shooting at Charlie\n";
	Bob_shoots(aaron_a, charlie_a);

	aaron_a = true;
	charlie_a = false;
	cout << "\tCase 3: Aaron alive, Charlie dead\n"
		 << "\t\tBob is shooting at Aaron\n";
	Bob_shoots(aaron_a, charlie_a);
}

void Charlie_shoots(bool& A_alive, bool& B_alive) {
	assert(A_alive || B_alive);
	if (B_alive) {
		B_alive = false;
	}
	else if (A_alive) {
		A_alive = false;
	}
}

//Testing previous function
void test_Charlie_shoots(void) {
	cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

	bool aaron_a = true;
	bool bob_a = true;
	cout << "\tCase 1: Aaron alive, Bob alive\n"
		 << "\t\tCharlie is shooting at Bob\n";
	Charlie_shoots(aaron_a, bob_a);

	aaron_a = false;
	bob_a = true;
	cout << "\tCase 2: Aaron dead, Bob alive\n"
		 << "\t\tCharlie is shooting at Bob\n";
	Charlie_shoots(aaron_a, bob_a);

	aaron_a = true;
	bob_a = false;
	cout << "\tCase 3: Aaron alive, Charlie dead\n"
		 << "\t\tCharlie is shooting at Aaron\n";
	Charlie_shoots(aaron_a, bob_a);
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) {
	int shoot_target_result = rand() % 100;

	assert(B_alive || C_alive);
	if (B_alive && C_alive) {
			B_alive = true;
			C_alive = true;
	}
	else if (C_alive) {
		if (shoot_target_result <= aaronsChances) {
			C_alive = false;
		}
		//else {
		//	C_alive = true;
		//}
	}
	else if (B_alive) {
		if (shoot_target_result <= aaronsChances) {
			B_alive = false;
		}
		//else {
		//	B_alive = true;
		//}
	}
}

//Testing previous function
void test_Aaron_shoots2(void) {
	cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

	bool bob_a = true;
	bool charlie_a = true;
	cout << "\tCase 1: Bob alive, Charlie alive\n"
		 << "\t\tAaron intentionally misses his first shot\n"
		 << "\t\tBoth Bob and Charlie are alive.\n";
	Aaron_shoots2(bob_a, charlie_a);

	bob_a = false;
	charlie_a = true;
	cout << "\tCase 2: Bob dead, Charlie alive\n"
		 << "\t\tAaron is shooting at Charlie\n";
	Aaron_shoots2(bob_a, charlie_a);

	bob_a = true;
	charlie_a = false;
	cout << "\tCase 3: Bob alive, Charlie dead\n"
		 << "\t\tAaron is shooting at Bob\n";
	Aaron_shoots2(bob_a, charlie_a);
}


void Press_any_key(void) {
	cout << "Press Enter to continue...";
	cin.ignore().get();
}

int main() {
	bool aaronAlive;
	bool bobAlive;
	bool charlieAlive;
	int aaronWins1 = 0;
	int aaronWins2 = 0;
	int bobWins = 0;
	int charlieWins = 0;
	int i = 0;

	cout<<"*** Welcome to Shoot Club's Duel Simulator ***\n";
	srand(time(0));
	test_at_least_two_alive();
	Press_any_key();
	test_Aaron_shoots1();
	Press_any_key();
	test_Bob_shoots();
	Press_any_key();
	test_Charlie_shoots();
	Press_any_key();
	test_Aaron_shoots2();
	Press_any_key();

	cout << "Ready to test strategy 1 (run 10000 times):\n";
	Press_any_key();

	for (i = 0; i < TOTAL_RUNS; i++) {
		aaronAlive = true;
		bobAlive = true;
		charlieAlive = true;
		while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
			if (aaronAlive) {
				Aaron_shoots1(bobAlive, charlieAlive);
			}
			if (bobAlive) {
				Bob_shoots(aaronAlive, charlieAlive);
			}
			if (charlieAlive) {
				Charlie_shoots(aaronAlive, bobAlive);
			}
		}
		if (aaronAlive) {
			aaronWins1++;
		}
		if (bobAlive) {
			bobWins++;
		}
		if (charlieAlive) {
			charlieWins++;
		}
}

	cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) /
		TOTAL_RUNS * 100 << "%\n"
	     << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) /
		TOTAL_RUNS * 100 << "%\n"
	     << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) /
		TOTAL_RUNS * 100 << "%\n" << endl;
	cout << "Ready to test strategy 2 (run 10000 times):\n";
	Press_any_key();

	bobWins = 0;
	charlieWins = 0;

	for (i = 0; i < TOTAL_RUNS; i++) {
		aaronAlive = true;
		bobAlive = true;
		charlieAlive = true;
		while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
			if (aaronAlive) {
				Aaron_shoots2(bobAlive, charlieAlive);
			}
			if (bobAlive) {
				Bob_shoots(aaronAlive, charlieAlive);
			}
			if (charlieAlive) {
				Charlie_shoots(aaronAlive, bobAlive);
			}
		}
		if (aaronAlive) {
			aaronWins2++;
		}
		if (bobAlive) {
			bobWins++;
		}
		if (charlieAlive) {
			charlieWins++;
		}
	}

	cout << "Aaron win " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) /
		TOTAL_RUNS * 100 << "%\n"
	     << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) /
		TOTAL_RUNS * 100 << "%\n"
	     << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) /
		TOTAL_RUNS * 100 << "%\n" << endl;

	if (aaronWins1 > aaronWins2) {
		cout << "Strategy 1 is better than strategy 2.\n";
	}
	else {
		cout << "Strategy 2 is better than strategy 1.\n";
	}

	return 0;

}

