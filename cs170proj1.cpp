#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

struct problem{
    vector<int> puzzle;
    int algorithm;
};  // problem will hold puzzle vector and algorithm choice

bool checkedIfSolved(problem p){
    if(p.puzzle.at(0) == 1)
    if(p.puzzle.at(1) == 2)
    if(p.puzzle.at(2) == 3)
    if(p.puzzle.at(3) == 4)
    if(p.puzzle.at(4) == 5)
    if(p.puzzle.at(5) == 6)
    if(p.puzzle.at(6) == 7)
    if(p.puzzle.at(7) == 8)
    if(p.puzzle.at(8) == 9)
    return true;
    return false;
}   // simple check if solved function

void displayProblem(problem p){
    cout << p.puzzle[0] << " " << p.puzzle[1] << " " << p.puzzle[2] << "\n";
    cout << p.puzzle[3] << " " << p.puzzle[4] << " " << p.puzzle[5] << "\n";
    cout << p.puzzle[6] << " " << p.puzzle[7] << " " << p.puzzle[8] << "\n";
}

problem assignDefaultPuzzle(){
    cout << "Using default puzzle\n";
    problem p;
    p.puzzle.clear();       // erase just in case
    p.puzzle.push_back(1);
    p.puzzle.push_back(2);
    p.puzzle.push_back(3);
    p.puzzle.push_back(4);
    p.puzzle.push_back(5);
    p.puzzle.push_back(6);
    p.puzzle.push_back(7);
    p.puzzle.push_back(8);
    p.puzzle.push_back(0);

    return p;
}   // assign default puzzle

bool checkInput(int a){
    if(a != 0)
    if(a != 1)
    if(a != 2)
    if(a != 3)
    if(a != 4)
    if(a != 5)
    if(a != 6)
    if(a != 7)
    if(a != 8)
    return false;
    return true;
}

bool sanitizeInputs(problem p){
    int a, b, c, d, e, f, g, h, i;
    a = p.puzzle.at(0);
    b = p.puzzle.at(1);
    c = p.puzzle.at(2);
    d = p.puzzle.at(3);
    e = p.puzzle.at(4);
    f = p.puzzle.at(5);
    g = p.puzzle.at(6);
    h = p.puzzle.at(7);
    i = p.puzzle.at(8);
    if(a == b || a == c || a == d || a == e || a == f || a == g || a == h || a == i)
        return false;
    if(b == c || b == d || b == e || b == f || b == g || b == h || b == i)
        return false;
    if(c == d || c == e || c == f || c == g || c == h || c == i)
        return false;
    if(d == e || d == f || d == g || d == h || d == i)
        return false;
    if(e == f || e == g || e == h || e == i)
        return false;
    if(f == g || f == h || f == i)
        return false;
    if(g == h || g == i)
        return false;
    if(h == i)
        return false;
    return true;
}

problem assignCustomPuzzle(){
    string row1, row2, row3;
    cout << "Enter your puzzle one number at a time, use a zero to represent the blank, enter in between entries.\n";
    int a;
    problem p;
    p.puzzle.clear();       // erase just in case
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }
    cin >> a;
    if(checkInput(a))
    p.puzzle.push_back(a);
    else {
        cout << "Invalid input, restarting\n";
        assignCustomPuzzle();
    }

    cout << "Is this correct? (y/n)\n";
    displayProblem(p);
    string b;
    cin >> b;
    if (b == "y")
        if(sanitizeInputs(p))
            return p;
        else{
            cout << "incorrect input, restarting\n";
            return assignCustomPuzzle();
        }
    else
        return assignCustomPuzzle();
}   // assign custom puzzle

problem getInput(){
    int puz = 0;
    problem p;
    cout << "Welcome to Ryan Yuzuki's 8-puzzle solver.\n";
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
    cin >> puz;
    if(puz == 1){
        p = assignDefaultPuzzle();
    }
    else if(puz == 2){
        p = assignCustomPuzzle();
    }
    else{
        cout << "invalid input\n";
        p = getInput();
    }

    return p;
}

problem getAlgorithm(problem p){
    cout << "Enter your choice of algorithm\n";
    cout << "1 Uniform Cost Search\n";
    cout << "2 A* with the Misplaced Tile heuristic\n";
    cout << "3 A* with the Manhattan distance heuristic\n";
    int a;
    cin >> a;
    if(a == 1){    
        cout << "\nWe will use the following puzzle:\n";
        displayProblem(p);
        cout << "using Uniform Cost Search.\n";
        p.algorithm = 1;
    }
    else if (a == 2){
        cout << "\nWe will use the following puzzle:\n";
        displayProblem(p);
        cout << "using A* with the Misplaced Tile heuristic.\n";
        p.algorithm = 2;
    }
    else if (a == 3){
        cout << "\nWe will use the following puzzle:\n";
        displayProblem(p);
        cout << "using A* with the Manhattan distance heuristic.\n";
        p.algorithm = 3;
    }
    else
    getAlgorithm(p);
    return p;
}

void uniformCostSearch(vector<int> puzzle){
    cout << "uniform cost";
}

void misplacedTileHeuristic(vector<int> puzzle){
    cout << "misplaced tile";
}
void manhattanDistanceHeuristic(vector<int> puzzle){
    cout << "manhattan distance";
}

int main(){
    problem p;
    p = getInput();
    p = getAlgorithm(p);
    if(p.algorithm == 1){
        uniformCostSearch(p.puzzle);
    }
    else if(p.algorithm == 2){
        misplacedTileHeuristic(p.puzzle);
    }
    else 
        manhattanDistanceHeuristic(p.puzzle);
    return 0;
}


//     cout << "1 Uniform Cost Search\n";
//     cout << "2 A* with the Misplaced Tile heuristic\n";
//     cout << "3 A* with the Manhattan distance heuristic\n";
    