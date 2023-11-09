#include <iostream>
using namespace std;

struct Stack {
    int num[10], top;
};

Stack s;
int mark[16][31], e_close[16][31], n, st = 0;
char data[15][15];

void push(int a) {
    s.num[s.top] = a;
    s.top = s.top + 1;
}

int pop() {
    int a;
    if (s.top == 0)
        return (-1);
    s.top = s.top - 1;
    a = s.num[s.top];
    return (a);
}

void epi_close(int s1, int s2, int c) {
    int i, j, f;
    for (i = 1; i <= n; i++) {
        if (data[s2][i] == 'e') {
            f = 0;
            for (j = 1; j<=c; j++) {
                if (e_close[s1][j] == i)
                    f = 1;
                if(f==0){
                    c++;
                    e_close[s1][c] = i;
                    push(i);
                }
            }
        }
    }
    while (s.top != 0) {
        epi_close(s1, pop(), c);
    }
}

int move(int sta, char c) {
    int i;
    for (i = 1; i <= n; i++) {
        if (data[sta][i] == c)
            return (i);
    }
    return (0);
}

void e_union(int m, int n) {
    int i = 0, j, k;
    for(j = 1;mark[m][i]!=-1;j++){
        while((mark[m][i]!=e_close[n][j])&&(mark[m][i]!=-1))
            i++;
        if(mark[m][i]==-1){
            mark[m][i]=e_close[n][j];
        }

    }
//    for (i = 1; e_close[n][i] != -1; i++) {
//        for (j = 1; e_close[m][j] != -1; j++) {
//            if (e_close[m][j] == e_close[n][i])
//                break;
//        }
//        if (e_close[m][j] == -1) {
//            e_close[m][j] = e_close[n][i];
//            push(e_close[n][i]);
//        }
//    }
//    k = pop();
//    if (k != -1)
//        e_union(m, k);
}

int main() {
    int i, j, k, Lo, m, p, q, t, f;

    cout << "\n enter the NFA state table entries:";
    cin >> n;
    cout << "\n";

    for (i = 0; i <= n; i++)
        cout << i;
    cout << "\n";

    for (i = 0; i <= n; i++)
        cout << "------";
    cout << "\n";

    for (i = 1; i <= n; i++) {
        cout << i << "|";
        for (j = 1; j <= n; j++)
            cin >> data[i][j];
    }

    for (i = 1; i <= 15; i++)
        for (j = 1; j <= 30; j++) {
            e_close[i][j] = -1;
            mark[i][j] = -1;
        }

    for (i = 1; i <= n; i++) {
        e_close[i][1] = i;
        s.top = 0;
        epi_close(i, i, 1);
    }

    // 冒泡排序
    for (i = 1; i <= n; i++) {
        for (j = 1; e_close[i][j] != -1; j++)
            for (k = 2; e_close[i][k] != -1; k++)
                if (e_close[i][k - 1] > e_close[i][k]) {
                    t = e_close[i][k - 1];
                    e_close[i][k - 1] = e_close[i][k];
                    e_close[i][k] = t;
                }
    }

    cout << "\n the epsilon closures are:";
    for (i = 1; i <= n; i++) {
        cout << "\n E(" << i << ")={";
        for (j = 1; e_close[i][j] != -1; j++)
            cout << e_close[i][j];
        cout << "}";
    }

    j = 1;
    while (e_close[1][j] != -1) {
        mark[1][j] = e_close[1][j];
        j++;
    }
    st = 1;

    cout << "\n DFA Table is:";
    cout << "\n a b ";
    cout << "\n--------------------------------------";

    for (i = 1; i <= st; i++) {
        cout << "\n{";
        for (j = 1; mark[i][j] != -1; j++)
            cout << mark[i][j];
        cout << "}";
        while (j < 7) {
            cout << " ";
            j++;
        }

        for (Lo = 1; Lo <= 2; Lo++) {
            for (j = 1; mark[i][j] != -1; j++) {
                if (Lo == 1)
                    t = move(mark[i][j], 'a');
                if (Lo == 2)
                    t = move(mark[i][j], 'b');
                if (t != 0)
                    e_union(st + 1, t);
            }

            for (p = 1; mark[st + 1][p] != -1; p++)
                for (q = 2; mark[st + 1][q] != -1; q++) {
                    if (mark[st + 1][q - 1] > mark[st + 1][q]) {
                        t = mark[st + 1][q];
                        mark[st + 1][q] = mark[st + 1][q - 1];
                        mark[st + 1][q - 1] = t;
                    }
                }

            f = 1;
            for (p = 1; p <= st; p++) {
                j = 1;
                while ((mark[st + 1][j] == mark[p][j]) && (mark[st + 1][j] != -1))
                    j++;
                if (mark[st + 1][j] == -1 && mark[p][j] == -1)
                    f = 0;
            }
            if (mark[st + 1][1] == -1)
                f = 0;

            cout << "\t{";
            for (j = 1; mark[st + 1][j] != -1; j++)
                cout << mark[st + 1][j];
            cout << "}\t";

            if (Lo == 1)
                cout << " ";

            if (f == 1) {
                st++;
//                for (j = 1; mark[st][j] != -1; j++) {
//                    mark[st + 1][j] = mark[st][j];
//                }
//                f = 1; // 在每次增加新状态时设置f为1
            }

            if (f == 0) {
                for (p = 1; p <= 30; p++)
                    mark[st + 1][p] = -1;
            }

        }
    }
    system("PAUSE");

    return 0;
}
