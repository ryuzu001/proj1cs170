#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

struct problem{
    vector<int> puzzle;
    int algorithm;
};  // problem will hold puzzle vector and algorithm choice

struct node{
  vector<int> state;  // vector of ints to represent state
  int cost;   // cost to get to state
};
struct node2{
  vector<int> state;  // vector of ints to represent state
  int hn; // same as node but with hn, gn instead of total cost.
  int gn;
};

int numExpanded = 0;
int maxNodes = 0;

node findCheapest(vector<node> nodes){
  // if the tree is super huge, like 1 billion or bigger nodes expanded we are in trouble.
  node cheapest;
  cheapest.cost = 1000000000;
  for(int i = 0; i < nodes.size(); i++){
    if(cheapest.cost > nodes.at(i).cost){
      cheapest = nodes.at(i);
    }
  }
  return cheapest;
} // find the cheapest given a vector of nodes
node2 findCheapest2(vector<node2> nodes){
  // if the tree is super huge, like 1 billion or bigger nodes expanded we are in trouble.
  node2 cheapest;
  cheapest.hn = 1000000000;
  cheapest.gn = 500;
  for(int i = 0; i < nodes.size(); i++){
    if((cheapest.gn + cheapest.hn) > (nodes.at(i).gn + nodes.at(i).hn)){
      cheapest = nodes.at(i);
    }
  }
  return cheapest;
}

void removeNode(node n, vector<node> & nodes, vector<node> & visitedNodes){
  // finds the matching node n with the one in nodes, and removes it and adds it to visitedNodes
  bool m = false;
  for(int i = 0; i < nodes.size(); i++){
    if(nodes.at(i).state.at(0) == n.state.at(0))
    if(nodes.at(i).state.at(1) == n.state.at(1))
    if(nodes.at(i).state.at(2) == n.state.at(2))
    if(nodes.at(i).state.at(3) == n.state.at(3))
    if(nodes.at(i).state.at(4) == n.state.at(4))
    if(nodes.at(i).state.at(5) == n.state.at(5))
    if(nodes.at(i).state.at(6) == n.state.at(6))
    if(nodes.at(i).state.at(7) == n.state.at(7))
    if(nodes.at(i).state.at(8) == n.state.at(8)){
      visitedNodes.push_back(nodes.at(i));
      nodes.erase(nodes.begin() + i);
      m = true;
    }
  }
  if(!m){// shouldn't be hit
    cout << "node not found\n";
  }
}

void removeNode2(node2 n, vector<node2> & nodes, vector<node2> & visitedNodes){
  // finds the matching node n with the one in nodes, and removes it and adds it to visitedNodes
  bool m = false;
  for(int i = 0; i < nodes.size(); i++){
    if(nodes.at(i).state.at(0) == n.state.at(0))
    if(nodes.at(i).state.at(1) == n.state.at(1))
    if(nodes.at(i).state.at(2) == n.state.at(2))
    if(nodes.at(i).state.at(3) == n.state.at(3))
    if(nodes.at(i).state.at(4) == n.state.at(4))
    if(nodes.at(i).state.at(5) == n.state.at(5))
    if(nodes.at(i).state.at(6) == n.state.at(6))
    if(nodes.at(i).state.at(7) == n.state.at(7))
    if(nodes.at(i).state.at(8) == n.state.at(8)){
      visitedNodes.push_back(nodes.at(i));
      nodes.erase(nodes.begin() + i);
      m = true;
    }
  }
  if(!m){
    cout << "node not found\n";
  }
}

bool isGoalState(vector<int> state){
  if(state.at(0) == 1)
  if(state.at(1) == 2)
  if(state.at(2) == 3)
  if(state.at(3) == 4)
  if(state.at(4) == 5)
  if(state.at(5) == 6)
  if(state.at(6) == 7)
  if(state.at(7) == 8)
  if(state.at(8) == 0)
  return true;
  return false;
}   // check if goal state

bool checkedIfSolved(node p){
    if(p.state.at(0) == 1)
    if(p.state.at(1) == 2)
    if(p.state.at(2) == 3)
    if(p.state.at(3) == 4)
    if(p.state.at(4) == 5)
    if(p.state.at(5) == 6)
    if(p.state.at(6) == 7)
    if(p.state.at(7) == 8)
    if(p.state.at(8) == 0)
    return true;
    return false;
}   // simple check if solved function

