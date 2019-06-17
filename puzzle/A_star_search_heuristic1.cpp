///;;;;;;;;;;;;;;;;;;:;;;A* Search example with 8-puzzle:::::::::::::::::::::
///::::::::::::::::::::::The heuristic is based on Number of Misplaced Tiles::::::::::::
#include<bits/stdc++.h>
#define MX 5
#define mp make_pair
#define matrix pair<int, pair<int, pair<int, pair<int, pair<int, pair<int, pair<int, pair<int, int> > > > > > > >
#define fmatrix pair<int, pair<int, pair<int, pair<int, pair<int, pair<int, pair<int, pair<int, pair<int, pair<int, int> > > > > > > > > >
using namespace std;
matrix base_con;
int goal[MX][MX];
set<fmatrix> to_be_exp;
map<matrix, bool> alreadly_exp;
map<matrix, matrix> path;

void print_state(int state[][MX])
{
    printf("\n");
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
            printf("%d ", state[i][j]);
        printf("\n");
    }
}

int cnt_mismatch(int cur_state[][MX])
{
    int cnt=0;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            if(cur_state[i][j]==0)
              continue;
            if(cur_state[i][j]!=goal[i][j])
                cnt++;
        }
    }
    return cnt;
}

void get_matrix(int state[][MX])
{
    set<fmatrix> ::iterator it;
    it=to_be_exp.begin();
    fmatrix pii = *it;
    state[1][1]=pii.second.second.first;
    state[1][2]=pii.second.second.second.first;
    state[1][3]=pii.second.second.second.second.first;
    state[2][1]=pii.second.second.second.second.second.first;
    state[2][2]=pii.second.second.second.second.second.second.first;
    state[2][3]=pii.second.second.second.second.second.second.second.first;
    state[3][1]=pii.second.second.second.second.second.second.second.second.first;
    state[3][2]=pii.second.second.second.second.second.second.second.second.second.first;
    state[3][3]=pii.second.second.second.second.second.second.second.second.second.second;
}

int get_cur_gn()
{
    set<fmatrix> ::iterator it;
    it=to_be_exp.begin();
    fmatrix pii = *it;
    return pii.second.first;
}


void insert_to_be_exp(int fn, int gn, int state[][MX])
{
    to_be_exp.insert(mp(fn, mp(gn, mp(state[1][1], mp(state[1][2], mp(state[1][3], mp(state[2][1], mp(state[2][2], mp(state[2][3], mp(state[3][1], mp(state[3][2], state[3][3])))))))))));
}

void delete_from_to_be_exp()
{
    set<fmatrix> ::iterator it;
    it=to_be_exp.begin();
    to_be_exp.erase(it);
}

bool check_alreadly(int state[][MX])
{
    matrix temp = mp(state[1][1], mp(state[1][2], mp(state[1][3], mp(state[2][1], mp(state[2][2], mp(state[2][3], mp(state[3][1], mp(state[3][2], state[3][3]))))))));
    return alreadly_exp[temp];
}

void add_to_alreadly_exp(int state[][MX])
{
    matrix temp = mp(state[1][1], mp(state[1][2], mp(state[1][3], mp(state[2][1], mp(state[2][2], mp(state[2][3], mp(state[3][1], mp(state[3][2], state[3][3]))))))));
    alreadly_exp[temp]=true;
}

void set_path(int from[][MX], int to[][MX])
{
    matrix fr = mp(from[1][1], mp(from[1][2], mp(from[1][3], mp(from[2][1], mp(from[2][2], mp(from[2][3], mp(from[3][1], mp(from[3][2], from[3][3]))))))));
    matrix tto = mp(to[1][1], mp(to[1][2], mp(to[1][3], mp(to[2][1], mp(to[2][2], mp(to[2][3], mp(to[3][1], mp(to[3][2], to[3][3]))))))));
    path[tto]=fr;
}


