// Statically allocated in the data segment when the program/DLL is first loaded
// Deallocated when the program/DLL exits
// scope - can be accessed from anywhere in the code
int someGlobalVariable;

// Statically allocated in the data segment when the program is first loaded
// Deallocated when the program/DLL exits
// scope - can be accessed from anywhere in this particular code file
static int someStaticVariable;

// "someArgument" is allocated on the stack each time MyFunction is called
// "someArgument" is deallocated when MyFunction returns
// scope - can be accessed only within MyFunction()
void MyFunction(int someArgument) {
    
    // Statically allocated in the data segment when the program is first loaded
    // Deallocated when the program/DLL exits
    // scope - can be accessed only within MyFunction()
    static int someLocalStaticVariable;
    
    // Allocated on the stack each time MyFunction is called
    // Deallocated when MyFunction returns
    // scope - can be accessed only within MyFunction()
    int someLocalVariable;
    
    // A *pointer* is allocated on the stack each time MyFunction is called
    // This pointer is deallocated when MyFunction returns
    // scope - the pointer can be accessed only within MyFunction()
    int* someDynamicVariable;
    
    // This line causes space for an integer to be allocated in the heap
    // when this line is executed. Note this is not at the beginning of
    // the call to MyFunction(), like the automatic variables
    // scope - only code within MyFunction() can access this space
    // *through this particular variable*.
    // However, if you pass the address somewhere else, that code
    // can access it too
    someDynamicVariable = new int;
    
    
    // This line deallocates the space for the integer in the heap.
    // If we did not write it, the memory would be "leaked".
    // Note a fundamental difference between the stack and heap
    // the heap must be managed. The stack is managed for us.
    delete someDynamicVariable;
    
    // In other cases, instead of deallocating this heap space you
    // might store the address somewhere more permanent to use later.
    // Some languages even take care of deallocation for you... but
    // always it needs to be taken care of at runtime by some mechanism.
    
    // When the function returns, someArgument, someLocalVariable
    // and the pointer someDynamicVariable are deallocated.
    // The space pointed to by someDynamicVariable was already
    // deallocated prior to returning.
    return;
}

// Note that someGlobalVariable, someStaticVariable and
// someLocalStaticVariable continue to exist, and are not
// deallocated until the program exits.
