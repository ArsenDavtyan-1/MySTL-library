MySTL

MySTL is a personal project focused on building an STL-like library from scratch in order to deeply understand how the C++ Standard Template Library works internally and to make its 
design more intuitive for myself. The project was originally started about 1.5 years ago, but the initial structure did not fully follow good design principles. As my understanding of C++,
templates, and software architecture has grown, I decided to rework the project from the ground up, applying better practices such as object-oriented design, clearer separation of 
responsibilities, and a structure closer to the real STL.

Project structure and evolution

The legacy branch contains the original implementation.
In that version, some components were organized in a non-STL-like way (for example, iterators were defined inside containers instead of being separated).
The current version aims to closely mirror the actual STL design:
  1.Containers, iterators, algorithms, and functors are separated
  2.Interfaces and responsibilities are more clearly defined
  3.The overall structure is cleaner and more maintainable

Testing

Testing will be added as the project evolves. The plan is to keep tests in a separate submodule, allowing independent development and cleaner separation between implementation and 
validation.

Current status

This project is at an early stage of redevelopment. At the moment, some parts of the old implementation are still being reused and gradually refactored as the new structure takes shape.
The main goal is learning through implementation, not replacing the real STL, but understanding why it is designed the way it is.