void solve(int initial[][MX])
{

    int h=cnt_mismatch(initial), explored=0;
    insert_to_be_exp(h,0,initial);

    while(true)
    {
        int gn=get_cur_gn()+1;
        int cur_state[MX][MX], come_from[MX][MX];
        get_matrix(come_from);
        get_matrix(cur_state);
        if(cnt_mismatch(cur_state)==0)
        {
            cout << "Moves Required: " << get_cur_gn() << endl;
            cout << "Nodes Explored: " << explored << endl;
            break;
        }
        explored++;
        add_to_alreadly_exp(cur_state);
        delete_from_to_be_exp();

        //finding the position of zero
        int a, b, i, j;
        for(int p=1; p<=3; p++)
        {
            for(int q=1; q<=3; q++)
            {
                if(cur_state[p][q]==0)
                {
                    i=p;
                    j=q;
                    break;
                }
            }
        }

        //exploring the node
        //up
        a=i-1, b=j;
        if(a>=1 && a<=3 && b>=1 && b<=3)
        {
            swap(cur_state[a][b], cur_state[i][j]);
            if(check_alreadly(cur_state)==false)
            {
                int hn=cnt_mismatch(cur_state);
                insert_to_be_exp(hn+gn, gn, cur_state);
                set_path(come_from, cur_state);
            }
            swap(cur_state[a][b], cur_state[i][j]);
        }
        //down
        a=i+1, b=j;
        if(a>=1 && a<=3 && b>=1 && b<=3)
        {
            swap(cur_state[a][b], cur_state[i][j]);
            if(check_alreadly(cur_state)==false)
            {
                int hn=cnt_mismatch(cur_state);
                insert_to_be_exp(hn+gn, gn, cur_state);
                set_path(come_from, cur_state);
            }
            swap(cur_state[a][b], cur_state[i][j]);
        }
        //left
        a=i, b=j-1;
        if(a>=1 && a<=3 && b>=1 && b<=3)
        {
            swap(cur_state[a][b], cur_state[i][j]);
            if(check_alreadly(cur_state)==false)
            {
                int hn=cnt_mismatch(cur_state);
                insert_to_be_exp(hn+gn, gn, cur_state);
                set_path(come_from, cur_state);
            }
            swap(cur_state[a][b], cur_state[i][j]);
        }
        //right
        a=i, b=j+1;
        if(a>=1 && a<=3 && b>=1 && b<=3)
        {
            swap(cur_state[a][b], cur_state[i][j]);
            if(check_alreadly(cur_state)==false)
            {
                int hn=cnt_mismatch(cur_state);
                insert_to_be_exp(hn+gn, gn, cur_state);
                set_path(come_from, cur_state);
            }
        }
    }
}

void print_path(matrix node)
{
    if(path[node]==base_con)
        return;
    print_path(path[node]);

    cout << endl;
    cout << node.first << " ";
    cout << node.second.first << " ";
    cout << node.second.second.first << endl;
    cout << node.second.second.second.first << " ";
    cout << node.second.second.second.second.first << " ";
    cout << node.second.second.second.second.second.first << endl;
    cout << node.second.second.second.second.second.second.first << " ";
    cout << node.second.second.second.second.second.second.second.first << " ";
    cout << node.second.second.second.second.second.second.second.second << endl;
}

int main()
{
    int initial[MX][MX];
    printf("Input initial state:\n");
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
        {
            scanf("%d", &initial[i][j]);
        }
    }
    printf("Input goal state:\n");
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++)
            scanf("%d", &goal[i][j]);
    }
    printf("\n\n");
    solve(initial);

    printf("\n\nSteps:\n");
    print_state(initial);

    matrix node = mp(goal[1][1], mp(goal[1][2], mp(goal[1][3], mp(goal[2][1], mp(goal[2][2], mp(goal[2][3], mp(goal[3][1], mp(goal[3][2], goal[3][3]))))))));
    print_path(node);
    if(path[node]==base_con)
        cout << "YES" << endl;

    return 0;
}

/*
Sample Input
7 2 4 6 3 1 8 0 5
1 2 3 4 5 6 7 8 0
*/
