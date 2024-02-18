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






![P1_DFA_jmr226(1)](https://github.com/jackr276/Email-Address-Recognition-with-a-Discrete-Finite-Automaton/assets/113046361/ffc8d175-1cb0-408f-9b86-b69a530b3de4)
