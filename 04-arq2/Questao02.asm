# Questão 1
# Grupo 3:
#	Alex Cyrillo de Sousa Borges
#	Cauã Marcos de Oliveira Silva
#	Davi Silveira Siqueira
#	Patrick Leite Oliveira
#	Thiago Melato Fonseca
################ Segmento de dados ################
.data
	n: .word
	zero: .float 0.0
	incremento: .float 1.0
	decremento: .float -1.0
	mensagemInput: .asciiz "Digite um número inteiro: "
	resultado: .asciiz "Resultado: "
	
################ Segmento de código ################
.text
.globl main
main:
	la $a0, mensagemInput    	# carregando o endereço da mensagemInput em $a0
	li $v0, 4 		 	# imprimir string
	syscall

	li $v0, 5 		 	# ler int
	syscall
	move $t0, $v0			# o inteiro lido é movido para $t0
	sw $t0, n			# $t0 é armazenado em n
	
	jal calcular     		# chamada da função
	
	jal saida			# chamando função para imprimir o resultado
	
calcular:
	lwc1 $f0, n			# o valor armazenado em n é carregado em $f0
	cvt.s.w $f0, $f0		# conversão de word em $f0 para single precision no próprio $f0
	l.s $f1, incremento 		# $f1 = 1 (será usado como numerador de cada fração)
	l.s $f2, incremento		# $f2 = 1 (será usado como constante, diferentemente de $f1)
	l.s $f3, decremento		# $f3 = -1 (será usado como constante para decremento do denominador)
	l.s $f4, zero			# $f4 será usado para armazenar a soma das frações
	loop:
		div.s $f5, $f1, $f0    	# $f5 é o resultado da divisão que corresponde à fração da iteração
		add.s $f4, $f4, $f5	# $f4 += fração do loop
		add.s $f1, $f1, $f2	# incremento no numerador
		add.s $f0, $f0, $f3 	# decremento no denominador
		add $t0, $t0, -1	# decremento no contador do loop ($t0 tem o mesmo valor de n)
		bgtz  $t0, loop		# enquanto n > 0
		
	jr $ra
	
saida:
	la $a0, resultado
	li $v0, 4			# impressão da string mensagem
	syscall

	li $v0, 2 		 	# imprimir float
	mov.s $f12, $f4			# o valor final do loop armazenado em $f6 é movido para $f12, que será impresso
	syscall
	
	jal encerrar			# encerrar o programa
	
encerrar:
	li $v0, 10		 	# encerrando o programa
	syscall
	
