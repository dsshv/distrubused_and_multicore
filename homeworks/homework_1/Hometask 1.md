# Hometask 1

### Task 1

Source code located int `./homework_1/src/task_1_s.c`

Without using distributed programming:

| N | time |
| --- | --- |
| 1000 | 0.00142 |
| 10 000 | 0.10535 |
| 100 000 | 8.96315 |
| 200 000 | 36.10415 |

Source code located int `./homework_1/src/task_1_p.c`

Within using distributed programming:

| N | time |
| --- | --- |
| 1000 | 0.00039 |
| 10 000 | 0.03225 |
| 100 000 | 2.92907 |
| 200 000 | 11.53329 |

All compiled programs are located in the folder `./homework_1/dist/`

![Untitled](Hometask%201%20cd247afba84f4076bb827bdc879dfbd8/Untitled.png)

Efficiency is similar to Pi, but increases more sharply due to the large number of operations in this code.

### Task 2

Source code located int `./homework_1/src/task_2.c`

Apparently, the workers managed to recieve vector `A`, but my knowledge of C syntax is not enough to print it normally. In general, the structure of vectors in C is not very clear to me yet.

### Task 3

Source code located int `./homework_1/src/task_3.c`

| N | time (using 1 node) | time (using 6 nodes) |
| --- | --- | --- |
| 10 000 000 | 0.012152 | 0.002068 |
| 20 000 000 | 0.023866 | 0.005106 |
| 30 000 000 | 0.047743 | 0.008458 |
| 40 000 000 | 0.047838 | 0.008311 |
| 50 000 000 | 0.083811 | 0.014155 |
| 60 000 000 | 0.091511 | 0.012595 |
| 70 000 000 | 0.108721 | 0.021659 |
| 80 000 000 | 0.099390 | 0.023876 |
| 90 000 000 | 0.160390 | 0.024090 |
| 100 000 000 | 0.162759 | 0.031157 |

Efficiency graph:

![Untitled](Hometask%201%20cd247afba84f4076bb827bdc879dfbd8/Untitled%201.png)