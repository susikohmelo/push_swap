# Push_swap <img align="left" src="https://github.com/susikohmelo/push_swap/blob/main/readme_files/score.png" height="120"/>
Push swap is a high efficiency stack sorting algorithm, the goal is to sort a stack with the smallest number of operations possible.

*You have two stacks, A - which is the stack that needs to be sorted, and B - which is a temporary stack for sorting.*
<img src="https://github.com/susikohmelo/push_swap/blob/main/readme_files/visualized_sort.gif" height="300" /><br/>
<sup>Credit to [push_swap_visalizer](https://github.com/o-reo/push_swap_visualizer) for this awesome software to visualize the algorithm

**I've used the most conventional solution at 42 schools - the mechanical turk algorithm.<br/>**
>Oversimplified; push values from A to B in the order of least operations required to push them near a node on stack B that is similar in value. When stack A has 3 or less values, sort them manually, then push the numbers back from B - again always pushing the value that requires the least operations to reach it's target first.

### You can perform the following operations:
| Operation  | Description   |
| ---------- | ------------- |
|sa  - swap a          | Swap the first 2 elements at the top of stack a.
|sb  - swap b          | Swap the first 2 elements at the top of stack b.
|ss  - swap s          | swap a and b at the same time.
|pa  - push a          | Take the first element at the top of b and put it at the top of a.
|pb  - push b          | Take the first element at the top of a and put it at the top of b.
|ra  - rotate a        | Shift up all elements of stack a by 1.
|rb  - rotate b        | Shift up all elements of stack b by 1.
|rr  - rotate r        | rotate and b at the same time.
|rra - reverse rotate a| Shift down all elements of stack a by 1.
|rrb - reverse rotate b| Shift down all elements of stack b by 1.
|rrr - reverse rotate r| reverse rotate a and b at the same time.

## To build & run
Download the repository and run `make` in the root folder.<br/>
To run the program, use `./push_swap <numbers_to_be_sorted>` and the program will print the operations it would that would sort the input. The input has to be an integer, and there cannot be repeated numbers.

Example: `./push_swap 42 900 1 0 5 24 3`
