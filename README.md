# doxygen_aspice
ASPICE document generator for all developers

# who has the rights to use it
- first of all , i do not want to use this project for reverse-engineering.
- ***the best documents for design is doxygen comments in header file.***   so i hope that you design in the header files with doxygen comments.
  - doxygen supports explanation for each API and arguments.
  - doxygen supports plantuml to draw the sequence diagram and flow chart. it is more convenient to manage with git and edit/modify because this is based on only text.
- this project wants to generates documents and update changes automatically with sychronized contents from source code.

# TODO
- make a header file with doxygen comments as design notes
  - considering FIDL
- doxygen compile with PERLMOD and gathered all information for python
- generate template for markdown and codebeamer wiki and plantuml png
- upload these result to codebeamer

## using tools : 
- python / perl / mako

## code beamer help
- wkik : https://codebeamer.com/cb/wiki/8798
- attatchment : https://codebeamer.com/cb/wiki/117612#section-Add+new+item+attachments
- uri : https://codebeamer.com/cb/wiki/117612#section-Get+items+related+to+a+user
