*This project has been created as part of the 42 curriculum by zaalrafa.*

                  _____                    _____                    _____                    _____                    _____                    _____                    _____                    _____          
                 /\    \                  /\    \                  /\    \                  /\    \                  /\    \                  /\    \                  /\    \                  /\    \         
                /::\    \                /::\____\                /::\    \                /::\____\                /::\    \                /::\____\                /::\    \                /::\    \        
               /::::\    \              /:::/    /               /::::\    \              /:::/    /               /::::\    \              /:::/    /               /::::\    \              /::::\    \       
              /::::::\    \            /:::/    /               /::::::\    \            /:::/    /               /::::::\    \            /:::/   _/___            /::::::\    \            /::::::\    \      
             /:::/\:::\    \          /:::/    /               /:::/\:::\    \          /:::/    /               /:::/\:::\    \          /:::/   /\    \          /:::/\:::\    \          /:::/\:::\    \     
            /:::/__\:::\    \        /:::/    /               /:::/__\:::\    \        /:::/____/               /:::/__\:::\    \        /:::/   /::\____\        /:::/__\:::\    \        /:::/__\:::\    \    
           /::::\   \:::\    \      /:::/    /                \:::\   \:::\    \      /::::\    \               \:::\   \:::\    \      /:::/   /:::/    /       /::::\   \:::\    \      /::::\   \:::\    \   
          /::::::\   \:::\    \    /:::/    /      _____    ___\:::\   \:::\    \    /::::::\    \   _____    ___\:::\   \:::\    \    /:::/   /:::/   _/___    /::::::\   \:::\    \    /::::::\   \:::\    \  
         /:::/\:::\   \:::\____\  /:::/____/      /\    \  /\   \:::\   \:::\    \  /:::/\:::\    \ /\    \  /\   \:::\   \:::\    \  /:::/___/:::/   /\    \  /:::/\:::\   \:::\    \  /:::/\:::\   \:::\____\ 
        /:::/  \:::\   \:::|    ||:::|    /      /::\____\/::\   \:::\   \:::\____\/:::/  \:::\    /::\____\/::\   \:::\   \:::\____\|:::|   /:::/   /::\____\/:::/  \:::\   \:::\____\/:::/  \:::\   \:::|    |
        \::/    \:::\  /:::|____||:::|____\     /:::/    /\:::\   \:::\   \::/    /\::/    \:::\  /:::/    /\:::\   \:::\   \::/    /|:::|__/:::/   /:::/    /\::/    \:::\  /:::/    /\::/    \:::\  /:::|____|
         \/_____/\:::\/:::/    /  \:::\    \   /:::/    /  \:::\   \:::\   \/____/  \/____/ \:::\/:::/    /  \:::\   \:::\   \/____/  \:::\/:::/   /:::/    /  \/____/ \:::\/:::/    /  \/_____/\:::\/:::/    / 
                  \::::::/    /    \:::\    \ /:::/    /    \:::\   \:::\    \               \::::::/    /    \:::\   \:::\    \       \::::::/   /:::/    /            \::::::/    /            \::::::/    /  
                   \::::/    /      \:::\    /:::/    /      \:::\   \:::\____\               \::::/    /      \:::\   \:::\____\       \::::/___/:::/    /              \::::/    /              \::::/    /   
                    \::/____/        \:::\__/:::/    /        \:::\  /:::/    /               /:::/    /        \:::\  /:::/    /        \:::\__/:::/    /               /:::/    /                \::/____/    
                     ~~               \::::::::/    /          \:::\/:::/    /               /:::/    /          \:::\/:::/    /          \::::::::/    /               /:::/    /                  ~~          
                                       \::::::/    /            \::::::/    /               /:::/    /            \::::::/    /            \::::::/    /               /:::/    /                               
                                        \::::/    /              \::::/    /               /:::/    /              \::::/    /              \::::/    /               /:::/    /                                
                                         \::/____/                \::/    /                \::/    /                \::/    /                \::/____/                \::/    /                                 
                                          ~~                       \/____/                  \/____/                  \/____/                  ~~                       \/____/                                  
                                                                                                                                                                                                                
Project: push_swap
==================

Description
-----------
push_swap is a small sorting project from the 42 curriculum. The goal is to sort
a list of integers using two stacks (A and B) and a very limited set of
operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr). The challenge is
to produce a valid sequence of operations that sorts the input using as few
operations as possible.

This repository implements several sorting strategies (small-input specialized
routines and a "Turk"/cheapest-move heuristic) and the basic stack operations
expected by the project.

Instructions
------------
Requirements
- A Unix-like system (Linux, macOS)
- A C compiler (gcc)
- Make (the provided Makefile)
- Optionally: the provided checker (or the project's checker) to verify output

Build
1. Clone the repository:
   git clone <your-repo-url>
2. Enter the project directory:
   cd push_swap
3. Build:
   make

Run
- Basic usage:
  ./push_swap 3 2 1 5 4
  The program prints a list of operations (one per line) that will sort the
  numbers given as arguments.

- Validate with the checker:
  ./push_swap 3 2 1 5 4 | ./checker_linux 3 2 1 5 4
  The checker should print "OK" when the operation sequence sorts the numbers.

- Debugging with Valgrind (optional):
  valgrind --leak-check=full ./push_swap 3 2 1 5 4

Notes
- For small sizes the program uses specialized routines (sort_2, sort_3, sort_5).
- For larger inputs the implementation uses a "Turk" (cheapest-move) heuristic:
  that computes a cost for moving each candidate from A to B, chooses the best,
  and executes it using combined rotations where possible to reduce move count.

Resources
---------
Helpful references and background material used while developing this project:

- Video overview / explanation:
  - [Push Swap explanation (video)](https://www.youtube.com/watch?v=wRvipSG4Mmk)

- Article / walkthrough:
  - [Push Swap strategy on Medium](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

- Project subject (consult your school's subject PDF / intranet for exact rules)
  - 42 push_swap subject (refer to your campus resources)

AI usage disclosure
-------------------
AI assistance (ChatGPT) was used during development for the following tasks:
- Designing and explaining the "Turk" (cheapest-move) algorithm and its steps.
- Proposing small helper functions and data structures (e.g., t_move) to store
  candidate costs and rotations.
- Debugging memory errors and NULL-dereference crashes (Valgrind traces): the AI
  helped identify unsafe list traversals and suggested safe iteration patterns.
- Fixing helper functions (ft_lstmax, ft_lstmin) to avoid invalid dereferences.
- Implementing robust helpers: get_index, get_rotation, find_pos_in_b,
  execute_rotations_and_pb and other utilities.
- Generating test suggestions, debug prints, and run/validation instructions.
- Generating this README.

All AI-proposed code was reviewed and integrated manually. Use of AI was limited
to design suggestions, bug diagnosis, and example code. Final verification,
compilation and testing were performed by the developer.

Development notes & tips
------------------------
- Keep the invariant for stack B explicit (common choice: B is kept in descending
  order top→bottom). Many insertion and push-back steps depend on this.
- When debugging, temporarily print the stacks after every operation to trace
  logic errors. Remove prints before final submission.
- Use Valgrind to locate invalid reads/writes and memory leaks.
- Be careful to compare integer values stored in node->content, not the pointers.
- Ensure helper functions gracefully handle empty lists (NULL) and return
  reasonable sentinel values or error codes to callers.

Contributing / Contact
----------------------
Author: zaalrafa

If you want to contribute, open an issue or send a patch with a clear
description of the change.

License
-------
This repository does not include a license file. Add one if you want to allow
others to reuse or contribute to your code
