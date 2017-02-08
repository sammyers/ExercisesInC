#SoftSys Reflection 1
### Sam Myers


####Sprint Reflection
Despite the fact that our team got off to a slightly rocky start, after this sprint I felt far more comfortable with C and reasonably prepared to actually start tackling the HTTP server project. I will say that our EduScrum practice still needs work, as we weren't really consistent with standups and goal-setting. I'm hopeful that as we move toward actually working on the project and dividing up tasks, we'll be able to ease into the Scrum workflow. For now, we've acknowledged this challenge and resolved to make an effort to be less ambiguous with our Trello cards. 

####Exercises
* [Chapter 1](../exercises/ex01/ex01.md)
* [Chapter 2](../exercises/ex02/stack.c)

####Reading Questions
[Chapters 1 & 2](../reading_questions/thinkos.md#chapter-1)

####Exam Question
Explain the difference between declaring a string with square bracket notation and with pointer notation.

*Answer:* When declaring a string variable as a pointer, the character values are placed as constants in read-only memory. Declaring the string as a char array allocates memory on the stack, which can be modified. In addition, declaring the string as a pointer allows you to reassign the pointer variable later. If declared as an array, the memory address of the head of the array is not distinct from the array variable, so it can't be reassigned.
