#include <string>
#include <vector>

using namespace std;

void MoveStrings (vector <string> &source, vector <string> &destination){
 for (string iter :source)
     destination.push_back(iter);
source.clear();
}