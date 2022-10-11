> 1. Find the five mistakes inside the map function in `megalistmanips.s`. Read all of the commented lines under the `map` function in `megalistmanips.s` (before it returns with `jr ra`), and make sure that the lines do what the comments say. Some hints:
> 
>       + Why do we need to save stuff on the stack before we call jal?
>
>       + What’s the difference between `add t0, s0, x0  `and `lw t0, 0(s0)`?
>       + Pay attention to the types of attributes in a `struct node`.
>       + Note: you need only focus on `map` , `mapLoop`, and `done` functions but it’s worth understanding the full program.
>       + Note: you may not use any `s` registers outside of `s0` and `s1` .


> 2. **For this exercise, we are requiring that you don’t use any extra save registers in your implementation**. While you normally can use the save registers to store values that you want to use after returning from a function (in this case, when we’re calling `f` in `map`), we want you to use temporary registers instead and follow their caller/callee conventions. The provided `map `implementation uses the `s0` and `s1` registers, so we’ll require that you don’t use `s2`-`s11`.


> 3. **Make an ordered list of each of the five mistakes, and the corrections you made to fix them**.

> 4. Save your corrected code in the `megalistmanips.s` file. Running on Venus, you should see the following output:
 ```
 Lists before:
5 2 7 8 1
1 6 3 8 4
5 2 7 4 3
1 2 3 4 7
5 6 7 8 9

Lists after:
30 6 56 72 2
2 42 12 72 20
30 6 56 20 12
2 6 12 20 56
30 42 56 72 90
```
# My answer
Modifications are saved in `megalistmanips.s`. The major problems were:

1. Wrong Instruction used.
2. Violation of Calling Convention.
3. Wrong offset calculation.
   