bool checkedIfSolved2(node2 p){
    if(p.state.at(0) == 1)
    if(p.state.at(1) == 2)
    if(p.state.at(2) == 3)
    if(p.state.at(3) == 4)
    if(p.state.at(4) == 5)
    if(p.state.at(5) == 6)
    if(p.state.at(6) == 7)
    if(p.state.at(7) == 8)
    if(p.state.at(8) == 0)
    return true;
    return false;
}   // simple check if solved function

void displayProblem(problem p){
    cout << p.puzzle[0] << " " << p.puzzle[1] << " " << p.puzzle[2] << "\n";
    cout << p.puzzle[3] << " " << p.puzzle[4] << " " << p.puzzle[5] << "\n";
    cout << p.puzzle[6] << " " << p.puzzle[7] << " " << p.puzzle[8] << "\n";
} // prints problem. probably better to call printNode but eh

void printFinalNode(node n){
  cout << n.state.at(0) << " " << n.state.at(1) << " " << n.state.at(2) << "\n";
  cout << n.state.at(3) << " " << n.state.at(4) << " " << n.state.at(5) << "\n";
  cout << n.state.at(6) << " " << n.state.at(7) << " " << n.state.at(8) << "\n";
  cout << "To solve this problem, the algorithm expanded " << numExpanded << " nodes.\n";
  cout << "The maximum number of nodes in the queue at any one time was " << maxNodes << endl;
  cout << "Depth of goal node: " << n.cost << "\n";
} // called at the end. prints out information, along with the solved node.

void printFinalNode2(node2 n){
  cout << n.state.at(0) << " " << n.state.at(1) << " " << n.state.at(2) << "\n";
  cout << n.state.at(3) << " " << n.state.at(4) << " " << n.state.at(5) << "\n";
  cout << n.state.at(6) << " " << n.state.at(7) << " " << n.state.at(8) << "\n";
  cout << "To solve this problem, the algorithm expanded " << numExpanded << " nodes.\n";
  cout << "The maximum number of nodes in the queue at any one time was " << maxNodes << endl;
  cout << "Depth of goal node: " << n.gn << "\n";
} // called at the end. prints out information, along with the solved node.

void printNode(node n){
  cout << n.state.at(0) << " " << n.state.at(1) << " " << n.state.at(2) << "\n";
  cout << n.state.at(3) << " " << n.state.at(4) << " " << n.state.at(5) << "\n";
  cout << n.state.at(6) << " " << n.state.at(7) << " " << n.state.at(8) << "\n";
}   //print node

void printNode2(node2 n){
  cout << n.state.at(0) << " " << n.state.at(1) << " " << n.state.at(2) << "\n";
  cout << n.state.at(3) << " " << n.state.at(4) << " " << n.state.at(5) << "\n";
  cout << n.state.at(6) << " " << n.state.at(7) << " " << n.state.at(8) << "\n";
} // print node2

problem assignDefaultPuzzle(){
    cout << "Using default puzzle\n";
    problem p;
    p.puzzle.clear();       // erase just in case
    p.puzzle.push_back(1);
    p.puzzle.push_back(2);
    p.puzzle.push_back(3);    // 123
    p.puzzle.push_back(4);    // 406
    p.puzzle.push_back(0);    // 758    is current default puzzle
    p.puzzle.push_back(6);
    p.puzzle.push_back(7);
    p.puzzle.push_back(5);
    p.puzzle.push_back(8);

    node temp;
    temp.state = p.puzzle;
    printNode(temp);
    cout << endl;

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
} // tests to see if the custom puzzle inputted is a valid one (ie. two '0' characters)

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
    p = getAlgorithm(p);
    cout << endl;
    cout << endl;
    return p;
}

bool isSameNode(node a, node b){
  if(a.state.at(0) == b.state.at(0))
  if(a.state.at(1) == b.state.at(1))
  if(a.state.at(2) == b.state.at(2))
  if(a.state.at(3) == b.state.at(3))
  if(a.state.at(4) == b.state.at(4))
  if(a.state.at(5) == b.state.at(5))
  if(a.state.at(6) == b.state.at(6))
  if(a.state.at(7) == b.state.at(7))
  if(a.state.at(8) == b.state.at(8))
  return true;
  return false;
} // simple test to see if same node

