Two!Ears Matlab Coding Style Guide
==================================


## Introduction

This is a first proposal of coding guide style lines for our Two!Ears model. At
the moment this document is limited to Matlab only.

Feel free to discuss every point of the proposal, but definitely those that are
especially marked with a **please discuss**.

## Documentation and Comments

Add documentation to every function or class you contribute to the Two!Ears
model.


### Function Headers

It is a good idea to have a consistent function header in all Two!Ears functions,
this makes a much better impression and enhances the understanding if people
uses the `help` function.

I propose the following standard.

```matlab
%functionName   This function is calculating fancy stuff1, not so fancy stuff2,
%               and provides you a nice solution.
%
%USAGE
%   outputParameter = functionName(inputParameter1)
%   outputParameter = functionName(inputParameter1,inputParameter2)
%
%INPUT PARAMETERS
%   inputParameter1 :   description of inputParameter1
%   inputParameter2 :   description of inputParameter2
%
%OUTPUT PARAMETERS
%   outputParameter :   description of outputParameter
%
%DETAILS
%   Here, more details could be presented. But only, if really needed.
```

This means that we follow not the Matlab standard of writing the function name
in capital letter at the beginning `FUNCTIONNAME`. This is not useful in our
case, because we use CamelCase notation.


### License

If a function comes with a different license (and only then) than the one
specified in the main README.md of the single repositories the license has
to be stated in the function.
In order to avoid clutter with the `help` command add an empty line between the
header and the license.

```matlab
%OUTPUT PARAMETERS
%   outputParameter :   description of outputParameter

% LICENSE: license
```


### Author

**please discuss**

Because we have lots of different authors that might also contribute to lots of
different files it could be discussed if it is really necessary to put an
author in to the function. On the other hand its easier to find the right person
to talk to, if you copy and paste this function out of the repository.

Possible solutions:

* State the authors only under the point *Credits* in the main README.md file of
  the repositories and not in the single functions
* In every function, add a field `AUTHOR:` and fill it with every one who
  modifies the function.
* Create a field `AUTHOR:` in every function and name only the one who created
  the function


### Versioning

If you don't use a version control system you are maybe used to put changes with
dates into the file header directly like

```matlab
% 10.10.2014: Completely changed everything
% 11.10.2014: Was not so good, undo changes
```

Since we are using git for versioning such lines should be deleted from the
code.


## Naming Conventions

### General

Avoid abbreviations of names if they are not common to the whole community as it
is the case with `fs`.

```matlab
% do not write
sigProc
% do write instead
signalProcessing
```

Abbreviations that are normally given in uppercase like `ILD` should be changed
in the following way:

```matlab
% variables
ildLimit
enhancedIldLimit
% objects
IldLimit
```

### Variables

Variables should start with a lower case letter and use upper case letters for
every starting word.

```matlab
signal
inputSignal
auditoryFrontEndCues
```

Use the prefix `n` for indicating the number of objects. Avoid `i` or `j` as
variables, because they could be the imaginary unit. A common solution to that
problem is the usage of `ii`, `jj`, `kk`, `nn` as indices of in a loop.

```matlab
for ii = 1:nFiles
    destroyFile(Files{ii});
end
```


### Constants

**please discuss**

I don't know if we need this, but if you have constants in your function that
can not be changed, you should write them completely uppercase.

```matlab
TRESHOLD = 3.2;
```

### Functions

For functions the naming convention is exactly the same as for variables.

```matlab
limit()
limitSignal()
disableAuditoryFrontEnd()
```

For finding the correct name for a function the following points should be
considered.

* name a function with a single output based on that output,
  `confidenceInterval`
* name a function with no output after what they do, `plotSignal`
* use the prefix `is` for boolean functions, `isFinished`
* avoid unintentional shadowing, e.g. use `convolution` not `conv`

### Classes/Objects

Like functions, but always start with a uppercase letter.

```matlab
Signals
BlackboardSystem
AuditoryFrontEnd
```

**please discuss**

When is the correct moment to use something like `+simulator` as it is done in
the [Two!Ears Binaural Simulator](https://github.com/TWOEARS/binaural-simulator)
compared to the `knowledge_sources` folder in the
[Two!Ears Blackboard System](https://github.com/TWOEARS/blackboard-system).


## Layout

### Code Indention

Use exactly 4 white spaces (not a tab) for indention.

```matlab
if true
    while true
        disp('wait a very long time.')
    end
end
```

In vim this behavior can be achieved with the following setting.

```vim
set sw=4 ts=4 expandtab
```

### Line Width

**please discuss**

The usual setting is to limit the line width in code to 80 characters. Should we
do the same?

Pros:

* this is THE common setting
* enhances compatibility for viewing code in different applications, for example
  online at github

Cons:

* due to the usage of long variable names it can often happen that we have to
  break a line, which could decrease its readability
* monitors nowadays a much larger than the 80 characters


