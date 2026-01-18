𝘛𝘩𝘪𝘴 𝘱𝘳𝘰𝘫𝘦𝘤𝘵 𝘩𝘢𝘴 𝘣𝘦𝘦𝘯 𝘤𝘳𝘦𝘢𝘵𝘦𝘥 𝘢𝘴 𝘱𝘢𝘳𝘵 𝘰𝘧 𝘵𝘩𝘦 42 𝘤𝘶𝘳𝘳𝘪𝘤𝘶𝘭𝘶𝘮 𝘣𝘺 <𝘧𝘴𝘩𝘦𝘭𝘯𝘢>

# Description
## Project Description
- A string or multiple containing integers numbers are given as input
  With two stacks and a set of commands provided by the subject you need to sort it
## Brief Overview
- I checked if the input is valid
- Converted and parsed in the Stack A
- Divided the numbers in Chunks
- Moved the chunks in B from the smallest
- Moved the chunks in A from the biggest
- And while doing this i tried to reduces the numbers of operations
# Instructions

- To compile use make command
- ARG=$(shuf -i 0-500 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l for testing

# Resources
## Links
- https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
## AI
- To reduce lines of functions
- Help visualize the chunk system i used
