/*
 * @author - Hemant Sherawat (hzs0084)
 * @version - 05/11/2020
 * 
 * project4_hzs0084.cpp
 *
 * Consulted project document, handout, class videos and piazza.
 */
 
 #include <iostream>
 using namespace std;
 
struct trivia_node {
	string question;
	string answer;
	int point;
	trivia_node *next;
};

//creates a pointer to trivia_node.
typedef trivia_node* ptr_node;

ptr_node last_node;
int totalPoints;
int num_of_questions;

//#define UNIT_TESTING 
#define trivia_quiz

//initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node& q_list) {

	num_of_questions = 3;
	q_list = new trivia_node;
	q_list->question = "How long was the shortest war on record?";
	q_list->answer = "38";
	q_list->point = 100;
		
	ptr_node q2 = new trivia_node;
	q2->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	q2->answer = "Bank of Italy";
	q2->point = 50;
	q_list->next = q2;
		
	ptr_node q3 = new trivia_node;
	q3->question = "What is the best-selling vide ogame of all time? (Hint: Call of Duty or Wii Sports)";
	q3->answer = "Wii Sports";
	q3->point = 20;
	q2->next = q3;
	last_node = q3;

}
	
//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
		
	ptr_node new_ptr = new trivia_node;
	string answer;
	string question;
	int points;
		
	cout << "Enter a new question: ";
	getline(cin, new_ptr->question);
		
	cout << "Enter an answer: ";
	getline(cin, new_ptr->answer);
		
	cout << "Enter award points: ";
	cin >> new_ptr->point;
	cin.ignore();
		
	last_node->next = new_ptr;
	last_node = new_ptr;
}
	
//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {
	totalPoints = 0;
	ptr_node cur_ptr = q_list;
		
	if (q_list == NULL)
		return 0;
		
	if (num_ask < 1) {
		cout << "Warning - the number of triviai to be asked must equal to or be larger than 1.";
	}
	else if (num_of_questions < num_ask) {
		cout << "Warning - There is only " << num_of_questions << " trivia in the list.";
	}
	else {
		for (int x = 0; x < num_ask; x++) {
			cout << "\nQuestion: " << cur_ptr->question << endl;
			cout << "Answer: ";
			string ans;
				
			getline(cin, ans);
				
			if (ans == cur_ptr->answer) {
				cout << "Your answer is correct! You receive " << cur_ptr->point << " points.\n";
				totalPoints += cur_ptr->point;
				cout << "Your total points: " << totalPoints << "\n";
			}
			else {
				cout << "Your answer is wrong. The correct answer is " << cur_ptr->answer << "\n";
				cout << "Your total points: " << totalPoints << "\n";
			}
			cur_ptr = cur_ptr->next;
		}
	}
	return 0;
}

//Test cases to check whether the methods work.
void Unit_Test() {
	ptr_node node_list = new trivia_node;
	
	init_question_list(node_list);
	cout <<"Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
	
	ask_question(node_list, 0);
	cout <<"\nCase 1 passed\n\n";
	
	ptr_node node_list2 = new trivia_node;
	init_question_list(node_list2);
	cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an\nincorrect answer." << endl;
	
	ask_question(node_list2, 1);
	cout << "\nCase 2.1 passed\n\n";
	
	ptr_node node_list3 = new trivia_node;
	init_question_list(node_list3);
	cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";

	ask_question(node_list3, 1);
	cout << "\nCase 2.2 passed\n\n";
	
	ptr_node node_list4 = new trivia_node;
	init_question_list(node_list4);
	cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list.";
	
	ask_question(node_list4, 3);
	cout << "\nCase 3 passed\n\n";
	
	ptr_node node_list5 = new trivia_node;
	init_question_list(node_list5);
	cout <<"Unit Test Case 4: Ask 5 questions in the linked list.";
	
	ask_question(node_list5, 5);
	cout << "\nCase 4 passed\n\n";
	cout << "*** End of the Debugging Version ***\n";
}

int main() {

	//For debugging only
	#ifdef UNIT_TESTING
		Unit_Test();
		return 0;
	}
	#endif
	
	//For production version
	#ifdef trivia_quiz
	ptr_node node_list = new trivia_node;
	//Creates a new trivia game /
	//Sets up three original questions/
	//Sets up loop for user to input his or her own questions.
	//Quiz questions are stored in liked list.

	init_question_list(node_list);
		
	cout << "*** Welcome to Hemant's trivia quiz game ***\n";
	totalPoints = 0;
		
	string cont = "Yes";
		
	do {
		add_question(node_list);
		num_of_questions++;
		cout << "Continue? (Yes/No): ";
		cin >> cont;
		cin.ignore();
	} while (cont == "Yes");
		
	ask_question(node_list, num_of_questions);
	cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
	return 0;
	
	
}
#endif


	
