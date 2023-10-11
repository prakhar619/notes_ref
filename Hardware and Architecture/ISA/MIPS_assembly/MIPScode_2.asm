#This is sample ams file for MIPS
.text
.globl main


main:
	#loop_dec
		#s7 will be loop variable
		#decrement s7 to zero
		# s7 =>  x->1	#never zero 
		
		
		addi $s7,$0,x
		Loop_start:
			beq $s7,$0,Loop_end
			
			#Inside loop
			  
			addi $s7,$s7,-1
			j Loop_start
		Loop_end:
		
	#----------------------------------------
		
	#loop_inc
		#s7 will be loop variable
		#s0 will have upper limit
		#s7 =>  0->(s1-1)
		
		addi $s0,$0,x
		
		addi $s7,$0,$0
		Loop_start:
			beq $s7,$s0,Loop_end
			
			#Inside loop
			
			addi $s7,$s7,1
			j Loop_start
		Loop_end:
		
	#----------------------------------------
	



#nested 2 loop

	#loop_inc
		#s7 will be loop variable
		#s6 will be loop variable2
		#s0 will have upper limit
		#s1 will have upper limit2
		#s7 =>  0->(s0-1)
		#s6 => 0->(s1-1)
		
		addi $s0,$0,x
		addi $s1,$0,x
		
		addi $s7,$0,$0
		Loop_start:
			beq $s7,$s0,Loop_end
			
			#Inside loop
				
				addi $s6,$0,$0
				Loop_start2:
					beq $s6,$s1,Loop_end2
					
					#Inside loop2
					
					addi $s6,$s6,1
					j Loop_start2
				Loop_end2:
				
			
			addi $s7,$s7,1
			j Loop_start
		Loop_end:
	
	#-----------------------------------------	
	

#nested 3 loop

#if

	# if(s0 > s1)
	#  { }
	 
	bgt $s1,$s0, else
	
		
	else:

   #--------------------------
	
	#if(s0 < s1)
	#  {}
	
	bgt $s0,$s1,else
	
	
	else:
	
  #---------------------------

#if else


	# if(s0 > s1)
	#  { }
	# else
	#  { } 
	bgt $s1,$s0, else
	
		
		j end
	else:




	end:
	
   #----------------------------
   
   
   	#if(s0 < s1)
	#  {}
	
	bgt $s0,$s1,else
	
	
		j end
	else:


	
	end:
	
  #--------------------------------

#if elseif else

	#ranged based if elseif else
	# if(x < 0)
	# elseif (x < 20)
	# elseif (x < 40)
	# else
	
	addi $s0,$0,x
	
	addi $s1,$0, x_1
	bgt $s0, $s1, elif1
	
		#here
		j end:
	elif1:
	addi $s1,$0,x_2
	bgt $s0,$s1,elif2
	
		#here
		j end:
	elif2:
	addi $s1,$0,x_3
	bgt $s0,$s1,else
	
		#here
		j end:
	else:
	
		#here
	end:
	
		

#print prompt

	la $a0, prompt_x
	addi $v0,$0, 4
	syscall
	
  #--------------------------------

#print int

	addi $a0,$0,x
	addi $v0,$0,1
	syscall
	
    #------------------------

#print char

	addi $a0,$0,x
	addi $v0,$0,11
	syscall
	
   #------------------------

#print string

	la $a0, x_label
	addi $v0,$0,4
	syscall
	
   #------------------------
	

#exit

	addi $v0,$0,10
	syscall
	
   #----------------------


#subroutine

	#max of 2 no
		
		jal Max2
		
		Max2:
			bgt $a1,$a0,A_one_big
				add $v0,$0,$a0
				jal $ra
			A_one_big:
				add $v0,$0,$a1
				jal $ra
			
	#-----------------------------------------------------
	
		jal Max3
		
		Max3:
			bgt $a1,$a0,A_one_big
				bgt $a2,$a0,A_two_big
					add $v0,$0,$a0
					jal $ra
			A_one_big:
				bgt $a2,$a1,A_two_big
					add $v0,$0,$a1
					jal $ra
			A_two_big:
				add $v0,$0,$a2
				jal $ra
				
	#----------------------------------------------------------
		
		jal string_iter
		
		string_iter:
			lb $t9, 0($a0)
			beq $t9,$0,string_end
				
				#t9 contain char
				
			addi $a0,$a0,1
			j string_iter
		string_end:
			
		

#user input int

#user input string

#user input char
