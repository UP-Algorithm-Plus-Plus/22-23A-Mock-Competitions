/*
*OnlineJudge
*489 - Hangman Judge
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n;
	string str;

	cin >> n;
	while (n != -1) {
		printf("Round %i\n", n);

		int correct = 0;
		int wrong = 0;
		int letters = 0;

		int alphabet[26] = {0};
		int guessed[26] = {0};

		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if(alphabet[str[i] - 'a'] != 1) {
				alphabet[str[i] - 'a'] = 1;
				letters++;
			}
		}

		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (guessed[str[i] - 'a'] != 1) { // assume not counted as wrong guess ung repeat letters or walang repeat
				guessed[str[i] - 'a'] = 1;
				if (alphabet[str[i] - 'a'] != 1)
					wrong++;
				else
					correct++;
			}

			if (correct == letters)
				break;
		}
		
		if ((wrong < 7) && (correct == letters))
			printf("You win.\n");
		else if (wrong < 7)
			printf("You chickened out.\n");
		else
			printf("You lose.\n");

		cin >> n;
	}
	return 0;
}
