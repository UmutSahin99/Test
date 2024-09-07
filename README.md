Test

This program checks if the password is valid or not by these rules : 
1) Password should contain at least one uppercase letter.
2) Password should be numeric.
3) Password should contain any of the special characters (@?!).
4) Password should contain at least two digits.

For each condition, seperate processes work and return values.Then the main process collects the exit codes of the child processes, sums them up, and determines the validity of the password.
