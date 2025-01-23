//#include <iostream>
//#include "GameState.h"
//
////@! Using Singletons
////To use a singleton, the create instance function is called to obtain a
////pointer reference to the singleton where its data can be accessed. The
////singleton can be accessed in various parts of the project without a need
////to pass the instance around.
//
//int main(){
//    GameState* state = GameState::createInstance();
//    state->setScore(50);
//    std::cout << "Output: " << state->getScore() << std::endl;
//    delete state;
//}
//
////@! Pointer Note
////When pointers are used and memory is allocated (using "new"), be sure
////to delete the allocated memory once the program finishes. This way
////memory is effiently utilized by the program.
