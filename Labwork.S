  # labwork.S
  # Written 2015 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1 2015-2016.
  # The macros PUSH and POP are in the public domain.

.macro	PUSH reg
	#sw	\reg,0($sp)
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

#.macro	PUSH (%reg)
#	addi	$sp,$sp,-4
#	sw	%reg,0($sp)
#.end_macro
#
.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm

  # You can add your own code here
  #
# timetemplate.asm
  # Written 2015 by F Lundevall
  # Copyright abandonded - this file is in the public domain.

	.data
	.align 2
timstr:	.ascii "abcdefghijklmnopqrstuv\0"
	.text

.global enable_interrupt
enable_interrupt:
	ei
	jr	$ra
	nop

hexasc:
	andi	$a0, 0xf	# 4 least significant bit values remain. Wipe others
	addi	$v0, $a0, 0x30  # make corresponding ASCII 
	slti	$t0, $a0, 0xa    # check if $a0 is less than 10
	beq	$t0, 1, exithexasc # branch to exithexasc if $t0 equals 1
	nop
	addi	$v0, $v0, 0x7	# add necessary value to jump to correct ASCII
	
exithexasc:	
	jr 	$ra 		# return to caller
	nop

.global delay
delay:  
	PUSH	$s0
	PUSH	$s1
	PUSH	$s3
	PUSH	$ra
	
	move	$s0, $a0	# set contents of a0 (ms) to s0
	#addi	$s1, $0, 0	# set start for for loop (i)
	addi	$s3, $0, 11500	# constant for for loop

delay_whileloop:
	addi	$s1, $0, 0	# set start for for loop (i)
	beq	$s0, $0, delay_exit	# exit while loop if s0 equals 0
	nop
	addi	$s0, $s0, -1	# subtract one from ms (s0)
	
delay_forloop:
	slt	$t0, $s1, $s3
	beq	$t0, $0, delay_whileloop
	nop
	addi	$s1, $s1, 0x1
	j	delay_forloop
	nop
	
delay_exit:
	POP	$ra
	POP	$s3
	POP	$s1
	POP	$s0
		
	jr	$ra
	nop	
	
.global time2string
time2string:
	PUSH	$s0	# push $s0 into stack
	PUSH	$s1	# push $s1 into stack
	PUSH	$ra	# push $ra into stack
	
	move	$s0, $a0	# move address in $a0 to $s0
	move	$s1, $a1	# move value in $a1 to $s1
	
	andi	$s1, 0xffff	# set all bits other than most significant 16 to 0
	srl	$a0, $s1, 12	# shift $s1 right 12 bits. Store in $a0.
	jal	hexasc		# call hexasc to convert $a0 to ascii
	nop
	sb	$v0, 0($s0)	# store ascii encoding at $s0 address (byte 0)
	
	srl	$a0, $s1, 8	# shift $s1 right 8 bits. Store in $a0. sra
	jal	hexasc		# call hexasc to convert $a0 to ascii
	nop
	sb	$v0, 1($s0)	# store ascii encoding at $s0 address (byte 1)
	
	andi	$a0, 0x0000	# clear $a0
	addi	$a0, $a0, 0x3a	# put encoded ascii value of ':' in $a0
	sb	$a0, 2($s0)	# store ascii encoding at $s0 address (byte 2)

	srl	$a0, $s1, 4	# shift $s1 right 4 bits. Store in $a0.
	jal	hexasc		# call hexasc to convert $a0 to ascii
	nop
	sb	$v0, 3($s0)	# store ascii encoding at $s0 address (byte 3)
	
	srl	$a0, $s1, 0	# store $s1 in $a0
	jal	hexasc		# call hexasc to convert $a0 to ascii
	nop
	addi	$s0, $s0, 0x4	# add 4 to $s0 address to move to up a word
	beq	$v0, 0x32, else	
	nop
	sb	$v0, 0($s0)	# store ascii encoding at $s0 address (byte 0)
	
	andi	$a0, 0x0000	# clear $a0
	addi	$a0, $a0, 0x00	# put encoded ascii value of 'NUL' in $a0
	sb	$a0, 1($s0)	# store ascii encoding at $s0 address (byte 1)
	
	POP	$ra
	POP	$s1
	POP	$s0
	
	jr	$ra
	nop

	else:
	li	$t0, 0x54	#T
	li	$t1, 0x57	#W
	li	$t2, 0x4f	#0
	
	sb	$t0, 0($s0)
	sb	$t1, 1($s0)
	sb	$t2, 2($s0)
	
	andi	$a0, 0x0000	# clear $a0
	addi	$a0, $a0, 0x00	# put encoded ascii value of 'NUL' in $a0
	sb	$a0, 3($s0)	# store ascii encoding at $s0 address (byte 1)
	
	POP	$ra
	POP	$s1
	POP	$s0
	
	jr	$ra
	nop

