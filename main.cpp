#include "stack.h"
#include "dialog.h"
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
int main() {
    Prog3_3::Stack *stack = new Prog3_3::Stack();
    Menu::start(stack);
    delete stack;
    _CrtDumpMemoryLeaks();
    return 0;
}