bool isSameNode2(node2 a, node2 b){
  if(a.state.at(0) == b.state.at(0))
  if(a.state.at(1) == b.state.at(1))
  if(a.state.at(2) == b.state.at(2))
  if(a.state.at(3) == b.state.at(3))
  if(a.state.at(4) == b.state.at(4))
  if(a.state.at(5) == b.state.at(5))
  if(a.state.at(6) == b.state.at(6))
  if(a.state.at(7) == b.state.at(7))
  if(a.state.at(8) == b.state.at(8))
  return true;
  return false;
} // sameNode but with node2 instead

bool isonList(node n, vector<node> v){
  for(int i = 0; i < v.size(); i++){
    if(isSameNode(n, v.at(i)))
      return true;
  }
  return false;
}

bool isonList2(node2 n, vector<node2> v){
  for(int i = 0; i < v.size(); i++){
    if(isSameNode2(n, v.at(i)))
      return true;
  }
  return false;
}

int locationOf0(node n){
  if(n.state.at(0) == 0)
  return 0;
  if(n.state.at(1) == 0)
  return 1;
  if(n.state.at(2) == 0)
  return 2;
  if(n.state.at(3) == 0)
  return 3;
  if(n.state.at(4) == 0)
  return 4;
  if(n.state.at(5) == 0)
  return 5;
  if(n.state.at(6) == 0)
  return 6;
  if(n.state.at(7) == 0)
  return 7;
  if(n.state.at(8) == 0)
  return 8;
  return -1;
}

int locationOf0_2(node2 n){
  if(n.state.at(0) == 0)
  return 0;
  if(n.state.at(1) == 0)
  return 1;
  if(n.state.at(2) == 0)
  return 2;
  if(n.state.at(3) == 0)
  return 3;
  if(n.state.at(4) == 0)
  return 4;
  if(n.state.at(5) == 0)
  return 5;
  if(n.state.at(6) == 0)
  return 6;
  if(n.state.at(7) == 0)
  return 7;
  if(n.state.at(8) == 0)
  return 8;
  return -1;
}

// See diagram

node swap1(node n){
  int t = n.state.at(0);
  n.state.at(0) = n.state.at(1);
  n.state.at(1) = t;
  return n;
}
node swap2(node n){
  int t = n.state.at(1);
  n.state.at(1) = n.state.at(2);
  n.state.at(2) = t;
  return n;
}
node swap3(node n){
  int t = n.state.at(0);
  n.state.at(0) = n.state.at(3);
  n.state.at(3) = t;
  return n;
}
node swap4(node n){
  int t = n.state.at(1);
  n.state.at(1) = n.state.at(4);
  n.state.at(4) = t;
  return n;
}
node swap5(node n){
  int t = n.state.at(2);
  n.state.at(2) = n.state.at(5);
  n.state.at(5) = t;
  return n;
}
node swap6(node n){
  int t = n.state.at(3);
  n.state.at(3) = n.state.at(4);
  n.state.at(4) = t;
  return n;
}
node swap7(node n){
  int t = n.state.at(4);
  n.state.at(4) = n.state.at(5);
  n.state.at(5) = t;
  return n;
}
node swap8(node n){
  int t = n.state.at(3);
  n.state.at(3) = n.state.at(6);
  n.state.at(6) = t;
  return n;
}
node swap9(node n){
  int t = n.state.at(4);
  n.state.at(4) = n.state.at(7);
  n.state.at(7) = t;
  return n;
}
node swap10(node n){
  int t = n.state.at(5);
  n.state.at(5) = n.state.at(8);
  n.state.at(8) = t;
  return n;
}
node swap11(node n){
  int t = n.state.at(6);
  n.state.at(6) = n.state.at(7);
  n.state.at(7) = t;
  return n;
}
node swap12(node n){
  int t = n.state.at(7);
  n.state.at(7) = n.state.at(8);
  n.state.at(8) = t;
  return n;
}

// copy but with node2 instead

