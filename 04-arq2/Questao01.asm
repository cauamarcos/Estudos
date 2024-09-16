# Questão 1
# Grupo 3:
#	Alex Cyrillo de Sousa Borges
#	Cauã Marcos de Oliveira Silva
#	Davi Silveira Siqueira
#	Patrick Leite Oliveira
#	Thiago Melato Fonseca
################ Segmento de dados ################
.data
	zero: .float 0.0
	meses: .float 12.0
	rendimento_anual: .float 1.07 	# o grupo decidiu que o rendimento anual usado na questão será de 7%
	ano: .word
	mensagemInput: .asciiz "Digite o valor inicial do investimento: "
	mensagem: .asciiz "Montante de capital ao final do ano "
	dois_pontos: .asciiz ": "
	quebra_linha: .asciiz "\n"
	
################ Segmento de código ################
.text
.globl main
main:
	la $a0, mensagemInput    	# carregando o endereço da mensagemInput em $a0
	li $v0, 4 		 	# imprimir string
	syscall

	li $v0, 6 		 	# ler float
	syscall
	
	jal calcularRendimento     	# chamada da função
	
calcularRendimento:
	l.s $f1, meses 			# $f1 = 12
	l.s $f2, rendimento_anual	# $f2 = 1.07
	l.s $f3, zero			# $f3 = 0
	l.s $f4, zero			# $f4 = 0 (o $f4 será usado como constante, diferentemente do $f3)
	li $t0, 0			# $t0 é o contador do loop
	loop:
		mul.s $f5, $f0, $f1    	# $f5 armazena o valor investido por ano
		add.s $f6, $f5, $f3	# $f6 = valor aplicado no ano + valor final do ano anterior
		mul.s $f6, $f6, $f2 	# $f6 *= 1.07
		add.s $f3, $f6, $f4	# $f3 = valor final do ano ($f6 + 0)
		addi $t0, $t0, 1	# incremento no contador
		sw $t0, ano		# contador armazenado em variavel para ser impresso a cada loop
		jal saida		# chamada da funcao de impressão de dados
		blt $t0, 10, loop	# enquanto o contador for < 10
	
	jal encerrar			# encerrar o programa
	
saida:
	la $a0, mensagem
	li $v0, 4			# impressão da string mensagem
	syscall
	
	li $v0, 1			# imprimir inteiro
	lw $a0, ano			# a variável ano é atualizada a cada loop para que mostre o número do ano
	syscall
	
	li $v0, 4
	la $a0, dois_pontos
	syscall

	li $v0, 2 		 	# imprimir float
	mov.s $f12, $f6			# o valor final do loop armazenado em $f6 é movido para $f12, que será impresso
	syscall
	
	li $v0, 4
	la $a0, quebra_linha
	syscall
	
	jr $ra
	
encerrar:
	li $v0, 10		 	# encerrar o programa
	syscall
	
