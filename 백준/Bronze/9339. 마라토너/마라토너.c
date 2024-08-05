#include <stdio.h>

int main() {
	int test_case, hour, min;
	int high_score, score;
	int pass_cnt, special = -1;
	int student_cnt;
	int participant_cnt;
	int student[100];
	int participant;

	scanf("%d", &test_case);

	for (int i = 0; i < test_case; ++i) {
		pass_cnt = 0;
		high_score = 361;
		scanf("%d", &student_cnt);
		for (int j = 0; j < student_cnt; ++j) 
			scanf("%d ", &student[j]);
		
		scanf("%d", &participant_cnt);
		for (int j = 0; j < participant_cnt; ++j) {
			scanf("%d %d %d", &participant, &hour, &min);

			if (hour == -1 && min == -1)
				continue;

			score = hour * 60 + min;
			if (score <= 360) {
				for (int idx = 0; idx < student_cnt; ++idx) {
					if (participant == student[idx]) {
						pass_cnt += 1;
						if (score < high_score) {
							high_score = score;
							special = participant;
						}
						break;
					}
				}
			}
		}
		printf("%d %d\n", special, pass_cnt);
	}

	return 0;
}