node2 swap1_2(node2 n){
  int t = n.state.at(0);
  n.state.at(0) = n.state.at(1);
  n.state.at(1) = t;
  return n;
}
node2 swap2_2(node2 n){
  int t = n.state.at(1);
  n.state.at(1) = n.state.at(2);
  n.state.at(2) = t;
  return n;
}
node2 swap3_2(node2 n){
  int t = n.state.at(0);
  n.state.at(0) = n.state.at(3);
  n.state.at(3) = t;
  return n;
}
node2 swap4_2(node2 n){
  int t = n.state.at(1);
  n.state.at(1) = n.state.at(4);
  n.state.at(4) = t;
  return n;
}
node2 swap5_2(node2 n){
  int t = n.state.at(2);
  n.state.at(2) = n.state.at(5);
  n.state.at(5) = t;
  return n;
}
node2 swap6_2(node2 n){
  int t = n.state.at(3);
  n.state.at(3) = n.state.at(4);
  n.state.at(4) = t;
  return n;
}
node2 swap7_2(node2 n){
  int t = n.state.at(4);
  n.state.at(4) = n.state.at(5);
  n.state.at(5) = t;
  return n;
}
node2 swap8_2(node2 n){
  int t = n.state.at(3);
  n.state.at(3) = n.state.at(6);
  n.state.at(6) = t;
  return n;
}
node2 swap9_2(node2 n){
  int t = n.state.at(4);
  n.state.at(4) = n.state.at(7);
  n.state.at(7) = t;
  return n;
}
node2 swap10_2(node2 n){
  int t = n.state.at(5);
  n.state.at(5) = n.state.at(8);
  n.state.at(8) = t;
  return n;
}
node2 swap11_2(node2 n){
  int t = n.state.at(6);
  n.state.at(6) = n.state.at(7);
  n.state.at(7) = t;
  return n;
}
node2 swap12_2(node2 n){
  int t = n.state.at(7);
  n.state.at(7) = n.state.at(8);
  n.state.at(8) = t;
  return n;
}

int findHeuristicMisplaced(node2 n){
  // find heuristic for misplaced tile Heuristic
  int ret = 0;
  if(n.state.at(0) != 1 && n.state.at(0) != 0)
  ret++;
  if(n.state.at(1) != 2 && n.state.at(0) != 0)
  ret++;
  if(n.state.at(2) != 3 && n.state.at(0) != 0)
  ret++;
  if(n.state.at(3) != 4 && n.state.at(0) != 0)
  ret++;
  if(n.state.at(4) != 5 && n.state.at(0) != 0)
  ret++;
  if(n.state.at(5) != 6 && n.state.at(0) != 0)
  ret++;
  if(n.state.at(6) != 7 && n.state.at(0) != 0)
  ret++;
  if(n.state.at(7) != 8 && n.state.at(0) != 0)
  ret++;
  return ret;
}

int findHeuristicManhattan(node2 n){
  // each indivdual case. Probably a better way to do this, but it works so I don't want to mess with it lol
  int ret = 0;
  if(n.state.at(0) == 2 || n.state.at(0) == 4)
  ret += 1;
  if(n.state.at(0) == 3 || n.state.at(0) == 7 || n.state.at(0) == 5)
  ret += 2;
  if(n.state.at(0) == 6 || n.state.at(0) == 8)
  ret += 3;
  if(n.state.at(1) == 1 || n.state.at(1) == 3 || n.state.at(1) == 5)
  ret += 1;
  if(n.state.at(1) == 4 || n.state.at(1) == 6 || n.state.at(1) == 8)
  ret += 2;
  if(n.state.at(1) == 7)
  ret += 3;
  if(n.state.at(2) == 2 || n.state.at(2) == 6)
  ret += 1;
  if(n.state.at(2) == 1 || n.state.at(2) == 5)
  ret += 2;
  if(n.state.at(2) == 4 || n.state.at(2) == 8)
  ret += 3;
  if(n.state.at(2) == 7)
  ret += 4;
  if(n.state.at(3) == 1 || n.state.at(3) == 5 || n.state.at(3) == 7)
  ret += 1;
  if(n.state.at(3) == 2 || n.state.at(3) == 6 || n.state.at(3) == 8)
  ret += 2;
  if(n.state.at(3) == 3)
  ret += 3;
  if(n.state.at(4) == 2 || n.state.at(4) == 4 || n.state.at(4) == 6 || n.state.at(4) == 8)
  ret +=1;
  if(n.state.at(4) == 1 || n.state.at(4) == 3 || n.state.at(4) ==7)
  ret += 2;
  if(n.state.at(5) == 3 || n.state.at(5) == 5)
  ret += 1;
  if(n.state.at(5) == 2 || n.state.at(5) == 4 || n.state.at(5) == 8)
  ret += 2;
  if(n.state.at(5) == 1 || n.state.at(5) == 7)
  ret += 3;
  if(n.state.at(6) == 4 || n.state.at(6) == 8)
  ret += 1;
  if(n.state.at(6) == 1 || n.state.at(6) == 5)
  ret += 2;
  if(n.state.at(6) == 2 || n.state.at(6) == 6)
  ret += 3;
  if(n.state.at(6) == 3)
  ret += 4;
  if(n.state.at(7) == 7 || n.state.at(7) == 5)
  ret +=1;
  if(n.state.at(7) == 2 || n.state.at(7) == 4 || n.state.at(7) == 6)
  ret += 2;
  if(n.state.at(7) == 1 || n.state.at(7) == 3)
  ret += 3;
  if(n.state.at(8) == 6 || n.state.at(8) == 8)
  ret += 1;
  if(n.state.at(8) == 3 || n.state.at(8) == 5 || n.state.at(8) == 7)
  ret += 2;
  if(n.state.at(8) == 2 || n.state.at(8) == 4)
  ret += 3;
  if(n.state.at(8) == 1)
  ret += 4;
  return ret;
}

