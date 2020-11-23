#meta 1
para testes ./uccompiler -l <testes/NOME.uc > testes/NOME.out

#meta 2
lex uccompiler.l
yacc -d uccompiler.y
clang-3.9 -o uccompiler lex.yy.c y.tab.c 

./uccompiler -l < first.uc

#print arvore
./uccompiler -t < first.uc





# COMO USAR O BASH DO PEDRO
- abrir a pasta da meta2
- adicionar o file tests.sh
- organizacao: 	meta2/tests/input com os ficheiros .c e .out dados pelo stor
				meta2/tests/output com os ficheiros .out são os nossos testes (inicialmente vazios)
- no terminal:	bash test.sh uccompiler -t

// -t é a flag da meta


links importantes:
- tokens da linguagem https://eden.dei.uc.pt/~rbarbosa/C99_standard.pdf
- repositorio do stor https://git.dei.uc.pt/rbarbosa/Comp2020/blob/master/meta1  
      user: email do dei sem o @student.dei.uc.pt
      passe: passe do email do dei
- mooshak para testar http://mooshak2.dei.uc.pt/~compiladores 
      user: uc2018274233_uc2018283892
      passe: E8nXij
      
      
- https://github.com/ruilinhares/Compiladores/blob/master/meta2/uccompiler.y

- https://github.com/jllopes/uccompiler/blob/master/uccompiler.y
      
