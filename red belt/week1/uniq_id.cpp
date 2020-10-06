
#include <ostream>
using namespace std;

#define ID(x) VAR_##x
#define TOKEN(x) ID(x)
#define UNIQ_ID TOKEN(__LINE__)            

int main() {
    int UNIQ_ID = 5;
    string UNIQ_ID = "hello!";

}