vector<node> uniformExpand(node n, vector<node> nodes, vector<node> visited){
  // see diagram for explanation, basically finds where the '0' blank character is then performs all possible operations from there.

  int locationOfZero = locationOf0(n);
  n.cost++;
  if(locationOfZero == 0){
    node temp = swap1(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap3(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 1){
    node temp = swap1(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap2(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap4(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 2){
    node temp = swap2(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap3(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 3){
    node temp = swap3(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap6(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap8(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 4){
    node temp = swap4(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap6(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap7(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap9(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 5){
    node temp = swap5(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap7(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap10(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 6){
    node temp = swap8(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap11(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 7){
    node temp = swap9(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap11(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap12(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 8){
    node temp = swap10(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
    temp = swap12(n);
    if(!isonList(temp, visited)){ // generated node is not visited yet
      nodes.push_back(temp);
    }
  }
  numExpanded++;
  if(nodes.size() > maxNodes)
    maxNodes = nodes.size();

  return nodes;
}

vector<node2> misplacedExpand(node2 n, vector<node2> nodes, vector<node2> visited){
  // see diagram for explanation, basically finds where the '0' blank character is then performs all possible operations from there.

  int locationOfZero = locationOf0_2(n);
  n.gn++;
  if(locationOfZero == 0){
    node2 temp = swap1_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap3_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 1){
    node2 temp = swap1_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap2_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap4_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 2){
    node2 temp = swap2_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap3_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 3){
    node2 temp = swap3_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap6_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap8_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 4){
    node2 temp = swap4_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap6_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap7_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap9_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 5){
    node2 temp = swap5_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap7_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap10_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 6){
    node2 temp = swap8_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap11_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 7){
    node2 temp = swap9_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap11_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap12_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 8){
    node2 temp = swap10_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
    temp = swap12_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicMisplaced(temp);
      nodes.push_back(temp);
    }
  }
  numExpanded++;
  if(nodes.size() > maxNodes)
    maxNodes = nodes.size();

  return nodes;
}

vector<node2> manhattanExpand(node2 n, vector<node2> nodes, vector<node2> visited){
  // see diagram for explanation, basically finds where the '0' blank character is then performs all possible operations from there.

  int locationOfZero = locationOf0_2(n);
  n.gn++;
  if(locationOfZero == 0){
    node2 temp = swap1_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap3_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 1){
    node2 temp = swap1_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap2_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap4_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 2){
    node2 temp = swap2_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap3_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 3){
    node2 temp = swap3_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap6_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap8_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 4){
    node2 temp = swap4_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap6_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap7_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap9_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 5){
    node2 temp = swap5_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap7_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap10_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 6){
    node2 temp = swap8_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap11_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 7){
    node2 temp = swap9_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap11_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap12_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  if(locationOfZero == 8){
    node2 temp = swap10_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
    temp = swap12_2(n);
    if(!isonList2(temp, visited)){ // generated node is not visited yet
      temp.hn = findHeuristicManhattan(temp);
      nodes.push_back(temp);
    }
  }
  numExpanded++;
  if(nodes.size() > maxNodes)
    maxNodes = nodes.size();

  return nodes;
}

node uniformCostSearch(vector<int> puzzle){
  // basically the driver program from the project infosheet

    node fail;
    fail.cost = 0;
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    // driver for uniform cost search
    node initial;
    initial.state = puzzle;
    initial.cost = 0;

    vector<node> nodes;
    vector<node> visited;
    nodes.push_back(initial);
    node currNode;

    while(1){
        if(nodes.size() == 0){
          cout << "failure\n";
          return fail;
        }
        currNode = findCheapest(nodes);

        removeNode(currNode, nodes, visited);
        if(checkedIfSolved(currNode)){
          cout << "Solved:\n";
          return currNode;
        }
        cout << "Expanding cheapest node with cost " << currNode.cost << ".\n";
        printNode(currNode);
        nodes = uniformExpand(currNode, nodes, visited);
    }
}

node2 misplacedTileHeuristic(vector<int> puzzle){
    // the total number of misplaced tiles. for example:
    // 328
    // 456
    // 710
    //
    // misplaced tile heuristic evaluates 3 because only 3 tiles are misplaced. (3,8,1)
    // not including the blank tile
    // SLIDE 30 Heuristic Search
    node2 fail;
    fail.hn = 0;
    fail.gn = 0;
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);
    fail.state.push_back(0);

    node2 initial;
    initial.state = puzzle;
    initial.hn = findHeuristicMisplaced(initial);
    initial.gn = 0;

    vector<node2> nodes;
    vector<node2> visited;
    nodes.push_back(initial);
    node2 currNode;

    while(1){
      if(nodes.size() == 0){
        cout << "failure\n";
        return fail;
      }
      currNode = findCheapest2(nodes);

      removeNode2(currNode, nodes, visited);
      if(checkedIfSolved2(currNode)){
        cout << "Solved: \n";
        return currNode;
      }
      cout << "The best state to expand with g(n) " << currNode.gn << " and h(n) " << currNode.hn << " is\n";
      printNode2(currNode);

      nodes = misplacedExpand(currNode, nodes, visited);
    }
}

node2 manhattanDistanceHeuristic(vector<int> puzzle){
  // the total distance of misplaced tiles. for example:
  // 328
  // 456
  // 710
  //
  // misplaced tile heuristic evaluates 2+3+3=8 because (3,8,1) are that far away (3 is 2 spaces away...)
  // SLIDE 31 Heuristic Search
  node2 fail;
  fail.hn = 0;
  fail.gn = 0;
  fail.state.push_back(0);
  fail.state.push_back(0);
  fail.state.push_back(0);
  fail.state.push_back(0);
  fail.state.push_back(0);
  fail.state.push_back(0);
  fail.state.push_back(0);
  fail.state.push_back(0);
  fail.state.push_back(0);

  node2 initial;
  initial.state = puzzle;
  initial.hn = findHeuristicManhattan(initial);
  initial.gn = 0;

  vector<node2> nodes;
  vector<node2> visited;
  nodes.push_back(initial);
  node2 currNode;

  while(1){
    if(nodes.size() == 0){
      cout << "failure\n";
      return fail;
    }
    currNode = findCheapest2(nodes);
    removeNode2(currNode, nodes, visited);
    if(checkedIfSolved2(currNode)){
      cout << "Solved: \n";
      return currNode;
    }
    cout << "The best state to expand with g(n) " << currNode.gn << " and h(n) " << currNode.hn << " is\n";
    printNode2(currNode);

    nodes = manhattanExpand(currNode, nodes, visited);
  }
}

int main(){
    problem p;
    p = getInput();
    p = getAlgorithm(p);
    node n;
    node2 n2;
    if(p.algorithm == 1){
        n = uniformCostSearch(p.puzzle);
        printFinalNode(n);
    }
    else if(p.algorithm == 2){
        n2 = misplacedTileHeuristic(p.puzzle);
        printFinalNode2(n2);
    }
    else{
        n2 = manhattanDistanceHeuristic(p.puzzle);
        printFinalNode2(n2);
    }
    return 0;
}
