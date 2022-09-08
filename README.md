# doxygen_aspice
ASPICE document generator for all python developers

# who has the rights to use it
- first of all , i do not want to use this project for reverse-engineering.
- ***the best documents for design is doxygen comments in header file.***   so i hope that you design in the header files with doxygen comments.
  - doxygen supports explanation for each API and arguments.
  - doxygen supports plantuml to draw the sequence diagram and flow chart. it is more convenient to manage with git and edit/modify because this is based on only text.
- this project wants to generates documents and update changes automatically with sychronized contents from source code.

# how to run
- ```make```
    - sample source : ./doxygen/src
    - make doxygen : ./doxygen/DOXYGEN_OUTPUT
        - perlmod file : ./doxygen/DOXYGEN_OUTPUT/perlmod/DoxyDocs.pm
    - tools/doxy2cga.pl : DoxyDocs.pm transfer to default.GV (for perl) and DB4python.data (for python)
    - cp tools/DB4python.data tools/D.py -f    : because we use import D
    - generate the markdown result through mako : ./gen/doc.md   from ./template/doc/doc.md.stcI

## using tools
- python / perl / mako

## code beamer help
- wkik : https://codebeamer.com/cb/wiki/8798
- attatchment : https://codebeamer.com/cb/wiki/117612#section-Add+new+item+attachments
- uri : https://codebeamer.com/cb/wiki/117612#section-Get+items+related+to+a+user

