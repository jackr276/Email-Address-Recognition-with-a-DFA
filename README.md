# Email Address Recognition with a Deterministic Finite Automaton
Author: [Jack Robbins](https://www.github.com/jackr276)

## Introduction
This project uses a determinstic finite automaton(DFA) to recognize strings that are in a regular language of valid email addresses $L$, fully defined below. This markdown document contains the description of $L$, the illustration of the DFA for $L$, and the formal mathematical 5-tuple defintion for this DFA. The source file [dfa.cpp](https://github.com/jackr276/Email-Address-Recognition-with-a-Deterministic-Finite-Automaton/blob/main/src/dfa.cpp) contains an implementation of the DFA that allows a user to enter strings and view the real-time processing of them, and will determine if the string is or is not in the language. A more in depth descritpion of each item is contained below.

## The Language $L$
### Alphabet of $L$
The Language $L$ is defined over the alphabet $\Sigma$, which itself is defined as $\Sigma = \Psi \cup \Pi \cup \Phi$ with: 
* $\Psi =$ {a, b, c,. . .,z} being the set of all lower case roman letters
* $\Pi =$ {.}
* $\Phi =$ {@}

In short, the alphabet for this language is all lowercase roman numerals, the "." and the "@" symbol.

### Definition of $L$
From here, we define the language $L$ to be the set of strings over the alphabet $\Sigma$ that are of the form: $L = S_{1}S_{2}^\star\Phi S_{1}S_{2}^\star(S_{3} \cup S_{4})$, where:
* $S_{1} = \Psi\Psi^\star$, which defines strings of lowercase roman numerals of length at least 1
* $S_{2} = \Pi\Psi\Psi^\star$, which defines strings like $S_{1}$, except that they begin with a dot
* $S_{3} =$ {.gov}, one possible valid ending of email addresses in $L$
* $S_{4} =$ {.gr}, the other possible valid ending of email addresses in $L$

To make this more grounded, two examples of strings that are defined over the Language L are: "abc@learner.gr" or "a.b.c.d@d.c.b.a.gov". Notice how every "." is followed by at least one letter, and there is only one "@" symbol. Strings like "my@website@example.gov" would not be accepted, even though this string ends properly in a ".gov", the use of two "@" symbols makes it incorrect. Strings like "abc@abc.com" are easier to identify as not being in the language, because stings in $L$ must end in ".gov" or ".gr", regardless of proper grammar otherwise.

### $L$ is a Regular Language
By definition, a langauge is regular if there exist a Deterministic Finite Automaton that **accepts** every string in the language and at the same time **rejects** every string not in the language. As we will soon see, there is a DFA $M$ that recognizes every string in $L$ and rejects every string not in $L$. The existence of $M$ shows us in practice that $L$ is a regular language, by definition.

## Deterministic Finite Automaton(DFA) $M$, for $L$
### 5-Tuple Definition for $M$
Formally, the DFA that recognizes the language $L$ can be defined as the 5-Tuple $M = (Q, \Sigma, \delta, q_{1}, F)$ with:
* $Q =$ { $q_{1}, q_{2}, q_{3}, q_{4}, q_{5}, q_{6}, q_{7}, q_{8}, q_{9}, q_{10}$ } is the set of all states in $M$
* $\Sigma = \Psi \cup \Pi \cup \Phi$ is the alphabet that $L$ is defined over, as described above
* $\delta: Q \times \Sigma \rightarrow Q$ is the transition function, which is defined as:

  | Q | $\Psi_{-g, r, o, v}$ | g | r | o | v | $\Pi$ | $\Phi$ |
  |---|---|:---------:|---|---|---|---|---|
  |$q_{1}$| $q_{2}$ | $q_{2}$ | $q_{2}$ | $q_{2}$ | $q_{2}$ | $q_{10}$ | $q_{10}$ |
  |$q_{2}$| $q_{2}$ | $q_{2}$ | $q_{2}$ | $q_{2}$ | $q_{2}$ | $q_{1}$ | $q_{3}$ |
  |$q_{3}$| $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{10}$ | $q_{10}$ | 
  |$q_{4}$| $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{5}$ | $q_{10}$ | 
  |$q_{5}$| $q_{4}$ | $q_{6}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{10}$ | $q_{10}$ | 
  |$q_{6}$| $q_{4}$ | $q_{4}$ | $q_{7}$ | $q_{8}$ | $q_{4}$ | $q_{5}$ | $q_{10}$ | 
  |$q_{7}$| $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{5}$ | $q_{10}$ | 
  |$q_{8}$| $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{9}$ | $q_{5}$ | $q_{10}$ | 
  |$q_{9}$| $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{4}$ | $q_{5}$ | $q_{10}$ | 
  |$q_{10}$| $q_{10}$ | $q_{10}$ | $q_{10}$ | $q_{10}$ | $q_{10}$ | $q_{10}$ | $q_{10}$ |

* $q_{1}$ is the starting state
* $F =$ { $q_{7}$, $q_{9}$ } is the set of accepting states

> [!NOTE]
> Once the DFA goes into state $q_{10}$, there is no way to leave it. This is because $q_{10}$ is a so-called "trap state", meaning that once the DFA enters it, it is trapped in it until it is done reading the string. Strings enter $q_{10}$ after there is a fatal grammar error. For example, reading a "." as the first character will send the DFA to $q_{10}$ for the rest of the string. However, being in $q_{10}$ does not cause the DFA to terminate immediately. This is because, by definition, the DFA must process the entire string, and **then** accept or reject it.

### Drawing of $M$
Though useful for rigorously defining the DFA $M$, the 5-Tuple definition is very abstract and not easy to understand at a glance. Below is an illustration of $M$, to better show how it works. $M$ can be represented as a directed graph, with the nodes being the states from $Q$ and the edges being labeled with what symbol must be read to advance to the next state. States that have a double circle border are accepting states.

![P1_DFA_jmr226(1)](https://github.com/jackr276/Email-Address-Recognition-with-a-Discrete-Finite-Automaton/assets/113046361/ffc8d175-1cb0-408f-9b86-b69a530b3de4)

Here is an example of how the DFA would process the string "a.bc@ex.gov"
1. Begin in start state $q_{1}$
2. Read symbol a $\in \Psi$, move to $q_{2}$
3. Read symbol "." $\in \Pi$, move to $q_{1}$
4. Read symbol b $\in \Psi$, move to $q_{2}$
5. Read symbol c $\in \Psi$, move to $q_{2}$
6. Read symbol "@" $\in \Phi$, move to $q_{3}$
7. Read symbol e $\in \Psi$, move to $q_{4}$
8. Read symbol x $\in \Psi$, move to $q_{4}$
9. Read symbol "." $\in \Pi$, move to $q_{5}$
10. Read symbol g, move to $q_{6}$
11. Read symbol o, move to $q_{8}$
12. Read symbol v, move to $q_{9}$

The entire string has been processed, and $M$ ended in $q_{9} \in F$ which is an accepting state, so the string "a.bc@ex.gov" is accepted as being in the language $L$

